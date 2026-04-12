/* parser.y - Analyseur syntaxique */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast/ast.h"
#include "../utils/error.h"

extern int yylex();
extern int yyline;

void yyerror(const char *msg);
%}


/* -- Types semantiques -- */

%union {
    int      entier;
    float    reel;
    char    *chaine;
    ASTNode *noeud;
}


/* -- Tokens sans valeur semantique -- */

%token MUT IMM
%token T_INTEGER T_REALES T_CATENA T_BINA T_NULLUM
%token VERUM FALSUM
%token CAPTUM EMITTUM
%token FUNCTIO ACTIO REDDERE
%token QUIA ALITER
%token DUM ITER IN DE JUSQUA
%token AFFECT
%token PLUS MOINS MULT DIV MOD
%token INF SUP INF_EG SUP_EG EGAL DIFF
%token ET OU NON
%token ACCOLADE_OUV ACCOLADE_FER
%token PAREN_OUV PAREN_FER
%token VIRGULE HASH APOSTROPHE


/* -- Tokens avec valeur semantique -- */

%token <entier> NOMBRE_ENTIER
%token <reel>   NOMBRE_REEL
%token <chaine> CHAINE
%token <chaine> IDENTI


/* -- Types des non-terminaux -- */

%type <noeud> programme liste_inst instruction bloc
%type <noeud> declaration affectation
%type <noeud> lecture ecriture
%type <noeud> condition boucle_dum boucle_iter
%type <noeud> def_functio def_actio appel
%type <noeud> expr expr_arith terme facteur
%type <noeud> expr_bool comp
%type <noeud> liste_params liste_args
%type <chaine> type


/* -- Precedences (du moins au plus prioritaire) -- */

%left OU
%left ET
%right NON
%left INF SUP INF_EG SUP_EG EGAL DIFF
%left PLUS MOINS
%left MULT DIV MOD
%right UMINUS


%%


/* -- Axiome -- */

programme
    : liste_inst                    { $$ = ast_programme($1); }
    ;


/* -- Suite d'instructions -- */

liste_inst
    : liste_inst instruction        { $$ = ast_liste($1, $2); }
    | instruction                   { $$ = $1; }
    ;


/* -- Instruction -- */

instruction
    : affectation   HASH            { $$ = $1; }
    | declaration   HASH            { $$ = $1; }
    | lecture       HASH            { $$ = $1; }
    | ecriture      HASH            { $$ = $1; }
    | condition                     { $$ = $1; }
    | boucle_dum                    { $$ = $1; }
    | boucle_iter                   { $$ = $1; }
    | def_functio                   { $$ = $1; }
    | def_actio                     { $$ = $1; }
    | appel         HASH            { $$ = $1; }
    | REDDERE expr  HASH            { $$ = ast_reddere($2); }
    ;


/* -- Bloc delimited par accolades -- */

bloc
    : ACCOLADE_OUV liste_inst ACCOLADE_FER  { $$ = $2; }
    ;


/* -- Types primitifs -- */

type
    : T_INTEGER     { $$ = "integer"; }
    | T_REALES      { $$ = "reales";  }
    | T_CATENA      { $$ = "catena";  }
    | T_BINA        { $$ = "bina";    }
    | T_NULLUM      { $$ = "nullum";  }
    ;


/* -- Declarations : mut (variable) et imm (constante) -- */

declaration
    : MUT type IDENTI
        { $$ = ast_decl_mut($2, $3, NULL); }
    | MUT type IDENTI AFFECT expr
        { $$ = ast_decl_mut($2, $3, $5); }
    | IMM type IDENTI AFFECT expr
        { $$ = ast_decl_imm($2, $3, $5); }
    ;


/* -- Affectation -- */

affectation
    : IDENTI AFFECT expr
        { $$ = ast_affect($1, $3); }
    | IDENTI AFFECT appel
        { $$ = ast_affect($1, $3); }
    | IDENTI AFFECT APOSTROPHE IDENTI APOSTROPHE
        { $$ = ast_affect_copie($1, $4); }
    ;


/* -- Lecture : captum -- */

lecture
    : CAPTUM PAREN_OUV IDENTI PAREN_FER
        { $$ = ast_captum($3); }
    ;


/* -- Ecriture : emittum -- */

ecriture
    : EMITTUM PAREN_OUV expr PAREN_FER
        { $$ = ast_emittum($3); }
    | EMITTUM PAREN_OUV liste_args PAREN_FER
        { $$ = ast_emittum_liste($3); }
    ;


/* -- Structure conditionnelle : quia / aliter -- */

condition
    : QUIA PAREN_OUV expr_bool PAREN_FER bloc
        { $$ = ast_quia($3, $5, NULL); }
    | QUIA PAREN_OUV expr_bool PAREN_FER bloc ALITER bloc
        { $$ = ast_quia($3, $5, $7); }
    | QUIA PAREN_OUV expr_bool PAREN_FER bloc ALITER condition
        { $$ = ast_quia($3, $5, $7); }
    ;


