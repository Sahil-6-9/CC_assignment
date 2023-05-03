%{
    #include "y.tab.h"
    int countn=0;
%}

%option yylineno

alpha [a-zA-Z]
digit [0-9]

%%

"printf"                    {  return PRINTFF; }
"main"                      {  return MAIN; }
"int"                       {  return INT; }
"float"                     {  return FLOAT; }
"char"                      {  return CHAR; }
"void"                      {  return VOID; }
"return"                    {  return RETURN; }
"for"	                    {  return FOR; }
"if"	                    {  return IF; }
"else"	                    {  return ELSE; }
"while"                     {  return WHILE; }
"switch"                    {  return SWITCH; }
"case"                      {  return CASE; }
"default"                   {  return DEFAULT; }
"break"                     {  return BREAK; }
"continue"                  {  return CONTINUE; }
"true"                      {  return TRUE; }
"false"                     {  return FALSE; }
{digit}+                {  return NUMBER; }
{digit}+\.{digit}{1,6}  {  return FLOAT_NUM; }
{alpha}({alpha}|{digit})*   {  return ID; }
"<="                        {  return LE; }
">="                        {  return GE; }
"=="                        {  return EQ; }
"!="                        {  return NE; }
">"	                        {  return GT; }
"<"	                        {  return LT; }
"&&"	                    {  return AND; }
"||"	                    {  return OR; }
"+"                         {  return ADD; }
"-"                         {  return SUBTRACT; }
"/"                         {  return DIVIDE; }
"*"                         {  return MULTIPLY; }
"%"                         {  return MODULO; }
"!"                         {  return NOT;}
\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \t]*                      { ; }
[\n]                        { countn++; }
.	                        {  return *yytext; }
["].*["]                    {  return STR; }
['].[']                     {  return CHARACTER; }

%%

int yywrap() {
    return 1;
}