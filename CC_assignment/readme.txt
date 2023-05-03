2020A7PA2065H Sahil
2020A7PS1720H Muffudal
2020A7PA2063H Dhruv
2020A7PS0116H Sai Hemanth
2020A7PS1724H Nikhil

How to run
1.Lexical_analysis
lex lexcical_analysis.l

2.syntax
yacc grammer1.y -d
lex Lex.l
cc lex.yy.c y.tab.c -lfl
./a.out

3.semantic
yacc grammer2.y -d
lex Lex2.l
cc lex.yy.c y.tab.c -lfl
./a.out


4.intermediate
yacc grammer.y -d
lex newlex.l
cc lex.yy.c y.tab.c -lfl
./a.out