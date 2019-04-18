/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    SEMICOL = 260,
    EQUALS = 261,
    ADD = 262,
    SUB = 263,
    MUL = 264,
    DIV = 265,
    MOD = 266,
    GT = 267,
    LT = 268,
    GE = 269,
    LE = 270,
    COMP = 271,
    NEQ = 272,
    MAIN = 273,
    IF = 274,
    FOR = 275,
    WHILE = 276,
    ELSE = 277,
    INT = 278,
    FLOAT = 279,
    TRUE = 280,
    FALSE = 281,
    BOOL = 282,
    LP = 283,
    RP = 284,
    LS = 285,
    RS = 286,
    LB = 287,
    RB = 288,
    RETURN = 289,
    BREAK = 290,
    CONTINUE = 291,
    COMMA = 292,
    INT_VALUE = 293,
    FLOAT_VAL = 294,
    LIBRARY = 295,
    ID = 296,
    NEWLINE = 297,
    WHITESPACE = 298,
    VOID = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "bison.y" /* yacc.c:1909  */

	struct DataNode *datanode;

#line 103 "bison.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */
