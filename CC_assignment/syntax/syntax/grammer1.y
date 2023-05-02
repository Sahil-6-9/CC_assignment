%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();
    extern FILE* yyin;
    extern int countn;
    extern char* yytext;
%}

%token VOID CHARACTER PRINTFF INT FLOAT CHAR FOR IF ELSE WHILE SWITCH CASE DEFAULT BREAK CONTINUE TRUE FALSE NUMBER FLOAT_NUM ID AND OR STR RETURN MAIN
%right '='
%left OR
%left AND
%left EQ NE
%left LE GE LT GT
%left ADD SUBTRACT
%left MULTIPLY DIVIDE MODULO
%right NOT

%%
s: program {printf("Valid Syntax\n");}
program: functions main 
| main
;

functions: functions function
| function
;

function:  datatype ID '(' functionParameter ')' '{' body return '}'
;

functionParameter: functionParameter ',' datatype ID
| datatype ID
|
;

functionCall: ID '(' actualParameters ')' ';'
;

actualParameters: actualParameters ',' ID
| ID
;

main: datatype MAIN '(' ')' '{' body return '}'
;

datatype: INT
| FLOAT
| CHAR
| VOID
;

body: FOR '(' statement ';' expression ';' statement ')' '{' body '}'
| ifStatement
| WHILE '(' expression ')' '{' body '}'
| SWITCH '(' ID ')' '{' cases '}'
| statement ';' 
| body body
| PRINTFF '(' printStatement ')' ';' 
| return
;

ifStatement: IF '(' expression ')' '{' body '}' else
;

printStatement: STR ',' variablelist
| STR
;

else: ELSE '{' body '}'
|
;

cases: case cases
| DEFAULT ':' body
;

case: CASE NUMBER ':' body
;

condition: value relop value 
| TRUE
| FALSE
;

statement: datatype variablelist
| ID '=' expression
| datatype ID '=' expression
| BREAK
| CONTINUE
;

variablelist: variablelist ',' variable
| variablelist ',' array
| variable
| array
;

variable: ID '=' expression
| ID
;

array: ID '[' ']' '=' '{' valueList '}'
| ID '[' NUMBER ']'
| ID '[' ']' '[' NUMBER ']'
| ID '[' NUMBER ']' '=' '{' valueList '}'
| ID '[' NUMBER ']' '[' NUMBER ']' '=' '{' valueList '}'
| ID '[' ']' '[' NUMBER ']' '=' '{' valueList '}'
| ID '[' NUMBER ']' '[' NUMBER ']' '=' '{' valueBlock '}'
| ID '[' ']' '[' NUMBER ']' '=' '{' valueBlock '}'
| ID '[' NUMBER ']' '=' STR 
| ID '[' ']' '=' STR
;



valueList: valueList ',' value
| value
;

valueBlock: valueBlock ',' '{' valueList '}'
| '{' valueList '}'
;

expression: NOT expression
| expression LT expression
| expression GT expression
| expression LE expression
| expression GE expression
| expression EQ expression
| expression NE expression
| expression ADD expression
| expression SUBTRACT expression
| expression MULTIPLY expression
| expression DIVIDE expression
| expression MODULO expression
| expression AND expression
| expression OR expression
| '(' expression ')'
| value
| arrayAccess
;

arrayAccess: ID '[' expression ']'
| ID '[' expression ']' '[' expression ']'
;

relop: LT
| GT
| LE
| GE
| EQ
| NE
;

value: NUMBER
| FLOAT_NUM
| CHARACTER
| ID
|
;

return: RETURN value ';'
|
;

%%

int main() {
    yyin = fopen("input.txt", "r");
    yyparse();
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s : %d : %s\n", msg, countn, yytext);
}