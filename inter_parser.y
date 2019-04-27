%{
    #include <bits/stdc++.h>
    using namespace std;
    extern int yylex();
    extern int yyparse();
    extern FILE* yyin;
    extern int yylineno;
    int yyerror(char *s);
    ofstream file;
    ifstream input("symtab.txt");
    bool flag = 1;
    stack <int> param_stack;
    int param_count = 0;
    int setlabel = 0;
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

// %left OR
// %left AND

%union
{
	struct DataNode *datanode;
}


%token <datanode> CONVERT FPARAM FRESULT FVAR FREG RESULT PAR_AM PARAM LB VAR RB ADDR CALL FLOAT_VAL INT_VALUE REG AND OR ID LS RS EQUALS ADD SUB MUL DIV MOD GT LT GE LE COMP COLON NEQ COMMA IF GOTO LABEL WHITESPACE NEWLINE FUNC BEG END MAIN RETURN SEMICOL
// %type<datanode> type term const func_call expr1 arith_expr expr rel_expr log_expr return_stmt op1 op2 op3 dims2 
%type <datanode> op expr expr1 op1

%start start
    
%%

start: 
    {
        file.open("assembly.s");
        for(string line; getline(input, line);){
            file << line << endl;
        }
        file << "           .text" << endl;
    }
    declarations
    body_main
;

declarations: 
    declarations asg SEMICOL
    | declarations func
    | declarations error NEWLINE
    | 
;

func:
    FUNC BEG ID INT_VALUE{
        param_stack.push(stoi($4->value));
        // cout<<param_stack.top()<<endl;
        file << ($3)->value <<":\n";
    } 
    stmt_list FUNC END {
        param_stack.pop();
        file << "jr $ra"<<endl;
    }
;

body_main:
    FUNC BEG MAIN {file << "main:"<<endl;} stmt_list FUNC END {
        file << "jr $ra"<<endl;
    }
;

stmt_list:  
    stmt_list stmt
    |   
;

stmt:
    LABEL COLON {
        file << ($1)->value <<":\n";
    }
    | error NEWLINE
    | asg SEMICOL
    | CALL ID SEMICOL {
        // param_stack.push(param_count);
        file << "addi $sp, $sp, "<<-4*(param_count)<<endl;
        for(int i=0;i<10;i++){
            file << "sw $t"<<i<<", "<<-4*(20-i)<<"($sp)"<<endl;
        }
        for(int i=0;i<10;i++){
            file << "s.s $f"<<i<<", "<<-4*(10-i)<<"($sp)"<<endl;
        }
        file << "addi $sp, $sp, "<<-4*(21)<<endl;
        file << "sw $ra, 0($sp)"<<endl;
        file << "jal "<< ($2)->value << endl;
        file << "lw $ra, 0($sp)"<<endl;
        for(int i=0;i<10;i++){
            file << "lw $t"<<i<<", "<<4*(i+1)<<"($sp)"<<endl;
        }
        for(int i=0;i<10;i++){
            file << "l.s $f"<<i<<", "<<4*(10+i+1)<<"($sp)"<<endl;
        }
        file << "addi $sp, $sp, "<<4*(param_count+21)<<endl;
        param_count = 0;
    }
    | IF REG COMP INT_VALUE GOTO LABEL {
        file << "beq "<<$2->value<<", 1, "<<$6->value<<endl;
    }
    | IF REG NEQ INT_VALUE GOTO LABEL {
        file << "bne "<<$2->value<<", 1, "<<$6->value<<endl;
    }
    | GOTO LABEL {
        file << "b "<<($2)->value<<endl;
    }
    | RETURN SEMICOL {
        file << "jr $ra"<<endl;
    }
    | RETURN REG SEMICOL {
        file << "move $v0, "<<($2)->value<<endl;
        file << "jr $ra"<<endl;
    }
    | RETURN FREG SEMICOL {
        file << "mov.s $f31, "<<($2)->value<<endl;
        file << "jr $ra"<<endl;
    }
    | PARAM REG SEMICOL {
        param_count++;
        file << "sw "<<($2)->value<<", "<<-4*param_count<<"($sp)"<<endl;
    }
    | PARAM FREG SEMICOL {
        param_count++;
        file << "s.s "<<($2)->value<<", "<<-4*param_count<<"($sp)"<<endl;
    }
    | PARAM RESULT SEMICOL{
    }
    | PARAM FRESULT SEMICOL{
    }
    | CONVERT REG FREG EQUALS REG SEMICOL{
        file << "mtc1 " << $2->value << ", " << $3->value << endl;
        file << "cvt.s.w " << $3->value << ", " << $3->value << endl;
    }
    | CONVERT FREG REG EQUALS FREG SEMICOL{
        file << "cvt.w.s " << $2->value << ", " << $2->value << endl;
        file << "mfc1 " << $3->value << ", " << $2->value << endl;
    }
;



asg:
    VAR EQUALS REG {file << "sw " << $3->value << " , " + $1->value << endl;}
    | FVAR EQUALS FREG {file << "s.s " << $3->value << " , " + $1->value << endl;}
    | REG EQUALS expr {
        if($3->type=="freg"){
            file << "li "<< $1->value <<", 1"<<endl;
            file << "bc1t setlabel"<<setlabel<<endl;
            file<< "li "<<$1->value <<", 0"<<endl;
            file << "setlabel"<<setlabel++<<":"<<endl;
        }
        else if($3->type1=="div"){
            file << $3->code_name << endl;
            file << "mflo " << $1->value << endl;     
        }
        else if($3->type1=="mod"){
            file << $3->code_name << endl;
            file << "mfhi " << $1->value << endl;     
        }
        else{
            file << $1->value << ", " + $3->code_name << endl;
        }    

    }
    | FREG EQUALS expr1 {file << $1->value << ", " + $3->code_name << endl;}
    | PAR_AM EQUALS REG {
        int paramcount = param_stack.top();
        int n = ($1)->value.size();
        string s = $1->value.substr(6,n-6);
        // cout<<s<<endl;
        int x = stoi(s);

        x = (paramcount)-x+20;
        file << "sw "<<$3->value<<", "<<(x)*4<<"($sp)"<<endl;
    }
    | PAR_AM EQUALS FREG {
        int paramcount = param_stack.top();
        int n = ($1)->value.size();
        string s = $1->value.substr(6,n-6);
        // cout<<s<<endl;
        int x = stoi(s);

        x = (paramcount)-x+20;
        file << "s.s "<<$3->value<<", "<<(x)*4<<"($sp)"<<endl;
    }
    | REG EQUALS PAR_AM {
        int paramcount = param_stack.top();
        int n = ($3)->value.size();
        string s = $3->value.substr(6,n-6);
        // cout<<s<<endl;
        int x = stoi(s);
        // cout<<paramcount<<" "<<x<<endl;

        x = (paramcount)-x+20;
        file << "lw "<<$1->value<<", "<<(x)*4<<"($sp)"<<endl;
    }
    | FREG EQUALS PAR_AM {
        int paramcount = param_stack.top();
        int n = ($3)->value.size();
        string s = $3->value.substr(6,n-6);
        // cout<<s<<endl;
        int x = stoi(s);
        // cout<<paramcount<<" "<<x<<endl;

        x = (paramcount)-x+20;
        file << "l.s "<<$1->value<<", "<<(x)*4<<"($sp)"<<endl;
    }
    | VAR EQUALS RESULT {
        file << "sw $v0, "<<($1)->value<<endl;
    }
    | FVAR EQUALS FRESULT {
        file << "s.s $f31, "<<($1)->value<<endl;
    }
    | REG EQUALS RESULT {
        file << "move "<<($1)->value<<", $v0"<<endl;
    }
    | FREG EQUALS FRESULT {
        file << "mov.s "<<($1)->value<<", $f31"<<endl;
    }
    | PAR_AM EQUALS RESULT {
        int paramcount = param_stack.top();
        int n = ($1)->value.size();
        string s = $1->value.substr(6,n-6);
        // cout<<s<<endl;
        int x = stoi(s);
        x = (paramcount)-x+20;
        file << "sw $v0, "<<(x)*4<<"($sp)"<<endl;
    }
    | PAR_AM EQUALS FRESULT {
        int paramcount = param_stack.top();
        int n = ($1)->value.size();
        string s = $1->value.substr(6,n-6);
        // cout<<s<<endl;
        int x = stoi(s);
        x = (paramcount)-x+20;
        file << "s.s $f31, "<<(x)*4<<"($sp)"<<endl;
    }
    | REG EQUALS ADDR LB VAR RB {
        file << "la "<<$1->value<<", "<<$5->value<<endl;
    }
    | REG EQUALS ADDR LB FVAR RB {
        file << "la "<<$1->value<<", "<<$5->value<<endl;
    }
    | REG LS REG RS EQUALS REG {
        file << "add "<<$1->value<<", "<<$1->value<<", "<<$3->value<<endl;
        file << "sw "<<$6->value<<", ("<<$1->value<<")"<<endl;
    }
    | REG LS REG RS EQUALS FREG {
        file << "add "<<$1->value<<", "<<$1->value<<", "<<$3->value<<endl;
        file << "s.s "<<$6->value<<", ("<<$1->value<<")"<<endl;
    }
    | REG EQUALS REG LS REG RS {
        file << "add "<<$3->value<<", "<<$3->value<<", "<<$5->value<<endl;
        file << "lw "<<$1->value<<", ("<<$3->value<<")"<<endl;
    }
    | FREG EQUALS REG LS REG RS {
        file << "add "<<$3->value<<", "<<$3->value<<", "<<$5->value<<endl;
        file << "l.s "<<$1->value<<", ("<<$3->value<<")"<<endl;
    }
;

expr:
    REG op REG {$$ = $1; $$->code_name = $1->value + ", " + $3->value; $$->type1=$2->type1;}
    | VAR { file << "lw "; $$ = $1; $$->code_name = $1->value;}
    | REG { file << "move "; $$ = $1; $$->code_name = $1->value;}
    | INT_VALUE {file << "li "; $$ = $1; $$->code_name = $1->value;}
    | REG op INT_VALUE {$$ = $1; $$->code_name = $1->value + ", " + $3->value; $$->type1=$2->type1;}
    | FREG op1 FREG {
        $$=$1;
        $$->type = "freg";
        file <<$1->value << ", " << $3->value<<endl;
        $$->type1=$2->type1;
        // $$->code_name = 
    }
;

expr1:
    FREG op1 FREG {$$ = $1; $$->code_name = $1->value + ", " + $3->value; $$->type1=$2->type1;}
    | FVAR { file << "l.s "; $$ = $1; $$->code_name = $1->value;}
    | FREG { file << "mov.s "; $$ = $1; $$->code_name = $1->value;}
    | FLOAT_VAL {file << "li.s "; $$ = $1; $$->code_name = $1->value;}
;

op1:
    LT  {file << "c.lt.s "; $$=$1;}
    | GT {file << "c.gt.s "; $$=$1;}
    | LE {file << "c.le.s "; $$=$1;}
    | GE {file << "c.ge.s "; $$=$1;}
    | COMP {file << "c.eq.s "; $$=$1;}
    | NEQ {file << "c.ne.s "; $$=$1;}
    | ADD {file << "add.s "; $$=$1;}
    | SUB {file << "sub.s "; $$=$1;}
    | MUL {file << "mul.s "; $$=$1;}
    | DIV {file << "div.s ";$$=$1;$$->type1="div";}
    | MOD {file << "div.s ";$$=$1;$$->type1="mod";}
    | AND {file << "and "; $$=$1;}
    | OR  {file << "or "; $$=$1;}
;

op:
    LT  {file << "slt "; $$=$1;}
    | GT {file << "sgt ";$$=$1;}
    | LE {file << "sle ";$$=$1;}
    | GE {file << "sge ";$$=$1;}
    | COMP {file << "seq ";$$=$1;}
    | NEQ {file << "sne ";$$=$1;}
    | ADD {file << "add ";$$=$1;}
    | SUB {file << "sub ";$$=$1;}
    | MUL {file << "mul ";$$=$1;}
    | DIV {file << "div ";$$=$1;$$->type="div";}
    | MOD {file << "div ";$$=$1;$$->type="mod";}
    | AND {file << "and ";$$=$1;}
    | OR  {file << "or ";$$=$1;}
;
%%

int yyerror(char *s)
{
    flag = 0;
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

    if (!flag) {
        cout << "Compilation failed for " <<  argv[1]<< "\n";
    }
    else {
        cout << "Compilation successful for " <<  argv[1]<< "\n";
    }
}