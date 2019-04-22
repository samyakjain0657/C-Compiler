<<<<<<< HEAD
bison bison.y -d -v
=======
bison bison.y -d
>>>>>>> 6538ce2e9de3d0101e83a6336b0f4e7ac00038ef
lex lex.l
g++ bison.tab.c lex.yy.c -o test -w 
./test $1
bison inter_parser.y -d -v
lex mips_lex.l
g++ inter_parser.tab.c lex.yy.c -o test -w
./test inter.txt