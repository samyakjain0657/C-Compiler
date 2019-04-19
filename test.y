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
%type<datanode> type term const func_call expr1 arith_expr expr rel_expr log_expr return_stmt 

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
    INT MAIN LB RB LP {scope=2; enter_func("main","int",active_func_ptr);}body{} RP
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
    type ID LB {scope++;
        enter_func(($2)->value,($1)->value,active_func_ptr);
    }
    decl_plist RB LP 
    {  
        scope++;
    } 
    body 
    {scope=0;}
    RP
    |
    VOID ID LB {scope++;
        enter_func(($2)->value,"void",active_func_ptr);
    }
    decl_plist RB LP 
    {  
        scope++;
    } 
    body 
    {scope=0;}
    RP
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
    |   IF LB expr RB LP stmt_list RP else_stmt
    |   FOR LB expr SEMICOL expr SEMICOL expr RB LP stmt_list RP
    |   WHILE LB expr RB LP stmt_list RP
    |   SWITCH LB ID RB LP case_stmt default RP
;

else_stmt: 
    ELSE LP stmt_list RP
    |   
;

case_stmt:
    case_stmt CASE INT_VALUE COLON stmt_list
    |   case_stmt CASE FLOAT_VAL COLON stmt_list
    |
;

default:
    DEFAULT COLON stmt_list
    |
;
return_stmt:    
    RETURN
    {
        DataNode *res = new DataNode();
        res->data_type = dt_none;
        $$ = res;
    }
    | RETURN expr {$$ = check_func_return_type($2);}
;

expr:
    arith_expr {$$ = $1;}
    | log_expr {$$ = $1;}
    | ID EQUALS arith_expr {$$ = checkType($1,$3);}
    | ID dims2 EQUALS arith_expr {$$ = checkType($1,$4);}
;

log_expr:
    log_expr OR rel_expr {$$ = $3;}
    | log_expr AND rel_expr {$$ = $3;}
    | rel_expr {$$ = $1;}
;

rel_expr: 
    arith_expr op3 arith_expr
    {
        DataNode *res = new DataNode();
        res->data_type = dt_bool;
        $$ = res;
    }
;

arith_expr:  
    arith_expr op1 expr1 {$$ = typecaster($1,$3);}
    |   expr1 {$$ = $1;}
;

expr1: 
    expr1 op2 term { $$ = typecaster($1,$3);}
    |   term {$$ = $1;}
;    

term:   
    LB arith_expr RB {$$ = $2;}
    |   func_call {$$ = $1;}
    |   const {$$ = $1;}
    |   ID {set_data_type($1); $$ = $1;}
    |   ID dims2
    {
        set_data_type($1);
        $$ = $1;
        ($$)->type = "Array";
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