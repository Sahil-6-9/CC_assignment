%{
    #include "y.tab.h"
    #include <string.h>
    #include "ast.h"
%}

%option yylineno

all_char .*

comment ([/][/]{all_char}[\n])|("/"([^]|\+[^/])\+"/")
identifier [a-zA-Z_][a-zA-Z0-9_]*
float [0-9]+([.][0-9]+)?[eE][+\-]?[0-9]+|[+\-]?[0-9]+[.][0-9]+
integer [0-9]+
punctuator [()\[\]\"'{};:,&]
character_literal ['].[']
string_literal ["]{all_char}["]
header "#include"{all_char}[>"]

%%

"if"  { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext));  return IF; }

"else"  { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return ELSE; }

"for"   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return FOR; }

"while"   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return WHILE; }

"switch" { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return SWITCH; }

"case"  { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return CASE; }

"default"   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return DEFAULT; }

"break"   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return BREAK; }

"continue"  { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return CONTINUE; }

"return"  { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return RETURN; }

"int"   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return INT; }

"float"   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return FLOAT; }

"char"  { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return CHAR; }   

"void" { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return VOID; }

"main"  { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return MAIN; }

"printf"    { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return PRINTF; }

"!="  { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return NE; }

"=="  { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return EQ; }

">="  { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return GE; }

"<="  { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return LE; }

"&&"  { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return AND; }

"||"  { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return OR; }

"!"   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return yytext[0]; }

"/"   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return yytext[0]; }

"%"   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return yytext[0]; }

"+"   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return yytext[0]; }

"*"   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return yytext[0]; }

"-"   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return yytext[0]; }

"<"   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return yytext[0]; }

">"   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return yytext[0]; }

"="   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return yytext[0]; }

{character_literal}   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); yylval.node->data_type = 2;  return CHARACTER; }

{string_literal}  { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); yylval.node->data_type = 2; return STRING; }

{integer}   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); yylval.node->data_type = 1; return INTEGER; }

{float}   { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); yylval.node->data_type = 3; return DECIMAL; }

{punctuator}  { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return yytext[0]; }

{identifier}  { yylval.node = (Node*)malloc(sizeof(Node)); yylval.node->num_child = 0; strcpy(yylval.node->name, (yytext)); return IDENTIFIER; }

[\n]  { yylineno++; }

{comment}   ;

{header}  ;

.   ;

%%

yywrap()
{
	return(1);
}