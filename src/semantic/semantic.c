/* semantic.c - Implementation de l'analyse semantique et de la table des symboles
 * Groupe 02 - Theorie des Langages et Compilation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantic.h"
#include "../utils/error.h"


/* nombre d'erreurs semantiques rencontrees */
static int nb_erreurs = 0;


/* -- Gestion de la table des symboles -- */

TableSymboles *ts_creer(void) {
    TableSymboles *ts = malloc(sizeof(TableSymboles));
    if (!ts) erreur_fatale("Allocation de la table des symboles echouee");
    ts->tete           = NULL;
    ts->portee_courante = 0;
    return ts;
}

int ts_inserer(TableSymboles *ts, const char *nom,
               const char *type, SymCategorie cat, int ligne) {
    /* verifie qu'il n'existe pas deja dans la portee courante */
    Symbole *s = ts->tete;
    while (s) {
        if (s->portee == ts->portee_courante && strcmp(s->nom, nom) == 0) {
            erreur_double_declaration(nom, ligne);
            nb_erreurs++;
            return -1;
        }
        s = s->suivant;
    }

    Symbole *nouveau = malloc(sizeof(Symbole));
    if (!nouveau) erreur_fatale("Allocation d'un symbole echouee");

    nouveau->nom       = strdup(nom);
    nouveau->type      = strdup(type);
    nouveau->categorie = cat;
    nouveau->portee    = ts->portee_courante;
    nouveau->ligne     = ligne;
    nouveau->suivant   = ts->tete;
    ts->tete           = nouveau;
    return 0;
}

Symbole *ts_chercher(TableSymboles *ts, const char *nom) {
    Symbole *s = ts->tete;
    while (s) {
        if (strcmp(s->nom, nom) == 0) return s;
        s = s->suivant;
    }
    return NULL;
}

void ts_ouvrir_portee(TableSymboles *ts) {
    ts->portee_courante++;
}

void ts_fermer_portee(TableSymboles *ts) {
    /* supprime tous les symboles de la portee courante */
    Symbole *s = ts->tete;
    Symbole *prev = NULL;
    while (s) {
        if (s->portee == ts->portee_courante) {
            Symbole *a_suppr = s;
            if (prev) prev->suivant = s->suivant;
            else       ts->tete     = s->suivant;
            s = s->suivant;
            free(a_suppr->nom);
            free(a_suppr->type);
            free(a_suppr);
        } else {
            prev = s;
            s    = s->suivant;
        }
    }
    ts->portee_courante--;
}

void ts_liberer(TableSymboles *ts) {
    Symbole *s = ts->tete;
    while (s) {
        Symbole *suivant = s->suivant;
        free(s->nom);
        free(s->type);
        free(s);
        s = suivant;
    }
    free(ts);
}


/* -- Fonctions d'analyse (parcours recursif de l'AST) -- */

static char *analyser_expr  (ASTNode *n, TableSymboles *ts);
static void  analyser_inst  (ASTNode *n, TableSymboles *ts,
                              const char *type_retour_courant);


