bison bison.y -d -v
lex lex.l
g++ bison.tab.c lex.yy.c -o test -w 
./test $1
if [ "$?" -eq 0 ]; then
    bison inter_parser.y -d -v
    lex mips_lex.l
    g++ inter_parser.tab.c lex.yy.c -o test -w
    ./test inter.txt
else
    rm inter.txt
    rm assembly.s
fi