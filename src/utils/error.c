/* error.c - Implementation des fonctions de gestion des erreurs */

#include <stdio.h>
#include <stdlib.h>
#include "error.h"


/* -- Erreurs lexicales -- */

void erreur_lexicale(char c, int ligne) {
    fprintf(stderr,
        "[Erreur lexicale]   Caractere '%c' (ASCII %d) non reconnu - ligne %d\n",
        c, (int)c, ligne);
}


/* -- Erreurs syntaxiques -- */

void erreur_syntaxique(const char *msg, int ligne) {
    fprintf(stderr,
        "[Erreur syntaxique] %s - ligne %d\n",
        msg, ligne);
}


/* -- Erreurs semantiques -- */

void erreur_variable_non_declaree(const char *nom, int ligne) {
    fprintf(stderr,
        "[Erreur semantique] Variable '%s' utilisee sans declaration - ligne %d\n",
        nom, ligne);
}

void erreur_double_declaration(const char *nom, int ligne) {
    fprintf(stderr,
        "[Erreur semantique] '%s' deja declare dans cette portee - ligne %d\n",
        nom, ligne);
}

void erreur_affectation_constante(const char *nom, int ligne) {
    fprintf(stderr,
        "[Erreur semantique] '%s' est une constante (imm), modification interdite - ligne %d\n",
        nom, ligne);
}

void erreur_type_incompatible(const char *attendu, const char *recu, int ligne) {
    fprintf(stderr,
        "[Erreur semantique] Type incompatible : attendu '%s', recu '%s' - ligne %d\n",
        attendu, recu, ligne);
}

void erreur_nb_arguments(const char *nom, int attendu, int recu, int ligne) {
    fprintf(stderr,
        "[Erreur semantique] '%s' attend %d argument(s), %d fourni(s) - ligne %d\n",
        nom, attendu, recu, ligne);
}

void erreur_retour_manquant(const char *nom, int ligne) {
    fprintf(stderr,
        "[Erreur semantique] Fonction '%s' sans instruction reddere - ligne %d\n",
        nom, ligne);
}

void erreur_type_retour(const char *nom, const char *attendu,
                        const char *recu, int ligne) {
    fprintf(stderr,
        "[Erreur semantique] '%s' doit retourner '%s', retourne '%s' - ligne %d\n",
        nom, attendu, recu, ligne);
}


/* -- Erreurs fatales -- */

void erreur_fatale(const char *msg) {
    fprintf(stderr,
        "[Erreur fatale]     %s\n", msg);
    exit(EXIT_FAILURE);
}