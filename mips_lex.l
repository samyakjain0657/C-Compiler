%{

	#include <bits/stdc++.h>
	#include "inter_parser.tab.h"

	using namespace std;

    enum DataType{
        dt_none,
        dt_int,
        dt_float,
        dt_func,
        dt_err
    };

    struct DataNode {
        string type;			// lexeme class
        string value;			// lexeme
        DataType data_type;		// datatype of the Datanode(if required)
        string code_name;
        string type1;

        DataNode (string t, string v) {
            type = t;
            value = v;
            data_type = dt_none;
        }
    };

%}
%option yylineno
%option noyywrap

LB		"("
RB		")"
LS      "["
RS      "]"
EQUALS	"="
ADD		"+"
SUB		"-"
MUL		"*"
DIV		"/"
MOD		"%"
GT		">"
LT		"<"
GE		">="
LE		"<="
COMP	"=="
COLON   ":"
NEQ 	("!=")
COMMA 	","
IF 		"if"
GOTO    "goto"
WHITESPACE 			([ \t]+)
NEWLINE 			([\n])
FUNC    "func"
BEG     "begin"
REG 	([$][t]([0-9])+)
FREG     ([$][f]([0-9])+)
END     "end"
CALL    "call"
VAR		([_][v][a][r]([0-9])+)
FVAR		([_][f][v][a][r]([0-9])+)
PAR_AM  ([_][p][a][r][a][m]([0-9])+)
RESULT  ([_][r][e][s][u][l][t]([0-9])+)
FRESULT  ([_][f][r][e][s][u][l][t]([0-9])+)
INT_VALUE 			([0-9]+)
FLOAT_VAL			([0-9]+\.[0-9]+)
AND     "&&"
OR      "||"
ADDR    "addr"
MAIN    "main"
ID      ([A-Za-z_]([A-Za-z0-9_])*)
RETURN  "return"
SEMICOL ";"
CONVERT "convert"

%%

{EQUALS}		{return EQUALS;}
{ADD} 			{(yylval.datanode) = new DataNode("INT", yytext); 
                return ADD;}
{SUB} 			{(yylval.datanode) = new DataNode("INT", yytext); 
                return SUB;}
{MUL} 			{(yylval.datanode) = new DataNode("INT", yytext); 
                return MUL;}
{DIV} 			{(yylval.datanode) = new DataNode("INT", yytext); 
                return DIV;}
{MOD} 			{(yylval.datanode) = new DataNode("INT", yytext); 
                return MOD;}
{GT} 			{(yylval.datanode) = new DataNode("GT", yytext); 
                return GT;}
{LT} 			{(yylval.datanode) = new DataNode("LT", yytext); 
                return LT;}
{GE} 			{(yylval.datanode) = new DataNode("GE", yytext); 
                return GE;}
{LE} 			{(yylval.datanode) = new DataNode("LE", yytext); 
                return LE;}
{COMP} 			{(yylval.datanode) = new DataNode("COMP", yytext); 
                return COMP;}
{NEQ} 			{(yylval.datanode) = new DataNode("NEQ", yytext); 
                return NEQ;}
{LS}	    	{return LS;}
{RS}		    {return RS;}
{LB}		    {return LB;}
{RB}		    {return RB;}
{IF} 			{return IF;}
{GOTO} 			{return GOTO;}
{FUNC}          {return FUNC;}
{BEG}           {return BEG;}
{END}           {return END;}
{AND}           {return AND;}
{OR}            {return OR;}
{COMMA}			{return COMMA;}
{CALL}          {return CALL;} 
{COLON}         {return COLON;}
{ADDR}          {return ADDR;}
{MAIN}          {return MAIN;}
{RETURN}        {return RETURN;}
{SEMICOL}       {return SEMICOL;}
param           {return PARAM;}
{CONVERT}       {return CONVERT;}
{REG}           {(yylval.datanode) = new DataNode("REG", yytext); 
                return REG;}
{FREG}           {(yylval.datanode) = new DataNode("FREG", yytext); 
                return FREG;}
{INT_VALUE}		{(yylval.datanode) = new DataNode("INT_VALUE", yytext); 
                yylval.datanode->data_type = (dt_int); 
                return INT_VALUE;}
{FLOAT_VAL}		{(yylval.datanode) = new DataNode("FLOAT_VAL", yytext); 
                yylval.datanode->data_type = (dt_float); 
                return FLOAT_VAL;}
(LF|LS|LT|LJ|IFF|IFT|SF|S([0-9]+)CT|IFS)([0-9]+) {(yylval.datanode) = new DataNode("LABEL", yytext); 
                return LABEL;}
{VAR}			{(yylval.datanode) = new DataNode("VAR", yytext); 
                return VAR;}
{FVAR}			{(yylval.datanode) = new DataNode("FVAR", yytext); 
                return FVAR;}
{PAR_AM}	    {(yylval.datanode) = new DataNode("PAR_AM", yytext); 
                return PAR_AM;}
{RESULT}        {(yylval.datanode) = new DataNode("RESULT", yytext); 
                return RESULT;}
{FRESULT}        {(yylval.datanode) = new DataNode("FRESULT", yytext); 
                return FRESULT;}
{ID}			{(yylval.datanode) = new DataNode("ID", yytext); 
                return ID;}
{NEWLINE} 		{}
{WHITESPACE}	{}
.					{cerr<< "Line No. <<yylineno << Error:TOKEN CANNOT BE MATCHED "<<endl;}
%%