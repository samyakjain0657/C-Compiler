/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "bison.y" /* yacc.c:339  */

#include <bits/stdc++.h>
#include "semantic.h"
using namespace std;
extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;
int yyerror(char *s);


#line 78 "bison.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "bison.tab.h".  */
#ifndef YY_YY_BISON_TAB_H_INCLUDED
# define YY_YY_BISON_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    OR = 258,
    AND = 259,
    DEFAULT = 260,
    CASE = 261,
    COLON = 262,
    SWITCH = 263,
    SEMICOL = 264,
    EQUALS = 265,
    ADD = 266,
    SUB = 267,
    MUL = 268,
    DIV = 269,
    MOD = 270,
    GT = 271,
    LT = 272,
    GE = 273,
    LE = 274,
    COMP = 275,
    NEQ = 276,
    MAIN = 277,
    IF = 278,
    FOR = 279,
    WHILE = 280,
    ELSE = 281,
    INT = 282,
    FLOAT = 283,
    TRUE = 284,
    FALSE = 285,
    BOOL = 286,
    LP = 287,
    RP = 288,
    LS = 289,
    RS = 290,
    LB = 291,
    RB = 292,
    RETURN = 293,
    BREAK = 294,
    CONTINUE = 295,
    COMMA = 296,
    INT_VALUE = 297,
    FLOAT_VAL = 298,
    LIBRARY = 299,
    ID = 300,
    NEWLINE = 301,
    WHITESPACE = 302,
    VOID = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "bison.y" /* yacc.c:355  */

	struct DataNode *datanode;

#line 171 "bison.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 188 "bison.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   230

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  209

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    29,    29,    33,    29,    39,    42,    48,    54,    46,
      63,    64,    68,    70,    75,    82,    85,    75,    92,    99,
     102,    92,   112,   113,   117,   118,   122,   130,   137,   142,
     149,   152,   160,   168,   170,   172,   177,   178,   182,   189,
     199,   203,   204,   208,   211,   208,   216,   217,   218,   224,
     232,   234,   241,   233,   246,   251,   255,   246,   267,   274,
     281,   266,   295,   311,   295,   320,   364,   320,   377,   376,
     390,   399,   403,   398,   407,   412,   411,   417,   423,   429,
     436,   437,   438,   448,   483,   484,   485,   489,   506,   519,
     523,   535,   539,   540,   541,   542,   550,   590,   591,   595,
     596,   600,   601,   602,   606,   607,   608,   609,   610,   611,
     615,   646,   647,   651,   652
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OR", "AND", "DEFAULT", "CASE", "COLON",
  "SWITCH", "SEMICOL", "EQUALS", "ADD", "SUB", "MUL", "DIV", "MOD", "GT",
  "LT", "GE", "LE", "COMP", "NEQ", "MAIN", "IF", "FOR", "WHILE", "ELSE",
  "INT", "FLOAT", "TRUE", "FALSE", "BOOL", "LP", "RP", "LS", "RS", "LB",
  "RB", "RETURN", "BREAK", "CONTINUE", "COMMA", "INT_VALUE", "FLOAT_VAL",
  "LIBRARY", "ID", "NEWLINE", "WHITESPACE", "VOID", "$accept", "start",
  "$@1", "$@2", "libraries", "body_main", "$@3", "$@4", "declarations",
  "dclr", "func_def", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
  "decl_plist", "decl_pl", "decl_param", "var_dclr", "type", "varl",
  "dims", "dims2", "body", "stmt_list", "stmt", "$@11", "$@12", "$@13",
  "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22",
  "$@23", "$@24", "else_stmt", "$@25", "case_stmt", "$@26", "$@27",
  "default", "$@28", "return_stmt", "expr", "log_expr", "rel_expr",
  "arith_expr", "expr1", "term", "const", "op1", "op2", "op3", "func_call",
  "paramlist", "plist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -127

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-127)))

