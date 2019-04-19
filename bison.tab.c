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
#define YYLAST   222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

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
       0,    30,    30,    29,    36,    39,    43,    43,    43,    47,
      48,    52,    54,    59,    64,    68,    59,    71,    75,    79,
      71,    85,    86,    90,    91,    95,   103,   110,   115,   122,
     125,   130,   135,   137,   139,   144,   145,   149,   150,   154,
     158,   159,   164,   168,   163,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   184,   185,   189,   190,   191,   195,
     196,   200,   206,   210,   211,   212,   213,   217,   218,   219,
     223,   232,   233,   237,   238,   242,   243,   244,   245,   246,
     255,   256,   260,   261,   265,   266,   267,   271,   272,   273,
     274,   275,   276,   280,   289,   290,   294,   295
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
  "$@1", "libraries", "body_main", "$@2", "$@3", "declarations", "dclr",
  "func_def", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "decl_plist",
  "decl_pl", "decl_param", "var_dclr", "type", "varl", "dims", "dims2",
  "body", "stmt_list", "stmt", "$@10", "$@11", "else_stmt", "case_stmt",
  "default", "return_stmt", "expr", "log_expr", "rel_expr", "arith_expr",
  "expr1", "term", "const", "op1", "op2", "op3", "func_call", "paramlist",
  "plist", YY_NULLPTR
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

#define YYPACT_NINF -122

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-122)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -122,    11,   -15,  -122,  -122,  -122,     5,    -7,  -122,     2,
    -122,  -122,  -122,  -122,    18,    31,    40,     8,    -1,    17,
    -122,   -29,    36,  -122,    53,  -122,    37,    59,   -22,    90,
    -122,  -122,     9,  -122,    48,  -122,    81,    57,  -122,  -122,
    -122,    61,   -22,    52,    -6,  -122,  -122,    69,    76,  -122,
      79,    -9,    -2,    90,    90,   -29,    12,    90,    90,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,    90,    90,  -122,
    -122,  -122,    90,  -122,    92,    96,   -29,    53,  -122,   102,
     -22,  -122,   105,  -122,    45,   108,  -122,   110,   107,    90,
      90,  -122,    81,  -122,    57,    45,  -122,   118,  -122,  -122,
    -122,   159,  -122,  -122,  -122,  -122,   -29,    45,   119,  -122,
     124,   126,   129,   130,   134,  -122,   -29,   162,   164,  -122,
     132,  -122,   171,   176,  -122,  -122,  -122,  -122,  -122,   143,
     -29,   -29,   -29,  -122,  -122,  -122,  -122,    14,  -122,  -122,
    -122,  -122,   152,   153,   183,   156,   159,   161,   163,   168,
     173,   -29,   174,   170,  -122,  -122,  -122,  -122,   198,  -122,
    -122,    84,    41,   -29,    80,   201,    72,   177,   185,   172,
    -122,  -122,   205,   206,  -122,   182,  -122,   184,   159,  -122,
    -122,  -122,  -122,   159,   159,   113,   136,  -122,  -122
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     2,     1,     4,    10,     0,    27,    28,     0,
       3,     9,    12,    11,     0,     0,     0,    29,     0,     0,
      17,     0,     0,    13,    33,    26,     0,     0,    22,     0,
      80,    81,    78,    30,    64,    69,    63,    72,    74,    77,
      76,     0,    22,     0,    32,     6,    27,     0,    21,    24,
       0,    78,     0,     0,     0,    95,    79,     0,     0,    82,
      83,    87,    88,    89,    90,    91,    92,     0,     0,    84,
      85,    86,     0,    35,     0,     0,     0,    34,    41,     0,
       0,    25,    79,    75,    65,     0,    97,     0,    94,     0,
       0,    67,     0,    68,    71,    70,    73,     0,    36,    31,
       7,    39,    18,    23,    37,    93,     0,    66,     0,    14,
       0,     0,     0,     0,     0,    42,    61,     0,     0,    45,
       0,    40,     0,     0,    41,    96,    38,    41,     8,     0,
       0,     0,     0,    41,    62,    48,    47,    29,    49,    46,
      19,    15,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,     0,     0,    20,    16,    58,    41,     0,    41,
      44,    60,     0,     0,     0,     0,     0,     0,    55,     0,
      52,    41,     0,     0,    53,     0,    50,     0,    59,    41,
      41,    41,    41,    56,    57,     0,     0,    54,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,   175,  -122,   135,   212,
      -5,  -122,   178,   169,  -107,  -121,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,   -21,  -122,    70,   -27,   154,   -51,  -122,
    -122,  -122,  -122,  -122,  -122,  -122
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     5,     2,    10,    78,   110,     6,    11,    12,
      42,   127,   148,    28,   124,   147,    47,    48,    49,   119,
     120,    18,    24,    56,   100,   101,   121,   133,   153,   176,
     161,   167,   122,   123,    34,    35,    36,    37,    38,    39,
      67,    72,    68,    40,    87,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    14,    52,    85,    76,    46,     8,    29,    25,    59,
      60,     3,   146,    30,    31,    15,    32,   140,    21,    53,
     141,    96,    89,    50,    21,    54,    84,    55,    22,     4,
      92,    92,     7,     8,    86,    83,   162,    50,   164,   108,
      26,    95,    22,    54,    23,    55,    90,    16,    22,   111,
     178,    57,    58,     9,    27,    99,    59,    60,   183,   184,
     185,   186,   107,    17,   112,   113,   114,    19,    46,     8,
      69,    70,    71,   115,   168,    50,    20,    29,    41,   116,
     117,   118,    44,    30,    31,   125,    32,    43,   111,   165,
     166,    45,    59,    60,    75,   134,    73,    61,    62,    63,
      64,    65,    66,   112,   113,   114,    79,    46,     8,   143,
     144,   145,   115,   170,   172,   173,    29,    80,   116,   117,
     118,   111,    30,    31,    81,    32,    29,    91,    93,    97,
     158,    98,    30,    31,   102,    51,   112,   113,   114,    90,
      46,     8,   169,   104,   111,   115,   187,   105,   106,    29,
     109,   116,   117,   118,   126,    30,    31,   128,    32,   112,
     113,   114,   129,    46,     8,   130,   131,   111,   115,   188,
     132,   135,    29,   136,   116,   117,   118,   137,    30,    31,
     138,    32,   112,   113,   114,   139,    46,     8,   142,   149,
     150,   115,   151,   152,   154,    29,   155,   116,   117,   118,
     156,    30,    31,   160,    32,   157,   159,   163,   171,   177,
     174,   175,   179,   180,   181,   103,   182,    74,    13,     0,
      82,    94,    77
};

