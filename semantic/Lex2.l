%{

    #include "y.tab.h"
    #include "ast.h"
    int countn=0;
%}

%option yylineno

alpha [a-zA-Z]
digit [0-9]

%%

"printf"                    { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return PRINTFF; }
"main"                      { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return MAIN; }
"int"                       { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return INT; }
"float"                     { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return FLOAT; }
"char"                      { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return CHAR; }
"void"                      { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return VOID; }
"return"                    { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return RETURN; }
"for"	                    { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return FOR; }
"if"	                    { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return IF; }
"else"	                    { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return ELSE; }
"while"                     { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return WHILE; }
"switch"                    { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return SWITCH; }
"case"                      { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return CASE; }
"default"                   { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return DEFAULT; }
"break"                     { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return BREAK; }
"continue"                  { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return CONTINUE; }
"true"                      { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return TRUE; }
"false"                     { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return FALSE; }
[-]?{digit}+                { yylval.nd_obj = (TreeNode *)malloc(sizeof(TreeNode)); strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return NUMBER; }
[+\-]?[0-9]+([.][0-9]+)?[eE][+\-]?[0-9]+|[+\-]?[0-9]+[.][0-9]+  { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return FLOAT_NUM; }
{alpha}({alpha}|{digit})*   { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return ID; }
"<="                        { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return LE; }
">="                        { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return GE; }
"=="                        { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return EQ; }
"!="                        { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return NE; }
">"	                        { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return GT; }
"<"	                        { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return LT; }
"&&"	                    { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return AND; }
"||"	                    { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return OR; }
"+"                         { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return ADD; }
"-"                         { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return SUBTRACT; }
"/"                         { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return DIVIDE; }
"*"                         { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return MULTIPLY; }
"%"                         { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return MODULO; }
"!"                         { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return NOT;}
\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \t]*                      { ; }
[\n]                        { countn++; }
.	                        { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return *yytext; }
["].*["]                    { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return STR; }
['].[']                     { strcpy(yylval.nd_obj->name,(yytext)); yylval.nd_obj->num_child = 0; strcpy(yylval.nd_obj->name,(yytext)); return CHARACTER; }

%%

int yywrap() {
    return 1;
}