/* retourne le type d'une expression, NULL si erreur */
static char *analyser_expr(ASTNode *n, TableSymboles *ts) {
    if (!n) return NULL;

    switch (n->type) {

        case N_ENTIER:  return "integer";
        case N_REEL:    return "reales";
        case N_CHAINE:  return "catena";
        case N_BOOLEEN: return "bina";

        case N_IDENTI: {
            Symbole *s = ts_chercher(ts, n->data.valeur_chaine);
            if (!s) {
                erreur_variable_non_declaree(n->data.valeur_chaine, 0);
                nb_erreurs++;
                return NULL;
            }
            return s->type;
        }

        case N_BINAIRE: {
            char *tg = analyser_expr(n->data.binaire.gauche, ts);
            char *td = analyser_expr(n->data.binaire.droite, ts);
            const char *op = n->data.binaire.operateur;

            /* operateurs de comparaison : retournent bina */
            if (strcmp(op, "<")  == 0 || strcmp(op, ">")  == 0 ||
                strcmp(op, "<=") == 0 || strcmp(op, ">=") == 0 ||
                strcmp(op, "==") == 0 || strcmp(op, "!=") == 0)
                return "bina";

            /* operateurs logiques : retournent bina */
            if (strcmp(op, "&&") == 0 || strcmp(op, "||") == 0)
                return "bina";

            /* operateurs arithmetiques : les deux operandes doivent etre numeriques */
            if (tg && td && strcmp(tg, td) != 0) {
                erreur_type_incompatible(tg, td, 0);
                nb_erreurs++;
                return NULL;
            }
            return tg;
        }

        case N_UNAIRE:
            return analyser_expr(n->data.unaire.operande, ts);

        case N_APPEL: {
            Symbole *s = ts_chercher(ts, n->data.appel.nom);
            if (!s) {
                erreur_variable_non_declaree(n->data.appel.nom, 0);
                nb_erreurs++;
                return NULL;
            }
            return s->type;
        }

        default:
            return NULL;
    }
}


