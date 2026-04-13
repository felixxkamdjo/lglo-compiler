/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 3 "src/parser/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast/ast.h"
#include "utils/error.h"

extern int yylex();
extern int yylineno;

void yyerror(const char *msg);

/* racine de l'AST, recuperee par main.c */
ASTNode *racine_ast = NULL;

/* Line 371 of yacc.c  */
#line 84 "build/parser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
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
/* Line 387 of yacc.c  */
#line 22 "src/parser/parser.y"

    int      entier;
    float    reel;
    char    *chaine;
    ASTNode *noeud;


/* Line 387 of yacc.c  */
#line 185 "build/parser.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 213 "build/parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   240

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNRULES -- Number of states.  */
#define YYNSTATES  162

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    16,    19,    22,
      24,    26,    28,    30,    32,    35,    39,    43,    45,    47,
      49,    51,    53,    57,    63,    69,    73,    77,    83,    88,
      93,    98,   104,   112,   120,   126,   138,   146,   153,   160,
     166,   171,   175,   178,   183,   185,   189,   191,   193,   195,
     199,   203,   205,   209,   213,   217,   219,   221,   223,   225,
     227,   229,   233,   236,   238,   242,   246,   249,   251,   255,
     259,   263,   267,   271,   275
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    -1,    53,    54,    -1,    54,    -1,
      58,    44,    -1,    57,    44,    -1,    59,    44,    -1,    60,
      44,    -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,
      65,    -1,    66,    44,    -1,    16,    69,    44,    -1,    39,
      53,    40,    -1,     5,    -1,     6,    -1,     7,    -1,     8,
      -1,     9,    -1,     3,    56,    49,    -1,     3,    56,    49,
      24,    69,    -1,     4,    56,    49,    24,    69,    -1,    49,
      24,    69,    -1,    49,    24,    66,    -1,    49,    24,    45,
      49,    45,    -1,    12,    41,    49,    42,    -1,    13,    41,
      69,    42,    -1,    13,    41,    68,    42,    -1,    17,    41,
      73,    42,    55,    -1,    17,    41,    73,    42,    55,    18,
      55,    -1,    17,    41,    73,    42,    55,    18,    61,    -1,
      19,    41,    73,    42,    55,    -1,    20,    41,    49,    21,
      70,    22,    70,    23,    70,    42,    55,    -1,    14,    56,
      49,    41,    67,    42,    55,    -1,    14,    56,    49,    41,
      42,    55,    -1,    15,    49,    41,    67,    42,    55,    -1,
      15,    49,    41,    42,    55,    -1,    49,    41,    68,    42,
      -1,    49,    41,    42,    -1,    56,    49,    -1,    67,    43,
      56,    49,    -1,    69,    -1,    68,    43,    69,    -1,    70,
      -1,    73,    -1,    48,    -1,    70,    25,    71,    -1,    70,
      26,    71,    -1,    71,    -1,    71,    27,    72,    -1,    71,
      28,    72,    -1,    71,    29,    72,    -1,    72,    -1,    46,
      -1,    47,    -1,    49,    -1,    10,    -1,    11,    -1,    41,
      70,    42,    -1,    26,    72,    -1,    66,    -1,    73,    36,
      74,    -1,    73,    37,    74,    -1,    38,    74,    -1,    74,
      -1,    70,    30,    70,    -1,    70,    31,    70,    -1,    70,
      32,    70,    -1,    70,    33,    70,    -1,    70,    34,    70,
      -1,    70,    35,    70,    -1,    41,    73,    42,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    86,    86,    97,    98,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   122,   129,   130,   131,
     132,   133,   140,   142,   144,   152,   154,   156,   164,   172,
     174,   182,   184,   186,   194,   202,   210,   212,   220,   222,
     230,   232,   240,   242,   250,   252,   260,   261,   262,   269,
     270,   271,   275,   276,   277,   278,   282,   283,   284,   285,
     286,   287,   288,   289,   296,   297,   298,   299,   303,   304,
     305,   306,   307,   308,   309
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MUT", "IMM", "T_INTEGER", "T_REALES",
  "T_CATENA", "T_BINA", "T_NULLUM", "VERUM", "FALSUM", "CAPTUM", "EMITTUM",
  "FUNCTIO", "ACTIO", "REDDERE", "QUIA", "ALITER", "DUM", "ITER", "IN",
  "DE", "JUSQUA", "AFFECT", "PLUS", "MOINS", "MULT", "DIV", "MOD", "INF",
  "SUP", "INF_EG", "SUP_EG", "EGAL", "DIFF", "ET", "OU", "NON",
  "ACCOLADE_OUV", "ACCOLADE_FER", "PAREN_OUV", "PAREN_FER", "VIRGULE",
  "HASH", "APOSTROPHE", "NOMBRE_ENTIER", "NOMBRE_REEL", "CHAINE", "IDENTI",
  "UMINUS", "$accept", "programme", "liste_inst", "instruction", "bloc",
  "type", "declaration", "affectation", "lecture", "ecriture", "condition",
  "boucle_dum", "boucle_iter", "def_functio", "def_actio", "appel",
  "liste_params", "liste_args", "expr", "expr_arith", "terme", "facteur",
  "expr_bool", "comp", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    55,    56,    56,    56,
      56,    56,    57,    57,    57,    58,    58,    58,    59,    60,
      60,    61,    61,    61,    62,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    69,    69,    70,
      70,    70,    71,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    73,    73,    73,    74,    74,
      74,    74,    74,    74,    74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     2,     3,     3,     1,     1,     1,
       1,     1,     3,     5,     5,     3,     3,     5,     4,     4,
       4,     5,     7,     7,     5,    11,     7,     6,     6,     5,
       4,     3,     2,     4,     1,     3,     1,     1,     1,     3,
       3,     1,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     3,     2,     1,     3,     3,     2,     1,     3,     3,
       3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     4,     0,     0,     0,     0,     9,
      10,    11,    12,    13,     0,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,    59,    60,     0,     0,
       0,    56,    57,    48,    58,    63,     0,    46,    51,    55,
      47,    67,     0,     0,     0,     0,     0,     1,     3,     6,
       5,     7,     8,    14,    22,     0,     0,     0,    44,     0,
       0,     0,    62,     0,    66,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    25,    41,     0,    44,
       0,     0,    28,    30,     0,    29,     0,     0,     0,     0,
       0,    61,    74,    49,    50,    68,    69,    70,    71,    72,
      73,    52,    53,    54,    64,    65,     0,     0,     0,     0,
      40,    23,    24,    45,     0,     0,     0,    39,    42,     0,
       0,    31,    34,     0,    27,    37,     0,     0,    38,     0,
       0,     0,    36,    16,    43,    32,    33,     0,     0,     0,
       0,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,   137,   108,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    45,   109,    67,    46,    47,
      48,    49,    50,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -38