#define YYTABLE_NINF -78

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -127,     5,  -127,  -127,   -36,  -127,  -127,    45,   -10,  -127,
     -30,  -127,  -127,  -127,  -127,   -19,    31,    48,     1,    -3,
       8,  -127,    13,    -9,  -127,    53,  -127,    43,    15,     3,
      13,  -127,  -127,   -18,    42,    47,  -127,  -127,  -127,    54,
       3,    50,     0,  -127,  -127,    65,    64,  -127,    63,     2,
      13,   170,    75,  -127,  -127,    13,  -127,  -127,  -127,    13,
    -127,    85,    90,    13,    53,  -127,    98,     3,  -127,  -127,
       9,     7,  -127,    61,  -127,    95,    94,    92,    13,    47,
    -127,   105,  -127,    42,  -127,   165,  -127,  -127,  -127,    13,
      14,    13,    13,  -127,  -127,  -127,  -127,  -127,  -127,    13,
    -127,   170,    11,  -127,   107,   109,   112,   113,   117,  -127,
     170,   145,   147,  -127,   115,  -127,   154,   159,  -127,    42,
      13,  -127,    95,  -127,    42,  -127,  -127,  -127,  -127,   126,
     170,   170,  -127,  -127,  -127,  -127,  -127,    17,  -127,  -127,
    -127,    42,  -127,   138,   139,   168,   170,   165,   146,   150,
      75,   149,   162,  -127,   158,   163,  -127,  -127,   161,   167,
    -127,   170,  -127,  -127,   177,  -127,  -127,   182,   179,  -127,
    -127,    58,  -127,  -127,  -127,    -1,  -127,   170,  -127,    -1,
    -127,   194,   169,   188,   180,    96,   183,   211,   178,  -127,
     187,  -127,   189,  -127,  -127,  -127,  -127,  -127,  -127,   165,
     215,  -127,  -127,  -127,   119,   142,   165,  -127,  -127
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     6,     1,     3,     5,    11,     0,    28,    29,
       0,     4,    10,    13,    12,     0,     0,     0,    30,     0,
       0,    18,     0,     0,    14,    34,    27,     0,     0,    23,
       0,    97,    98,    95,    31,    89,    91,    94,    93,     0,
      23,     0,    33,     7,    28,     0,    22,    25,     0,     0,
       0,   112,    96,    99,   100,     0,   101,   102,   103,     0,
      36,     0,     0,     0,    35,    42,     0,     0,    26,    92,
       0,    95,   114,    81,    86,    80,     0,   111,     0,    88,
      90,     0,    37,    32,     8,    40,    19,    24,    38,     0,
      96,     0,     0,   104,   105,   106,   107,   108,   109,     0,
     110,     0,     0,    15,     0,     0,     0,     0,     0,    43,
      78,     0,     0,    46,     0,    41,     0,     0,    42,    82,
       0,    84,     0,    85,    87,   113,    39,    42,     9,     0,
       0,     0,    54,    42,    79,    49,    48,    30,    50,    47,
      20,    83,    16,    62,     0,     0,     0,    44,     0,     0,
      65,     0,     0,    58,     0,     0,    21,    17,     0,     0,
      51,     0,    55,    45,     0,    63,    42,     0,     0,    66,
      74,     0,    59,    56,    74,    71,    52,     0,    42,    71,
      75,     0,     0,    70,     0,     0,     0,     0,     0,    64,
       0,    53,     0,    57,    67,    42,    72,    68,    60,    76,
       0,    42,    42,    42,     0,     0,    73,    69,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,   184,  -127,   156,
     218,    -4,  -127,   185,   -69,   -99,  -126,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,    52,  -127,  -127,    49,  -127,  -127,
     -51,  -127,    26,   -21,   174,   171,  -127,  -127,  -127,  -127,
    -127,  -127,  -127
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     4,    11,    65,   104,     7,    12,
      13,    40,   127,   149,    29,   118,   148,    45,    46,    47,
     113,   114,    19,    25,    52,    84,    85,   115,   133,   155,
     166,   183,   146,   168,   178,   161,   177,   202,   151,   170,
     158,   174,   191,   201,   175,   181,   200,   182,   187,   116,
     117,    73,    74,    75,    35,    36,    37,    55,    59,    99,
      38,    76,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      72,    34,    90,    15,   180,     3,    26,   147,     5,    49,
      63,    22,    16,    53,    54,    17,    50,    89,    51,   140,
      53,    54,    53,    54,   120,    48,    18,    22,   142,    70,
      44,     9,   -77,    39,    23,    23,    48,    24,    27,    69,
     171,    50,    83,    51,    88,    28,   126,    43,    78,    30,
     125,    23,   185,    53,    54,    31,    32,   102,    33,   134,
      56,    57,    58,    48,    91,    92,   105,    20,   119,   199,
     122,   122,     8,     9,   150,   204,   205,   206,   124,   144,
     145,   106,   107,   108,    21,    44,     9,    41,    42,    60,
     109,   176,    62,    10,    30,   154,   110,   111,   112,   141,
      31,    32,    66,    71,   105,    67,    53,    54,    68,    78,
     167,    93,    94,    95,    96,    97,    98,   121,   123,   106,
     107,   108,    81,    44,     9,    82,   184,   105,   109,   193,
      86,   100,    30,   101,   110,   111,   112,   103,    31,    32,
     128,    71,   106,   107,   108,   129,    44,     9,   130,   131,
     105,   109,   207,   132,   135,    30,   136,   110,   111,   112,
     137,    31,    32,   138,    71,   106,   107,   108,   139,    44,
       9,   143,    50,   105,   109,   208,   152,   153,    30,   156,
     110,   111,   112,   157,    31,    32,   159,    71,   106,   107,
     108,   172,    44,     9,   160,   162,   163,   109,   164,   165,
     188,    30,   189,   110,   111,   112,    30,    31,    32,   169,
      71,   173,    31,    32,   190,    71,   194,   192,   195,   197,
     196,   198,   203,    87,    61,    14,   179,    64,   186,    79,
      80
};

