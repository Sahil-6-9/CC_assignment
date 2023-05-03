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
    struct Quadruple {
        int index;
        char Op[20];
        char arg1[20];
        char arg2[20];
        char result[20];
    } quad_node[1000];
    int cnt=0;
    int label = 0;
    int arr[100];
    int top = -1;
    int tempVariable = 0;
    char* genTempVariable(int id){
        char* temp = (char*)malloc(10*sizeof(char));
        temp[0] = 'T';
        snprintf(temp, 10, "T%d", id);
        return temp;
    }
    int gencode(char* lhs, char* op, char* rhs){
        printf("T%d = %s%s%s\n", tempVariable, lhs, op, rhs);
        quad_node[cnt].index=cnt;
        strcpy(quad_node[cnt].Op,op);
        strcpy(quad_node[cnt].arg1,lhs);
        strcpy(quad_node[cnt].arg2,rhs);
        char temp_var[5]="T";
        char temp_1[5]="";
        sprintf(temp_1, "%d", tempVariable);
        strcat(temp_var,temp_1);
        strcpy(quad_node[cnt].result,temp_var);
        cnt++;
        return tempVariable;
    }
    void assignment(char* lhs, char* rhs){
        printf("%s = %s \n", lhs, rhs);
        quad_node[cnt].index=cnt;
        strcpy(quad_node[cnt].Op,"=");
        strcpy(quad_node[cnt].arg1,rhs);
        strcpy(quad_node[cnt].arg2,"");
        strcpy(quad_node[cnt].result,lhs);
        cnt++;
    }

%}

%union{
    char* lexeme;
}
%token <lexeme> VOID CHARACTER PRINTFF INT FLOAT CHAR FOR IF ELSE WHILE SWITCH CASE DEFAULT BREAK CONTINUE TRUE FALSE NUMBER FLOAT_NUM ID STR RETURN MAIN
%right <lexeme> '='
%left <lexeme> OR
%left <lexeme> AND
%left <lexeme> EQ NE
%left <lexeme> LE GE LT GT
%left <lexeme> ADD SUBTRACT
%left <lexeme> MULTIPLY DIVIDE MODULO
%right <lexeme> NOT
%type <lexeme> program functions function functionParameters functionParameter actualParameters main datatype body printStatement cases case condition statement variablelist variable array valueList valueBlock expression value relop return functionCall arrayAccess ifStatement elseStatment
%%
 
program: functions main 
| main
;
 
functions: functions function
| function
;
 
function:  datatype ID '(' functionParameters ')' '{' body return '}'                                                                    
;

 
functionParameters: functionParameters ',' functionParameter 
| functionParameter 
|
;
 
functionParameter: datatype variable 
;

functionCall: ID '(' actualParameters ')' ';' 
;

 
actualParameters: actualParameters ',' variable 
| variable 
;

 
main: datatype MAIN '(' ')' '{' body return '}'  
;


datatype: INT { $$ = $1; }
| FLOAT { $$ = $1; }
| CHAR { $$ = $1; }
| VOID { $$ = $1; }
;

 
body: FOR '(' {;} statement {;}';'{ top++; printf("L%d: \n", label); arr[top] = label; label++; } expression ';' statement ')' '{' body '}' {printf("iftrue(%s) goto L%d\n", $8, arr[top--]);}
| ifStatement 
| WHILE { top++; printf("L%d: \n", label); arr[top] = label; label++; } '(' expression')' '{' body '}' {printf("iftrue(%s) goto L%d\n", $4, arr[top--]);}
| SWITCH '(' ID ')' '{' cases DEFAULT ':' body '}' 
| statement ';' 
| body body 
| PRINTFF '(' printStatement ')' ';' 
| return 
;
 
ifStatement:  IF '(' expression ')' { top++; printf("iffalse(%s) goto L%d\n",$3,label); arr[top] = label; label++; } '{' body '}' {printf("L%d: \n", arr[top--]);} elseStatment
;

elseStatment: ELSE '{' body '}'
| ELSE ifStatement
|
;
 
printStatement: STR ',' variablelist 
| STR 
;
 
cases: cases case 
|
;
 
case: CASE NUMBER ':' body
;
 
condition: value relop value {
    int a = gencode($1,$2,$3);
    char* tempVar = genTempVariable(a);
    $$ = tempVar;
    tempVariable++;
}
| TRUE
| FALSE
;
 
