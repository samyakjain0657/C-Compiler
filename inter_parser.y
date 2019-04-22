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

    int param_count = 0;

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


%token <datanode> RESULT PAR_AM PARAM LB VAR RB ADDR CALL FLOAT_VAL INT_VALUE REG AND OR ID LS RS EQUALS ADD SUB MUL DIV MOD GT LT GE LE COMP COLON NEQ COMMA IF GOTO LABEL WHITESPACE NEWLINE FUNC BEG END MAIN RETURN SEMICOL
// %type<datanode> type term const func_call expr1 arith_expr expr rel_expr log_expr return_stmt op1 op2 op3 dims2 
%type <datanode> op expr term

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
    func FUNC BEG body_main FUNC END {
        file << "jr $ra"<<endl;
    }
;

func:
    func FUNC BEG ID {
        file << ($4)->value <<":\n";
    } 
    stmt_list FUNC END {
        file << "jr $ra"<<endl;
    }
    |
;


body_main:
    MAIN {
        file << "main:"<<endl;
    } 
    stmt_list 
;

stmt_list:  
    stmt_list stmt
    |   
;

stmt:
    LABEL COLON {
        file << ($1)->value <<":\n";
    }
    | asg SEMICOL
    | CALL ID SEMICOL {
        file << "addi $sp, $sp, "<<-4*(1+param_count)<<endl;
        file << "sw $ra, 0($sp)"<<endl;
        file << "jal "<< ($2)->value << endl;
        file << "lw $ra, 0($sp)"<<endl;
        file << "addi $sp, $sp, "<<4*(param_count+1)<<endl;
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
    | PARAM term SEMICOL {
        param_count++;
        file << "sw "<<($2)->value<<", "<<-4*param_count<<"($sp)"<<endl;
    }
    | PARAM RESULT SEMICOL{
    }
;

term:
    VAR {$$=$1;}
    | REG {$$=$1;}
    | INT_VALUE {$$=$1;}
    | FLOAT_VAL {$$=$1;}
;

asg:
    VAR EQUALS REG {file << "sw " << $3->value << " , " + $1->value << endl;}
    | REG EQUALS expr {file << $1->value << ", " + $3->code_name << endl;}
    | REG LS REG RS EQUALS expr
    | PAR_AM EQUALS REG {
        int n = ($1)->value.size();
        string s = $1->value.substr(6,n-6);
        // cout<<s<<endl;
        int x = stoi(s);
        file << "sw "<<$3->value<<", "<<(x+1)*4<<"($sp)"<<endl;
    }
    | REG EQUALS PAR_AM {
        int n = ($3)->value.size();
        string s = $3->value.substr(6,n-6);
        // cout<<s<<endl;
        int x = stoi(s);
        file << "lw "<<$1->value<<", "<<(x+1)*4<<"($sp)"<<endl;
    }
    | VAR EQUALS RESULT {
        file << "sw $v0, "<<($1)->value<<endl;
    }
    | REG EQUALS RESULT {
        file << "sw $v0, "<<($1)->value<<endl;
    }
    | PAR_AM EQUALS RESULT {
        int n = ($1)->value.size();
        string s = $1->value.substr(6,n-6);
        // cout<<s<<endl;
        int x = stoi(s);
        file << "sw $v0, "<<(x+1)*4<<"($sp)"<<endl;
    }
;

expr:
    REG op REG {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | REG LS REG RS
    | VAR { file << "lw "; $$ = $1; $$->code_name = $1->value;}
    | REG { file << "move "; $$ = $1; $$->code_name = $1->value;}
    | INT_VALUE {file << "li "; $$ = $1; $$->code_name = $1->value;}
    | FLOAT_VAL {file << "li "; $$ = $1; $$->code_name = $1->value;}
    | ADDR LB REG RB
    | REG op INT_VALUE {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
;

op:
    LT  {file << "slt ";}
    | GT {file << "sgt ";}
    | LE {file << "sle ";}
    | GE {file << "sge ";}
    | COMP {file << "seq ";}
    | NEQ {file << "sne ";}
    | ADD {file << "add ";}
    | SUB {file << "sub ";}
    | MUL {file << "mul ";}
    | DIV {file << "div ";}
    | MOD 
    | AND {file << "and ";}
    | OR  {file << "or ";}
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
}