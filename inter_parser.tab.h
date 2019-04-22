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

#ifndef YY_YY_INTER_PARSER_TAB_H_INCLUDED
# define YY_YY_INTER_PARSER_TAB_H_INCLUDED
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
    RESULT = 258,
    PAR_AM = 259,
    PARAM = 260,
    LB = 261,
    VAR = 262,
    RB = 263,
    ADDR = 264,
    CALL = 265,
    FLOAT_VAL = 266,
    INT_VALUE = 267,
    REG = 268,
    AND = 269,
    OR = 270,
    ID = 271,
    LS = 272,
    RS = 273,
    EQUALS = 274,
    ADD = 275,
    SUB = 276,
    MUL = 277,
    DIV = 278,
    MOD = 279,
    GT = 280,
    LT = 281,
    GE = 282,
    LE = 283,
    COMP = 284,
    COLON = 285,
    NEQ = 286,
    COMMA = 287,
    IF = 288,
    GOTO = 289,
    LABEL = 290,
    WHITESPACE = 291,
    NEWLINE = 292,
    FUNC = 293,
    BEG = 294,
    END = 295,
    MAIN = 296,
    RETURN = 297,
    SEMICOL = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 41 "inter_parser.y" /* yacc.c:1909  */

	struct DataNode *datanode;

#line 102 "inter_parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INTER_PARSER_TAB_H_INCLUDED  */