static const yytype_int16 yypact[] =
{
      64,   209,   209,   -22,   -18,   209,   -37,   105,     2,     6,
      13,    58,    15,    64,   -38,    12,    22,    25,    41,   -38,
     -38,   -38,   -38,   -38,    44,   -38,   -38,   -38,   -38,   -38,
      51,    81,    89,   105,    93,    54,   -38,   -38,   122,   129,
     118,   -38,   -38,   -38,   104,   -38,    90,   169,    78,   -38,
     147,   -38,   118,   118,   108,    63,    76,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   138,   150,   137,   167,   151,   136,
      23,   122,   -38,   169,   -38,   156,   -26,   -38,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   129,
     129,    61,   171,   176,   180,   161,   -38,   -38,   177,   -38,
     105,   105,   -38,   -38,   105,   -38,    85,   189,   182,   179,
      95,   -38,   -38,    78,    78,   186,   186,   186,   186,   186,
     186,   -38,   -38,   -38,   -38,   -38,   189,   189,   122,   185,
     -38,   -38,   -38,   -38,   189,   181,    64,   -38,   -38,   189,
     209,   207,   -38,    20,   -38,   -38,   189,    21,   -38,   183,
       5,   122,   -38,   -38,   -38,   -38,   -38,   135,   122,   124,
     189,   -38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -38,   -38,    97,   -12,    46,     1,   -38,   -38,   -38,   -38,
      84,   -38,   -38,   -38,   -38,     0,   130,   184,   -29,   -32,
     148,   -24,   -35,   -30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -27
static const yytype_int16 yytable[] =
{
      24,    58,    30,    31,    68,    76,    34,    73,    75,    74,
      89,    90,    35,    24,    72,    57,   112,    91,    92,    32,
      73,    73,     8,    33,     1,     2,    96,    99,    25,    26,
      27,    28,    29,     3,     4,     5,     6,     7,     8,   110,
       9,    10,   151,    52,   136,    78,    79,    53,   115,   116,
     117,   118,   119,   120,    54,    95,    59,    73,    73,   124,
     125,   153,   121,   122,   123,   107,    60,     1,     2,    61,
      11,   131,   132,    36,    37,   133,     3,     4,     5,     6,
       7,     8,    55,     9,    10,    62,    36,    37,    63,    38,
      25,    26,    27,    28,    29,    70,   143,    89,    90,    56,
      64,    39,    38,   126,    40,    86,    87,    88,    94,    41,
      42,    43,    44,    11,    39,    36,    37,    40,    97,   157,
      78,    79,    41,    42,    43,    44,   159,   134,    36,    37,
      65,    38,    36,    37,    77,    58,    24,   111,    66,    36,
      37,   149,    69,    39,    38,    56,    40,    24,    38,    78,
      79,    41,    42,    43,    44,    38,    39,    93,   158,    40,
      78,    79,   100,    71,    41,    42,   160,    44,    41,    42,
      40,    44,   141,   142,   101,    41,    42,   106,    44,   102,
     145,    78,    79,    89,    90,   148,    80,    81,    82,    83,
      84,    85,   152,   105,    78,    79,   155,   128,   111,    80,
      81,    82,    83,    84,    85,   -26,   161,    89,    90,   103,
     104,    78,    79,   127,    25,    26,    27,    28,    29,   130,
     104,   139,   140,   146,   140,   150,   113,   114,   136,   129,
     144,   138,   154,   147,   156,     0,   135,     0,     0,     0,
      98
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-38)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    13,     1,     2,    33,    40,     5,    39,    40,    39,
      36,    37,    49,    13,    38,     0,    42,    52,    53,    41,
      52,    53,    17,    41,     3,     4,    55,    56,     5,     6,
       7,     8,     9,    12,    13,    14,    15,    16,    17,    71,
      19,    20,    22,    41,    39,    25,    26,    41,    80,    81,
      82,    83,    84,    85,    41,    55,    44,    89,    90,    89,
      90,    40,    86,    87,    88,    42,    44,     3,     4,    44,
      49,   100,   101,    10,    11,   104,    12,    13,    14,    15,
      16,    17,    24,    19,    20,    44,    10,    11,    44,    26,
       5,     6,     7,     8,     9,    41,   128,    36,    37,    41,
      49,    38,    26,    42,    41,    27,    28,    29,    45,    46,
      47,    48,    49,    49,    38,    10,    11,    41,    42,   151,
      25,    26,    46,    47,    48,    49,   158,    42,    10,    11,
      49,    26,    10,    11,    44,   147,   136,    42,    49,    10,
      11,   140,    49,    38,    26,    41,    41,   147,    26,    25,
      26,    46,    47,    48,    49,    26,    38,    49,    23,    41,
      25,    26,    24,    41,    46,    47,    42,    49,    46,    47,
      41,    49,   126,   127,    24,    46,    47,    41,    49,    42,
     134,    25,    26,    36,    37,   139,    30,    31,    32,    33,
      34,    35,   146,    42,    25,    26,   150,    21,    42,    30,
      31,    32,    33,    34,    35,    44,   160,    36,    37,    42,
      43,    25,    26,    42,     5,     6,     7,     8,     9,    42,
      43,    42,    43,    42,    43,    18,    78,    79,    39,    49,
      45,    49,    49,   136,   150,    -1,   106,    -1,    -1,    -1,
      56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    12,    13,    14,    15,    16,    17,    19,
      20,    49,    52,    53,    54,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     5,     6,     7,     8,     9,
      56,    56,    41,    41,    56,    49,    10,    11,    26,    38,
      41,    46,    47,    48,    49,    66,    69,    70,    71,    72,
      73,    74,    41,    41,    41,    24,    41,     0,    54,    44,
      44,    44,    44,    44,    49,    49,    49,    68,    69,    49,
      41,    41,    72,    70,    74,    70,    73,    44,    25,    26,
      30,    31,    32,    33,    34,    35,    27,    28,    29,    36,
      37,    73,    73,    49,    45,    66,    69,    42,    68,    69,
      24,    24,    42,    42,    43,    42,    41,    42,    56,    67,
      70,    42,    42,    71,    71,    70,    70,    70,    70,    70,
      70,    72,    72,    72,    74,    74,    42,    42,    21,    49,
      42,    69,    69,    69,    42,    67,    39,    55,    49,    42,
      43,    55,    55,    70,    45,    55,    42,    53,    55,    56,
      18,    22,    55,    40,    49,    55,    61,    70,    23,    70,
      42,    55
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 87 "src/parser/parser.y"
    {
            (yyval.noeud) = ast_programme((yyvsp[(1) - (1)].noeud));
            racine_ast = (yyval.noeud);
        }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 97 "src/parser/parser.y"
    { (yyval.noeud) = ast_liste((yyvsp[(1) - (2)].noeud), (yyvsp[(2) - (2)].noeud)); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 98 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 105 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (2)].noeud); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 106 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (2)].noeud); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 107 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (2)].noeud); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 108 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (2)].noeud); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 109 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 110 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 111 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 112 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 113 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 114 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (2)].noeud); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 115 "src/parser/parser.y"
    { (yyval.noeud) = ast_reddere((yyvsp[(2) - (3)].noeud)); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 122 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(2) - (3)].noeud); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 129 "src/parser/parser.y"
    { (yyval.chaine) = "integer"; }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 130 "src/parser/parser.y"
    { (yyval.chaine) = "reales";  }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 131 "src/parser/parser.y"
    { (yyval.chaine) = "catena";  }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 132 "src/parser/parser.y"
    { (yyval.chaine) = "bina";    }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 133 "src/parser/parser.y"
    { (yyval.chaine) = "nullum";  }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 141 "src/parser/parser.y"
    { (yyval.noeud) = ast_decl_mut((yyvsp[(2) - (3)].chaine), (yyvsp[(3) - (3)].chaine), NULL); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 143 "src/parser/parser.y"
    { (yyval.noeud) = ast_decl_mut((yyvsp[(2) - (5)].chaine), (yyvsp[(3) - (5)].chaine), (yyvsp[(5) - (5)].noeud)); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 145 "src/parser/parser.y"
    { (yyval.noeud) = ast_decl_imm((yyvsp[(2) - (5)].chaine), (yyvsp[(3) - (5)].chaine), (yyvsp[(5) - (5)].noeud)); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 153 "src/parser/parser.y"
    { (yyval.noeud) = ast_affect((yyvsp[(1) - (3)].chaine), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 155 "src/parser/parser.y"
    { (yyval.noeud) = ast_affect((yyvsp[(1) - (3)].chaine), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 157 "src/parser/parser.y"
    { (yyval.noeud) = ast_affect_copie((yyvsp[(1) - (5)].chaine), (yyvsp[(4) - (5)].chaine)); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 165 "src/parser/parser.y"
    { (yyval.noeud) = ast_captum((yyvsp[(3) - (4)].chaine)); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 173 "src/parser/parser.y"
    { (yyval.noeud) = ast_emittum((yyvsp[(3) - (4)].noeud)); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 175 "src/parser/parser.y"
    { (yyval.noeud) = ast_emittum_liste((yyvsp[(3) - (4)].noeud)); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 183 "src/parser/parser.y"
    { (yyval.noeud) = ast_quia((yyvsp[(3) - (5)].noeud), (yyvsp[(5) - (5)].noeud), NULL); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 185 "src/parser/parser.y"
    { (yyval.noeud) = ast_quia((yyvsp[(3) - (7)].noeud), (yyvsp[(5) - (7)].noeud), (yyvsp[(7) - (7)].noeud)); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 187 "src/parser/parser.y"
    { (yyval.noeud) = ast_quia((yyvsp[(3) - (7)].noeud), (yyvsp[(5) - (7)].noeud), (yyvsp[(7) - (7)].noeud)); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 195 "src/parser/parser.y"
    { (yyval.noeud) = ast_dum((yyvsp[(3) - (5)].noeud), (yyvsp[(5) - (5)].noeud)); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 203 "src/parser/parser.y"
    { (yyval.noeud) = ast_iter((yyvsp[(3) - (11)].chaine), (yyvsp[(5) - (11)].noeud), (yyvsp[(7) - (11)].noeud), (yyvsp[(9) - (11)].noeud), (yyvsp[(11) - (11)].noeud)); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 211 "src/parser/parser.y"
    { (yyval.noeud) = ast_functio((yyvsp[(2) - (7)].chaine), (yyvsp[(3) - (7)].chaine), (yyvsp[(5) - (7)].noeud), (yyvsp[(7) - (7)].noeud)); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 213 "src/parser/parser.y"
    { (yyval.noeud) = ast_functio((yyvsp[(2) - (6)].chaine), (yyvsp[(3) - (6)].chaine), NULL, (yyvsp[(6) - (6)].noeud)); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 221 "src/parser/parser.y"
    { (yyval.noeud) = ast_actio((yyvsp[(2) - (6)].chaine), (yyvsp[(4) - (6)].noeud), (yyvsp[(6) - (6)].noeud)); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 223 "src/parser/parser.y"
    { (yyval.noeud) = ast_actio((yyvsp[(2) - (5)].chaine), NULL, (yyvsp[(5) - (5)].noeud)); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 231 "src/parser/parser.y"
    { (yyval.noeud) = ast_appel((yyvsp[(1) - (4)].chaine), (yyvsp[(3) - (4)].noeud)); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 233 "src/parser/parser.y"
    { (yyval.noeud) = ast_appel((yyvsp[(1) - (3)].chaine), NULL); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 241 "src/parser/parser.y"
    { (yyval.noeud) = ast_param((yyvsp[(1) - (2)].chaine), (yyvsp[(2) - (2)].chaine), NULL); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 243 "src/parser/parser.y"
    { (yyval.noeud) = ast_param((yyvsp[(3) - (4)].chaine), (yyvsp[(4) - (4)].chaine), (yyvsp[(1) - (4)].noeud)); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 251 "src/parser/parser.y"
    { (yyval.noeud) = ast_arg((yyvsp[(1) - (1)].noeud), NULL); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 253 "src/parser/parser.y"
    { (yyval.noeud) = ast_arg((yyvsp[(3) - (3)].noeud), (yyvsp[(1) - (3)].noeud)); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 260 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 261 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 262 "src/parser/parser.y"
    { (yyval.noeud) = ast_chaine((yyvsp[(1) - (1)].chaine)); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 269 "src/parser/parser.y"
    { (yyval.noeud) = ast_binaire("+", (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 270 "src/parser/parser.y"
    { (yyval.noeud) = ast_binaire("-", (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 271 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 275 "src/parser/parser.y"
    { (yyval.noeud) = ast_binaire("*", (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 276 "src/parser/parser.y"
    { (yyval.noeud) = ast_binaire("/", (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 277 "src/parser/parser.y"
    { (yyval.noeud) = ast_binaire("%", (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 278 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 282 "src/parser/parser.y"
    { (yyval.noeud) = ast_entier((yyvsp[(1) - (1)].entier)); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 283 "src/parser/parser.y"
    { (yyval.noeud) = ast_reel((yyvsp[(1) - (1)].reel)); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 284 "src/parser/parser.y"
    { (yyval.noeud) = ast_identi((yyvsp[(1) - (1)].chaine)); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 285 "src/parser/parser.y"
    { (yyval.noeud) = ast_booleen(1); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 286 "src/parser/parser.y"
    { (yyval.noeud) = ast_booleen(0); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 287 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(2) - (3)].noeud); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 288 "src/parser/parser.y"
    { (yyval.noeud) = ast_unaire("-", (yyvsp[(2) - (2)].noeud)); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 289 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 296 "src/parser/parser.y"
    { (yyval.noeud) = ast_binaire("&&", (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 297 "src/parser/parser.y"
    { (yyval.noeud) = ast_binaire("||", (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 298 "src/parser/parser.y"
    { (yyval.noeud) = ast_unaire("!", (yyvsp[(2) - (2)].noeud)); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 299 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(1) - (1)].noeud); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 303 "src/parser/parser.y"
    { (yyval.noeud) = ast_binaire("<",  (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 304 "src/parser/parser.y"
    { (yyval.noeud) = ast_binaire(">",  (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 305 "src/parser/parser.y"
    { (yyval.noeud) = ast_binaire("<=", (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 306 "src/parser/parser.y"
    { (yyval.noeud) = ast_binaire(">=", (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 307 "src/parser/parser.y"
    { (yyval.noeud) = ast_binaire("==", (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 308 "src/parser/parser.y"
    { (yyval.noeud) = ast_binaire("!=", (yyvsp[(1) - (3)].noeud), (yyvsp[(3) - (3)].noeud)); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 309 "src/parser/parser.y"
    { (yyval.noeud) = (yyvsp[(2) - (3)].noeud); }
    break;


/* Line 1792 of yacc.c  */
#line 2004 "build/parser.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 313 "src/parser/parser.y"



/* -- Erreur syntaxique : affiche le message et la ligne courante -- */

void yyerror(const char *msg) {
    fprintf(stderr, "[Erreur syntaxique] %s - ligne %d\n", msg, yylineno);
}
