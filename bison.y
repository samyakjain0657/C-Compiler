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

%token<datanode>  DEFAULT PRINTINT PRINTFLOAT CASE COLON SWITCH SEMICOL EQUALS ADD SUB MUL DIV MOD GT LT GE LE COMP NEQ MAIN IF FOR WHILE ELSE INT FLOAT TRUE FALSE BOOL LP RP LS RS LB RB RETURN OR AND BREAK CONTINUE COMMA INT_VALUE FLOAT_VAL LIBRARY ID NEWLINE WHITESPACE VOID PLUSPLUS MINUSMINUS PLUSEQU MINUSEQU DIVEQU MULEQU MODEQU 
%type<datanode> type term const func_call expr1 arith_expr expr rel_expr log_expr return_stmt op1 op2 op3 dims2 log_expr_prime and_expr and_expr_prime factor glob_dclr glob_varl paramlist plist plusnegterm for_expr for_log_expr

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
    | libraries error
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
    glob_dclr {
    } 
    |func_def

;

func_def:  
    type ID LB {
        scope++;
        active_type = dt_none;
        enter_func(($2)->value,($1)->value,active_func_ptr);
        param_count=0;
        file << "func begin " << ($2)->value ;
    }
    decl_plist RB LP {
        file << " " << func_dec_counter << "\n";  
        func_dec_counter = 0;                
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
        file << "func begin " << ($2)->value;
    }
    decl_plist RB LP {  
        file << " " << func_dec_counter << "\n";  
        func_dec_counter = 0;
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
    decl_pl COMMA decl_param {func_dec_counter++;}
    |decl_param {func_dec_counter++;}
;

decl_param: 
    type ID {   
        var *param;
        enter_param(($2)->value,($1)->value,active_func_ptr,param);
        active_type = dt_none;
    }
;

glob_dclr: type glob_varl SEMICOL {
        patch_type(($1)->value);
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

glob_varl: ID {
        enter_var(($1)->value,scope,"simple",dimlist,active_func_ptr);
    }
    | ID EQUALS const {
        // bool chk = check_type($1, $3);
        if (1) {
            glob_val = $3->value;
            enter_var(($1)->value,scope,"simple",dimlist,active_func_ptr);
            // file << get_var_code_name($1->value) << " = " << $3->value << ";" <<  endl;
            release_temp_name($3->value);
        }
    }
    | glob_varl COMMA ID EQUALS const {
        // bool 1 = check_type($3, $5);
        if (1) {
            glob_val = $5->value;
            enter_var(($3)->value,scope,"simple",dimlist,active_func_ptr);
            // file << get_var_code_name($3->value) << " = " << $5->value << ";" <<  endl;
            release_temp_name($5->value);
        }
    }
    | ID EQUALS ADD const {
        // bool chk = check_type($1, $3);
        if (1) {
            glob_val = $3->value + $4->value;
            enter_var(($1)->value,scope,"simple",dimlist,active_func_ptr);
            // file << get_var_code_name($1->value) << " = " << $4->value << ";" <<  endl;
            release_temp_name($4->value);
        }
    }
    | glob_varl COMMA ID EQUALS  ADD const {
        // bool 1 = check_type($3, $5);
        if (1) {
            glob_val = $5->value + $6->value;
            enter_var(($3)->value,scope,"simple",dimlist,active_func_ptr);
            // file << get_var_code_name($3->value) << " = " << $6->value << ";" <<  endl;
            release_temp_name($6->value);
        }
    }
    | ID EQUALS SUB const {
        // bool chk = check_type($1, $3);
        if (1) {
            glob_val = $3->value + $4->value;
            enter_var(($1)->value,scope,"simple",dimlist,active_func_ptr);
            // file << get_var_code_name($1->value) << " = " << $4->value << ";" <<  endl;
            release_temp_name($4->value);
        }
    }
    | glob_varl COMMA ID EQUALS  SUB const {
        // bool 1 = check_type($3, $5);
        if (1) {
            glob_val = $5->value + $6->value;
            enter_var(($3)->value,scope,"simple",dimlist,active_func_ptr);
            // file << get_var_code_name($3->value) << " = " << $6->value << ";" <<  endl;
            release_temp_name($6->value);
        }
    }
    | glob_varl COMMA ID 
    {   enter_var(($3)->value,scope,"simple",dimlist,active_func_ptr);}
    | ID dims
    {   enter_var(($1)->value,scope,"array",dimlist,active_func_ptr);}
    | glob_varl COMMA ID dims 
    {   enter_var(($3)->value,scope,"array",dimlist,active_func_ptr);}
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
        if ($2->data_type == dt_int) {
            $$ = new DataNode();
            $$->dimlist_call.push_back($2->code_name);
        }
            
        else 
            cout << "Line No. " << yylineno << " Error : array subscript (" << dimlist_call.size() <<  ") is not an integer " << endl; 
    }
    | dims2 LS arith_expr RS
    {
        $$ = $1;
       if ($2->data_type == dt_int)
            $$->dimlist_call.push_back($3->code_name);
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
    |   error LP
    |   error SEMICOL
    |   var_dclr
    |   expr SEMICOL {
        release_temp_name($1->code_name);
    }
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
    |   FOR LB for_expr SEMICOL 
        {
            loop_stack.push(loop_counter);
            last_used.push(1);
            file << "LJ" << loop_counter << ":\n";
            release_temp_name($3->code_name);
        }
        for_log_expr SEMICOL
        {
            file << "if " << $6->code_name  << " != 1 goto LF" << loop_counter << endl;
            file << "goto LS" << loop_counter << endl;
            file << "LT" << loop_counter << ":\n";
            release_temp_name($6->code_name);
        } 
        for_expr RB LP 
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

            string temp_name5 = get_temp_name();
            pair<string, string> temp = return_arr($3,$4);
            file << temp_name5 << " = " << temp.first << "[" << temp.second <<"]" << ";" <<  endl;
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $4->dimlist_call.clear();
            curr_temp = temp_name5;                        
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
    |   PRINTINT SEMICOL {
            string temp = $1->value;
            int found = temp.find(',');
            temp.replace(0, found+1,"");
            found = temp.find(')');
            temp.replace(found, temp.length(),"");
            // cout << temp << endl;

            string varname = get_var_code_name(temp);
            file << "print " << varname << ";\n";

        }
    | PRINTFLOAT SEMICOL {
        string temp = $1->value;
        int found = temp.find(',');
        temp.replace(0, found+1,"");
        found = temp.find(')');
        temp.replace(found, temp.length(),"");
        // cout << temp << endl;

        string varname = get_var_code_name(temp);
        file << "print " << varname << ";\n";
            
    }
;

for_expr:
    expr {$$ = $1;}
    | {
        $$ = new DataNode();
    }

;

for_log_expr:
    log_expr {$$ = $1;}
    | {
        $$ = new DataNode();
        string temp1, temp2, temp3;
        temp1 = get_temp_name();
        temp2 = get_temp_name();
        temp3 = get_temp_name();
        file << temp2 << " = 1;\n";
        file << temp3 << " = 1;\n";
        file << temp1 << " = " << temp2 << " == " << temp3 << " ;" << endl; 
        release_temp_name(temp2);
        release_temp_name(temp3);
        $$->code_name = temp1;
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
        $$ = check_func_return_type(res);
        file << "return;\n";
    }
    | RETURN expr {
        $$ = check_func_return_type($2);
        file << "return " << $2->code_name << ";" << endl;
        release_temp_name($2->code_name);
    }
;

expr:
    arith_expr {$$ = $1;}
    | log_expr {$$ = $1;}
    | ID PLUSEQU arith_expr
    {
        $$ = checkType($1,$3);
        
        if ($$->data_type == dt_int) {
            string temp_name2 = get_temp_name();
            file << temp_name2 << " = " <<  get_var_code_name($1->value) << ";" << endl;
            string temp_name3 = get_temp_name();
            file << temp_name3 << " = " << temp_name2 << " + " << $$->code_name << ";" << endl;
            file << get_var_code_name($1->value) << " = " << temp_name3 << ";" << endl;
            release_temp_name(temp_name3);
            release_temp_name(temp_name2);
            release_temp_name($$->code_name);
            string temp_name = get_temp_name();
            $$->code_name = temp_name;
        }
        else {
            string temp_name2 = get_ftemp_name();
            file << temp_name2 << " = " <<  get_var_code_name($1->value) << ";" << endl;
            string temp_name3 = get_ftemp_name();
            file << temp_name3 << " = " << temp_name2 << " + " << $$->code_name << ";" << endl;
            file << get_var_code_name($1->value) << " = " << temp_name3 << ";" << endl;
            release_temp_name(temp_name3);
            release_temp_name(temp_name2);
            release_temp_name($$->code_name);
            string temp_name = get_ftemp_name();
            $$->code_name = temp_name;
        }
    }
    | ID MINUSEQU arith_expr
    {
        $$ = checkType($1,$3);
        
        if ($$->data_type == dt_int) {
            string temp_name2 = get_temp_name();
            file << temp_name2 << " = " <<  get_var_code_name($1->value) << ";" << endl;
            string temp_name3 = get_temp_name();
            file << temp_name3 << " = " << temp_name2 << " - " << $$->code_name << ";" << endl;
            file << get_var_code_name($1->value) << " = " << temp_name3 << ";" << endl;
            release_temp_name(temp_name3);
            release_temp_name(temp_name2);
            release_temp_name($$->code_name);
            string temp_name = get_temp_name();
            $$->code_name = temp_name;
        }
        else {
            string temp_name2 = get_ftemp_name();
            file << temp_name2 << " = " <<  get_var_code_name($1->value) << ";" << endl;
            string temp_name3 = get_ftemp_name();
            file << temp_name3 << " = " << temp_name2 << " - " << $$->code_name << ";" << endl;
            file << get_var_code_name($1->value) << " = " << temp_name3 << ";" << endl;
            release_temp_name(temp_name3);
            release_temp_name(temp_name2);
            release_temp_name($$->code_name);
            string temp_name = get_ftemp_name();
            $$->code_name = temp_name;
        }
    }
    | ID DIVEQU arith_expr
    {
        $$ = checkType($1,$3);
        
        if ($$->data_type == dt_int) {
            string temp_name2 = get_temp_name();
            file << temp_name2 << " = " <<  get_var_code_name($1->value) << ";" << endl;
            string temp_name3 = get_temp_name();
            file << temp_name3 << " = " << temp_name2 << " / " << $$->code_name << ";" << endl;
            file << get_var_code_name($1->value) << " = " << temp_name3 << ";" << endl;
            release_temp_name(temp_name3);
            release_temp_name(temp_name2);
            release_temp_name($$->code_name);
            string temp_name = get_temp_name();
            $$->code_name = temp_name;
        }
        else {
            string temp_name2 = get_ftemp_name();
            file << temp_name2 << " = " <<  get_var_code_name($1->value) << ";" << endl;
            string temp_name3 = get_ftemp_name();
            file << temp_name3 << " = " << temp_name2 << " / " << $$->code_name << ";" << endl;
            file << get_var_code_name($1->value) << " = " << temp_name3 << ";" << endl;
            release_temp_name(temp_name3);
            release_temp_name(temp_name2);
            release_temp_name($$->code_name);
            string temp_name = get_ftemp_name();
            $$->code_name = temp_name;
        }
    }
    | ID MULEQU arith_expr
    {
        $$ = checkType($1,$3);
        
        if ($$->data_type == dt_int) {
            string temp_name2 = get_temp_name();
            file << temp_name2 << " = " <<  get_var_code_name($1->value) << ";" << endl;
            string temp_name3 = get_temp_name();
            file << temp_name3 << " = " << temp_name2 << " * " << $$->code_name << ";" << endl;
            file << get_var_code_name($1->value) << " = " << temp_name3 << ";" << endl;
            release_temp_name(temp_name3);
            release_temp_name(temp_name2);
            release_temp_name($$->code_name);
            string temp_name = get_temp_name();
            $$->code_name = temp_name;
        }
        else {
            string temp_name2 = get_ftemp_name();
            file << temp_name2 << " = " <<  get_var_code_name($1->value) << ";" << endl;
            string temp_name3 = get_ftemp_name();
            file << temp_name3 << " = " << temp_name2 << " * " << $$->code_name << ";" << endl;
            file << get_var_code_name($1->value) << " = " << temp_name3 << ";" << endl;
            release_temp_name(temp_name3);
            release_temp_name(temp_name2);
            release_temp_name($$->code_name);
            string temp_name = get_ftemp_name();
            $$->code_name = temp_name;
        }
    }
    | ID MODEQU arith_expr
    {
        $$ = checkType($1,$3);
        
        if ($$->data_type == dt_int) {
            string temp_name2 = get_temp_name();
            file << temp_name2 << " = " <<  get_var_code_name($1->value) << ";" << endl;
            string temp_name3 = get_temp_name();
            file << temp_name3 << " = " << temp_name2 << " % " << $$->code_name << ";" << endl;
            file << get_var_code_name($1->value) << " = " << temp_name3 << ";" << endl;
            release_temp_name(temp_name3);
            release_temp_name(temp_name2);
            release_temp_name($$->code_name);
            string temp_name = get_temp_name();
            $$->code_name = temp_name;
        }
        else {
            string temp_name2 = get_ftemp_name();
            file << temp_name2 << " = " <<  get_var_code_name($1->value) << ";" << endl;
            string temp_name3 = get_ftemp_name();
            file << temp_name3 << " = " << temp_name2 << " % " << $$->code_name << ";" << endl;
            file << get_var_code_name($1->value) << " = " << temp_name3 << ";" << endl;
            release_temp_name(temp_name3);
            release_temp_name(temp_name2);
            release_temp_name($$->code_name);
            string temp_name = get_ftemp_name();
            $$->code_name = temp_name;
        }
    }
    
    | ID EQUALS arith_expr 
    {
        $$ = checkType($1,$3);        
        file << get_var_code_name($1->value) << " = " << $$->code_name << ";" << endl;
    }
    | ID dims2 EQUALS arith_expr 
    {
        $$ = checkType($1,$4);
        pair<string, string> temp = return_arr($1, $2);

        if ($$->data_type == dt_int) {
            string temp_name5 = get_temp_name();
            file << temp.first << "[" << temp.second <<"]"  << " = " << $$->code_name << ";" <<  endl;
            file << temp_name5 << " = " << temp.first << "[" << temp.second <<"];" << endl;
            release_temp_name($$->code_name);
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $2->dimlist_call.clear();
            $$->code_name = temp_name5;
        }
        else {
            string temp_name5 = get_ftemp_name();
            file << temp.first << "[" << temp.second <<"]"  << " = " << $$->code_name << ";" <<  endl;
            file << temp_name5 << " = " << temp.first << "[" << temp.second <<"];" << endl;
            release_temp_name($$->code_name);
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $2->dimlist_call.clear();
            $$->code_name = temp_name5;
        }
        
    }
    | ID dims2 PLUSEQU arith_expr 
    {
        $$ = checkType($1,$4);
        pair<string, string> temp = return_arr($1, $2);

        if ($$->data_type == dt_int) {
            string temp_name5 = get_temp_name();
            string temp_name7 = get_temp_name();
            string temp_name8 = get_temp_name();
            file << temp_name7 << " = " << temp.first << "[" << temp.second << "]" << ";" <<  endl;
            file << temp_name8 << " = " << temp_name7 << " + " << $$->code_name << ";" <<  endl;
            file << temp.first << "[" << temp.second <<"]"  << " = " << temp_name8 << ";" <<  endl;

            file << temp_name5 << " = " << temp.first << "[" << temp.second <<"];" << endl;
            release_temp_name($$->code_name);
            release_temp_name(temp_name7);
            release_temp_name(temp_name8);
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $2->dimlist_call.clear();
            $$->code_name = temp_name5;
        }
        else {
            string temp_name5 = get_ftemp_name();
            string temp_name7 = get_ftemp_name();
            string temp_name8 = get_ftemp_name();
            file << temp_name7 << " = " << temp.first << "[" << temp.second << "]" << ";" <<  endl;
            file << temp_name8 << " = " << temp_name7 << " + " << $$->code_name << ";" <<  endl;
            file << temp.first << "[" << temp.second <<"]"  << " = " << temp_name8 << ";" <<  endl;

            file << temp_name5 << " = " << temp.first << "[" << temp.second <<"];" << endl;
            release_temp_name($$->code_name);
            release_temp_name(temp_name7);
            release_temp_name(temp_name8);
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $2->dimlist_call.clear();
            $$->code_name = temp_name5;
        }
            
    }
    | ID dims2 MINUSEQU arith_expr 
    {
        $$ = checkType($1,$4);
        pair<string, string> temp = return_arr($1, $2);

        if ($$->data_type == dt_int) {
            string temp_name5 = get_temp_name();
            string temp_name7 = get_temp_name();
            string temp_name8 = get_temp_name();
            file << temp_name7 << " = " << temp.first << "[" << temp.second << "]" << ";" <<  endl;
            file << temp_name8 << " = " << temp_name7 << " - " << $$->code_name << ";" <<  endl;
            file << temp.first << "[" << temp.second <<"]"  << " = " << temp_name8 << ";" <<  endl;

            file << temp_name5 << " = " << temp.first << "[" << temp.second <<"];" << endl;
            release_temp_name($$->code_name);
            release_temp_name(temp_name7);
            release_temp_name(temp_name8);
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $2->dimlist_call.clear();
            $$->code_name = temp_name5;
        }
        else {
            string temp_name5 = get_ftemp_name();
            string temp_name7 = get_ftemp_name();
            string temp_name8 = get_ftemp_name();
            file << temp_name7 << " = " << temp.first << "[" << temp.second << "]" << ";" <<  endl;
            file << temp_name8 << " = " << temp_name7 << " - " << $$->code_name << ";" <<  endl;
            file << temp.first << "[" << temp.second <<"]"  << " = " << temp_name8 << ";" <<  endl;

            file << temp_name5 << " = " << temp.first << "[" << temp.second <<"];" << endl;
            release_temp_name($$->code_name);
            release_temp_name(temp_name7);
            release_temp_name(temp_name8);
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $2->dimlist_call.clear();
            $$->code_name = temp_name5;
        }
    }
    | ID dims2 DIVEQU arith_expr 
    {
        $$ = checkType($1,$4);
        pair<string, string> temp = return_arr($1, $2);

        if ($$->data_type == dt_int) {
            string temp_name5 = get_temp_name();
            string temp_name7 = get_temp_name();
            string temp_name8 = get_temp_name();
            file << temp_name7 << " = " << temp.first << "[" << temp.second << "]" << ";" <<  endl;
            file << temp_name8 << " = " << temp_name7 << " / " << $$->code_name << ";" <<  endl;
            file << temp.first << "[" << temp.second <<"]"  << " = " << temp_name8 << ";" <<  endl;

            file << temp_name5 << " = " << temp.first << "[" << temp.second <<"];" << endl;
            release_temp_name($$->code_name);
            release_temp_name(temp_name7);
            release_temp_name(temp_name8);
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $2->dimlist_call.clear();
            $$->code_name = temp_name5;
        }
        else {
            string temp_name5 = get_ftemp_name();
            string temp_name7 = get_ftemp_name();
            string temp_name8 = get_ftemp_name();
            file << temp_name7 << " = " << temp.first << "[" << temp.second << "]" << ";" <<  endl;
            file << temp_name8 << " = " << temp_name7 << " / " << $$->code_name << ";" <<  endl;
            file << temp.first << "[" << temp.second <<"]"  << " = " << temp_name8 << ";" <<  endl;

            file << temp_name5 << " = " << temp.first << "[" << temp.second <<"];" << endl;
            release_temp_name($$->code_name);
            release_temp_name(temp_name7);
            release_temp_name(temp_name8);
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $2->dimlist_call.clear();
            $$->code_name = temp_name5;
        }
    }
    | ID dims2 MULEQU arith_expr 
    {
        $$ = checkType($1,$4);
        pair<string, string> temp = return_arr($1, $2);

        if ($$->data_type == dt_int) {
            string temp_name5 = get_temp_name();
            string temp_name7 = get_temp_name();
            string temp_name8 = get_temp_name();
            file << temp_name7 << " = " << temp.first << "[" << temp.second << "]" << ";" <<  endl;
            file << temp_name8 << " = " << temp_name7 << " * " << $$->code_name << ";" <<  endl;
            file << temp.first << "[" << temp.second <<"]"  << " = " << temp_name8 << ";" <<  endl;

            file << temp_name5 << " = " << temp.first << "[" << temp.second <<"];" << endl;
            release_temp_name($$->code_name);
            release_temp_name(temp_name7);
            release_temp_name(temp_name8);
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $2->dimlist_call.clear();
            $$->code_name = temp_name5;
        }
        else {
            string temp_name5 = get_ftemp_name();
            string temp_name7 = get_ftemp_name();
            string temp_name8 = get_ftemp_name();
            file << temp_name7 << " = " << temp.first << "[" << temp.second << "]" << ";" <<  endl;
            file << temp_name8 << " = " << temp_name7 << " * " << $$->code_name << ";" <<  endl;
            file << temp.first << "[" << temp.second <<"]"  << " = " << temp_name8 << ";" <<  endl;

            file << temp_name5 << " = " << temp.first << "[" << temp.second <<"];" << endl;
            release_temp_name($$->code_name);
            release_temp_name(temp_name7);
            release_temp_name(temp_name8);
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $2->dimlist_call.clear();
            $$->code_name = temp_name5;
        }
    }
    | ID dims2 MODEQU arith_expr 
    {
        $$ = checkType($1,$4);
        pair<string, string> temp = return_arr($1, $2);

        if ($$->data_type == dt_int) {
            string temp_name5 = get_temp_name();
            string temp_name7 = get_temp_name();
            string temp_name8 = get_temp_name();
            file << temp_name7 << " = " << temp.first << "[" << temp.second << "]" << ";" <<  endl;
            file << temp_name8 << " = " << temp_name7 << " % " << $$->code_name << ";" <<  endl;
            file << temp.first << "[" << temp.second <<"]"  << " = " << temp_name8 << ";" <<  endl;

            file << temp_name5 << " = " << temp.first << "[" << temp.second <<"];" << endl;
            release_temp_name($$->code_name);
            release_temp_name(temp_name7);
            release_temp_name(temp_name8);
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $2->dimlist_call.clear();
            $$->code_name = temp_name5;
        }
        else {
            string temp_name5 = get_ftemp_name();
            string temp_name7 = get_ftemp_name();
            string temp_name8 = get_ftemp_name();
            file << temp_name7 << " = " << temp.first << "[" << temp.second << "]" << ";" <<  endl;
            file << temp_name8 << " = " << temp_name7 << " % " << $$->code_name << ";" <<  endl;
            file << temp.first << "[" << temp.second <<"]"  << " = " << temp_name8 << ";" <<  endl;

            file << temp_name5 << " = " << temp.first << "[" << temp.second <<"];" << endl;
            release_temp_name($$->code_name);
            release_temp_name(temp_name7);
            release_temp_name(temp_name8);
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $2->dimlist_call.clear();
            $$->code_name = temp_name5;
        }
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
        string temp3;
        int flag = 0;

        if($1->data_type == dt_float && $3->data_type == dt_int){
            file << "convert " << $3->code_name  << "\n";
            temp3 = get_ftemp_name();
            file << temp3 << " = " << $3->code_name<< ";"  << endl;
            flag = 1;
        }
        else if ($1->data_type == dt_int && $3->data_type == dt_float){
            file << "convert " << $1->code_name << "\n";
            temp3 = get_ftemp_name();
            file << temp3 << " = " << $1->code_name<< ";" << endl;
            flag = 2;
        }

        string temp_name = get_temp_name();
        if(flag == 1){
            file << temp_name  << " = "  <<  temp1 << " " << $2->code_name << " " << temp3 << ";" <<  endl;
        }
        else if(flag == 2){
            file << temp_name  << " = "  <<  temp3 << " " << $2->code_name << " " << temp2 << ";" <<  endl;
        }
        else{
            file << temp_name  << " = "  <<  temp1 << " " << $2->code_name << " " << temp2 << ";" <<  endl;                
        }
        release_temp_name(temp1);
        release_temp_name(temp2);
        release_temp_name(temp3);
        $$->code_name = temp_name;
    }
;


arith_expr:  
    arith_expr op1 expr1 
    {
        string temp1 = $1->code_name;
        string temp2 = $3->code_name;
        string temp3, temp_name;
        int flag = 0;
        $$ = typecaster($1,$3);
        if($1->data_type == dt_float && $3->data_type == dt_int){
            file << "convert " << $3->code_name  << "\n";
            temp3 = get_ftemp_name();
            file << temp3 << " = " << $3->code_name << ";" << endl;
            flag = 1;
        }
        else if ($1->data_type == dt_int && $3->data_type == dt_float){
            file << "convert " << $1->code_name << "\n";
            temp3 = get_ftemp_name();
            file << temp3 << " = " << $1->code_name << ";"<< endl;
            flag = 2;
        }
        if($$->data_type == dt_int){
            temp_name = get_temp_name();
            file << temp_name  << " = "  <<  temp1 << " " << $2->code_name << " " << temp2 << ";" <<  endl;
            release_temp_name(temp1);
            release_temp_name(temp2);
        }
        else if($$->data_type == dt_float){
            temp_name = get_ftemp_name();
            if(flag == 1){
                file << temp_name  << " = "  <<  temp1 << " " << $2->code_name << " " << temp3 << ";" <<  endl;
            }
            else if(flag == 2){
                file << temp_name  << " = "  <<  temp3 << " " << $2->code_name << " " << temp2 << ";" <<  endl;
            }
            else{
                file << temp_name  << " = "  <<  temp1 << " " << $2->code_name << " " << temp2 << ";" <<  endl;                
            }
            release_temp_name(temp1);
            release_temp_name(temp2);
            release_temp_name(temp3);
        }
        $$->code_name = temp_name;
    }
    |   expr1 {$$ = $1;}
;

expr1: 
    expr1 op2 plusnegterm 
    {
        string temp1 = $1->code_name;
        string temp2 = $3->code_name;
        string temp3, temp_name;
        int flag = 0;        
        $$ = typecaster($1,$3);
        if($1->data_type == dt_float && $3->data_type == dt_int){
            file << "convert " << $3->code_name << "\n";
            temp3 = get_ftemp_name();
            file << temp3 << " = " << $3->code_name  << ";" << endl;
            flag = 1;
        }
        else if ($1->data_type == dt_int && $3->data_type == dt_float){
            file << "convert " << $1->code_name << "\n";
            temp3 = get_ftemp_name();
            file << temp3 << " = " << $1->code_name << ";" << endl;
            flag = 2;
        }
        if($$->data_type == dt_int){
            temp_name = get_temp_name();
            file << temp_name  << " = "  <<  temp1 << " " << $2->code_name << " " << temp2 << ";" <<  endl;
            release_temp_name(temp1);
            release_temp_name(temp2);
        }
        else if($$->data_type == dt_float){
            temp_name = get_ftemp_name();
            if(flag == 1){
                file << temp_name  << " = "  <<  temp1 << " " << $2->code_name << " " << temp3 << ";" <<  endl;
            }
            else if(flag == 2){
                file << temp_name  << " = "  <<  temp3 << " " << $2->code_name << " " << temp2 << ";" <<  endl;
            }
            else {
                file << temp_name  << " = "  <<  temp1 << " " << $2->code_name << " " << temp2 << ";" <<  endl;
            }
            release_temp_name(temp1);
            release_temp_name(temp2);
            release_temp_name(temp3);
        }
        $$->code_name = temp_name;
    }
    |   plusnegterm {$$ = $1;}
;

plusnegterm:
    ADD term
    {
        $$ = $2;
        string temp_name;
        if ($2->code_name[1] == 't') {
            temp_name = get_temp_name();
            string temp_name2 = get_temp_name();
            file << temp_name2 << " = " << "0" << ";" << endl;
            file << temp_name << " = " << temp_name2 << " + " << $2->code_name << ";" <<  endl;
            release_temp_name($2->code_name);
            release_temp_name(temp_name2);
            $$->code_name = temp_name;
        }
        else {
            temp_name = get_ftemp_name();
            string temp_name2 = get_ftemp_name();
            file << temp_name2 << " = " << "0.0" << ";" << endl;
            file << temp_name << " = " << temp_name2 << " + " << $2->code_name << ";" <<  endl;
            release_temp_name($2->code_name);
            release_temp_name(temp_name2);
            $$->code_name = temp_name;
        }

    }
    | SUB term {
        $$ = $2;
        string temp_name;
        if ($2->code_name[1] == 't') {
            temp_name = get_temp_name();
            string temp_name2 = get_temp_name();
            file << temp_name2 << " = " << "0" << ";" << endl;
            file << temp_name << " = " << temp_name2 << " - " << $2->code_name << ";" <<  endl;
            release_temp_name($2->code_name);
            release_temp_name(temp_name2);
            $$->code_name = temp_name;
        }
        else {
            temp_name = get_ftemp_name();
            string temp_name2 = get_ftemp_name();
            file << temp_name2 << " = " << "0.0" << ";" << endl;
            file << temp_name << " = " << temp_name2 << " - " << $2->code_name << ";" <<  endl;
            release_temp_name($2->code_name);
            release_temp_name(temp_name2);
            $$->code_name = temp_name;
        }

    }
    | term {
        $$ = $1;
    }
;

term:   
     LB arith_expr RB 
    {
        $$ = $2;
    }
    |    func_call 
    {
        $$ = $1;
        string temp_name;
        if ($1->data_type == dt_int) {
            temp_name = get_temp_name();
            file << temp_name << " = " << $1->code_name << ";" <<  endl;
            $$->code_name = temp_name;
        }
        else if ($1->data_type == dt_float) {
            temp_name = get_ftemp_name();
            file << temp_name << " = " << $1->code_name << ";" <<  endl;
            $$->code_name = temp_name;
        }
        
    }
    |    const 
    {
        $$ = $1;
        string temp_name;
        if ($1->data_type == dt_int) {
            temp_name = get_temp_name();
        }
        else {
            temp_name = get_ftemp_name();
        }
        file << temp_name << " = " << $1->value << ";" <<  endl;
        $$->code_name = temp_name;
    }
    |    ID 
    {
        set_data_type($1,1); 
        $$ = $1;
        string temp_name;
        if ($1->data_type == dt_int) {
            temp_name = get_temp_name();
        }
        else {
            temp_name = get_ftemp_name();
        }
        file << temp_name << " = " << get_var_code_name($1->value) << ";" <<  endl;
        $$->code_name = temp_name;
    }
    |    ID PLUSPLUS
    {
        set_data_type($1,1); 
        $$ = $1;
        string temp_name;
        if ($1->data_type == dt_int) {
            temp_name = get_temp_name();
        }
        else {
            temp_name = get_ftemp_name();
        }
        file << temp_name << " = " << get_var_code_name($1->value) << ";" <<  endl;
        $$->code_name = temp_name;

        if ($1->data_type == dt_int) {
            string temp_name2 = get_temp_name();
            string temp_name3 = get_temp_name();
            file << temp_name2 << " = " << temp_name << ";" << endl;
            file << temp_name3 << " = " << temp_name << ";" << endl;
            file << temp_name3 << " = " << temp_name2 << " + 1;\n";
            file << get_var_code_name($1->value)  << " = " << temp_name3 << ";" <<  endl;
            release_temp_name(temp_name2);
            release_temp_name(temp_name3);
        }
        else {
            string temp_name2 = get_ftemp_name();
            string temp_name3 = get_ftemp_name();
            string temp_name4 = get_ftemp_name();
            file << temp_name2 << " = " << temp_name << ";" << endl;
            file << temp_name3 << " = " << temp_name << ";" << endl;
            file << temp_name4 << " = 1.0;\n"; 
            file << temp_name3 << " = " << temp_name2 << " + " << temp_name4 << ";\n";
            file << get_var_code_name($1->value)  << " = " << temp_name3 << ";" <<  endl;
            release_temp_name(temp_name2);
            release_temp_name(temp_name3);
            release_temp_name(temp_name4);
        }
        
    }
    |    ID MINUSMINUS {
        set_data_type($1,1); 
        $$ = $1;
        string temp_name;
        if ($1->data_type == dt_int) {
            temp_name = get_temp_name();
        }
        else {
            temp_name = get_ftemp_name();
        }
        file << temp_name << " = " << get_var_code_name($1->value) << ";" <<  endl;
        $$->code_name = temp_name;

        if ($1->data_type == dt_int) {
            string temp_name2 = get_temp_name();
            string temp_name3 = get_temp_name();
            file << temp_name2 << " = " << temp_name << ";" << endl;
            file << temp_name3 << " = " << temp_name << ";" << endl;
            file << temp_name3 << " = " << temp_name2 << " - 1;\n";
            file << get_var_code_name($1->value)  << " = " << temp_name3 << ";" <<  endl;
            release_temp_name(temp_name2);
            release_temp_name(temp_name3);
        }
        else {
            string temp_name2 = get_ftemp_name();
            string temp_name3 = get_ftemp_name();
            string temp_name4 = get_ftemp_name();
            file << temp_name2 << " = " << temp_name << ";" << endl;
            file << temp_name3 << " = " << temp_name << ";" << endl;
            file << temp_name4 << " = 1.0;\n"; 
            file << temp_name3 << " = " << temp_name2 << " - " << temp_name4 << ";\n";
            file << get_var_code_name($1->value)  << " = " << temp_name3 << ";" <<  endl;
            release_temp_name(temp_name2);
            release_temp_name(temp_name3);
            release_temp_name(temp_name4);
        }
    }
    |    PLUSPLUS ID {
        set_data_type($2,1); 
        $$ = $2;
        string temp_name;
        if ($2->data_type == dt_int) {
            temp_name = get_temp_name();
            string temp_name2 = get_temp_name();
            string temp_name3 = get_temp_name();
            file << temp_name2 << " = " << get_var_code_name($2->value) << ";" << endl;
            file << temp_name3 << " = " << get_var_code_name($2->value) << ";" << endl;
            file << temp_name3 << " = " << temp_name2 << " + 1;\n";
            file << get_var_code_name($2->value)  << " = " << temp_name3 << ";" <<  endl;
            release_temp_name(temp_name2);
            release_temp_name(temp_name3);
            file << temp_name << " = " << get_var_code_name($2->value) << ";" <<  endl;
        }
        else {
            temp_name = get_ftemp_name();
            string temp_name2 = get_ftemp_name();
            string temp_name3 = get_ftemp_name();
            string temp_name4 = get_ftemp_name();
            file << temp_name2 << " = " << get_var_code_name($2->value) << ";" << endl;
            file << temp_name3 << " = " << get_var_code_name($2->value) << ";" << endl;
            file << temp_name4 << " = " << "1.0;\n";
            file << temp_name3 << " = " << temp_name2 << " + "<< temp_name4 <<";\n";
            file << get_var_code_name($2->value)  << " = " << temp_name3 << ";" <<  endl;
            release_temp_name(temp_name2);
            release_temp_name(temp_name3);
            release_temp_name(temp_name4);
            file << temp_name << " = " << get_var_code_name($2->value) << ";" <<  endl;
        }
        $$->code_name = temp_name;
    }
    |   MINUSMINUS ID {
        set_data_type($2,1); 
        $$ = $2;
        string temp_name;
        if ($2->data_type == dt_int) {
            temp_name = get_temp_name();
            string temp_name2 = get_temp_name();
            string temp_name3 = get_temp_name();
            file << temp_name2 << " = " << get_var_code_name($2->value) << ";" << endl;
            file << temp_name3 << " = " << get_var_code_name($2->value) << ";" << endl;
            file << temp_name3 << " = " << temp_name2 << " - 1;\n";
            file << get_var_code_name($2->value)  << " = " << temp_name3 << ";" <<  endl;
            release_temp_name(temp_name2);
            release_temp_name(temp_name3);
            file << temp_name << " = " << get_var_code_name($2->value) << ";" <<  endl;
        }
        else {
            temp_name = get_ftemp_name();
            string temp_name2 = get_ftemp_name();
            string temp_name3 = get_ftemp_name();
            string temp_name4 = get_ftemp_name();
            file << temp_name2 << " = " << get_var_code_name($2->value) << ";" << endl;
            file << temp_name3 << " = " << get_var_code_name($2->value) << ";" << endl;
            file << temp_name4 << " = " << "1.0;\n";
            file << temp_name3 << " = " << temp_name2 << " - "<< temp_name4 <<";\n";
            file << get_var_code_name($2->value)  << " = " << temp_name3 << ";" <<  endl;
            release_temp_name(temp_name2);
            release_temp_name(temp_name3);
            release_temp_name(temp_name4);
            file << temp_name << " = " << get_var_code_name($2->value) << ";" <<  endl;
        }
        $$->code_name = temp_name;
    }
    |    ID dims2
    {        
        set_data_type($1, 0);
        $$ = $1;
        ($$)->type = "array";

        pair<string, string> temp = return_arr($1, $2);
        string temp2;
        if ($1->data_type == dt_int) {
            temp2 = get_temp_name();
        }
        else {
            temp2 = get_ftemp_name();
        }
        
        file << temp2 << " = " << temp.first << "[" << temp.second <<"]" << ";" <<  endl;
        release_temp_name(temp.second);
        release_temp_name(temp.first);
        $2->dimlist_call.clear();
        $$->code_name = temp2;
    }
    |    ID dims2 PLUSPLUS
    {        
        set_data_type($1, 0);  
        $$ = $1;
        ($$)->type = "array";

        pair<string, string> temp = return_arr($1, $2);
        string temp2;
        if ($1->data_type == dt_int) {
            temp2 = get_temp_name();
        }
        else {
            temp2 = get_ftemp_name();
        }
        file << temp2 << " = " << temp.first << "[" << temp.second <<"]" << ";" <<  endl;

        if ($1->data_type == dt_int) {
            string temp_name6 = get_temp_name();
            file << temp_name6 << " = " << temp2 << ";" << endl;
            file << temp.first << "[" << temp.second <<"]" << " = " << temp_name6 << " + 1" << ";" <<  endl;
            release_temp_name(temp_name6);        
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $2->dimlist_call.clear();
            $$->code_name = temp2;
        }
        else {
            string temp_name6 = get_ftemp_name();
            string temp_name7 = get_ftemp_name();
            file << temp_name6 << " = " << temp2 << ";" << endl;
            file << temp_name7 << " = " << "1.0;\n";
            file << temp.first << "[" << temp.second <<"]" << " = " << temp_name6 << " + " << temp_name7 << ";" <<  endl;
            release_temp_name(temp_name6);  
            release_temp_name(temp_name7);        
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $2->dimlist_call.clear();
            $$->code_name = temp2;
        }
        
    }
    |    ID dims2 MINUSMINUS
    {        
        set_data_type($1, 0);  
        $$ = $1;
        ($$)->type = "array";

        pair<string, string> temp = return_arr($1, $2);
        string temp2;
        if ($1->data_type == dt_int) {
            temp2 = get_temp_name();
        }
        else {
            temp2 = get_ftemp_name();
        }
        file << temp2 << " = " << temp.first << "[" << temp.second <<"]" << ";" <<  endl;

        if ($1->data_type == dt_int) {
            string temp_name6 = get_temp_name();
            file << temp_name6 << " = " << temp2 << ";" << endl;
            file << temp.first << "[" << temp.second <<"]" << " = " << temp_name6 << " - 1" << ";" <<  endl;
            release_temp_name(temp_name6);        
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $2->dimlist_call.clear();
            $$->code_name = temp2;
        }
        else {
            string temp_name6 = get_ftemp_name();
            string temp_name7 = get_ftemp_name();
            file << temp_name6 << " = " << temp2 << ";" << endl;
            file << temp_name7 << " = " << "1.0;\n";
            file << temp.first << "[" << temp.second <<"]" << " = " << temp_name6 << " - " << temp_name7 << ";" <<  endl;
            release_temp_name(temp_name6);  
            release_temp_name(temp_name7);        
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $2->dimlist_call.clear();
            $$->code_name = temp2;
        }
    }
    |    PLUSPLUS ID dims2
    {        
        set_data_type($2, 0);
        $$ = $2;
        ($$)->type = "array";

        pair<string, string> temp = return_arr($2, $3);
        string temp2;
        if ($2->data_type == dt_int) {
            temp2 = get_temp_name();
            string temp_name6 = get_temp_name();
            file << temp_name6 << " = " << temp.first << "[" << temp.second <<"]" << ";" <<  endl;
            file << temp.first << "[" << temp.second <<"]" << " = " << temp_name6 << " + 1" << ";" <<  endl;
            release_temp_name(temp_name6);

            file << temp2 << " = " << temp.first << "[" << temp.second <<"]" << ";" <<  endl;
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $3->dimlist_call.clear();
            $$->code_name = temp2;
        }
        else {
            temp2 = get_ftemp_name();
            string temp_name6 = get_ftemp_name();
            string temp_name7 = get_ftemp_name();
            file << temp_name6 << " = " << temp.first << "[" << temp.second <<"]" << ";" <<  endl;
            file << temp_name7 << " = " << "1.0;\n";
            file << temp.first << "[" << temp.second <<"]" << " = " << temp_name6 << " + " << temp_name7 << ";" <<  endl;
            release_temp_name(temp_name6);
            release_temp_name(temp_name7);

            file << temp2 << " = " << temp.first << "[" << temp.second <<"]" << ";" <<  endl;
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $3->dimlist_call.clear();
            $$->code_name = temp2;
        }
    }
    |    MINUSMINUS ID dims2
    {        
        set_data_type($2, 0);
        $$ = $2;
        ($$)->type = "array";

        pair<string, string> temp = return_arr($2, $3);
        string temp2;
        if ($2->data_type == dt_int) {
            temp2 = get_temp_name();
            string temp_name6 = get_temp_name();
            file << temp_name6 << " = " << temp.first << "[" << temp.second <<"]" << ";" <<  endl;
            file << temp.first << "[" << temp.second <<"]" << " = " << temp_name6 << " - 1" << ";" <<  endl;
            release_temp_name(temp_name6);

            file << temp2 << " = " << temp.first << "[" << temp.second <<"]" << ";" <<  endl;
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $3->dimlist_call.clear();
            $$->code_name = temp2;
        }
        else {
            temp2 = get_ftemp_name();
            string temp_name6 = get_ftemp_name();
            string temp_name7 = get_ftemp_name();
            file << temp_name6 << " = " << temp.first << "[" << temp.second <<"]" << ";" <<  endl;
            file << temp_name7 << " = " << "1.0;\n";
            file << temp.first << "[" << temp.second <<"]" << " = " << temp_name6 << " - " << temp_name7 << ";" <<  endl;
            release_temp_name(temp_name6);
            release_temp_name(temp_name7);

            file << temp2 << " = " << temp.first << "[" << temp.second <<"]" << ";" <<  endl;
            release_temp_name(temp.second);
            release_temp_name(temp.first);
            $3->dimlist_call.clear();
            $$->code_name = temp2;
        }
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
        DataNode* func = check_func_call(($1)->value, $3->param_list);
        for (auto it: $3->param_list) {
            file << "param " << it.first << ";\n";
            release_temp_name(it.first);
        }
        if(func->data_type == dt_int){
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
            variable->value = "0";
            symbol_list.push_back(*variable);
            func->code_name =  variable->code_name;
        }
        else if(func->data_type == dt_float ){
            file << "param _fresult" << res_counter <<";\n"; 
            var *variable = new var();
            
            if (func->data_type == dt_int)
                variable->eletype = "int";
            else
                variable->eletype = "float";
            
            variable->name = "_fresult" + to_string(res_counter);
            variable->code_name =  "_fresult" + to_string(res_counter++);
            variable->level = scope;
            variable->type = "simple";
            variable->isParam = false;
            variable->value = "0";
            symbol_list.push_back(*variable);
            func->code_name =  variable->code_name;
        }
        else {
            file << "param _fresult" << res_counter <<";\n"; 
            var *variable = new var();
            
            // if (func->data_type == dt_int)
            //     variable->eletype = "int";
            // else
            //     variable->eletype = "float";
            
            variable->eletype = "void";
            variable->name = "_fresult" + to_string(res_counter);
            variable->code_name =  "_fresult" + to_string(res_counter++);
            variable->level = scope;
            variable->type = "simple";
            variable->isParam = false;
            variable->value = "0";
            symbol_list.push_back(*variable);
            func->code_name =  variable->code_name;
        }
        file << "call " << ($1)->value <<";\n";
        $3->param_list.clear();
        $$ = func;
    }
;

paramlist:  
    plist {$$ = $1;}
    | {$$ = new DataNode;}
;

plist:  
    plist COMMA expr {$$ = $1; $$->param_list.push_back({($3)->code_name,($3)->data_type});}
    | expr { $$ = new DataNode(); $$->param_list.push_back({($1)->code_name,($1)->data_type});}
;

%%

int yyerror(char *s)
{
    globflag = 0;
    extern char *yytext;
    printf("Line No. %d Error: %s at symbol %s\n",yylineno, s, yytext);
}

int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        printf("File not found\n");
        return 0;
    }
    yyin = fp;

    cout << "Compilation starts for " <<  argv[1]<< "\n";
	do {
		yyparse();
	} while(!feof(yyin));

    // if (my_errors.size() > 0) {
    //     flag = 0;
    // }

    // sort(my_errors.begin(), my_errors.end());
    // my_errors.erase(std::unique(my_errors.begin(), my_errors.end()), my_errors.end());
    // for (auto it: my_errors) {
    //     cout << it;
    // }

    if (!globflag) {
        cout << "Compilation failed for " <<  argv[1]<< "\n";
        return 1;
    }
    else {
        cout << "Compilation successful for " <<  argv[1]<< "\n";
        return 0;
    }
    
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

	
}