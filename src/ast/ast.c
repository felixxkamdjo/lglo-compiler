/* ast.c - Implementation des constructeurs et utilitaires*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "../utils/error.h"


/* -- Allocation d'un noeud vide -- */

static ASTNode *nouveau_noeud(NodeType type) {
    ASTNode *n = malloc(sizeof(ASTNode));
    if (!n) {
        fprintf(stderr, "[AST] Erreur d'allocation memoire\n");
        exit(EXIT_FAILURE);
    }
    memset(n, 0, sizeof(ASTNode));
    n->type = type;
    return n;
}


/* -- Programme et liste -- */

ASTNode *ast_programme(ASTNode *corps) {
    ASTNode *n = nouveau_noeud(N_PROGRAMME);
    n->data.liste.gauche = corps;
    n->data.liste.droite = NULL;
    return n;
}

ASTNode *ast_liste(ASTNode *gauche, ASTNode *droite) {
    ASTNode *n = nouveau_noeud(N_LISTE);
    n->data.liste.gauche = gauche;
    n->data.liste.droite = droite;
    return n;
}


/* -- Declarations -- */

ASTNode *ast_decl_mut(char *type_var, char *nom, ASTNode *init) {
    ASTNode *n = nouveau_noeud(N_DECL_MUT);
    n->data.decl.type_var = strdup(type_var);
    n->data.decl.nom      = strdup(nom);
    n->data.decl.init     = init;
    return n;
}

ASTNode *ast_decl_imm(char *type_var, char *nom, ASTNode *init) {
    ASTNode *n = nouveau_noeud(N_DECL_IMM);
    n->data.decl.type_var = strdup(type_var);
    n->data.decl.nom      = strdup(nom);
    n->data.decl.init     = init;
    return n;
}


/* -- Affectation -- */

ASTNode *ast_affect(char *cible, ASTNode *valeur) {
    ASTNode *n = nouveau_noeud(N_AFFECT);
    n->data.affect.cible  = strdup(cible);
    n->data.affect.valeur = valeur;
    n->data.affect.source = NULL;
    return n;
}

ASTNode *ast_affect_copie(char *cible, char *source) {
    ASTNode *n = nouveau_noeud(N_AFFECT_COPIE);
    n->data.affect.cible  = strdup(cible);
    n->data.affect.source = strdup(source);
    n->data.affect.valeur = NULL;
    return n;
}


/* -- Entrees / Sorties -- */

ASTNode *ast_captum(char *nom) {
    ASTNode *n = nouveau_noeud(N_CAPTUM);
    n->data.captum.nom = strdup(nom);
    return n;
}

ASTNode *ast_emittum(ASTNode *expr) {
    ASTNode *n = nouveau_noeud(N_EMITTUM);
    n->data.emittum.expr = expr;
    return n;
}

ASTNode *ast_emittum_liste(ASTNode *liste) {
    ASTNode *n = nouveau_noeud(N_EMITTUM_LISTE);
    n->data.emittum.expr = liste;
    return n;
}


/* -- Structure conditionnelle -- */

ASTNode *ast_quia(ASTNode *condition, ASTNode *alors, ASTNode *sinon) {
    ASTNode *n = nouveau_noeud(N_QUIA);
    n->data.quia.condition = condition;
    n->data.quia.alors     = alors;
    n->data.quia.sinon     = sinon;
    return n;
}


/* -- Boucle dum (while) -- */

ASTNode *ast_dum(ASTNode *condition, ASTNode *corps) {
    ASTNode *n = nouveau_noeud(N_DUM);
    n->data.dum.condition = condition;
    n->data.dum.corps     = corps;
    return n;
}


/* -- Boucle iter (for) -- */

ASTNode *ast_iter(char *var, ASTNode *init, ASTNode *pas,
                  ASTNode *borne, ASTNode *corps) {
    ASTNode *n = nouveau_noeud(N_ITER);
    n->data.iter.var   = strdup(var);
    n->data.iter.init  = init;
    n->data.iter.pas   = pas;
    n->data.iter.borne = borne;
    n->data.iter.corps = corps;
    return n;
}


