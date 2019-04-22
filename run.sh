bison bison.y -d -v
lex lex.l
g++ bison.tab.c lex.yy.c -o test -w 
./test $1