static const yytype_int16 yycheck[] =
{
      21,     6,    29,    54,    10,    27,    28,    36,     9,    11,
      12,     0,   133,    42,    43,    22,    45,   124,    10,    10,
     127,    72,    10,    28,    10,    34,    53,    36,    34,    44,
      57,    58,    27,    28,    55,    37,   157,    42,   159,    90,
      41,    68,    34,    34,    36,    36,    34,    45,    34,     8,
     171,     3,     4,    48,    37,    76,    11,    12,   179,   180,
     181,   182,    89,    45,    23,    24,    25,    36,    27,    28,
      13,    14,    15,    32,    33,    80,    36,    36,    42,    38,
      39,    40,    45,    42,    43,   106,    45,    34,     8,     5,
       6,    32,    11,    12,    42,   116,    35,    16,    17,    18,
      19,    20,    21,    23,    24,    25,    37,    27,    28,   130,
     131,   132,    32,    33,    42,    43,    36,    41,    38,    39,
      40,     8,    42,    43,    45,    45,    36,    57,    58,    37,
     151,    35,    42,    43,    32,    45,    23,    24,    25,    34,
      27,    28,   163,    35,     8,    32,    33,    37,    41,    36,
      32,    38,    39,    40,    35,    42,    43,    33,    45,    23,
      24,    25,    36,    27,    28,    36,    36,     8,    32,    33,
      36,     9,    36,     9,    38,    39,    40,    45,    42,    43,
       9,    45,    23,    24,    25,     9,    27,    28,    45,    37,
      37,    32,     9,    37,    33,    36,    33,    38,    39,    40,
      32,    42,    43,    33,    45,    32,    32,     9,     7,    37,
      33,    26,     7,     7,    32,    80,    32,    42,     6,    -1,
      51,    67,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,    52,     0,    44,    51,    56,    27,    28,    48,
      53,    57,    58,    68,    69,    22,    45,    45,    70,    36,
      36,    10,    34,    36,    71,     9,    41,    37,    62,    36,
      42,    43,    45,    82,    83,    84,    85,    86,    87,    88,
      92,    42,    59,    34,    45,    32,    27,    65,    66,    67,
      69,    45,    85,    10,    34,    36,    72,     3,     4,    11,
      12,    16,    17,    18,    19,    20,    21,    89,    91,    13,
      14,    15,    90,    35,    65,    42,    10,    71,    54,    37,
      41,    45,    72,    37,    85,    87,    82,    93,    94,    10,
      34,    84,    85,    84,    86,    85,    87,    37,    35,    82,
      73,    74,    32,    67,    35,    37,    41,    85,    87,    32,
      55,     8,    23,    24,    25,    32,    38,    39,    40,    68,
      69,    75,    81,    82,    63,    82,    35,    60,    33,    36,
      36,    36,    36,    76,    82,     9,     9,    45,     9,     9,
      73,    73,    45,    82,    82,    82,    74,    64,    61,    37,
      37,     9,    37,    77,    33,    33,    32,    32,    82,    32,
      33,    79,    74,     9,    74,     5,     6,    80,    33,    82,
      33,     7,    42,    43,    33,    26,    78,    37,    74,     7,
       7,    32,    32,    74,    74,    74,    74,    33,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    51,    50,    52,    52,    54,    55,    53,    56,
      56,    57,    57,    59,    60,    61,    58,    62,    63,    64,
      58,    65,    65,    66,    66,    67,    68,    69,    69,    70,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    73,
      74,    74,    76,    77,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    78,    78,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    82,    82,    83,    83,    83,
      84,    85,    85,    86,    86,    87,    87,    87,    87,    87,
      88,    88,    89,    89,    90,    90,    90,    91,    91,    91,
      91,    91,    91,    92,    93,    93,    94,    94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     2,     0,     0,     0,     9,     2,
       0,     1,     1,     0,     0,     0,    11,     0,     0,     0,
      11,     1,     0,     3,     1,     2,     3,     1,     1,     1,
       3,     5,     3,     2,     4,     3,     4,     3,     4,     1,
       2,     0,     0,     0,     5,     1,     2,     2,     2,     2,
       8,    11,     7,     8,     4,     0,     5,     5,     0,     3,
       0,     1,     2,     1,     1,     3,     4,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     0,     3,     1
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
#line 30 "bison.y" /* yacc.c:1646  */
    {scope=0;}
#line 1406 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 36 "bison.y" /* yacc.c:1646  */
    {

    }
#line 1414 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 43 "bison.y" /* yacc.c:1646  */
    {scope=2; enter_func("main","int",active_func_ptr);}
#line 1420 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 43 "bison.y" /* yacc.c:1646  */
    {}
#line 1426 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 52 "bison.y" /* yacc.c:1646  */
    {
    }
#line 1433 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 59 "bison.y" /* yacc.c:1646  */
    {scope++;
        active_type = dt_none;
        enter_func(((yyvsp[-1].datanode))->value,((yyvsp[-2].datanode))->value,active_func_ptr);
    }
#line 1442 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 64 "bison.y" /* yacc.c:1646  */
    {  
        scope++;
    }
#line 1450 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 68 "bison.y" /* yacc.c:1646  */
    {scope=0;}
#line 1456 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 71 "bison.y" /* yacc.c:1646  */
    {scope++;
        enter_func(((yyvsp[-1].datanode))->value,"void",active_func_ptr);
    }
#line 1464 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 75 "bison.y" /* yacc.c:1646  */
    {  
        scope++;
    }
#line 1472 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 79 "bison.y" /* yacc.c:1646  */
    {scope=0;}
#line 1478 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 95 "bison.y" /* yacc.c:1646  */
    {   
        var *param;
        enter_param(((yyvsp[0].datanode))->value,((yyvsp[-1].datanode))->value,active_func_ptr,param);
        active_type = dt_none;
    }
#line 1488 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 103 "bison.y" /* yacc.c:1646  */
    {
        patch_type(((yyvsp[-2].datanode))->value);
        active_type = dt_none;
    }
#line 1497 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 110 "bison.y" /* yacc.c:1646  */
    { 
        active_type = dt_int;
        (yyval.datanode) = (yyvsp[0].datanode);
    }
#line 1506 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 115 "bison.y" /* yacc.c:1646  */
    {
        active_type = dt_float;
        (yyval.datanode) = (yyvsp[0].datanode);
    }
#line 1515 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 122 "bison.y" /* yacc.c:1646  */
    {
        enter_var(((yyvsp[0].datanode))->value,scope,"simple",dimlist,active_func_ptr);
    }
#line 1523 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 125 "bison.y" /* yacc.c:1646  */
    {
        bool chk = check_type((yyvsp[-2].datanode), (yyvsp[0].datanode));
        if (chk)
            enter_var(((yyvsp[-2].datanode))->value,scope,"simple",dimlist,active_func_ptr);
    }
#line 1533 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 130 "bison.y" /* yacc.c:1646  */
    {
        bool chk = check_type((yyvsp[-2].datanode), (yyvsp[0].datanode));
        if (chk)
            enter_var(((yyvsp[-2].datanode))->value,scope,"simple",dimlist,active_func_ptr);
    }
#line 1543 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 136 "bison.y" /* yacc.c:1646  */
    {   enter_var(((yyvsp[0].datanode))->value,scope,"simple",dimlist,active_func_ptr);}
#line 1549 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 138 "bison.y" /* yacc.c:1646  */
    {   enter_var(((yyvsp[-1].datanode))->value,scope,"array",dimlist,active_func_ptr);}
#line 1555 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 140 "bison.y" /* yacc.c:1646  */
    {   enter_var(((yyvsp[-1].datanode))->value,scope,"array",dimlist,active_func_ptr);}
#line 1561 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 144 "bison.y" /* yacc.c:1646  */
    {dimlist.push_back(stoi(((yyvsp[-1].datanode))->value));}
#line 1567 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 145 "bison.y" /* yacc.c:1646  */
    {dimlist.push_back(stoi(((yyvsp[-1].datanode))->value));}
#line 1573 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 164 "bison.y" /* yacc.c:1646  */
    {
        scope++;   
    }
#line 1581 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 168 "bison.y" /* yacc.c:1646  */
    {
        scope--;
    }
#line 1589 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 201 "bison.y" /* yacc.c:1646  */
    {
        DataNode *res = new DataNode();
        res->data_type = dt_none;
        (yyval.datanode) = res;
    }
#line 1599 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 206 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = check_func_return_type((yyvsp[0].datanode));}
#line 1605 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 210 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1611 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 211 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1617 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 212 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = checkType((yyvsp[-2].datanode),(yyvsp[0].datanode));}
#line 1623 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 213 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = checkType((yyvsp[-3].datanode),(yyvsp[0].datanode));}
#line 1629 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 217 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1635 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 218 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1641 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 219 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1647 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 224 "bison.y" /* yacc.c:1646  */
    {
        DataNode *res = new DataNode();
        res->data_type = dt_bool;
        (yyval.datanode) = res;
    }
#line 1657 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 232 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = typecaster((yyvsp[-2].datanode),(yyvsp[0].datanode));}
#line 1663 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 233 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1669 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 237 "bison.y" /* yacc.c:1646  */
    { (yyval.datanode) = typecaster((yyvsp[-2].datanode),(yyvsp[0].datanode));}
#line 1675 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 238 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1681 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 242 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[-1].datanode);}
#line 1687 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 243 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1693 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 244 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1699 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 245 "bison.y" /* yacc.c:1646  */
    {set_data_type((yyvsp[0].datanode)); (yyval.datanode) = (yyvsp[0].datanode);}
#line 1705 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 247 "bison.y" /* yacc.c:1646  */
    {
        set_data_type((yyvsp[-1].datanode));
        (yyval.datanode) = (yyvsp[-1].datanode);
        ((yyval.datanode))->type = "Array";
    }
#line 1715 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 255 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1721 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 256 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1727 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 281 "bison.y" /* yacc.c:1646  */
    {
        DataNode* func = check_func_call(((yyvsp[-3].datanode))->value);
        param_list.clear();
        (yyval.datanode) = func;
    }
#line 1737 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 294 "bison.y" /* yacc.c:1646  */
    {param_list.push_back(((yyvsp[0].datanode))->data_type);}
#line 1743 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 295 "bison.y" /* yacc.c:1646  */
    {param_list.push_back(((yyvsp[0].datanode))->data_type);}
#line 1749 "bison.tab.c" /* yacc.c:1646  */
    break;


#line 1753 "bison.tab.c" /* yacc.c:1646  */
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
#line 298 "bison.y" /* yacc.c:1906  */


int yyerror(char *s)
{
  extern char *yytext;
  printf("Line No.%d ERROR: %s at symbol %s\n",yylineno, s, yytext);
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

    for(auto i = var_list.begin(); i!=var_list.end(); i++){
         cout<< *i <<endl;
    }

    cout << "Symbol Table\n";
    for (auto it: sym_tab) {
        cout << it.first << " ";
        it.second.print();
    }

    cout << "Function Table\n";
    for (auto it: func_table) {
        cout << it.first << " ";
        it.second.print();
    }

	return 0;
}
