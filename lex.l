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
        int line_number;		// line number where the Datanode is occuring

        // Children of the DataNodes
        DataNode *child1;
        DataNode *child2;
        DataNode *child3;
        DataNode *child4;

        DataNode (string t, string v, DataNode *c1, DataNode *c2, DataNode *c3) {
            type = t;
            value = v;
            data_type = dt_none;
            child3 = c3;
            child2 = c2;
            child1 = c1;
            child4 = NULL;
            line_number = yylineno;
        }

        void addChild4(DataNode *c4){
            child4 = c4;
        }

        string getValue(){
            return value;
        }

        string getType(){
            return type;
        }

        DataType getDataType(){
            return data_type;
        }

        void setDataType(DataType dt){
            data_type = dt;
        }
    };

    DataNode* initialise (string c, string v){
            
        //Initialising a new code
        DataNode *d = new DataNode( c,v,NULL,NULL,NULL);

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
NEQ 	("!="|"<>")
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
{ADD} 			{return ADD;}
{SUB} 			{return SUB;}
{MUL} 			{return MUL;}
{DIV} 			{return DIV;}
{MOD} 			{return MOD;}
{GT} 			{return GT;}
{LT} 			{return LT;}
{GE} 			{return GE;}
{LE} 			{return LE;}
{COMP} 			{return COMP;}
{NEQ} 			{return NEQ;}
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

.					{cerr<< "TOKEN CANNOT BE MATCHED "<<endl;}

%%