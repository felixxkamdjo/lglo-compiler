/* ast.h - Definition des noeuds de l'arbre syntaxique abstrait) */

#ifndef AST_H
#define AST_H

#include <stdlib.h>


/* -- Types de noeuds -- */

typedef enum {
    /* structure generale */
    N_PROGRAMME,
    N_LISTE,

    /* declarations */
    N_DECL_MUT,
    N_DECL_IMM,

    /* affectation */
    N_AFFECT,
    N_AFFECT_COPIE,

    /* entrees / sorties */
    N_CAPTUM,
    N_EMITTUM,
    N_EMITTUM_LISTE,

    /* structures de controle */
    N_QUIA,
    N_DUM,
    N_ITER,

    /* sous-programmes */
    N_FUNCTIO,
    N_ACTIO,
    N_APPEL,
    N_REDDERE,

    /* parametres et arguments */
    N_PARAM,
    N_ARG,

    /* expressions */
    N_BINAIRE,
    N_UNAIRE,

    /* litteraux */
    N_ENTIER,
    N_REEL,
    N_CHAINE,
    N_BOOLEEN,
    N_IDENTI

} NodeType;


/* -- Structure principale d'un noeud -- */

typedef struct ASTNode {

    NodeType type;

    union {

        /* N_ENTIER */
        int valeur_entier;

        /* N_REEL */
        float valeur_reel;

        /* N_BOOLEEN */
        int valeur_bool;

        /* N_CHAINE, N_IDENTI */
        char *valeur_chaine;

        /* N_LISTE, N_PROGRAMME */
        struct {
            struct ASTNode *gauche;
            struct ASTNode *droite;
        } liste;

        /* N_DECL_MUT, N_DECL_IMM */
        struct {
            char           *type_var;   /* "integer", "reales", etc. */
            char           *nom;
            struct ASTNode *init;       /* NULL si non initialise    */
        } decl;

        /* N_AFFECT, N_AFFECT_COPIE */
        struct {
            char           *cible;
            struct ASTNode *valeur;     /* NULL pour AFFECT_COPIE    */
            char           *source;     /* utilise pour AFFECT_COPIE */
        } affect;

        /* N_CAPTUM */
        struct {
            char *nom;
        } captum;

        /* N_EMITTUM, N_EMITTUM_LISTE */
        struct {
            struct ASTNode *expr;
        } emittum;

        /* N_QUIA */
        struct {
            struct ASTNode *condition;
            struct ASTNode *alors;
            struct ASTNode *sinon;      /* NULL si pas de aliter     */
        } quia;

        /* N_DUM */
        struct {
            struct ASTNode *condition;
            struct ASTNode *corps;
        } dum;

        /* N_ITER */
        struct {
            char           *var;
            struct ASTNode *init;
            struct ASTNode *pas;
            struct ASTNode *borne;
            struct ASTNode *corps;
        } iter;

        /* N_FUNCTIO */
        struct {
            char           *type_retour;
            char           *nom;
            struct ASTNode *params;     /* NULL si aucun parametre   */
            struct ASTNode *corps;
        } functio;

        /* N_ACTIO */
        struct {
            char           *nom;
            struct ASTNode *params;     /* NULL si aucun parametre   */
            struct ASTNode *corps;
        } actio;

        /* N_APPEL */
        struct {
            char           *nom;
            struct ASTNode *args;       /* NULL si aucun argument    */
        } appel;

        /* N_REDDERE */
        struct {
            struct ASTNode *expr;
        } reddere;

        /* N_PARAM */
        struct {
            char           *type_var;
            char           *nom;
            struct ASTNode *suivant;    /* liste chainee de params   */
        } param;

        /* N_ARG */
        struct {
            struct ASTNode *expr;
            struct ASTNode *suivant;    /* liste chainee d'args      */
        } arg;

        /* N_BINAIRE */
        struct {
            char           *operateur;
            struct ASTNode *gauche;
            struct ASTNode *droite;
        } binaire;

        /* N_UNAIRE */
        struct {
            char           *operateur;
            struct ASTNode *operande;
        } unaire;

    } data;

} ASTNode;


/* -- Constructeurs -- */

ASTNode *ast_programme      (ASTNode *corps);
ASTNode *ast_liste          (ASTNode *gauche, ASTNode *droite);

ASTNode *ast_decl_mut       (char *type_var, char *nom, ASTNode *init);
ASTNode *ast_decl_imm       (char *type_var, char *nom, ASTNode *init);

ASTNode *ast_affect         (char *cible, ASTNode *valeur);
ASTNode *ast_affect_copie   (char *cible, char *source);

ASTNode *ast_captum         (char *nom);
ASTNode *ast_emittum        (ASTNode *expr);
ASTNode *ast_emittum_liste  (ASTNode *liste);

ASTNode *ast_quia           (ASTNode *condition, ASTNode *alors, ASTNode *sinon);
ASTNode *ast_dum            (ASTNode *condition, ASTNode *corps);
ASTNode *ast_iter           (char *var, ASTNode *init, ASTNode *pas, ASTNode *borne, ASTNode *corps);

ASTNode *ast_functio        (char *type_retour, char *nom, ASTNode *params, ASTNode *corps);
ASTNode *ast_actio          (char *nom, ASTNode *params, ASTNode *corps);
ASTNode *ast_appel          (char *nom, ASTNode *args);
ASTNode *ast_reddere        (ASTNode *expr);

ASTNode *ast_param          (char *type_var, char *nom, ASTNode *suivant);
ASTNode *ast_arg            (ASTNode *expr, ASTNode *suivant);

ASTNode *ast_binaire        (char *operateur, ASTNode *gauche, ASTNode *droite);
ASTNode *ast_unaire         (char *operateur, ASTNode *operande);

ASTNode *ast_entier         (int valeur);
ASTNode *ast_reel           (float valeur);
ASTNode *ast_chaine         (char *valeur);
ASTNode *ast_booleen        (int valeur);
ASTNode *ast_identi         (char *nom);


/* -- Utilitaires -- */

/* affiche l'arbre dans la sortie standard */
void ast_afficher           (ASTNode *noeud, int profondeur);

/* libere recursivement toute la memoire allouee */
void ast_liberer            (ASTNode *noeud);


#endif