static const yytype_uint8 yycheck[] =
{
      51,    22,    71,     7,     5,     0,     9,   133,    44,    30,
      10,    10,    22,    11,    12,    45,    34,    10,    36,   118,
      11,    12,    11,    12,    10,    29,    45,    10,   127,    50,
      27,    28,    33,    42,    34,    34,    40,    36,    41,    37,
     166,    34,    63,    36,    35,    37,    35,    32,    34,    36,
     101,    34,   178,    11,    12,    42,    43,    78,    45,   110,
      13,    14,    15,    67,     3,     4,     8,    36,    89,   195,
      91,    92,    27,    28,   143,   201,   202,   203,    99,   130,
     131,    23,    24,    25,    36,    27,    28,    34,    45,    35,
      32,    33,    42,    48,    36,   146,    38,    39,    40,   120,
      42,    43,    37,    45,     8,    41,    11,    12,    45,    34,
     161,    16,    17,    18,    19,    20,    21,    91,    92,    23,
      24,    25,    37,    27,    28,    35,   177,     8,    32,    33,
      32,    37,    36,    41,    38,    39,    40,    32,    42,    43,
      33,    45,    23,    24,    25,    36,    27,    28,    36,    36,
       8,    32,    33,    36,     9,    36,     9,    38,    39,    40,
      45,    42,    43,     9,    45,    23,    24,    25,     9,    27,
      28,    45,    34,     8,    32,    33,    37,     9,    36,    33,
      38,    39,    40,    33,    42,    43,    37,    45,    23,    24,
      25,     9,    27,    28,    32,    37,    33,    32,    37,    32,
       6,    36,    33,    38,    39,    40,    36,    42,    43,    32,
      45,    32,    42,    43,    26,    45,    33,    37,     7,    32,
      42,    32,     7,    67,    40,     7,   174,    42,   179,    55,
      59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,    51,     0,    53,    44,    52,    57,    27,    28,
      48,    54,    58,    59,    69,    70,    22,    45,    45,    71,
      36,    36,    10,    34,    36,    72,     9,    41,    37,    63,
      36,    42,    43,    45,   102,   103,   104,   105,   109,    42,
      60,    34,    45,    32,    27,    66,    67,    68,    70,   102,
      34,    36,    73,    11,    12,   106,    13,    14,    15,   107,
      35,    66,    42,    10,    72,    55,    37,    41,    45,    37,
     102,    45,    99,   100,   101,   102,   110,   111,    34,   103,
     104,    37,    35,   102,    74,    75,    32,    68,    35,    10,
      73,     3,     4,    16,    17,    18,    19,    20,    21,   108,
      37,    41,   102,    32,    56,     8,    23,    24,    25,    32,
      38,    39,    40,    69,    70,    76,    98,    99,    64,   102,
      10,   101,   102,   101,   102,    99,    35,    61,    33,    36,
      36,    36,    36,    77,    99,     9,     9,    45,     9,     9,
      74,   102,    74,    45,    99,    99,    81,    75,    65,    62,
      73,    87,    37,     9,    99,    78,    33,    33,    89,    37,
      32,    84,    37,    33,    37,    32,    79,    99,    82,    32,
      88,    75,     9,    32,    90,    93,    33,    85,    83,    93,
       5,    94,    96,    80,    99,    75,    96,    97,     6,    33,
      26,    91,    37,    33,    33,     7,    42,    32,    32,    75,
      95,    92,    86,     7,    75,    75,    75,    33,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    51,    52,    50,    53,    53,    55,    56,    54,
      57,    57,    58,    58,    60,    61,    62,    59,    63,    64,
      65,    59,    66,    66,    67,    67,    68,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    72,    72,    73,    73,
      74,    75,    75,    77,    78,    76,    76,    76,    76,    76,
      76,    79,    80,    76,    81,    82,    83,    76,    84,    85,
      86,    76,    87,    88,    76,    89,    90,    76,    92,    91,
      91,    94,    95,    93,    93,    97,    96,    96,    98,    98,
      99,    99,    99,    99,   100,   100,   100,   101,   102,   102,
     103,   103,   104,   104,   104,   104,   104,   105,   105,   106,
     106,   107,   107,   107,   108,   108,   108,   108,   108,   108,
     109,   110,   110,   111,   111
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     5,     2,     0,     0,     0,     9,
       2,     0,     1,     1,     0,     0,     0,    11,     0,     0,
       0,    11,     1,     0,     3,     1,     2,     3,     1,     1,
       1,     3,     5,     3,     2,     4,     3,     4,     3,     4,
       1,     2,     0,     0,     0,     5,     1,     2,     2,     2,
       2,     0,     0,    10,     0,     0,     0,    10,     0,     0,
       0,    14,     0,     0,    10,     0,     0,    11,     0,     5,
       0,     0,     0,     7,     0,     0,     4,     0,     1,     2,
       1,     1,     3,     4,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 29 "bison.y" /* yacc.c:1646  */
    {
        file.open("inter.txt");
    }
#line 1428 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 33 "bison.y" /* yacc.c:1646  */
    {scope=0;}
#line 1434 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 39 "bison.y" /* yacc.c:1646  */
    {

    }
#line 1442 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 48 "bison.y" /* yacc.c:1646  */
    {
        scope=2; 
        enter_func("main","int",active_func_ptr);
        file << "func begin main\n";
    }
#line 1452 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 54 "bison.y" /* yacc.c:1646  */
    {
        release_var(active_func_ptr,scope);
        scope--;
        file << "func end\n";
    }
#line 1462 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 68 "bison.y" /* yacc.c:1646  */
    {
    }
#line 1469 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 75 "bison.y" /* yacc.c:1646  */
    {
        scope++;
        active_type = dt_none;
        enter_func(((yyvsp[-1].datanode))->value,((yyvsp[-2].datanode))->value,active_func_ptr);
        param_count=0;
        file << "func begin " << ((yyvsp[-1].datanode))->value << "\n";
    }
#line 1481 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 82 "bison.y" /* yacc.c:1646  */
    {                  
        scope++;
    }
#line 1489 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 85 "bison.y" /* yacc.c:1646  */
    {
        release_var(active_func_ptr,2);
        scope=0;
        file << "func end\n";
    }
#line 1499 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 92 "bison.y" /* yacc.c:1646  */
    {
        scope++;
        active_type = dt_none;
        enter_func(((yyvsp[-1].datanode))->value,"void",active_func_ptr);
        param_count=0;
        file << "func begin " << ((yyvsp[-1].datanode))->value << "\n";
    }
#line 1511 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 99 "bison.y" /* yacc.c:1646  */
    {  
        scope++;
    }
#line 1519 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 102 "bison.y" /* yacc.c:1646  */
    {
        release_var(active_func_ptr,2);
        scope=0;
        file << "func end\n";
    }
#line 1529 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 122 "bison.y" /* yacc.c:1646  */
    {   
        var *param;
        enter_param(((yyvsp[0].datanode))->value,((yyvsp[-1].datanode))->value,active_func_ptr,param);
        active_type = dt_none;
    }
#line 1539 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 130 "bison.y" /* yacc.c:1646  */
    {
        patch_type(((yyvsp[-2].datanode))->value);
        active_type = dt_none;
    }
#line 1548 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 137 "bison.y" /* yacc.c:1646  */
    { 
        active_type = dt_int;
        (yyval.datanode) = (yyvsp[0].datanode);
    }
#line 1557 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 142 "bison.y" /* yacc.c:1646  */
    {
        active_type = dt_float;
        (yyval.datanode) = (yyvsp[0].datanode);
    }
#line 1566 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 149 "bison.y" /* yacc.c:1646  */
    {
        enter_var(((yyvsp[0].datanode))->value,scope,"simple",dimlist,active_func_ptr);
    }
#line 1574 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 152 "bison.y" /* yacc.c:1646  */
    {
        bool chk = check_type((yyvsp[-2].datanode), (yyvsp[0].datanode));
        if (chk) {
            enter_var(((yyvsp[-2].datanode))->value,scope,"simple",dimlist,active_func_ptr);
            file << get_var_code_name((yyvsp[-2].datanode)->value) << " = " << (yyvsp[0].datanode)->code_name << endl;
            release_temp_name((yyvsp[0].datanode)->code_name);
        }
    }
#line 1587 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 160 "bison.y" /* yacc.c:1646  */
    {
        bool chk = check_type((yyvsp[-2].datanode), (yyvsp[0].datanode));
        if (chk) {
            enter_var(((yyvsp[-2].datanode))->value,scope,"simple",dimlist,active_func_ptr);
            file << get_var_code_name((yyvsp[-2].datanode)->value) << " = " << (yyvsp[0].datanode)->code_name << endl;
            release_temp_name((yyvsp[0].datanode)->code_name);
        }
    }
#line 1600 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 169 "bison.y" /* yacc.c:1646  */
    {   enter_var(((yyvsp[0].datanode))->value,scope,"simple",dimlist,active_func_ptr);}
#line 1606 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 171 "bison.y" /* yacc.c:1646  */
    {   enter_var(((yyvsp[-1].datanode))->value,scope,"array",dimlist,active_func_ptr);}
#line 1612 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 173 "bison.y" /* yacc.c:1646  */
    {   enter_var(((yyvsp[-1].datanode))->value,scope,"array",dimlist,active_func_ptr);}
#line 1618 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 177 "bison.y" /* yacc.c:1646  */
    {dimlist.push_back(stoi(((yyvsp[-1].datanode))->value));}
#line 1624 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 178 "bison.y" /* yacc.c:1646  */
    {dimlist.push_back(stoi(((yyvsp[-1].datanode))->value));}
#line 1630 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 183 "bison.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].datanode)->data_type == dt_int)
            dimlist_call.push_back((yyvsp[-1].datanode)->code_name);
        else 
            cout << "Line No. " << yylineno << " Error : array subscript (" << dimlist_call.size() <<  ") is not an integer " << endl; 
    }
