bison bison.y -d
lex lex.l
g++ bison.tab.c lex.yy.c -o test -Wall -g
gdb ./test 