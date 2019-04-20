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

%token<datanode> DEFAULT CASE COLON SWITCH SEMICOL EQUALS ADD SUB MUL DIV MOD GT LT GE LE COMP NEQ MAIN IF FOR WHILE ELSE INT FLOAT TRUE FALSE BOOL LP RP LS RS LB RB RETURN OR AND BREAK CONTINUE COMMA INT_VALUE FLOAT_VAL LIBRARY ID NEWLINE WHITESPACE VOID
%type<datanode> type term const func_call expr1 arith_expr expr rel_expr log_expr return_stmt op1 op2 op3 dims2 

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
    INT MAIN LB RB 
    LP 
    {
        scope=2; 
        enter_func("main","int",active_func_ptr);
        // file << "func begin main\n";
    }
    body
    {
        // release_var(active_func_ptr,scope);
        scope--;
        // file << "func end\n";
    } 
    RP 
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
        active_type = dt_none;
        enter_func(($2)->value,($1)->value,active_func_ptr);
    }
    decl_plist RB LP 
    {                  
        scope++;
    } 
    body 
    {release_var(active_func_ptr,2),scope=0;}
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
    {release_var(active_func_ptr,2),scope=0;}
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
        active_type = dt_none;
    }
;

var_dclr:   
    type varl SEMICOL {
        patch_type(($1)->value);
        active_type = dt_none;
    }
;

type:  
    INT { 
        active_type = dt_int;
        $$ = $1;
    }
    |
    FLOAT {
        active_type = dt_float;
        $$ = $1;
    }
;

varl:
    ID {
        enter_var(($1)->value,scope,"simple",dimlist,active_func_ptr);
    }
    | ID EQUALS expr {
        bool chk = check_type($1, $3);
        if (chk) {
            enter_var(($1)->value,scope,"simple",dimlist,active_func_ptr);
        }
    }
    | varl COMMA ID EQUALS expr {
        bool chk = check_type($3, $5);
        if (chk)
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
    {
        dim_count++;
        // dimlist_call.push_back($2->code_name);
    }
    | dims2 LS term RS
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
        release_var(active_func_ptr,scope);
        scope--;
    } 
    RP
    |   var_dclr
    |   expr SEMICOL
    |   CONTINUE SEMICOL
    |   BREAK SEMICOL
    |   return_stmt SEMICOL
    |   IF LB expr RB LP {scope++;}
        stmt_list RP {
            release_var(active_func_ptr,scope);
            scope--;
        }
        else_stmt
    |   FOR LB expr SEMICOL expr SEMICOL expr RB LP {scope++;}stmt_list RP { 
            release_var(active_func_ptr,scope);
            scope--;
        }
    |   WHILE LB expr RB LP {scope++;} stmt_list RP {
            release_var(active_func_ptr,scope);
            scope--;
        }
    |   SWITCH LB ID{
            var *variable;
            bool found = false;
            search_var(($3)->value,active_func_ptr,scope,found,variable);
            if(!found){
                cout << "Line No. " << yylineno << " Error : Variable " << ($3)->value << " not declared" << endl; 
            }
            else{
                if(variable->eletype!="int")
                    cout << "Line No. " << yylineno << " Error: expression must have integral type"<< endl; 
            }
            
        }
        RB LP { scope++; } 
        case_stmt default RP { 
            release_var(active_func_ptr,scope);
            scope--;
        }
    |   SWITCH LB ID dims2{
           var *variable;
            bool found = false;
            search_var(($3)->value,active_func_ptr,scope,found,variable);
            if(!found){
                cout << "Line No. " << yylineno << " Error : Variable " << ($3)->value << " not declared" << endl; 
            }
            else{
                if(variable->eletype!="int")
                    cout << "Line No. " << yylineno << " Error: expression must have integral type"<< endl; 
            }            
        }
        RB LP { scope++; } 
        case_stmt default RP { 
            release_var(active_func_ptr,scope);
            scope--;
        }
;

else_stmt: 
    ELSE LP {scope++;} stmt_list RP {
        release_var(active_func_ptr,scope);
        scope--;
    }
    |   
;

case_stmt:
    case_stmt CASE INT_VALUE COLON stmt_list
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
    |   ID 
    {
        set_data_type($1); 
        $$ = $1;
        // $$->code_name = get_var_code_name($1->value);

    }
    |   ID dims2
    {
        dim_count = 0;
        
        set_data_type($1);
        
        $$ = $1;
        ($$)->type = "array";

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
;

const:  
    INT_VALUE {$$ = $1; $$->code_name = $1->value;}
    |   FLOAT_VAL {$$ = $1; $$->code_name = $1->value;}
;

op1:    
    ADD {$$ = $1; $$->code_name = $1->value;}
    |   SUB {$$ = $1; $$->code_name = $1->value;}
;

op2:    
    MUL {$$ = $1; $$->code_name = $1->value;}
    |   DIV {$$ = $1; $$->code_name = $1->value;}
    |   MOD {$$ = $1; $$->code_name = $1->value;}
;

op3:
    GT {$$ = $1; $$->code_name = $1->value;}
    |   LT {$$ = $1; $$->code_name = $1->value;}
    |   GE {$$ = $1; $$->code_name = $1->value;}
    |   LE {$$ = $1; $$->code_name = $1->value;}
    |   COMP {$$ = $1; $$->code_name = $1->value;}
    |   NEQ {$$ = $1; $$->code_name = $1->value;}
;

func_call:  
    ID LB paramlist RB 
    {
        DataNode* func = check_func_call(($1)->value);
        param_list.clear();
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