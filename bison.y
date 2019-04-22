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
%type<datanode> type term const func_call expr1 arith_expr expr rel_expr log_expr return_stmt op1 op2 op3 dims2 log_expr_prime and_expr and_expr_prime factor

%start start
    
%%

start:  
    {
        file.open("inter.txt");
    }
    libraries 
    {scope=0;} 
    declarations
    body_main
    {
        symfile.open("symtab.txt");
        symfile << "\t\t\t.data\n" ;
        print_symbol_list();
        symfile.close();
    }
    
    
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
        file << "func begin main\n";
    }
    body
    {
        release_var(active_func_ptr,scope);
        scope--;
        file << "func end\n";
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
    type ID LB {
        scope++;
        active_type = dt_none;
        enter_func(($2)->value,($1)->value,active_func_ptr);
        param_count=0;
        file << "func begin " << ($2)->value << "\n";
    }
    decl_plist RB LP {                  
        scope++;
    } 
    body {
        release_var(active_func_ptr,2);
        scope=0;
        file << "func end\n";
    }
    RP
    |
    VOID ID LB {
        scope++;
        active_type = dt_none;
        enter_func(($2)->value,"void",active_func_ptr);
        param_count=0;
        file << "func begin " << ($2)->value << "\n";
    }
    decl_plist RB LP {  
        scope++;
    } 
    body {
        release_var(active_func_ptr,2);
        scope=0;
        file << "func end\n";
    }
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
    | ID EQUALS arith_expr {
        bool chk = check_type($1, $3);
        if (chk) {
            enter_var(($1)->value,scope,"simple",dimlist,active_func_ptr);
            file << get_var_code_name($1->value) << " = " << $3->code_name << ";" <<  endl;
            release_temp_name($3->code_name);
        }
    }
    | varl COMMA ID EQUALS arith_expr {
        bool chk = check_type($3, $5);
        if (chk) {
            enter_var(($3)->value,scope,"simple",dimlist,active_func_ptr);
            file << get_var_code_name($3->value) << " = " << $5->code_name << ";" <<  endl;
            release_temp_name($5->code_name);
        }
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
    LS arith_expr RS 
    {
        if ($2->data_type == dt_int)
            dimlist_call.push_back($2->code_name);
        else 
            cout << "Line No. " << yylineno << " Error : array subscript (" << dimlist_call.size() <<  ") is not an integer " << endl; 
    }
    | dims2 LS arith_expr RS
    {
       if ($2->data_type == dt_int)
            dimlist_call.push_back($3->code_name);
        else 
            cout << "Line No. " << yylineno << " Error : array subscript (" << dimlist_call.size() <<  ") is not an integer " << endl; 
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
    LP {
        scope++;   
    }
    stmt_list {   
        release_var(active_func_ptr,scope);
        scope--;
    } 
    RP
    |   var_dclr
    |   expr SEMICOL
    |   CONTINUE SEMICOL {
            if(loop_stack.size()==0)
                cout << "Line No. " << yylineno << " Error : Continue should be always used inside a loop"<<endl; 
            else
                file << "goto LT" << loop_stack.top() << endl;
        }
    |   BREAK SEMICOL {
            if(last_used.size()==0)
                cout << "Line No. " << yylineno << " Error : break should be always used inside a loop or switch"<<endl; 
            else if(last_used.top()==0)
                file << "goto SF" << switch_stack.top() << endl;
            else
                file << "goto LF" << loop_stack.top() << endl;
        }
    |   return_stmt SEMICOL
    |   IF LB log_expr RB LP 
        {
            scope++;
            file << "if " << $3->code_name << " != 1 goto IFF" << if_counter << endl;
            if_stack.push(if_counter++);
            release_temp_name($3->code_name);
            // file << "IFS" << if_counter << ":\n";
            // if_stack.push(if_counter++);
        }
        stmt_list RP 
        {
            release_var(active_func_ptr,scope);
            scope--;
        }
        else_stmt
    |   WHILE LB {
            loop_stack.push(loop_counter);
            last_used.push(1);
            file << "LT" << loop_counter << ":\n";
        }
        log_expr RB{
            file << "if "<<$4->code_name << " != 1 goto LF" << loop_counter++ << endl;
            release_temp_name($4->code_name);
        } 
        LP {
            scope++; 
        } 
        stmt_list RP {
            release_var(active_func_ptr,scope);
            scope--;
            file << "goto LT" << loop_stack.top()<< endl;
            file << "LF" << loop_stack.top() << ":" << endl;
            loop_stack.pop();
            last_used.pop();
        }
    |   FOR LB expr SEMICOL 
        {
            loop_stack.push(loop_counter);
            last_used.push(1);
            file << "LJ" << loop_counter << ":\n";
            release_temp_name($3->code_name);
        }
        log_expr SEMICOL
        {
            file << "if " << $6->code_name  << " != 1 goto LF" << loop_counter << endl;
            file << "goto LS" << loop_counter << endl;
            file << "LT" << loop_counter << ":\n";
            release_temp_name($6->code_name);
        } 
        expr RB LP 
        {
            scope++;
            file << "goto LJ" << loop_counter << endl;
            file << "LS" << loop_counter++ << ":\n";
            release_temp_name($9->code_name);
        }
        stmt_list RP { 
            release_var(active_func_ptr,scope);
            scope--;
            file << "goto LT" << loop_stack.top()<< endl;
            file << "LF" << loop_stack.top() << ":" << endl;
            loop_stack.pop();
            last_used.pop();
        }
    |   SWITCH LB ID{
            switch_stack.push(switch_counter++);
            last_used.push(0);
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
            curr_temp = get_temp_name();
            file << curr_temp << " = " << variable->code_name << ";" <<  endl;
        }
        RB LP { scope++; } 
        case_stmt default RP { 
            release_var(active_func_ptr,scope);
            scope--;
            file << "SF" << switch_stack.top() << ":" << endl;
            switch_stack.pop();
            last_used.pop();
            release_temp_name(curr_temp);
        }
    |   SWITCH LB ID dims2{
            switch_stack.push(switch_counter++);
            last_used.push(0);
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

            string temp_name = dimlist_call[0];
            string temp_name3 = get_temp_name();
            string temp_name4 = get_temp_name();
            string temp_name5 = get_temp_name();
            string temp_name6;  
            string temp_name2;      
            vector<int> temp_dim_list = get_dimlist($3->value);
            for (int i = 1; i < temp_dim_list.size(); i++) {
                temp_name2 = get_temp_name(); 
                temp_name6 = get_temp_name();    
                file << temp_name6 << " = " << temp_name << " * " << temp_dim_list[i] << ";" <<  endl;
                file << temp_name2 << " = " << temp_name6 << " + " << dimlist_call[i] << ";" <<  endl;
                release_temp_name(temp_name);
                release_temp_name(dimlist_call[i]);
                release_temp_name(temp_name6);
                temp_name = temp_name2;
            }
            file << temp_name3 << " = " << temp_name2 << " * 4;\n";
            file << temp_name4 << " = " << "addr(" << get_var_code_name($3->value) << ")" << ";" <<  endl;
            // file << temp_name4 << "[" << temp_name3 <<"]"  << " = " << $4->code_name << ";" <<  endl;
            file << temp_name5 << " = " << temp_name4 << "[" << temp_name3 <<"]" << ";" <<  endl;
            release_temp_name(temp_name2);
            release_temp_name(temp_name3);
            release_temp_name(temp_name4);
            temp_dim_list.clear();
            dimlist_call.clear();
            curr_temp = temp_name5;
            // $$->code_name = temp_name5;
                        
        }
        RB LP { scope++; } 
        case_stmt default RP { 
            release_var(active_func_ptr,scope);
            scope--;
            file << "SF" << switch_stack.top() << ":" << endl;
            switch_stack.pop();
            last_used.pop();
            release_temp_name(curr_temp);
        }
;

else_stmt: 
    ELSE LP 
    {
        scope++;
        file << "goto IFT" << if_stack.top() << endl; 
        file << "IFF" << if_stack.top() << ":\n";
    } 
    stmt_list RP 
    {
        release_var(active_func_ptr,scope);
        scope--;
        file << "IFT" << if_stack.top() << ":\n";
        if_stack.pop();
    }
    |   
    {
        file << "IFF" << if_stack.top() << ":\n";
        if_stack.pop();
    }
;


case_stmt:
    case_stmt 
    {
        file << "S" << switch_stack.top() << "CT" << case_counter++ << ": " << endl;
    }
    CASE INT_VALUE 
    {
        file << "if " << curr_temp << " != " << $4->value << " goto "<< "S" << switch_stack.top() << "CT" << case_counter << endl; 
    }
    COLON stmt_list
    |
;

default:
    DEFAULT 
    {
        file << "S" << switch_stack.top() << "CT" << case_counter++ << ": " << endl;
    }
    COLON stmt_list
    |
    {
        file << "S" << switch_stack.top() << "CT" << case_counter++ << ": " << endl;
    }
;

return_stmt:    
    RETURN {
        DataNode *res = new DataNode();
        res->data_type = dt_none;
        $$ = res;
        file << "return;\n";
    }
    | RETURN expr {
        $$ = check_func_return_type($2);
        file << "return " << $2->code_name << ";" << endl;
    }
;

expr:
    arith_expr {$$ = $1;}
    | log_expr
    | ID EQUALS arith_expr 
    {
        $$ = checkType($1,$3);
        
        file << get_var_code_name($1->value) << " = " << $3->code_name << ";" << endl;
        release_temp_name($3->code_name);
        string temp_name = get_temp_name();
        // file << temp_name << " = " << get_var_code_name($1->value) <<  ";" << endl;
        $$->code_name = temp_name;
    }
    | ID dims2 EQUALS arith_expr 
    {
        $$ = checkType($1,$4);

        string temp_name = dimlist_call[0];
        string temp_name3 = get_temp_name();
        string temp_name4 = get_temp_name();
        string temp_name5 = get_temp_name();
        string temp_name6;  
        string temp_name2;      
        vector<int> temp_dim_list = get_dimlist($1->value);
        for (int i = 1; i < temp_dim_list.size(); i++) {
            temp_name2 = get_temp_name(); 
            temp_name6 = get_temp_name();    
            file << temp_name6 << " = " << temp_name << " * " << temp_dim_list[i] << ";" << endl;
            file << temp_name2 << " = " << temp_name6 << " + " << dimlist_call[i] << ";" << endl;
            release_temp_name(temp_name);
            release_temp_name(dimlist_call[i]);
            release_temp_name(temp_name6);
            temp_name = temp_name2;
        }
        file << temp_name3 << " = " << temp_name2 << " * 4;\n";
        file << temp_name4 << " = " << "addr(" << get_var_code_name($1->value) << ");" << endl;
        file << temp_name4 << "[" << temp_name3 <<"]"  << " = " << $4->code_name << ";" <<  endl;
        file << temp_name5 << " = " << temp_name4 << "[" << temp_name3 <<"];" << endl;
        release_temp_name(temp_name2);
        release_temp_name(temp_name3);
        release_temp_name(temp_name4);
        temp_dim_list.clear();
        dimlist_call.clear();
        $$->code_name = temp_name5;
    }
;

log_expr:
    and_expr
    {
        cond_stack.push(cond_counter++);
        file << "if " << $1->code_name << " == 1 goto IFS" << cond_stack.top() << endl;
        
        // release_temp_name($1->code_name);
    } 
    log_expr_prime 
    {
        file << "IFS" << cond_stack.top() << ":\n";
        cond_stack.pop();
        
        DataNode *res = new DataNode();
        res->data_type = dt_bool;
        $$ = res;

        if ($3->code_name != "0") {
            string temp1 = $1->code_name;
            string temp2 = $3->code_name;
            
            string temp_name = get_temp_name();
            file << temp_name  << " = "  <<  temp1 << " " << "||" << " " << temp2 << ";" <<  endl;
            release_temp_name(temp1);
            release_temp_name(temp2);
            $$->code_name = temp_name;
        }
        else {
            $$->code_name = $1->code_name;
        }
    }
;

log_expr_prime:
    OR and_expr
    {
        file << "if " << $2->code_name << " == 1 goto IFS" << cond_stack.top() << endl;
    } 
    log_expr_prime 
    {
        DataNode *res = new DataNode();
        res->data_type = dt_bool;
        $$ = res;

        if ($4->code_name != "0") {
            string temp1 = $2->code_name;
            string temp2 = $4->code_name;
            
            string temp_name = get_temp_name();
            file << temp_name  << " = "  <<  temp1 << " " << "||" << " " << temp2 << ";" <<  endl;
            release_temp_name(temp1);
            release_temp_name(temp2);
            $$->code_name = temp_name;
        }
        else {
            $$->code_name = $2->code_name;
        }
    }
    |
    {
        DataNode *res = new DataNode();
        res->data_type = dt_bool;
        $$ = res;
        $$->code_name = "0";

    }
;

and_expr:
    factor
    {
        cond_stack.push(cond_counter++);
        file << "if " << $1->code_name << " != 1 goto IFS" << cond_stack.top() << endl;
    }
    and_expr_prime 
    {
        file << "IFS" << cond_stack.top() << ":\n";
        cond_stack.pop();

        DataNode *res = new DataNode();
        res->data_type = dt_bool;
        $$ = res;

        if ($3->code_name != "1") {
            string temp1 = $1->code_name;
            string temp2 = $3->code_name;
            
            string temp_name = get_temp_name();
            file << temp_name  << " = "  <<  temp1 << " " << "&&" << " " << temp2 << ";" <<  endl;
            release_temp_name(temp1);
            release_temp_name(temp2);
            $$->code_name = temp_name;
        }
        else {
            $$->code_name = $1->code_name;
        }
    }
;

and_expr_prime:
    AND factor
    {
        file << "if " << $2->code_name << " != 1 goto IFS" << cond_stack.top() << endl;
    } 
    and_expr_prime 
    {
        DataNode *res = new DataNode();
        res->data_type = dt_bool;
        $$ = res;

        if ($4->code_name != "1") {
            string temp1 = $2->code_name;
            string temp2 = $4->code_name;
            
            string temp_name = get_temp_name();
            file << temp_name  << " = "  <<  temp1 << " " << "&&" << " " << temp2 << ";" <<  endl;
            release_temp_name(temp1);
            release_temp_name(temp2);
            $$->code_name = temp_name;
        }
        else {
            $$->code_name = $2->code_name;
        }
    }
    | 
    {
        DataNode *res = new DataNode();
        res->data_type = dt_bool;
        $$ = res;
        $$->code_name = "1";
    }
;

factor:
    rel_expr { $$ = $1;}
    | LB log_expr RB { $$ = $2;}
;

rel_expr: 
    arith_expr op3 arith_expr
    {
        DataNode *res = new DataNode();
        res->data_type = dt_bool;
        $$ = res;
        string temp1 = $1->code_name;
        string temp2 = $3->code_name;
        
        string temp_name = get_temp_name();
        file << temp_name  << " = "  <<  temp1 << " " << $2->code_name << " " << temp2 << ";" <<  endl;
        release_temp_name(temp1);
        release_temp_name(temp2);
        $$->code_name = temp_name;
    }
;


arith_expr:  
    arith_expr op1 expr1 
    {
        string temp1 = $1->code_name;
        string temp2 = $3->code_name;

        $$ = typecaster($1,$3);

        string temp_name = get_temp_name();
        file << temp_name  << " = "  <<  temp1 << " " << $2->code_name << " " << temp2 << ";" <<  endl;
        release_temp_name(temp1);
        release_temp_name(temp2);
        $$->code_name = temp_name;
    }
    |   expr1 {$$ = $1;}
;

expr1: 
    expr1 op2 term 
    {
        string temp1 = $1->code_name;
        string temp2 = $3->code_name;

        $$ = typecaster($1,$3);
        string temp_name = get_temp_name();
        file << temp_name  << " = "  <<  temp1 << " " << $2->code_name << " " << temp2 << ";" <<  endl;
        release_temp_name(temp1);
        release_temp_name(temp2);
        $$->code_name = temp_name;
    }
    |   term {$$ = $1;}
;    

term:   
    LB arith_expr RB {$$ = $2;}
    |   func_call {$$ = $1;}
    |   const 
    {
        $$ = $1;
        string temp_name = get_temp_name();
        file << temp_name << " = " << $1->value << ";" <<  endl;
        $$->code_name = temp_name;
    }
    |   ID 
    {
        set_data_type($1); 
        $$ = $1;
        string temp_name = get_temp_name();
        file << temp_name << " = " << get_var_code_name($1->value) << ";" <<  endl;
        $$->code_name = temp_name;
    }
    |   ID dims2
    {        
        set_data_type($1);
        
        $$ = $1;
        ($$)->type = "array";

        string temp_name = dimlist_call[0];
        string temp_name3 = get_temp_name();
        string temp_name4 = get_temp_name();
        string temp_name5 = get_temp_name();
        string temp_name6;  
        string temp_name2;      
        vector<int> temp_dim_list = get_dimlist($1->value);
        // for (auto it: dimlist_call) {
        //     cout << it <<  " ";
        // }cout << endl;
        for (int i = 1; i < temp_dim_list.size(); i++) {
            temp_name2 = get_temp_name(); 
            temp_name6 = get_temp_name();    
            file << temp_name6 << " = " << temp_name << " * " << temp_dim_list[i] << ";" <<  endl;
            file << temp_name2 << " = " << temp_name6 << " + " << dimlist_call[i] << ";" <<  endl;
            release_temp_name(temp_name);
            release_temp_name(dimlist_call[i]);
            release_temp_name(temp_name6);
            temp_name = temp_name2;
        }
        file << temp_name3 << " = " << temp_name2 << " * 4;\n";
        file << temp_name4 << " = " << "addr(" << get_var_code_name($1->value) << ")" << ";" <<  endl;
        file << temp_name5 << " = " << temp_name4 << "[" << temp_name3 <<"]" << ";" <<  endl;
        release_temp_name(temp_name2);
        release_temp_name(temp_name3);
        release_temp_name(temp_name4);
        temp_dim_list.clear();
        dimlist_call.clear();
        $$->code_name = temp_name5;
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
        for (auto it: param_list) {
            file << "param " << it.first << ";\n";
            release_temp_name(it.first);
        }
        if(func->data_type == dt_int || func->data_type == dt_float ){
            file << "param _result" << res_counter <<";\n"; 
            var *variable = new var();
            
            if (func->data_type == dt_int)
                variable->eletype = "int";
            else
                variable->eletype = "float";
            
            variable->name = "_result" + to_string(res_counter);
            variable->code_name =  "_result" + to_string(res_counter++);
            variable->level = scope;
            variable->type = "simple";
            variable->isParam = false;
            symbol_list.push_back(*variable);
            func->code_name =  variable->code_name;
        }
        file << "call " << ($1)->value <<";\n";
        param_list.clear();
        $$ = func;
    }
;

paramlist:  
    plist 
    |
;

plist:  
    plist COMMA expr {param_list.push_back({($3)->code_name,($3)->data_type});}
    | expr {param_list.push_back({($1)->code_name,($1)->data_type});}
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