#line 1641 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 190 "bison.y" /* yacc.c:1646  */
    {
       if ((yyvsp[-2].datanode)->data_type == dt_int)
            dimlist_call.push_back((yyvsp[-1].datanode)->code_name);
        else 
            cout << "Line No. " << yylineno << " Error : array subscript (" << dimlist_call.size() <<  ") is not an integer " << endl; 
    }
#line 1652 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 208 "bison.y" /* yacc.c:1646  */
    {
        scope++;   
    }
#line 1660 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 211 "bison.y" /* yacc.c:1646  */
    {   
        release_var(active_func_ptr,scope);
        scope--;
    }
#line 1669 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 218 "bison.y" /* yacc.c:1646  */
    {
            if(loop_stack.size()==0)
                cout << "Line No. " << yylineno << " Error : Continue should be always used inside a loop"<<endl; 
            else
                file << "goto LT" << loop_stack.top() << endl;
        }
#line 1680 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 224 "bison.y" /* yacc.c:1646  */
    {
            if(last_used.size()==0)
                cout << "Line No. " << yylineno << " Error : break should be always used inside a loop or switch"<<endl; 
            else if(last_used.top()==0)
                file << "goto SF" << switch_stack.top() << endl;
            else
                file << "goto LF" << loop_stack.top() << endl;
        }
