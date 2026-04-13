/* lexer.l - Analyseur lexical */

%{
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast/ast.h"
#include "parser.tab.h"
#include "utils/error.h"
%}

%option noyywrap
%option nounput
%option noinput
%option yylineno

%x COMMENTAIRE_BLOC


CHIFFRE        [0-9]
LETTRE         [a-zA-Z_]
ALPHANUM       [a-zA-Z0-9_]
IDENTI         {LETTRE}{ALPHANUM}*
NOMBRE_ENTIER  {CHIFFRE}+
NOMBRE_REEL    {CHIFFRE}+"."{CHIFFRE}+
CHAINE         \"([^\"\\]|\\.)*\"
BLANC          [ \t\r]+

%%


"(*"                        { BEGIN(COMMENTAIRE_BLOC); }
<COMMENTAIRE_BLOC>"*)"      { BEGIN(INITIAL); }
<COMMENTAIRE_BLOC>\n        { /* yylineno auto */ }
<COMMENTAIRE_BLOC>.         { /* ignore */ }


"mut"       { return MUT; }
"imm"       { return IMM; }

"integer"   { return T_INTEGER; }
"reales"    { return T_REALES; }
"catena"    { return T_CATENA; }
"bina"      { return T_BINA; }
"nullum"    { return T_NULLUM; }

"verum"     { return VERUM; }
"falsum"    { return FALSUM; }

"captum"    { return CAPTUM; }
"emittum"   { return EMITTUM; }

"functio"   { return FUNCTIO; }
"actio"     { return ACTIO; }
"reddere"   { return REDDERE; }

"quia"      { return QUIA; }
"aliter"    { return ALITER; }

"dum"       { return DUM; }
"iter"      { return ITER; }
"in"        { return IN; }
"de"        { return DE; }
"jusqua"    { return JUSQUA; }


"<--"       { return AFFECT; }

"+"         { return PLUS; }
"-"         { return MOINS; }
"*"         { return MULT; }
"/"         { return DIV; }
"%"         { return MOD; }

"<="        { return INF_EG; }
">="        { return SUP_EG; }
"=="        { return EGAL; }
"!="        { return DIFF; }
"<"         { return INF; }
">"         { return SUP; }

"&&"        { return ET; }
"||"        { return OU; }
"!"         { return NON; }


"{"         { return ACCOLADE_OUV; }
"}"         { return ACCOLADE_FER; }
"("         { return PAREN_OUV; }
")"         { return PAREN_FER; }
","         { return VIRGULE; }
"#"         { return HASH; }
"'"         { return APOSTROPHE; }


{NOMBRE_REEL} {
    yylval.reel = atof(yytext);
    return NOMBRE_REEL;
}

{NOMBRE_ENTIER} {
    yylval.entier = atoi(yytext);
    return NOMBRE_ENTIER;
}

{CHAINE} {
    yylval.chaine = malloc(yyleng - 1);
    strncpy(yylval.chaine, yytext + 1, yyleng - 2);
    yylval.chaine[yyleng - 2] = '\0';
    return CHAINE;
}

{IDENTI} {
    yylval.chaine = strdup(yytext);
    return IDENTI;
}


\n      { /* yylineno auto */ }


{BLANC} { /* ignore */ }


. {
    erreur_lexicale(yytext[0], yylineno);
}

%%