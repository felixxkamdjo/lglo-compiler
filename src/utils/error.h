/* error.h - Declarations des fonctions de gestion des erreurs */

#ifndef ERROR_H
#define ERROR_H


/* -- Erreurs lexicales -- */

/* caractere non reconnu par le lexer */
void erreur_lexicale(char c, int ligne);


/* -- Erreurs syntaxiques -- */

/* appele par yyerror() dans parser.y */
void erreur_syntaxique(const char *msg, int ligne);


/* -- Erreurs semantiques -- */

/* variable utilisee sans avoir ete declaree */
void erreur_variable_non_declaree(const char *nom, int ligne);

/* variable declaree plus d'une fois dans la meme portee */
void erreur_double_declaration(const char *nom, int ligne);

/* tentative de modification d'une constante imm */
void erreur_affectation_constante(const char *nom, int ligne);

/* incompatibilite de types entre deux operandes ou entre param et arg */
void erreur_type_incompatible(const char *attendu, const char *recu, int ligne);

/* fonction appelee avec un mauvais nombre d'arguments */
void erreur_nb_arguments(const char *nom, int attendu, int recu, int ligne);

/* reddere absent ou mal place dans une functio */
void erreur_retour_manquant(const char *nom, int ligne);

/* type de retour incompatible avec la signature de la functio */
void erreur_type_retour(const char *nom, const char *attendu,
                        const char *recu, int ligne);


/* -- Erreurs fatales -- */

/* erreur interne non recuperable (allocation, etat invalide, etc.) */
void erreur_fatale(const char *msg);


#endif