#line 1693 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 234 "bison.y" /* yacc.c:1646  */
    {
            scope++;
            file << "if " << (yyvsp[-2].datanode)->code_name << " <= 0 goto IFF" << if_counter << endl;
            if_stack.push(if_counter++);
            release_temp_name((yyvsp[-2].datanode)->code_name);
        }
#line 1704 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 241 "bison.y" /* yacc.c:1646  */
    {
            release_var(active_func_ptr,scope);
            scope--;
        }
#line 1713 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 246 "bison.y" /* yacc.c:1646  */
    {
            loop_stack.push(loop_counter);
            last_used.push(1);
            file << "LT" << loop_counter << ":\n";
        }
#line 1723 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 251 "bison.y" /* yacc.c:1646  */
    {
            file << "if "<<(yyvsp[-1].datanode)->code_name << " <= 0 goto LF" << loop_counter++ << endl;
            release_temp_name((yyvsp[-1].datanode)->code_name);
        }
#line 1732 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 255 "bison.y" /* yacc.c:1646  */
    {
            scope++; 
        }
#line 1740 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 258 "bison.y" /* yacc.c:1646  */
    {
            release_var(active_func_ptr,scope);
            scope--;
            file << "goto LT" << loop_stack.top()<< endl;
            file << "LF" << loop_stack.top() << ":" << endl;
            loop_stack.pop();
            last_used.pop();
        }
#line 1753 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 267 "bison.y" /* yacc.c:1646  */
    {
            loop_stack.push(loop_counter);
            last_used.push(1);
            file << "LJ" << loop_counter << ":\n";
            release_temp_name((yyvsp[-1].datanode)->code_name);
        }
#line 1764 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 274 "bison.y" /* yacc.c:1646  */
    {
            file << "if " << (yyvsp[-1].datanode)->code_name  << " <= 0 goto LF" << loop_counter << endl;
            file << "goto LS" << loop_counter << ":" << endl;
            file << "LT" << loop_counter << ":\n";
            release_temp_name((yyvsp[-1].datanode)->code_name);
        }
#line 1775 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 281 "bison.y" /* yacc.c:1646  */
    {
            scope++;
            file << "goto LJ" << loop_counter << endl;
            file << "LS" << loop_counter++ << ":\n";
            release_temp_name((yyvsp[-2].datanode)->code_name);
        }
#line 1786 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 287 "bison.y" /* yacc.c:1646  */
    { 
            release_var(active_func_ptr,scope);
            scope--;
            file << "goto LT" << loop_stack.top()<< endl;
            file << "LF" << loop_stack.top() << ":" << endl;
            loop_stack.pop();
            last_used.pop();
        }
