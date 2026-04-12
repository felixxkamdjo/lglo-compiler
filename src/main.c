/* main.c - Point d'entree du compilateur */

#include <stdio.h>
#include <stdlib.h>
#include "../include/global.h"
#include "ast/ast.h"
#include "semantic/semantic.h"
#include "utils/error.h"

/* fournis par Bison et Flex */
extern FILE *yyin;
extern int   yyparse();
extern int   yyline;

/* racine de l'AST, renseignee par parser.y apres analyse complete */
extern ASTNode *racine_ast;


int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage : lglo_compiler <fichier.lglo>\n");
        return EXIT_FAILURE;
    }

    /* -- Ouverture du fichier source -- */
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "[Erreur] Impossible d'ouvrir le fichier : %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("Compilation de : %s\n", argv[1]);

    /* -- Analyse lexicale et syntaxique -- */
    int statut = yyparse();

    fclose(yyin);

    if (statut != 0) {
        fprintf(stderr, "[Echec] Analyse syntaxique echouee.\n");
        return EXIT_FAILURE;
    }

    printf("[OK] Analyse syntaxique reussie.\n");

    /* -- Affichage de l'AST (debug) -- */
    #ifdef DEBUG
        printf("\n--- Arbre Syntaxique Abstrait ---\n");
        ast_afficher(racine_ast, 0);
        printf("---------------------------------\n\n");
    #endif

    /* -- Analyse semantique -- */
    if (analyser_semantique(racine_ast) != 0) {
        fprintf(stderr, "[Echec] Analyse semantique echouee.\n");
        ast_liberer(racine_ast);
        return EXIT_FAILURE;
    }

    printf("[OK] Analyse semantique reussie.\n");

    /* -- Liberation de la memoire -- */
    ast_liberer(racine_ast);

    printf("[OK] Compilation terminee avec succes.\n");
    return EXIT_SUCCESS;
}