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
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

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
       0,    30,    30,    29,    36,    39,    45,    51,    43,    60,
      61,    65,    67,    72,    77,    81,    72,    84,    88,    92,
      84,    98,    99,   103,   104,   108,   116,   123,   128,   135,
     138,   144,   149,   151,   153,   158,   159,   163,   168,   184,
     188,   189,   194,   198,   193,   203,   204,   205,   206,   207,
     208,   209,   208,   214,   214,   218,   218,   222,   235,   222,
     240,   252,   240,   260,   260,   264,   268,   269,   273,   274,
     278,   284,   288,   289,   290,   291,   295,   296,   297,   301,
     310,   311,   315,   316,   320,   321,   322,   323,   330,   364,
     365,   369,   370,   374,   375,   376,   380,   381,   382,   383,
     384,   385,   389,   398,   399,   403,   404
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
  "body", "stmt_list", "stmt", "$@10", "$@11", "$@12", "$@13", "$@14",
  "$@15", "$@16", "$@17", "$@18", "$@19", "else_stmt", "$@20", "case_stmt",
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

#define YYPACT_NINF -129

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-129)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -129,     6,   -31,  -129,  -129,  -129,     1,    -6,  -129,   -23,
    -129,  -129,  -129,  -129,   -19,    12,    20,    -1,    -5,    -7,
    -129,    16,    18,  -129,    30,  -129,    38,    54,    -9,    48,
    -129,  -129,    10,  -129,    47,  -129,    61,    53,  -129,  -129,
    -129,    52,    -9,    55,     7,  -129,  -129,    57,    58,  -129,
      44,   -24,     3,    48,    48,    16,    11,    48,    48,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,    48,    48,  -129,
    -129,  -129,    48,  -129,    59,    63,    16,    30,  -129,    68,
      -9,  -129,    67,  -129,    42,    71,  -129,    77,    74,    48,
      48,  -129,    61,  -129,    53,    42,  -129,    70,  -129,  -129,
    -129,   185,  -129,  -129,  -129,  -129,    16,    42,    82,  -129,
      88,    90,    91,    92,    93,  -129,    16,   121,   123,  -129,
      89,  -129,   124,   126,  -129,  -129,  -129,  -129,  -129,    97,
      16,    16,    16,  -129,  -129,  -129,  -129,    13,  -129,  -129,
    -129,  -129,   102,   100,   129,   109,   185,   117,   118,    67,
     120,   128,    16,   133,   135,  -129,  -129,   132,   141,  -129,
     144,  -129,  -129,   142,  -129,  -129,    16,  -129,  -129,  -129,
      80,   143,   116,  -129,    65,  -129,   151,  -129,    65,   169,
     146,   158,   166,  -129,   163,  -129,   190,  -129,   167,  -129,
    -129,  -129,   185,  -129,  -129,   139,   185,  -129,  -129,   162,
    -129
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     2,     1,     4,    10,     0,    27,    28,     0,
       3,     9,    12,    11,     0,     0,     0,    29,     0,     0,
      17,     0,     0,    13,    33,    26,     0,     0,    22,     0,
      89,    90,    87,    30,    73,    78,    72,    81,    83,    86,
      85,     0,    22,     0,    32,     6,    27,     0,    21,    24,
       0,    87,     0,     0,     0,   104,    88,     0,     0,    91,
      92,    96,    97,    98,    99,   100,   101,     0,     0,    93,
      94,    95,     0,    35,     0,     0,     0,    34,    41,     0,
       0,    25,    88,    84,    74,     0,   106,     0,   103,     0,
       0,    76,     0,    77,    80,    79,    82,     0,    36,    31,
       7,    39,    18,    23,    37,   102,     0,    75,     0,    14,
       0,     0,     0,     0,     0,    42,    70,     0,     0,    45,
       0,    40,     0,     0,    41,   105,    38,    41,     8,     0,
       0,     0,     0,    41,    71,    48,    47,    29,    49,    46,
      19,    15,    57,     0,     0,     0,    43,     0,     0,    60,
       0,     0,     0,     0,     0,    20,    16,     0,     0,    50,
       0,    55,    44,     0,    58,    41,     0,    41,    61,    67,
       0,     0,     0,    67,    69,    51,     0,    56,    69,     0,
       0,     0,    65,    53,     0,    41,     0,    59,     0,    52,
      41,    62,    68,    41,    63,     0,    66,    41,    54,     0,
      64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,   161,  -129,   131,   200,
      -4,  -129,   170,   -50,  -116,  -128,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,    43,
      37,  -129,   -21,  -129,    17,   -26,   152,   -47,  -129,  -129,
    -129,  -129,  -129,  -129,  -129
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     5,     2,    10,    78,   110,     6,    11,    12,
      42,   127,   148,    28,   124,   147,    47,    48,    49,   119,
     120,    18,    24,    56,   100,   101,   121,   133,   154,   165,
     182,   190,   167,   150,   169,   157,   173,   189,   197,   174,
     181,   122,   123,    34,    35,    36,    37,    38,    39,    67,
      72,    68,    40,    87,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    82,    14,    52,    25,   146,     3,    85,   140,    21,
      54,   141,    55,     4,    59,    60,    15,    76,    46,     8,
      53,    89,    16,    21,    50,    96,    17,    84,     7,     8,
      27,    92,    92,    22,    86,    23,    26,   170,    50,   172,
      83,    22,    95,   108,    54,    90,    55,    22,    19,     9,
      57,    58,    29,    59,    60,    99,    20,   192,    30,    31,
      41,    32,   195,   107,    43,   196,    69,    70,    71,   199,
     179,   180,    59,    60,    91,    93,    50,    61,    62,    63,
      64,    65,    66,    44,    29,   125,    45,    73,   111,    81,
      30,    31,   149,    51,    79,   134,    97,    75,    98,    80,
     102,    90,   109,   112,   113,   114,   104,    46,     8,   143,
     144,   145,   115,   175,   105,   106,    29,   126,   116,   117,
     118,   128,    30,    31,   111,    32,   129,   130,   131,   132,
     135,   160,   136,   138,   137,   139,    54,   151,   152,   112,
     113,   114,   142,    46,     8,   171,   153,   111,   115,   177,
     155,   156,    29,   166,   116,   117,   118,   158,    30,    31,
     159,    32,   112,   113,   114,   161,    46,     8,   162,   163,
     111,   115,   198,   164,   168,    29,   185,   116,   117,   118,
     176,    30,    31,   183,    32,   112,   113,   114,   186,    46,
       8,   187,   188,   111,   115,   200,   191,   193,    29,   194,
     116,   117,   118,    74,    30,    31,    13,    32,   112,   113,
     114,   103,    46,     8,    77,   184,   178,   115,     0,    94,
       0,    29,     0,   116,   117,   118,     0,    30,    31,     0,
      32
};

