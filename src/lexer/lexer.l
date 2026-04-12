/* lexer.l - Analyseur lexical */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
#include "../utils/error.h"

/* Compteur de lignes */
int yyline = 1;

/* Macro de mise à jour de la position courante */
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yyline;
%}

/* Suppression des dependances et activation du suivi automatique du numero de la ligne courante */
%option noyywrap
%option nounput
%option noinput
%option yylineno


/* -- Patterns de base -- */

CHIFFRE        [0-9]
LETTRE         [a-zA-Z_]
ALPHANUM       [a-zA-Z0-9_]
IDENTI         {LETTRE}{ALPHANUM}*
NOMBRE_ENTIER  {CHIFFRE}+
NOMBRE_REEL    {CHIFFRE}+"."{CHIFFRE}+
CHAINE         \"([^\"\\]|\\.)*\"
BLANC          [ \t\r]+


%%


/* -- Commentaires -- */

"//"[^\n]*                  { /* commentaire ligne, ignore */ }
"(*"([^*]|\*+[^*)])*"*)"   {
                                for (int i = 0; yytext[i]; i++)
                                    if (yytext[i] == '\n') yyline++;
                            }




/* -- Declarations -- */

"mut"           { return MUT;     } /* variable mutable         */
"imm"           { return IMM;     } /* declaration de constante */




/* -- Types primitifs -- */

"integer"       { return T_INTEGER; }   /* type entier                          */
"reales"        { return T_REALES;  }   /* type nombre reel                     */
"catena"        { return T_CATENA;  }   /* type chaines de caracteres           */
"bina"          { return T_BINA;    }   /* type booleen                         */
"nullum"        { return T_NULLUM;  }   /* type void                            */


/* -- Litteraux booleens -- */

"verum"         { return VERUM;  }  /* valeur booleenne vraie               */
"falsum"        { return FALSUM; }  /* valeur booleenne fausse               */




/* -- Entrees / Sorties -- */

"captum"        { return CAPTUM;  } /* instruction de lecture               */
"emittum"       { return EMITTUM; } /* instruction de d'eriture             */




/* -- Sous-programmes -- */

"functio"       { return FUNCTIO; } /* definition de fonction               */
"actio"         { return ACTIO;   } /* définition de procedure              */
"reddere"       { return REDDERE; } /* définition de valeur (return)        */




/* -- Structures conditionnelles -- */

"quia"          { return QUIA;   }  /* condition (if)       */
"aliter"        { return ALITER; }  /* condition (else)     */




/* -- Structures repetitives -- */

"dum"           { return DUM;    }  /* boucle tant que (while)              */
"iter"          { return ITER;   }  /* boucle d'itération (for)             */
"in"            { return IN;     }  /* mot-clé iter : variable d'iteration  */
"de"            { return DE;     }  /* mot-clé iter : pas (step)            */
"jusqua"        { return JUSQUA; }  /* mot-cle iter : borne superieure      */




/* -- Operateur d'affectation -- */

"<--"           { return AFFECT; }  /* opérateur d'affectation LGLo         */




/* -- Operateurs arithmetiques -- */

"+"             { return PLUS;  }
"-"             { return MOINS; }
"*"             { return MULT;  }
"/"             { return DIV;   }
"%"             { return MOD;   }


/* -- Operateurs de comparaison (ordre : 2 caracteres avant 1 caractere) -- */

"<="            { return INF_EG; }
">="            { return SUP_EG; }
"=="            { return EGAL;   }
"!="            { return DIFF;   }
"<"             { return INF;    }
">"             { return SUP;    }




/* -- Operateurs logiques -- */

"&&"            { return ET;  } /* conjonction logique (AND)            */
"||"            { return OU;  } /* disjonction logique (OR)             */
"!"             { return NON; } /* négation logique (NOT)               */




/* -- Delimiteurs et ponctuations -- */

"{"             { return ACCOLADE_OUV; }    /* début de bloc                   */
"}"             { return ACCOLADE_FER; }    /* fin de bloc                     */
"("             { return PAREN_OUV;    }    /* parenthese ouvrante             */
")"             { return PAREN_FER;    }    /* parenthese fermante             */
","             { return VIRGULE;      }    /* separateur de parametres        */
"#"             { return HASH;         }    /* terminateur d'instruction       */
"'"             { return APOSTROPHE;   }    /* delimiteur de copie d'identi    */




/* -- Litteraux numeriques (NOMBRE_REEL avant NOMBRE_ENTIER, obligatoire) -- */

{NOMBRE_REEL}   {
                    yylval.reel = atof(yytext);
                    return NOMBRE_REEL;
                }

{NOMBRE_ENTIER} {
                    yylval.entier = atoi(yytext);
                    return NOMBRE_ENTIER;
                }




/* -- Litteraux de type chaine -- */

{CHAINE}        {
                    /* stocke la valeur sans les guillemets */
                    yylval.chaine = strndup(yytext + 1, yyleng - 2);
                    return CHAINE;
                }




/* -- Identifiants (apres tous les mots-cles) -- */

{IDENTI}        {
                    yylval.chaine = strdup(yytext);
                    return IDENTI;
                }




/* -- Gestion des sauts de ligne -- */

"\n"            { yyline++; }




/* -- Espaces blancs ignores -- */

{BLANC}         { }




/* -- Caractere non reconnu : erreur lexicale -- */

.               { erreur_lexicale(yytext[0], yyline); }


%%