#line 1799 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 295 "bison.y" /* yacc.c:1646  */
    {
            switch_stack.push(switch_counter++);
            last_used.push(0);
            var *variable;
            bool found = false;
            search_var(((yyvsp[0].datanode))->value,active_func_ptr,scope,found,variable);
            if(!found){
                cout << "Line No. " << yylineno << " Error : Variable " << ((yyvsp[0].datanode))->value << " not declared" << endl; 
            }
            else{
                if(variable->eletype!="int")
                    cout << "Line No. " << yylineno << " Error: expression must have integral type"<< endl; 
            } 
            curr_temp = get_temp_name();
            file << curr_temp << " = " << variable->code_name << endl;
        }
#line 1820 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 311 "bison.y" /* yacc.c:1646  */
    { scope++; }
#line 1826 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 312 "bison.y" /* yacc.c:1646  */
    { 
            release_var(active_func_ptr,scope);
            scope--;
            file << "SF" << switch_stack.top() << ":" << endl;
            switch_stack.pop();
            last_used.pop();
            release_temp_name(curr_temp);
        }
#line 1839 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 320 "bison.y" /* yacc.c:1646  */
    {
            switch_stack.push(switch_counter++);
            last_used.push(0);
            var *variable;
            bool found = false;
            search_var(((yyvsp[-1].datanode))->value,active_func_ptr,scope,found,variable);
            if(!found){
                cout << "Line No. " << yylineno << " Error : Variable " << ((yyvsp[-1].datanode))->value << " not declared" << endl; 
            }
            else{
                if(variable->eletype!="int")
                    cout << "Line No. " << yylineno << " Error: expression must have integral type"<< endl; 
            }

            string temp_name = dimlist_call[0];
            string temp_name3 = get_temp_name();
            string temp_name4 = get_temp_name();
            string temp_name5 = get_temp_name();
            string temp_name6;  
            string temp_name2;      
            vector<int> temp_dim_list = get_dimlist((yyvsp[-1].datanode)->value);
            for (int i = 1; i < temp_dim_list.size(); i++) {
                temp_name2 = get_temp_name(); 
                temp_name6 = get_temp_name();    
                file << temp_name6 << " = " << temp_name << " * " << temp_dim_list[i] << endl;
                file << temp_name2 << " = " << temp_name6 << " + " << dimlist_call[i] << endl;
                release_temp_name(temp_name);
                release_temp_name(dimlist_call[i]);
                release_temp_name(temp_name6);
                temp_name = temp_name2;
            }
            file << temp_name3 << " = " << temp_name2 << " * 4\n";
            file << temp_name4 << " = " << "addr(" << get_var_code_name((yyvsp[-1].datanode)->value) << ")" << endl;
            // file << temp_name4 << "[" << temp_name3 <<"]"  << " = " << $4->code_name << endl;
            file << temp_name5 << " = " << temp_name4 << "[" << temp_name3 <<"]" << endl;
            release_temp_name(temp_name2);
            release_temp_name(temp_name3);
            release_temp_name(temp_name4);
            temp_dim_list.clear();
            dimlist_call.clear();
            curr_temp = temp_name5;
            // $$->code_name = temp_name5;
                        
        }
#line 1888 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 364 "bison.y" /* yacc.c:1646  */
    { scope++; }
#line 1894 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 365 "bison.y" /* yacc.c:1646  */
    { 
            release_var(active_func_ptr,scope);
            scope--;
            file << "SF" << switch_stack.top() << ":" << endl;
            switch_stack.pop();
            last_used.pop();
            release_temp_name(curr_temp);
        }
#line 1907 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 377 "bison.y" /* yacc.c:1646  */
    {
        scope++;
        file << "goto IFT" << if_stack.top() << endl; 
        file << "IFF" << if_stack.top() << ":\n";
    }
#line 1917 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 383 "bison.y" /* yacc.c:1646  */
    {
        release_var(active_func_ptr,scope);
        scope--;
        file << "IFT" << if_stack.top() << ":\n";
        if_stack.pop();
    }
#line 1928 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 390 "bison.y" /* yacc.c:1646  */
    {
        file << "IFF" << if_stack.top() << ":\n";
        if_stack.pop();
    }
#line 1937 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 399 "bison.y" /* yacc.c:1646  */
    {
        file << "CT" << case_counter++ << ": " << endl;
    }
#line 1945 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 403 "bison.y" /* yacc.c:1646  */
    {
        file << "if " << curr_temp << " != " << (yyvsp[0].datanode)->value << " goto CT" << case_counter << endl; 
    }
#line 1953 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 412 "bison.y" /* yacc.c:1646  */
    {
        file << "CT" << case_counter++ << ": " << endl;
    }
#line 1961 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 417 "bison.y" /* yacc.c:1646  */
    {
        file << "CT" << case_counter++ << ": " << endl;
    }
