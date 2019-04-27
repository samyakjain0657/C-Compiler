%{

	#include <bits/stdc++.h>
    // #include "semantic.h"
	#include "bison.tab.h"


	using namespace std;


    enum DataType{
        dt_none,
        dt_int,
        dt_char,
        dt_string,
        dt_float,
        dt_bool,
        dt_func,
        dt_err
    };

    extern int yylineno;
    // Nodes of the AST
    struct DataNode {
    public:
        string type;			// lexeme class
        string value;			// lexeme
        DataType data_type;		// datatype of the Datanode(if required)
        string code_name;
        vector<string> dimlist_call;
        vector<pair<string, DataType>> param_list;
        int line_number;		// line number where the Datanode is occuring

        DataNode () {}

        DataNode (string t, string v) {
            type = t;
            value = v;
            data_type = dt_none;
            line_number = yylineno;
        }

        void setDataType(DataType dt){
            data_type = dt;
        }
    };

    DataNode* initialise (string c, string v){
            
        //Initialising a new code
        DataNode *d = new DataNode( c,v);

        return d;
    }


%}

%option yylineno
%option noyywrap

SEMICOL	";"
OR 		"||"
AND 	"&&"
LP		"{"
RP		"}"
LB		"("
PLUSPLUS "++"
MINUSMINUS "--"
PLUSEQU "+="
MINUSEQU "-="
DIVEQU  "/="
MULEQU  "*="
MODEQU  "%="
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
MAIN	"main"
RETURN 	"return"
IF 		"if"
FOR		"for"
WHILE	"while"
ELSE	"else"
INT		"int"
CHAR	"char"
STRING	"string"
VOID	"void"
FLOAT 	"float"
BOOL	"bool"
TRUE 	"true"
FALSE	"false"
SWITCH  "switch"
CASE    "case"
DEFAULT "default"
INT_VALUE 			([0-9]+)
FLOAT_VAL			([0-9]+\.[0-9]+)
BREAK               "break"
CONTINUE 	        "continue"
LIBRARY 	 		(\#include[ \n\t]*\<.+\>)|((\#include[ \t\n]*\".+\"))
ID					([A-Za-z_]([A-Za-z0-9_])*)
WHITESPACE 			([ \t]+)
NEWLINE 			([\n])

%%

{SEMICOL}		{return SEMICOL;}
{EQUALS}		{return EQUALS;}
{PLUSPLUS}      {return PLUSPLUS;}
{MINUSMINUS}    {return MINUSMINUS;}
{PLUSEQU}       {return PLUSEQU;}
{MINUSEQU}      {return MINUSEQU;}
{DIVEQU}        {return DIVEQU;}
{MULEQU}        {return MULEQU;}
{MODEQU}        {return MODEQU;}
{ADD} 			{(yylval.datanode) = initialise("INT", yytext); 
                return ADD;}
{SUB} 			{(yylval.datanode) = initialise("INT", yytext); 
                return SUB;}
{MUL} 			{(yylval.datanode) = initialise("INT", yytext); 
                return MUL;}
{DIV} 			{(yylval.datanode) = initialise("INT", yytext); 
                return DIV;}
{MOD} 			{(yylval.datanode) = initialise("INT", yytext); 
                return MOD;}
{GT} 			{(yylval.datanode) = initialise("GT", yytext); 
                return GT;}
{LT} 			{(yylval.datanode) = initialise("LT", yytext); 
                return LT;}
{GE} 			{(yylval.datanode) = initialise("GE", yytext); 
                return GE;}
{LE} 			{(yylval.datanode) = initialise("LE", yytext); 
                return LE;}
{COMP} 			{(yylval.datanode) = initialise("COMP", yytext); 
                return COMP;}
{NEQ} 			{(yylval.datanode) = initialise("NEQ", yytext); 
                return NEQ;}
{MAIN} 			{return MAIN;}
{IF} 			{return IF;}
{FOR} 			{return FOR;}
{WHILE} 		{return WHILE;}
{ELSE} 			{return ELSE;}
{COLON}         {return COLON;}
{CASE}          {return CASE;}
{DEFAULT}       {return DEFAULT;}
{INT} 			{(yylval.datanode) = initialise("INT", yytext); 
                return INT;}
{TRUE} 			{(yylval.datanode) = initialise("TRUE", yytext); 
                yylval.datanode->setDataType(dt_bool); 
                return TRUE;}
{FALSE} 		{(yylval.datanode) = initialise("FALSE", yytext); 
                yylval.datanode->setDataType(dt_bool); 
                return FALSE;}
{FLOAT} 		{(yylval.datanode) = initialise("FLOAT", yytext); 
                return FLOAT;}
{BOOL} 			{(yylval.datanode) = initialise("BOOL", yytext); 
                return BOOL;}
{VOID}          {(yylval.datanode) = initialise("VOID", yytext); 
                return VOID;}
{LP}	    	{return LP;}
{RP}		    {return RP;}
{LS}	    	{return LS;}
{RS}		    {return RS;}
{LB}		    {return LB;}
{RB}		    {return RB;}
{RETURN} 		{return RETURN;}
{OR} 			{return OR;}
{AND} 			{return AND;}
{BREAK} 		{return BREAK;}
{CONTINUE} 		{return CONTINUE;}
{COMMA}			{return COMMA;}
{SWITCH}        {return SWITCH;}
{INT_VALUE}		{(yylval.datanode) = initialise("INT_VALUE", yytext); 
                yylval.datanode->setDataType(dt_int); 
                return INT_VALUE;}
{FLOAT_VAL}		{(yylval.datanode) = initialise("FLOAT_VAL", yytext); 
                yylval.datanode->setDataType(dt_float); 
                return FLOAT_VAL;}
{LIBRARY}		{(yylval.datanode) = initialise("LIBRARY", yytext); 
                return LIBRARY;}
{ID}			{(yylval.datanode) = initialise("ID", yytext); 
                return ID;}
{NEWLINE} 		{}
{WHITESPACE}	{}

.					{cerr<< "Line No. <<yylineno << Error:TOKEN CANNOT BE MATCHED "<<endl;}

%%