static void analyser_inst(ASTNode *n, TableSymboles *ts,
                           const char *type_retour_courant) {
    if (!n) return;

    switch (n->type) {

        case N_LISTE:
        case N_PROGRAMME:
            analyser_inst(n->data.liste.gauche, ts, type_retour_courant);
            analyser_inst(n->data.liste.droite, ts, type_retour_courant);
            break;

        case N_DECL_MUT: {
            char *type_init = analyser_expr(n->data.decl.init, ts);
            if (type_init && strcmp(type_init, n->data.decl.type_var) != 0) {
                erreur_type_incompatible(n->data.decl.type_var, type_init,
                                         n->data.decl.init ? 0 : 0);
                nb_erreurs++;
            }
            ts_inserer(ts, n->data.decl.nom, n->data.decl.type_var,
                       SYM_VARIABLE, 0);
            break;
        }

        case N_DECL_IMM: {
            char *type_init = analyser_expr(n->data.decl.init, ts);
            if (type_init && strcmp(type_init, n->data.decl.type_var) != 0) {
                erreur_type_incompatible(n->data.decl.type_var, type_init, 0);
                nb_erreurs++;
            }
            ts_inserer(ts, n->data.decl.nom, n->data.decl.type_var,
                       SYM_CONSTANTE, 0);
            break;
        }

        case N_AFFECT: {
            Symbole *s = ts_chercher(ts, n->data.affect.cible);
            if (!s) {
                erreur_variable_non_declaree(n->data.affect.cible, 0);
                nb_erreurs++;
                break;
            }
            if (s->categorie == SYM_CONSTANTE) {
                erreur_affectation_constante(n->data.affect.cible, 0);
                nb_erreurs++;
                break;
            }
            char *type_val = analyser_expr(n->data.affect.valeur, ts);
            if (type_val && strcmp(type_val, s->type) != 0) {
                erreur_type_incompatible(s->type, type_val, 0);
                nb_erreurs++;
            }
            break;
        }

        case N_AFFECT_COPIE: {
            Symbole *cible  = ts_chercher(ts, n->data.affect.cible);
            Symbole *source = ts_chercher(ts, n->data.affect.source);
            if (!cible) {
                erreur_variable_non_declaree(n->data.affect.cible, 0);
                nb_erreurs++;
            }
            if (!source) {
                erreur_variable_non_declaree(n->data.affect.source, 0);
                nb_erreurs++;
            }
            if (cible && source && strcmp(cible->type, source->type) != 0) {
                erreur_type_incompatible(cible->type, source->type, 0);
                nb_erreurs++;
            }
            break;
        }

        case N_CAPTUM: {
            Symbole *s = ts_chercher(ts, n->data.captum.nom);
            if (!s) {
                erreur_variable_non_declaree(n->data.captum.nom, 0);
                nb_erreurs++;
            } else if (s->categorie == SYM_CONSTANTE) {
                erreur_affectation_constante(n->data.captum.nom, 0);
                nb_erreurs++;
            }
            break;
        }

        case N_EMITTUM:
        case N_EMITTUM_LISTE:
            analyser_expr(n->data.emittum.expr, ts);
            break;

        case N_QUIA:
            analyser_expr(n->data.quia.condition, ts);
            ts_ouvrir_portee(ts);
            analyser_inst(n->data.quia.alors, ts, type_retour_courant);
            ts_fermer_portee(ts);
            if (n->data.quia.sinon) {
                ts_ouvrir_portee(ts);
                analyser_inst(n->data.quia.sinon, ts, type_retour_courant);
                ts_fermer_portee(ts);
            }
            break;

        case N_DUM:
            analyser_expr(n->data.dum.condition, ts);
            ts_ouvrir_portee(ts);
            analyser_inst(n->data.dum.corps, ts, type_retour_courant);
            ts_fermer_portee(ts);
            break;

        case N_ITER: {
            analyser_expr(n->data.iter.init,  ts);
            analyser_expr(n->data.iter.pas,   ts);
            analyser_expr(n->data.iter.borne, ts);
            ts_ouvrir_portee(ts);
            /* la variable d'iteration est locale au bloc iter */
            ts_inserer(ts, n->data.iter.var, "integer", SYM_VARIABLE, 0);
            analyser_inst(n->data.iter.corps, ts, type_retour_courant);
            ts_fermer_portee(ts);
            break;
        }

        case N_FUNCTIO: {
            ts_inserer(ts, n->data.functio.nom, n->data.functio.type_retour,
                       SYM_FUNCTIO, 0);
            ts_ouvrir_portee(ts);
            /* enregistre les parametres dans la portee locale */
            ASTNode *p = n->data.functio.params;
            while (p) {
                ts_inserer(ts, p->data.param.nom, p->data.param.type_var,
                           SYM_VARIABLE, 0);
                p = p->data.param.suivant;
            }
            analyser_inst(n->data.functio.corps, ts,
                          n->data.functio.type_retour);
            ts_fermer_portee(ts);
            break;
        }

        case N_ACTIO: {
            ts_inserer(ts, n->data.actio.nom, "nullum", SYM_ACTIO, 0);
            ts_ouvrir_portee(ts);
            ASTNode *p = n->data.actio.params;
            while (p) {
                ts_inserer(ts, p->data.param.nom, p->data.param.type_var,
                           SYM_VARIABLE, 0);
                p = p->data.param.suivant;
            }
            analyser_inst(n->data.actio.corps, ts, "nullum");
            ts_fermer_portee(ts);
            break;
        }

        case N_APPEL: {
            Symbole *s = ts_chercher(ts, n->data.appel.nom);
            if (!s) {
                erreur_variable_non_declaree(n->data.appel.nom, 0);
                nb_erreurs++;
            }
            /* parcourt les arguments sans verification de types detaillee */
            ASTNode *a = n->data.appel.args;
            while (a) {
                analyser_expr(a->data.arg.expr, ts);
                a = a->data.arg.suivant;
            }
            break;
        }

        case N_REDDERE: {
            char *type_expr = analyser_expr(n->data.reddere.expr, ts);
            if (type_retour_courant && type_expr &&
                strcmp(type_expr, type_retour_courant) != 0) {
                erreur_type_retour("functio courante",
                                   type_retour_courant, type_expr, 0);
                nb_erreurs++;
            }
            break;
        }

        default:
            break;
    }
}


/* -- Point d'entree -- */

int analyser_semantique(ASTNode *racine) {
    nb_erreurs = 0;

    TableSymboles *ts = ts_creer();
    analyser_inst(racine, ts, NULL);
    ts_liberer(ts);

    if (nb_erreurs > 0) {
        fprintf(stderr, "[Semantique] %d erreur(s) detectee(s).\n", nb_erreurs);
        return -1;
    }

    return 0;
}