/* -- Sous-programmes -- */

ASTNode *ast_functio(char *type_retour, char *nom,
                     ASTNode *params, ASTNode *corps) {
    ASTNode *n = nouveau_noeud(N_FUNCTIO);
    n->data.functio.type_retour = strdup(type_retour);
    n->data.functio.nom         = strdup(nom);
    n->data.functio.params      = params;
    n->data.functio.corps       = corps;
    return n;
}

ASTNode *ast_actio(char *nom, ASTNode *params, ASTNode *corps) {
    ASTNode *n = nouveau_noeud(N_ACTIO);
    n->data.actio.nom    = strdup(nom);
    n->data.actio.params = params;
    n->data.actio.corps  = corps;
    return n;
}

ASTNode *ast_appel(char *nom, ASTNode *args) {
    ASTNode *n = nouveau_noeud(N_APPEL);
    n->data.appel.nom  = strdup(nom);
    n->data.appel.args = args;
    return n;
}

ASTNode *ast_reddere(ASTNode *expr) {
    ASTNode *n = nouveau_noeud(N_REDDERE);
    n->data.reddere.expr = expr;
    return n;
}


/* -- Parametres et arguments -- */

ASTNode *ast_param(char *type_var, char *nom, ASTNode *suivant) {
    ASTNode *n = nouveau_noeud(N_PARAM);
    n->data.param.type_var = strdup(type_var);
    n->data.param.nom      = strdup(nom);
    n->data.param.suivant  = suivant;
    return n;
}

ASTNode *ast_arg(ASTNode *expr, ASTNode *suivant) {
    ASTNode *n = nouveau_noeud(N_ARG);
    n->data.arg.expr    = expr;
    n->data.arg.suivant = suivant;
    return n;
}


/* -- Expressions -- */

ASTNode *ast_binaire(char *operateur, ASTNode *gauche, ASTNode *droite) {
    ASTNode *n = nouveau_noeud(N_BINAIRE);
    n->data.binaire.operateur = strdup(operateur);
    n->data.binaire.gauche    = gauche;
    n->data.binaire.droite    = droite;
    return n;
}

ASTNode *ast_unaire(char *operateur, ASTNode *operande) {
    ASTNode *n = nouveau_noeud(N_UNAIRE);
    n->data.unaire.operateur = strdup(operateur);
    n->data.unaire.operande  = operande;
    return n;
}


/* -- Litteraux -- */

ASTNode *ast_entier(int valeur) {
    ASTNode *n = nouveau_noeud(N_ENTIER);
    n->data.valeur_entier = valeur;
    return n;
}

ASTNode *ast_reel(float valeur) {
    ASTNode *n = nouveau_noeud(N_REEL);
    n->data.valeur_reel = valeur;
    return n;
}

ASTNode *ast_chaine(char *valeur) {
    ASTNode *n = nouveau_noeud(N_CHAINE);
    n->data.valeur_chaine = strdup(valeur);
    return n;
}

ASTNode *ast_booleen(int valeur) {
    ASTNode *n = nouveau_noeud(N_BOOLEEN);
    n->data.valeur_bool = valeur;
    return n;
}

ASTNode *ast_identi(char *nom) {
    ASTNode *n = nouveau_noeud(N_IDENTI);
    n->data.valeur_chaine = strdup(nom);
    return n;
}


/* -- Affichage de l'arbre (debug) -- */

static void indenter(int profondeur) {
    for (int i = 0; i < profondeur; i++) printf("  ");
}