statement: datatype variablelist
| ID '=' expression {
    assignment($1,$3);
    $$=$1;
}
| datatype ID '=' expression {
    assignment($2,$4);
    $$=$2;
}
| arrayAccess '=' expression {

}
| BREAK
| CONTINUE
;
 
variablelist: variablelist ',' variable
| variablelist ',' array
| variable
| array
;
 
variable: ID '=' expression {
    assignment($1,$3);
    $$=$1;
}
| ID
| arrayAccess
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
 
expression: NOT expression {
    int a = gencode("","!",$2);
    char* tempVar = genTempVariable(a);
    $$ = tempVar;
    tempVariable++;
}
| expression LT expression {
    int a = gencode($1,"<",$3);
    char* tempVar = genTempVariable(a);
    $$ = tempVar;
    tempVariable++;
}
| expression GT expression {
    int a = gencode($1,">",$3);
    char* tempVar = genTempVariable(a);
    $$ = tempVar;
    tempVariable++;
}
| expression LE expression {
    int a = gencode($1,"<=",$3);
    char* tempVar = genTempVariable(a);
    $$ = tempVar;
    tempVariable++;
}
| expression GE expression{
    int a = gencode($1,">=",$3);
    char* tempVar = genTempVariable(a);
    $$ = tempVar;
    tempVariable++;
}
| expression EQ expression {
    int a = gencode($1,"==",$3);
    char* tempVar = genTempVariable(a);
    $$ = tempVar;
    tempVariable++;
}
| expression NE expression {
    int a = gencode($1,"!=",$3);
    char* tempVar = genTempVariable(a);
    $$ = tempVar;
    tempVariable++;
}
| expression ADD expression {
    int a = gencode($1,"+",$3);
    char* tempVar = genTempVariable(a);
    $$ = tempVar;
    tempVariable++;
}
| expression SUBTRACT expression {
    int a = gencode($1,"-",$3);
    char* tempVar = genTempVariable(a);
    $$ = tempVar;
    tempVariable++;
}
| expression MULTIPLY expression {
    int a = gencode($1,"*",$3);
    char* tempVar = genTempVariable(a);
    $$ = tempVar;
    tempVariable++;
}
| expression DIVIDE expression {
    int a = gencode($1,"/",$3);
    char* tempVar = genTempVariable(a);
    $$ = tempVar;
    tempVariable++;
}
| expression MODULO expression {
    int a = gencode($1,"%",$3);
    char* tempVar = genTempVariable(a);
    $$ = tempVar;
    tempVariable++;
}
| expression AND expression {
    int a = gencode($1,"&&",$3);
    char* tempVar = genTempVariable(a);
    $$ = tempVar;
    tempVariable++;
}
| expression OR expression {
    int a = gencode($1,"||",$3);
    char* tempVar = genTempVariable(a);
    $$ = tempVar;
    tempVariable++;
}
| '(' expression ')'
| value
| arrayAccess {
    $$=$1;}
| functionCall
;
 
arrayAccess: ID '[' expression ']' {
    int a = gencode("4","*",$3);
    char* tempVar = genTempVariable(a);
    tempVariable++;
    int b = gencode("","&",$1);
    char* tempVar2 = genTempVariable(b);
    tempVariable++;
    int c = gencode(tempVar,"+",tempVar2);
    char* tempVar3 = genTempVariable(c);
    tempVariable++;
    int d = gencode("","*",tempVar3);
    char* tempVar4 = genTempVariable(d);
    tempVariable++;
    $$ = tempVar4;
}
| ID '[' expression ']' '[' expression ']' 
;
 
relop: LT
| GT {$$=$1;}
| LE {$$=$1;}
| GE {$$=$1;}
| EQ {$$=$1;}
| NE {$$=$1;}
;
 
value: NUMBER
| FLOAT_NUM
| CHARACTER
| ID {$$=$1;}
|
;
 
return: RETURN value ';'
|
;
 
%%
 
int main() {
    yyin = fopen("input.txt", "r");
    yyparse();
    printf("ind\top\targ1\targ2\tres\n");
    for(int i=0;i<cnt;i++){
        printf("%d",quad_node[i].index);
        printf("\t");
        printf("%s",quad_node[i].Op);
        printf("\t");
        printf("%s",quad_node[i].arg1);
        printf("\t");
        printf("%s",quad_node[i].arg2);
        printf("\t");
        printf("%s",quad_node[i].result);
        printf("\n");
    }
}
 
void yyerror(const char* msg) {
    fprintf(stderr, "%s : %d : %s\n", msg, countn, yytext);
}