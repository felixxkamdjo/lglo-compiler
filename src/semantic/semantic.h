/* semantic.h - Analyse semantique et table des symboles */

#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "../ast/ast.h"


/* -- Categorie d'un symbole -- */
typedef enum {
    SYM_VARIABLE,   /* declaree avec mut  */
    SYM_CONSTANTE,  /* declaree avec imm  */
    SYM_FUNCTIO,    /* fonction           */
    SYM_ACTIO       /* procedure          */
} SymCategorie;


/* -- Entree dans la table des symboles -- */
typedef struct Symbole {
    char        *nom;
    char        *type;          /* "integer", "reales", "catena", "bina", "nullum" */
    SymCategorie categorie;
    int          portee;        /* 0 = globale, 1+ = locale (profondeur de bloc)   */
    int          ligne;         /* ligne de declaration, utile pour les erreurs     */
    struct Symbole *suivant;    /* liste chainee                                    */
} Symbole;


/* -- Table des symboles -- */
typedef struct {
    Symbole *tete;
    int      portee_courante;
} TableSymboles;


/* -- Gestion de la table des symboles -- */

/* cree et initialise une table vide */
TableSymboles  *ts_creer          (void);

/* insere un symbole, retourne -1 si deja declare dans la meme portee */
int ts_inserer(TableSymboles *ts, const char *nom,
                const char *type, SymCategorie cat, int ligne);

/* recherche un symbole, retourne NULL si introuvable */
Symbole *ts_chercher(TableSymboles *ts, const char *nom);

/* ouvre une nouvelle portee (entree dans un bloc) */
void ts_ouvrir_portee(TableSymboles *ts);

/* ferme la portee courante et supprime ses symboles */
void ts_fermer_portee(TableSymboles *ts);

/* libere toute la table */
void ts_liberer (TableSymboles *ts);


/* -- Point d'entree de l'analyse semantique -- */

/* parcourt l'AST et effectue toutes les verifications
 * retourne 0 si aucune erreur, -1 sinon */
int analyser_semantique(ASTNode *racine);


#endif