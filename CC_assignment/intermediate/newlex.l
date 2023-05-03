%{
    #include "y.tab.h"
    int countn=0;
%}

%option yylineno

alpha [a-zA-Z]
digit [0-9]

%%

"printf"                    {yylval.lexeme = strdup(yytext);  return PRINTFF; }
"main"                      {yylval.lexeme = strdup(yytext);  return MAIN; }
"int"                       {yylval.lexeme = strdup(yytext);  return INT; }
"float"                     {yylval.lexeme = strdup(yytext);  return FLOAT; }
"char"                      {yylval.lexeme = strdup(yytext);  return CHAR; }
"void"                      {yylval.lexeme = strdup(yytext);  return VOID; }
"return"                    {yylval.lexeme = strdup(yytext);  return RETURN; }
"for"                       {yylval.lexeme = strdup(yytext);  return FOR; }
"if"                        {yylval.lexeme = strdup(yytext);  return IF; }
"else"                      {yylval.lexeme = strdup(yytext);  return ELSE; }
"while"                     {yylval.lexeme = strdup(yytext);  return WHILE; }
"switch"                    {yylval.lexeme = strdup(yytext);  return SWITCH; }
"case"                      {yylval.lexeme = strdup(yytext);  return CASE; }
"default"                   {yylval.lexeme = strdup(yytext);  return DEFAULT; }
"break"                     {yylval.lexeme = strdup(yytext);  return BREAK; }
"continue"                  {yylval.lexeme = strdup(yytext);  return CONTINUE; }
"true"                      {yylval.lexeme = strdup(yytext);  return TRUE; }
"false"                     {yylval.lexeme = strdup(yytext);  return FALSE; }
{digit}+                {yylval.lexeme = strdup(yytext);  return NUMBER; }
{digit}+\.{digit}{1,6}  {yylval.lexeme = strdup(yytext);  return FLOAT_NUM; }
{alpha}({alpha}|{digit})*   {yylval.lexeme = strdup(yytext);  return ID; }
"<="                        {yylval.lexeme = strdup(yytext);  return LE; }
">="                        {yylval.lexeme = strdup(yytext);  return GE; }
"=="                        {yylval.lexeme = strdup(yytext);  return EQ; }
"!="                        {yylval.lexeme = strdup(yytext);  return NE; }
">"                         {yylval.lexeme = strdup(yytext);  return GT; }
"<"                         {yylval.lexeme = strdup(yytext);  return LT; }
"&&"                        {yylval.lexeme = strdup(yytext);  return AND; }
"||"                        {yylval.lexeme = strdup(yytext);  return OR; }
"+"                         {yylval.lexeme = strdup(yytext);  return ADD; }
"-"                         {yylval.lexeme = strdup(yytext);  return SUBTRACT; }
"/"                         {yylval.lexeme = strdup(yytext);  return DIVIDE; }
"*"                         {yylval.lexeme = strdup(yytext);  return MULTIPLY; }
"%"                         {yylval.lexeme = strdup(yytext);  return MODULO; }
"!"                         {yylval.lexeme = strdup(yytext);  return NOT;}
\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \t]*                      { ; }
[\n]                        {countn++; }
.                           {yylval.lexeme = strdup(yytext);  return *yytext; }
["].*["]                    {yylval.lexeme = strdup(yytext);  return STR; }
['].[']                     {yylval.lexeme = strdup(yytext);  return CHARACTER; }

%%

int yywrap() {
    return 1;
}