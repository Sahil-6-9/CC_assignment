%{
    #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdbool.h>
    #include<ctype.h>

%}

digits [0-9]+
keyword (int|float|char|if|else|for|while|switch|void|break|continue|case|default|return)
operators (\+|\-|\*|\%|\/|\=|\==|\!=|\<=|\>=|\<|\>|\&&|\!)
int_const [-]?{digits}(e[+-]?{digits})?
float_const [-]?{digits}([.]{digits})(e[+-]?{digits})?
char_const ['].[']
identifier [_]*[A-Za-z]+[0-9]*[_]*
space [" "|"   "]
comment "/*"([^*]|\*+[^*/])*\*+"/"
string ["].+["]
valid_printf printf[(]{string}(,{identifier})*[)]

%%
\/\/.*\n {}
{comment} {}
\n {}
{keyword} {
    char temp[100];
    int i=0;
    while(yytext[i]){
        temp[i]=toupper(yytext[i]);
        i++;
    }
    return (temp);
}
\|\| {return OR;}
{int_const} {return (INT_CONST);}
{float_const} {return (FLOAT_CONST);}
{char_const} {return (CHAR_CONST);}
{string} {return (STR_CONST);}
"+" {return (PLUS);}
"-" {return (SUB);}
"*" {return (MULT);}
"%" {return (MOD);}
"/" {return (DIV);}
"=" {return (ASSIGN);}
"==" {return (EQEQ);}
"!=" {return (NEQ);}
"<=" {return (LEQ);}
">=" {return (GEQ);}
"<" {return (LESSER);}
">" {return (GREATER);}
"&&" {return (AND);}
"!" {return (NOT);}
"{" {return CURLY_O;}
"}" {return CURLY_C;}
"]" {return SQUARE_C;}
"[" {return SQUARE_O;}
"(" {return BRACKET_O;}
")" {return BRACKET_C;}
";" {return SEMICOLON;}
":" {return COLON;}
"." {return DOT;}
"->" {return POINTER;}
"," {return COMMA;}
{identifier} {return (IDENTIFIER);}
{space}+ {}

%%

int main(){
    yyin = fopen("data.txt", "r");
    yylex();

    return 0;
}