#line 1969 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 423 "bison.y" /* yacc.c:1646  */
    {
        DataNode *res = new DataNode();
        res->data_type = dt_none;
        (yyval.datanode) = res;
        file << "return\n";
    }
#line 1980 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 429 "bison.y" /* yacc.c:1646  */
    {
        (yyval.datanode) = check_func_return_type((yyvsp[0].datanode));
        file << "return " << (yyvsp[0].datanode)->code_name << endl;
    }
#line 1989 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 436 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1995 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 437 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 2001 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 439 "bison.y" /* yacc.c:1646  */
    {
        (yyval.datanode) = checkType((yyvsp[-2].datanode),(yyvsp[0].datanode));
        
        file << get_var_code_name((yyvsp[-2].datanode)->value) << " = " << (yyvsp[0].datanode)->code_name << endl;
        release_temp_name((yyvsp[0].datanode)->code_name);
        string temp_name = get_temp_name();
        file << temp_name << " = " << get_var_code_name((yyvsp[-2].datanode)->value) << endl;
        (yyval.datanode)->code_name = temp_name;
    }
#line 2015 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 449 "bison.y" /* yacc.c:1646  */
    {
        (yyval.datanode) = checkType((yyvsp[-3].datanode),(yyvsp[0].datanode));

        string temp_name = dimlist_call[0];
        string temp_name3 = get_temp_name();
        string temp_name4 = get_temp_name();
        string temp_name5 = get_temp_name();
        string temp_name6;  
        string temp_name2;      
        vector<int> temp_dim_list = get_dimlist((yyvsp[-3].datanode)->value);
        for (int i = 1; i < temp_dim_list.size(); i++) {
            temp_name2 = get_temp_name(); 
            temp_name6 = get_temp_name();    
            file << temp_name6 << " = " << temp_name << " * " << temp_dim_list[i] << endl;
            file << temp_name2 << " = " << temp_name6 << " + " << dimlist_call[i] << endl;
            release_temp_name(temp_name);
            release_temp_name(dimlist_call[i]);
            release_temp_name(temp_name6);
            temp_name = temp_name2;
        }
        file << temp_name3 << " = " << temp_name2 << " * 4\n";
        file << temp_name4 << " = " << "addr(" << get_var_code_name((yyvsp[-3].datanode)->value) << ")" << endl;
        file << temp_name4 << "[" << temp_name3 <<"]"  << " = " << (yyvsp[0].datanode)->code_name << endl;
        file << temp_name5 << " = " << temp_name4 << "[" << temp_name3 <<"]" << endl;
        release_temp_name(temp_name2);
        release_temp_name(temp_name3);
        release_temp_name(temp_name4);
        temp_dim_list.clear();
        dimlist_call.clear();
        (yyval.datanode)->code_name = temp_name5;
    }
#line 2051 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 483 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 2057 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 484 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 2063 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 485 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 2069 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 490 "bison.y" /* yacc.c:1646  */
    {
        DataNode *res = new DataNode();
        res->data_type = dt_bool;
        (yyval.datanode) = res;
        string temp1 = (yyvsp[-2].datanode)->code_name;
        string temp2 = (yyvsp[0].datanode)->code_name;
        
        string temp_name = get_temp_name();
        file << temp_name  << " = "  <<  temp1 << " " << (yyvsp[-1].datanode)->code_name << " " << temp2 << endl;
        release_temp_name(temp1);
        release_temp_name(temp2);
        (yyval.datanode)->code_name = temp_name;
    }
#line 2087 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 507 "bison.y" /* yacc.c:1646  */
    {
        string temp1 = (yyvsp[-2].datanode)->code_name;
        string temp2 = (yyvsp[0].datanode)->code_name;

        (yyval.datanode) = typecaster((yyvsp[-2].datanode),(yyvsp[0].datanode));

        string temp_name = get_temp_name();
        file << temp_name  << " = "  <<  temp1 << " " << (yyvsp[-1].datanode)->code_name << " " << temp2 << endl;
        release_temp_name(temp1);
        release_temp_name(temp2);
        (yyval.datanode)->code_name = temp_name;
    }
#line 2104 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 519 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 2110 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 524 "bison.y" /* yacc.c:1646  */
    {
        string temp1 = (yyvsp[-2].datanode)->code_name;
        string temp2 = (yyvsp[0].datanode)->code_name;

        (yyval.datanode) = typecaster((yyvsp[-2].datanode),(yyvsp[0].datanode));
        string temp_name = get_temp_name();
        file << temp_name  << " = "  <<  temp1 << " " << (yyvsp[-1].datanode)->code_name << " " << temp2 << endl;
        release_temp_name(temp1);
        release_temp_name(temp2);
        (yyval.datanode)->code_name = temp_name;
    }
