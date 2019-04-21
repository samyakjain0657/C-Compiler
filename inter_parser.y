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


%token <datanode> LB VAR RB ADDR CALL FLOAT_VAL INT_VALUE REG AND OR ID LS RS EQUALS ADD SUB MUL DIV MOD GT LT GE LE COMP COLON NEQ COMMA IF GOTO LABEL WHITESPACE NEWLINE FUNC BEG END MAIN RETURN SEMICOL
// %type<datanode> type term const func_call expr1 arith_expr expr rel_expr log_expr return_stmt op1 op2 op3 dims2 
%type <datanode> op expr

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
    func FUNC BEG body_main FUNC END
;

func:
    func FUNC BEG func_def FUNC END
    |
;

func_def:
    ID stmt_list 
;

body_main:
    MAIN stmt_list 
;

stmt_list:  
    stmt_list stmt
    |   
;

stmt:
    LABEL COLON
    | asg SEMICOL
    | CALL ID SEMICOL
    | IF expr GOTO LABEL
    | GOTO LABEL
    | RETURN SEMICOL
    | RETURN term SEMICOL
    | "param" term SEMICOL
;

term:
    VAR 
    | REG
    | INT_VALUE
    | FLOAT_VAL
;

asg:
    VAR EQUALS expr {file << $1->value << ", " + $3->code_name << endl;}
    | REG EQUALS expr {file << $1->value << ", " + $3->code_name << endl;}
    | REG LS REG RS EQUALS expr
;

expr:
     VAR op VAR {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | VAR op REG  {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | VAR op INT_VALUE {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | VAR op FLOAT_VAL {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | REG op VAR {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | REG op REG {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | REG op INT_VALUE {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | REG op FLOAT_VAL {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | INT_VALUE op VAR {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | INT_VALUE op REG {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | INT_VALUE op INT_VALUE {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | INT_VALUE op FLOAT_VAL {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | FLOAT_VAL op VAR {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | FLOAT_VAL op REG {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | FLOAT_VAL op INT_VALUE {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | FLOAT_VAL op FLOAT_VAL {$$ = $1; $$->code_name = $1->value + ", " + $3->value;}
    | REG LS REG RS
    | REG {$$ = $1; $$->code_name = $1->value;}
    | VAR {$$ = $1; $$->code_name = $1->value;}
    | INT_VALUE {file << "li "; $$ = $1; $$->code_name = $1->value;}
    | FLOAT_VAL {file << "li "; $$ = $1; $$->code_name = $1->value;}
    | ADDR LB VAR RB
    | ADDR LB REG RB

;

op:
    LT 
    | GT
    | LE
    | GE
    | COMP
    | NEQ
    | ADD {file << "add ";}
    | SUB {file << "sub ";}
    | MUL {file << "mult ";}
    | DIV {file << "div ";}
    | MOD
    | AND
    | OR
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