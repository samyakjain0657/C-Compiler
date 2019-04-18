%{
#include <bits/stdc++.h>
#include "semantic.h"
using namespace std;
extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;
int yyerror(char *s);

%}

%left OR
%left AND

%union
{
	struct DataNode *datanode;
}

%token<datanode> SEMICOL EQUALS ADD SUB MUL DIV MOD GT LT GE LE COMP NEQ MAIN IF FOR WHILE ELSE INT FLOAT TRUE FALSE BOOL LP RP LS RS LB RB RETURN OR AND BREAK CONTINUE COMMA INT_VALUE FLOAT_VAL LIBRARY ID NEWLINE WHITESPACE VOID
%type<datanode> type term const func_call expr1 arith_expr expr rel_expr log_expr

%start start
    
%%

start:  
    libraries 
    {scope=0;} 
    declarations
    body_main
;

libraries: 
    libraries LIBRARY {

    }
    |
;

body_main: 
    INT MAIN LB RB LP {scope=1; enter_func("main","int",active_func_ptr);}body{} RP
;

declarations: 
    declarations dclr 
    | 
;

dclr:  
    var_dclr {
    } 
    |func_def

;

func_def:  
    type ID LB decl_plist RB LP {scope++;} body {scope--;}RP
;


decl_plist: 
    decl_pl
    |
;

decl_pl:    
    decl_pl COMMA decl_param
    |decl_param
;

decl_param: 
    type ID {   
        var *param;
        enter_param(($2)->value,($1)->value,active_func_ptr,param);
    }
;

var_dclr:   
    type varl SEMICOL {
        patch_type(($1)->value);
    }
;

type:  
    INT { 
        $$ = $1;
    }
    |
    FLOAT {
        $$ = $1;
    }
;

varl:
    ID {
        enter_var(($1)->value,scope,"simple",dimlist,active_func_ptr);
    }
    | ID EQUALS expr {
        enter_var(($1)->value,scope,"simple",dimlist,active_func_ptr);
    }
    | varl COMMA ID EQUALS expr {   
        enter_var(($3)->value,scope,"simple",dimlist,active_func_ptr);
    }
    | varl COMMA ID 
    {   enter_var(($3)->value,scope,"simple",dimlist,active_func_ptr);}
    | ID dims
    {   enter_var(($1)->value,scope,"array",dimlist,active_func_ptr);}
    | varl COMMA ID dims 
    {   enter_var(($3)->value,scope,"array",dimlist,active_func_ptr);}
;

dims: 
    LS INT_VALUE RS {dimlist.push_back(stoi(($2)->value));}
    | dims LS INT_VALUE RS {dimlist.push_back(stoi(($3)->value));}
;

dims2:
    LS term RS
    | dims2 LS term RS
;

body:
    stmt_list
;

stmt_list:  
    stmt_list stmt
    |   
;

stmt:   
    LP 
    {
        scope++;   
    }
    stmt_list
    {
        scope--;
    } 
    RP
    |   var_dclr
    |   expr SEMICOL
    |   CONTINUE SEMICOL
    |   BREAK SEMICOL
    |   return_stmt SEMICOL
;

return_stmt:    
    RETURN
    | RETURN expr
;

expr:
    arith_expr
    | log_expr
    | ID EQUALS arith_expr
    | ID dims2 EQUALS arith_expr
;

log_expr:
    log_expr OR rel_expr
    | log_expr AND rel_expr
    | rel_expr
;

rel_expr: 
    arith_expr op3 arith_expr
;

arith_expr:  
    arith_expr op1 expr1
    |   expr1
;

expr1: 
    expr1 op2 term
    |   term {$$ = $1;}
;    

term:   
    LB arith_expr RB {$$ = $2;}
    |   func_call {$$ = $1;}
    |   const {$$ = $1;}
    |   ID {$$ = $1;}
    |   ID dims2
    {
        $$ = $1;
    }
;

const:  
    INT_VALUE {$$ = $1;}
    |   FLOAT_VAL {$$ = $1;}
;

op1:    
    ADD
    |   SUB
;

op2:    
    MUL
    |   DIV
    |   MOD
;

op3:
    GT
    |   LT
    |   GE
    |   LE
    |   COMP
    |   NEQ
;

func_call:  
    ID LB paramlist RB 
    {
        DataNode* func = check_func_call(($1)->value);
        $$ = func;
    }
;

paramlist:  
    plist 
    |
;

plist:  
    plist COMMA expr {param_list.push_back(($3)->data_type);}
    | expr {param_list.push_back(($1)->data_type);}
;

%%

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