void ast_afficher(ASTNode *n, int p) {
    if (!n) return;

    indenter(p);

    switch (n->type) {

        case N_PROGRAMME:
            printf("[Programme]\n");
            ast_afficher(n->data.liste.gauche, p + 1);
            break;

        case N_LISTE:
            ast_afficher(n->data.liste.gauche, p);
            ast_afficher(n->data.liste.droite, p);
            break;

        case N_DECL_MUT:
            printf("[Decl mut] %s %s\n",
                n->data.decl.type_var, n->data.decl.nom);
            if (n->data.decl.init) {
                indenter(p + 1);
                printf("init =>\n");
                ast_afficher(n->data.decl.init, p + 2);
            }
            break;

        case N_DECL_IMM:
            printf("[Decl imm] %s %s\n",
                n->data.decl.type_var, n->data.decl.nom);
            indenter(p + 1);
            printf("init =>\n");
            ast_afficher(n->data.decl.init, p + 2);
            break;

        case N_AFFECT:
            printf("[Affect] %s <--\n", n->data.affect.cible);
            ast_afficher(n->data.affect.valeur, p + 1);
            break;

        case N_AFFECT_COPIE:
            printf("[Affect copie] %s <-- '%s'\n",
                n->data.affect.cible, n->data.affect.source);
            break;

        case N_CAPTUM:
            printf("[Captum] %s\n", n->data.captum.nom);
            break;

        case N_EMITTUM:
            printf("[Emittum]\n");
            ast_afficher(n->data.emittum.expr, p + 1);
            break;

        case N_EMITTUM_LISTE:
            printf("[Emittum liste]\n");
            ast_afficher(n->data.emittum.expr, p + 1);
            break;

        case N_QUIA:
            printf("[Quia]\n");
            indenter(p + 1); printf("condition =>\n");
            ast_afficher(n->data.quia.condition, p + 2);
            indenter(p + 1); printf("alors =>\n");
            ast_afficher(n->data.quia.alors, p + 2);
            if (n->data.quia.sinon) {
                indenter(p + 1); printf("sinon =>\n");
                ast_afficher(n->data.quia.sinon, p + 2);
            }
            break;

        case N_DUM:
            printf("[Dum]\n");
            indenter(p + 1); printf("condition =>\n");
            ast_afficher(n->data.dum.condition, p + 2);
            indenter(p + 1); printf("corps =>\n");
            ast_afficher(n->data.dum.corps, p + 2);
            break;

        case N_ITER:
            printf("[Iter] %s\n", n->data.iter.var);
            indenter(p + 1); printf("init =>\n");
            ast_afficher(n->data.iter.init, p + 2);
            indenter(p + 1); printf("pas =>\n");
            ast_afficher(n->data.iter.pas, p + 2);
            indenter(p + 1); printf("borne =>\n");
            ast_afficher(n->data.iter.borne, p + 2);
            indenter(p + 1); printf("corps =>\n");
            ast_afficher(n->data.iter.corps, p + 2);
            break;

        case N_FUNCTIO:
            printf("[Functio] %s -> %s\n",
                n->data.functio.nom, n->data.functio.type_retour);
            if (n->data.functio.params) {
                indenter(p + 1); printf("params =>\n");
                ast_afficher(n->data.functio.params, p + 2);
            }
            indenter(p + 1); printf("corps =>\n");
            ast_afficher(n->data.functio.corps, p + 2);
            break;

        case N_ACTIO:
            printf("[Actio] %s\n", n->data.actio.nom);
            if (n->data.actio.params) {
                indenter(p + 1); printf("params =>\n");
                ast_afficher(n->data.actio.params, p + 2);
            }
            indenter(p + 1); printf("corps =>\n");
            ast_afficher(n->data.actio.corps, p + 2);
            break;

        case N_APPEL:
            printf("[Appel] %s\n", n->data.appel.nom);
            if (n->data.appel.args) {
                indenter(p + 1); printf("args =>\n");
                ast_afficher(n->data.appel.args, p + 2);
            }
            break;

        case N_REDDERE:
            printf("[Reddere]\n");
            ast_afficher(n->data.reddere.expr, p + 1);
            break;

        case N_PARAM:
            printf("[Param] %s %s\n",
                n->data.param.type_var, n->data.param.nom);
            ast_afficher(n->data.param.suivant, p);
            break;

        case N_ARG:
            printf("[Arg]\n");
            ast_afficher(n->data.arg.expr, p + 1);
            ast_afficher(n->data.arg.suivant, p);
            break;

        case N_BINAIRE:
            printf("[Binaire] %s\n", n->data.binaire.operateur);
            ast_afficher(n->data.binaire.gauche, p + 1);
            ast_afficher(n->data.binaire.droite, p + 1);
            break;

        case N_UNAIRE:
            printf("[Unaire] %s\n", n->data.unaire.operateur);
            ast_afficher(n->data.unaire.operande, p + 1);
            break;

        case N_ENTIER:
            printf("[Entier] %d\n", n->data.valeur_entier);
            break;

        case N_REEL:
            printf("[Reel] %f\n", n->data.valeur_reel);
            break;

        case N_CHAINE:
            printf("[Chaine] \"%s\"\n", n->data.valeur_chaine);
            break;

        case N_BOOLEEN:
            printf("[Booleen] %s\n", n->data.valeur_bool ? "verum" : "falsum");
            break;

        case N_IDENTI:
            printf("[Identi] %s\n", n->data.valeur_chaine);
            break;

        default:
            printf("[Noeud inconnu]\n");
            break;
    }
}