static const yytype_int16 yycheck[] =
{
      21,    51,     6,    29,     9,   133,     0,    54,   124,    10,
      34,   127,    36,    44,    11,    12,    22,    10,    27,    28,
      10,    10,    45,    10,    28,    72,    45,    53,    27,    28,
      37,    57,    58,    34,    55,    36,    41,   165,    42,   167,
      37,    34,    68,    90,    34,    34,    36,    34,    36,    48,
       3,     4,    36,    11,    12,    76,    36,   185,    42,    43,
      42,    45,   190,    89,    34,   193,    13,    14,    15,   197,
       5,     6,    11,    12,    57,    58,    80,    16,    17,    18,
      19,    20,    21,    45,    36,   106,    32,    35,     8,    45,
      42,    43,   142,    45,    37,   116,    37,    42,    35,    41,
      32,    34,    32,    23,    24,    25,    35,    27,    28,   130,
     131,   132,    32,    33,    37,    41,    36,    35,    38,    39,
      40,    33,    42,    43,     8,    45,    36,    36,    36,    36,
       9,   152,     9,     9,    45,     9,    34,    37,     9,    23,
      24,    25,    45,    27,    28,   166,    37,     8,    32,    33,
      33,    33,    36,     9,    38,    39,    40,    37,    42,    43,
      32,    45,    23,    24,    25,    32,    27,    28,    33,    37,
       8,    32,    33,    32,    32,    36,     7,    38,    39,    40,
      37,    42,    43,    32,    45,    23,    24,    25,    42,    27,
      28,    33,    26,     8,    32,    33,    33,     7,    36,    32,
      38,    39,    40,    42,    42,    43,     6,    45,    23,    24,
      25,    80,    27,    28,    44,   178,   173,    32,    -1,    67,
      -1,    36,    -1,    38,    39,    40,    -1,    42,    43,    -1,
      45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,    52,     0,    44,    51,    56,    27,    28,    48,
      53,    57,    58,    68,    69,    22,    45,    45,    70,    36,
      36,    10,    34,    36,    71,     9,    41,    37,    62,    36,
      42,    43,    45,    91,    92,    93,    94,    95,    96,    97,
     101,    42,    59,    34,    45,    32,    27,    65,    66,    67,
      69,    45,    94,    10,    34,    36,    72,     3,     4,    11,
      12,    16,    17,    18,    19,    20,    21,    98,   100,    13,
      14,    15,    99,    35,    65,    42,    10,    71,    54,    37,
      41,    45,    72,    37,    94,    96,    91,   102,   103,    10,
      34,    93,    94,    93,    95,    94,    96,    37,    35,    91,
      73,    74,    32,    67,    35,    37,    41,    94,    96,    32,
      55,     8,    23,    24,    25,    32,    38,    39,    40,    68,
      69,    75,    90,    91,    63,    91,    35,    60,    33,    36,
      36,    36,    36,    76,    91,     9,     9,    45,     9,     9,
      73,    73,    45,    91,    91,    91,    74,    64,    61,    72,
      82,    37,     9,    37,    77,    33,    33,    84,    37,    32,
      91,    32,    33,    37,    32,    78,     9,    81,    32,    83,
      74,    91,    74,    85,    88,    33,    37,    33,    88,     5,
       6,    89,    79,    32,    89,     7,    42,    33,    26,    86,
      80,    33,    74,     7,    32,    74,    74,    87,    33,    74,
      33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    51,    50,    52,    52,    54,    55,    53,    56,
      56,    57,    57,    59,    60,    61,    58,    62,    63,    64,
      58,    65,    65,    66,    66,    67,    68,    69,    69,    70,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    73,
      74,    74,    76,    77,    75,    75,    75,    75,    75,    75,
      78,    79,    75,    80,    75,    81,    75,    82,    83,    75,
      84,    85,    75,    87,    86,    86,    88,    88,    89,    89,
      90,    90,    91,    91,    91,    91,    92,    92,    92,    93,
      94,    94,    95,    95,    96,    96,    96,    96,    96,    97,
      97,    98,    98,    99,    99,    99,   100,   100,   100,   100,
     100,   100,   101,   102,   102,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     2,     0,     0,     0,     9,     2,
       0,     1,     1,     0,     0,     0,    11,     0,     0,     0,
      11,     1,     0,     3,     1,     2,     3,     1,     1,     1,
       3,     5,     3,     2,     4,     3,     4,     3,     4,     1,
       2,     0,     0,     0,     5,     1,     2,     2,     2,     2,
       0,     0,    10,     0,    12,     0,     8,     0,     0,    10,
       0,     0,    11,     0,     5,     0,     5,     0,     3,     0,
       1,     2,     1,     1,     3,     4,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     0,     3,     1
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
#line 1420 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 36 "bison.y" /* yacc.c:1646  */
    {

    }
#line 1428 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 45 "bison.y" /* yacc.c:1646  */
    {
        scope=2; 
        enter_func("main","int",active_func_ptr);
        // file << "func begin main\n";
    }
#line 1438 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 51 "bison.y" /* yacc.c:1646  */
    {
        // release_var(active_func_ptr,scope);
        scope--;
        // file << "func end\n";
    }
#line 1448 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 65 "bison.y" /* yacc.c:1646  */
    {
    }
#line 1455 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 72 "bison.y" /* yacc.c:1646  */
    {scope++;
        active_type = dt_none;
        enter_func(((yyvsp[-1].datanode))->value,((yyvsp[-2].datanode))->value,active_func_ptr);
    }
#line 1464 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 77 "bison.y" /* yacc.c:1646  */
    {                  
        scope++;
    }
#line 1472 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 81 "bison.y" /* yacc.c:1646  */
    {release_var(active_func_ptr,2),scope=0;}
#line 1478 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 84 "bison.y" /* yacc.c:1646  */
    {scope++;
        enter_func(((yyvsp[-1].datanode))->value,"void",active_func_ptr);
    }
#line 1486 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 88 "bison.y" /* yacc.c:1646  */
    {  
        scope++;
    }
#line 1494 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 92 "bison.y" /* yacc.c:1646  */
    {release_var(active_func_ptr,2),scope=0;}
#line 1500 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 108 "bison.y" /* yacc.c:1646  */
    {   
        var *param;
        enter_param(((yyvsp[0].datanode))->value,((yyvsp[-1].datanode))->value,active_func_ptr,param);
        active_type = dt_none;
    }
#line 1510 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 116 "bison.y" /* yacc.c:1646  */
    {
        patch_type(((yyvsp[-2].datanode))->value);
        active_type = dt_none;
    }
#line 1519 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 123 "bison.y" /* yacc.c:1646  */
    { 
        active_type = dt_int;
        (yyval.datanode) = (yyvsp[0].datanode);
    }
#line 1528 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 128 "bison.y" /* yacc.c:1646  */
    {
        active_type = dt_float;
        (yyval.datanode) = (yyvsp[0].datanode);
    }
#line 1537 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 135 "bison.y" /* yacc.c:1646  */
    {
        enter_var(((yyvsp[0].datanode))->value,scope,"simple",dimlist,active_func_ptr);
    }
#line 1545 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 138 "bison.y" /* yacc.c:1646  */
    {
        bool chk = check_type((yyvsp[-2].datanode), (yyvsp[0].datanode));
        if (chk) {
            enter_var(((yyvsp[-2].datanode))->value,scope,"simple",dimlist,active_func_ptr);
        }
    }
#line 1556 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 144 "bison.y" /* yacc.c:1646  */
    {
        bool chk = check_type((yyvsp[-2].datanode), (yyvsp[0].datanode));
        if (chk)
            enter_var(((yyvsp[-2].datanode))->value,scope,"simple",dimlist,active_func_ptr);
    }
#line 1566 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 150 "bison.y" /* yacc.c:1646  */
    {   enter_var(((yyvsp[0].datanode))->value,scope,"simple",dimlist,active_func_ptr);}
#line 1572 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 152 "bison.y" /* yacc.c:1646  */
    {   enter_var(((yyvsp[-1].datanode))->value,scope,"array",dimlist,active_func_ptr);}
#line 1578 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 154 "bison.y" /* yacc.c:1646  */
    {   enter_var(((yyvsp[-1].datanode))->value,scope,"array",dimlist,active_func_ptr);}
#line 1584 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 158 "bison.y" /* yacc.c:1646  */
    {dimlist.push_back(stoi(((yyvsp[-1].datanode))->value));}
#line 1590 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 159 "bison.y" /* yacc.c:1646  */
    {dimlist.push_back(stoi(((yyvsp[-1].datanode))->value));}
#line 1596 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 164 "bison.y" /* yacc.c:1646  */
    {
        dim_count++;
        // dimlist_call.push_back($2->code_name);
    }
#line 1605 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 169 "bison.y" /* yacc.c:1646  */
    {
      //  $1->code_name*dimlist_call[dim_count]+$3->code_name;
        // string temp_name = get_temp_name();
        // string temp_name2 = get_temp_name();
        // file << temp_name << " = " << $1->code_name << " * " << dimlist_call[dim_count] << endl;
        // file << temp_name2 << " = " << temp_name << " + " << $3->code_name;
        // release_temp_name(temp_name);
        // release_temp_name($3->code_name);
        // $$->code_name = temp_name2;
        // dimlist_call.push_back($3->code_name);
        dim_count++;
    }
#line 1622 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 194 "bison.y" /* yacc.c:1646  */
    {
        scope++;   
    }
#line 1630 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 198 "bison.y" /* yacc.c:1646  */
    {   
        release_var(active_func_ptr,scope);
        scope--;
    }
#line 1639 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 208 "bison.y" /* yacc.c:1646  */
    {scope++;}
#line 1645 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 209 "bison.y" /* yacc.c:1646  */
    {
            release_var(active_func_ptr,scope);
            scope--;
        }
#line 1654 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 214 "bison.y" /* yacc.c:1646  */
    {scope++;}
#line 1660 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 214 "bison.y" /* yacc.c:1646  */
    { 
            release_var(active_func_ptr,scope);
            scope--;
        }
#line 1669 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 218 "bison.y" /* yacc.c:1646  */
    {scope++;}
#line 1675 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 218 "bison.y" /* yacc.c:1646  */
    {
            release_var(active_func_ptr,scope);
            scope--;
        }
#line 1684 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 222 "bison.y" /* yacc.c:1646  */
    {
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
            
        }
#line 1702 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 235 "bison.y" /* yacc.c:1646  */
    { scope++; }
#line 1708 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 236 "bison.y" /* yacc.c:1646  */
    { 
            release_var(active_func_ptr,scope);
            scope--;
        }
#line 1717 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 240 "bison.y" /* yacc.c:1646  */
    {
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
        }
#line 1734 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 252 "bison.y" /* yacc.c:1646  */
    { scope++; }
#line 1740 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 253 "bison.y" /* yacc.c:1646  */
    { 
            release_var(active_func_ptr,scope);
            scope--;
        }
#line 1749 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 260 "bison.y" /* yacc.c:1646  */
    {scope++;}
#line 1755 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 260 "bison.y" /* yacc.c:1646  */
    {
        release_var(active_func_ptr,scope);
        scope--;
    }
#line 1764 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 279 "bison.y" /* yacc.c:1646  */
    {
        DataNode *res = new DataNode();
        res->data_type = dt_none;
        (yyval.datanode) = res;
    }
#line 1774 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 284 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = check_func_return_type((yyvsp[0].datanode));}
#line 1780 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 288 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1786 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 289 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1792 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 290 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = checkType((yyvsp[-2].datanode),(yyvsp[0].datanode));}
#line 1798 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 291 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = checkType((yyvsp[-3].datanode),(yyvsp[0].datanode));}
#line 1804 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 295 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1810 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 296 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1816 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 297 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1822 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 302 "bison.y" /* yacc.c:1646  */
    {
        DataNode *res = new DataNode();
        res->data_type = dt_bool;
        (yyval.datanode) = res;
    }
#line 1832 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 310 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = typecaster((yyvsp[-2].datanode),(yyvsp[0].datanode));}
#line 1838 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 311 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1844 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 315 "bison.y" /* yacc.c:1646  */
    { (yyval.datanode) = typecaster((yyvsp[-2].datanode),(yyvsp[0].datanode));}
#line 1850 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 316 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1856 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 320 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[-1].datanode);}
#line 1862 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 321 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1868 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 322 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode);}
#line 1874 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 324 "bison.y" /* yacc.c:1646  */
    {
        set_data_type((yyvsp[0].datanode)); 
        (yyval.datanode) = (yyvsp[0].datanode);
        // $$->code_name = get_var_code_name($1->value);

    }
#line 1885 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 331 "bison.y" /* yacc.c:1646  */
    {
        dim_count = 0;
        
        set_data_type((yyvsp[-1].datanode));
        
        (yyval.datanode) = (yyvsp[-1].datanode);
        ((yyval.datanode))->type = "array";

        // string temp_name = get_temp_name();
        // string temp_name3 = get_temp_name();
        // string temp_name4 = get_temp_name();
        // string temp_name5 = get_temp_name();  
        // string temp_name2;      
        // vector<int> temp_dim_list = get_dimlist($1->value);
        // for (int i = 0; i < temp_dim_list.size()-1; i++) {
        //     temp_name2 = get_temp_name();    
        //     file << temp_name << " = " << dimlist_call[i] << " * " << temp_dim_list[i+1] << endl;
        //     file << temp_name2 << " = " << temp_name << " + " << dimlist_call[i+1];
        //     release_temp_name(temp_name);
        //     temp_name = temp_name2;
        // }
        // file << temp_name3 << " = " << temp_name2 << " * 4\n";
        // file << temp_name4 << " = " << "addr(" << get_var_code_name($1->value) << ")" << endl;
        // file << temp_name5 << " = " << temp_name4 << "[" << temp_name3 <<"]" << endl;
        // release_temp_name(temp_name2);
        // release_temp_name(temp_name3);
        // release_temp_name(temp_name4);
        // temp_dim_list.clear();
        // $$->code_name = temp_name5;
    }
#line 1920 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 364 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 1926 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 365 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 1932 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 369 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 1938 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 370 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 1944 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 374 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 1950 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 375 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 1956 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 376 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 1962 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 380 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 1968 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 381 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 1974 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 382 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 1980 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 383 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 1986 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 384 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 1992 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 385 "bison.y" /* yacc.c:1646  */
    {(yyval.datanode) = (yyvsp[0].datanode); (yyval.datanode)->code_name = (yyvsp[0].datanode)->value;}
#line 1998 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 390 "bison.y" /* yacc.c:1646  */
    {
        DataNode* func = check_func_call(((yyvsp[-3].datanode))->value);
        param_list.clear();
        (yyval.datanode) = func;
    }
#line 2008 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 403 "bison.y" /* yacc.c:1646  */
    {param_list.push_back(((yyvsp[0].datanode))->data_type);}
#line 2014 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 404 "bison.y" /* yacc.c:1646  */
    {param_list.push_back(((yyvsp[0].datanode))->data_type);}
#line 2020 "bison.tab.c" /* yacc.c:1646  */
    break;


#line 2024 "bison.tab.c" /* yacc.c:1646  */
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
#line 407 "bison.y" /* yacc.c:1906  */


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