/* -- Boucle dum (while) -- */

boucle_dum
    : DUM PAREN_OUV expr_bool PAREN_FER bloc
        { $$ = ast_dum($3, $5); }
    ;


/* -- Boucle iter (for) : identi in init de pas jusqua borne -- */

boucle_iter
    : ITER PAREN_OUV IDENTI IN expr_arith DE expr_arith JUSQUA expr_arith PAREN_FER bloc
        { $$ = ast_iter($3, $5, $7, $9, $11); }
    ;


/* -- Definition de fonction : functio type nom(params) bloc -- */

def_functio
    : FUNCTIO type IDENTI PAREN_OUV liste_params PAREN_FER bloc
        { $$ = ast_functio($2, $3, $5, $7); }
    | FUNCTIO type IDENTI PAREN_OUV PAREN_FER bloc
        { $$ = ast_functio($2, $3, NULL, $6); }
    ;


/* -- Definition de procedure : actio nom(params) bloc -- */

def_actio
    : ACTIO IDENTI PAREN_OUV liste_params PAREN_FER bloc
        { $$ = ast_actio($2, $4, $6); }
    | ACTIO IDENTI PAREN_OUV PAREN_FER bloc
        { $$ = ast_actio($2, NULL, $5); }
    ;


/* -- Appel de fonction ou de procedure -- */

appel
    : IDENTI PAREN_OUV liste_args PAREN_FER
        { $$ = ast_appel($1, $3); }
    | IDENTI PAREN_OUV PAREN_FER
        { $$ = ast_appel($1, NULL); }
    ;


/* -- Parametres formels -- */

liste_params
    : type IDENTI
        { $$ = ast_param($1, $2, NULL); }
    | liste_params VIRGULE type IDENTI
        { $$ = ast_param($3, $4, $1); }
    ;


/* -- Arguments effectifs -- */

liste_args
    : expr
        { $$ = ast_arg($1, NULL); }
    | liste_args VIRGULE expr
        { $$ = ast_arg($3, $1); }
    ;


/* -- Expression generale -- */

expr
    : expr_arith                    { $$ = $1; }
    | expr_bool                     { $$ = $1; }
    | CHAINE                        { $$ = ast_chaine($1); }
    ;


/* -- Expressions arithmetiques -- */

expr_arith
    : expr_arith PLUS  terme        { $$ = ast_binaire("+", $1, $3); }
    | expr_arith MOINS terme        { $$ = ast_binaire("-", $1, $3); }
    | terme                         { $$ = $1; }
    ;

terme
    : terme MULT   facteur          { $$ = ast_binaire("*", $1, $3); }
    | terme DIV    facteur          { $$ = ast_binaire("/", $1, $3); }
    | terme MOD    facteur          { $$ = ast_binaire("%", $1, $3); }
    | facteur                       { $$ = $1; }
    ;

facteur
    : NOMBRE_ENTIER                 { $$ = ast_entier($1); }
    | NOMBRE_REEL                   { $$ = ast_reel($1); }
    | IDENTI                        { $$ = ast_identi($1); }
    | PAREN_OUV expr_arith PAREN_FER { $$ = $2; }
    | MOINS facteur %prec UMINUS    { $$ = ast_unaire("-", $2); }
    | appel                         { $$ = $1; }
    ;


/* -- Expressions booleennes -- */

expr_bool
    : expr_bool ET  comp            { $$ = ast_binaire("&&", $1, $3); }
    | expr_bool OU  comp            { $$ = ast_binaire("||", $1, $3); }
    | NON comp                      { $$ = ast_unaire("!", $2); }
    | comp                          { $$ = $1; }
    ;

comp
    : expr_arith INF    expr_arith  { $$ = ast_binaire("<",  $1, $3); }
    | expr_arith SUP    expr_arith  { $$ = ast_binaire(">",  $1, $3); }
    | expr_arith INF_EG expr_arith  { $$ = ast_binaire("<=", $1, $3); }
    | expr_arith SUP_EG expr_arith  { $$ = ast_binaire(">=", $1, $3); }
    | expr_arith EGAL   expr_arith  { $$ = ast_binaire("==", $1, $3); }
    | expr_arith DIFF   expr_arith  { $$ = ast_binaire("!=", $1, $3); }
    | VERUM                         { $$ = ast_booleen(1); }
    | FALSUM                        { $$ = ast_booleen(0); }
    | PAREN_OUV expr_bool PAREN_FER { $$ = $2; }
    ;


%%


/* -- Erreur syntaxique : affiche le message et la ligne courante -- */

void yyerror(const char *msg) {
    fprintf(stderr, "[Erreur syntaxique] %s - ligne %d\n", msg, yyline);
}