/* -- Liberation recursive de la memoire -- */

void ast_liberer(ASTNode *n) {
    if (!n) return;

    switch (n->type) {

        case N_PROGRAMME:
        case N_LISTE:
            ast_liberer(n->data.liste.gauche);
            ast_liberer(n->data.liste.droite);
            break;

        case N_DECL_MUT:
        case N_DECL_IMM:
            free(n->data.decl.type_var);
            free(n->data.decl.nom);
            ast_liberer(n->data.decl.init);
            break;

        case N_AFFECT:
            free(n->data.affect.cible);
            ast_liberer(n->data.affect.valeur);
            break;

        case N_AFFECT_COPIE:
            free(n->data.affect.cible);
            free(n->data.affect.source);
            break;

        case N_CAPTUM:
            free(n->data.captum.nom);
            break;

        case N_EMITTUM:
        case N_EMITTUM_LISTE:
            ast_liberer(n->data.emittum.expr);
            break;

        case N_QUIA:
            ast_liberer(n->data.quia.condition);
            ast_liberer(n->data.quia.alors);
            ast_liberer(n->data.quia.sinon);
            break;

        case N_DUM:
            ast_liberer(n->data.dum.condition);
            ast_liberer(n->data.dum.corps);
            break;

        case N_ITER:
            free(n->data.iter.var);
            ast_liberer(n->data.iter.init);
            ast_liberer(n->data.iter.pas);
            ast_liberer(n->data.iter.borne);
            ast_liberer(n->data.iter.corps);
            break;

        case N_FUNCTIO:
            free(n->data.functio.type_retour);
            free(n->data.functio.nom);
            ast_liberer(n->data.functio.params);
            ast_liberer(n->data.functio.corps);
            break;

        case N_ACTIO:
            free(n->data.actio.nom);
            ast_liberer(n->data.actio.params);
            ast_liberer(n->data.actio.corps);
            break;

        case N_APPEL:
            free(n->data.appel.nom);
            ast_liberer(n->data.appel.args);
            break;

        case N_REDDERE:
            ast_liberer(n->data.reddere.expr);
            break;

        case N_PARAM:
            free(n->data.param.type_var);
            free(n->data.param.nom);
            ast_liberer(n->data.param.suivant);
            break;

        case N_ARG:
            ast_liberer(n->data.arg.expr);
            ast_liberer(n->data.arg.suivant);
            break;

        case N_BINAIRE:
            free(n->data.binaire.operateur);
            ast_liberer(n->data.binaire.gauche);
            ast_liberer(n->data.binaire.droite);
            break;

        case N_UNAIRE:
            free(n->data.unaire.operateur);
            ast_liberer(n->data.unaire.operande);
            break;

        case N_CHAINE:
        case N_IDENTI:
            free(n->data.valeur_chaine);
            break;

        default:
            break;
    }

    free(n);
}