#line 2126 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 535 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 2132 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 539 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[-1].datanode);}
#line 2138 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 540 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 2144 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 541 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 2150 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 543 "bison.y" /* yacc.c:1646  */
    {
        set_data_type((yyvsp[0].datanode)); 
        (yyval.datanode) = (yyvsp[0].datanode);
        string temp_name = get_temp_name();
        file << temp_name << " = " << get_var_code_name((yyvsp[0].datanode)->value) << endl;
        (yyval.datanode)->code_name = temp_name;
    }
#line 2162 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 551 "bison.y" /* yacc.c:1646  */
    {        
        set_data_type((yyvsp[-1].datanode));
        
        (yyval.datanode) = (yyvsp[-1].datanode);
        ((yyval.datanode))->type = "array";

        string temp_name = dimlist_call[0];
        string temp_name3 = get_temp_name();
        string temp_name4 = get_temp_name();
        string temp_name5 = get_temp_name();
        string temp_name6;  
        string temp_name2;      
        vector<int> temp_dim_list = get_dimlist((yyvsp[-1].datanode)->value);
        // for (auto it: dimlist_call) {
        //     cout << it <<  " ";
        // }cout << endl;
        for (int i = 1; i < temp_dim_list.size(); i++) {
            temp_name2 = get_temp_name(); 
            temp_name6 = get_temp_name();    
            file << temp_name6 << " = " << temp_name << " * " << temp_dim_list[i] << endl;
            file << temp_name2 << " = " << temp_name6 << " + " << dimlist_call[i] << endl;
            release_temp_name(temp_name);
            release_temp_name(dimlist_call[i]);
            release_temp_name(temp_name6);
            temp_name = temp_name2;
        }
        file << temp_name3 << " = " << temp_name2 << " * 4\n";
        file << temp_name4 << " = " << "addr(" << get_var_code_name((yyvsp[-1].datanode)->value) << ")" << endl;
        file << temp_name5 << " = " << temp_name4 << "[" << temp_name3 <<"]" << endl;
        release_temp_name(temp_name2);
        release_temp_name(temp_name3);
        release_temp_name(temp_name4);
        temp_dim_list.clear();
        dimlist_call.clear();
        (yyval.datanode)->code_name = temp_name5;
    }
#line 2203 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 590 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 2209 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 591 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 2215 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 595 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 2221 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 596 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 2227 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 600 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 2233 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 601 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 2239 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 602 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 2245 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 606 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 2251 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 607 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 2257 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 608 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 2263 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 609 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 2269 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 610 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 2275 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 611 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 2281 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 616 "bison.y" /* yacc.c:1646  */
    {
        DataNode* func = check_func_call(((yyvsp[-3].datanode))->value);
        for (auto it: param_list) {
            file << "param " << it.first << "\n";
            release_temp_name(it.first);
        }
        if(func->data_type == dt_int || func->data_type == dt_float ){
            file << "refparam _result" << res_counter <<"\n"; 
            var *variable = new var();
            
            if (func->data_type == dt_int)
                variable->eletype = "int";
            else
                variable->eletype = "float";
            
            variable->name = "_result" + to_string(res_counter);
            variable->code_name =  "_result" + to_string(res_counter++);
            variable->level = scope;
            variable->type = "simple";
            variable->isParam = false;
            symbol_list.push_back(*variable);
            func->code_name =  variable->code_name;
        }
        file << "call " << ((yyvsp[-3].datanode))->value <<"\n";
        param_list.clear();
        (yyval.datanode) = func;
    }
#line 2313 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 651 "bison.y" /* yacc.c:1646  */
    {param_list.push_back({((yyvsp[0].datanode))->code_name,((yyvsp[0].datanode))->data_type});}
#line 2319 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 652 "bison.y" /* yacc.c:1646  */
    {param_list.push_back({((yyvsp[0].datanode))->code_name,((yyvsp[0].datanode))->data_type});}
#line 2325 "bison.tab.c" /* yacc.c:1646  */
    break;


#line 2329 "bison.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 655 "bison.y" /* yacc.c:1906  */


int yyerror(char *s)
{
  extern char *yytext;
  printf("Line No. %d ERROR: %s at symbol %s\n",yylineno, s, yytext);
}

int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        printf("File not found\n");
        return 0;
    }
    yyin = fp;

	do {
		yyparse();
	} while(!feof(yyin));

    // for(auto i = var_list.begin(); i!=var_list.end(); i++){
    //      cout<< *i <<endl;
    // }

    // cout << "Symbol Table\n";
    // for (auto it: sym_tab) {
    //     cout << it.first << " ";
    //     it.second.print();
    // }

    // cout << "Function Table\n";
    // for (auto it: func_table) {
    //     cout << it.first << " ";
    //     it.second.print();
    // }

	return 0;
}
