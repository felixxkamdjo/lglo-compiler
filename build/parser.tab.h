/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_BUILD_PARSER_TAB_H_INCLUDED
# define YY_YY_BUILD_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MUT = 258,
     IMM = 259,
     T_INTEGER = 260,
     T_REALES = 261,
     T_CATENA = 262,
     T_BINA = 263,
     T_NULLUM = 264,
     VERUM = 265,
     FALSUM = 266,
     CAPTUM = 267,
     EMITTUM = 268,
     FUNCTIO = 269,
     ACTIO = 270,
     REDDERE = 271,
     QUIA = 272,
     ALITER = 273,
     DUM = 274,
     ITER = 275,
     IN = 276,
     DE = 277,
     JUSQUA = 278,
     AFFECT = 279,
     PLUS = 280,
     MOINS = 281,
     MULT = 282,
     DIV = 283,
     MOD = 284,
     INF = 285,
     SUP = 286,
     INF_EG = 287,
     SUP_EG = 288,
     EGAL = 289,
     DIFF = 290,
     ET = 291,
     OU = 292,
     NON = 293,
     ACCOLADE_OUV = 294,
     ACCOLADE_FER = 295,
     PAREN_OUV = 296,
     PAREN_FER = 297,
     VIRGULE = 298,
     HASH = 299,
     APOSTROPHE = 300,
     NOMBRE_ENTIER = 301,
     NOMBRE_REEL = 302,
     CHAINE = 303,
     IDENTI = 304,
     UMINUS = 305
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 22 "src/parser/parser.y"

    int      entier;
    float    reel;
    char    *chaine;
    ASTNode *noeud;


/* Line 2058 of yacc.c  */
#line 115 "build/parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_BUILD_PARSER_TAB_H_INCLUDED  */
