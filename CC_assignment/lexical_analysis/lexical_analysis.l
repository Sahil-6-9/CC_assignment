%{
    #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdbool.h>
    #include<ctype.h>
    int ind=0;
    int line_no=1;
    struct Node{
        int lineNo[100000];
        char* lexeme[100000];
        char* token_type[100000];
    };
    struct Node symbolTable;

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
\/\/.*\n {line_no++;}
{comment} {
    for(int i=0;i<yyleng;i++){
        if(yytext[i]=='\n')line_no++;
    }
}
\n {line_no++;}
{keyword} {
    //printf("%s",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(1000 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"keyword");
    char temp[100];
    int i=0;
    while(yytext[i]){
        temp[i]=toupper(yytext[i]);
        i++;
    }
    ind++;
    //return (temp);
}
\|\| {
    //printf("%s",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(10 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"operator");
    ind++;
    //return (OR)
}
{int_const} {
    //printf("%s",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"int_const");
    ind++;
    //return (INT_CONST);
}
{float_const} {
    //printf("%s",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"float_const");
    ind++;
    //return (FLOAT_CONST);
}
{char_const} {
    //printf("%s",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"char_const");
    ind++;
    //return (CHAR_CONST);
}

{string} {
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"string");
    ind++;
    //return (STR_CONST);
}


"+" {
    //printf("indentifer %s\n",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"operator");
    ind++;
    //return (PLUS);
}

"-" {
    //printf("indentifer %s\n",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"operator");
    ind++;
    //return (SUB);
}

"*" {
    //printf("indentifer %s\n",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"operator");
    ind++;
    //return (MULT);
}

"%" {
    //printf("indentifer %s\n",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"operator");
    ind++;
    //return (MOD);
}


"/" {
    //printf("indentifer %s\n",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"operator");
    ind++;
    //return (DIV);
}

"=" {
    //printf("indentifer %s\n",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"operator");
    ind++;
    //return (ASSIGN);
}

"==" {
    //printf("indentifer %s\n",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"operator");
    ind++;
    //return (EQEQ);
}

"!=" {
    //printf("indentifer %s\n",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"operator");
    ind++;
    //return (NEQ);
}

"<=" {
    //printf("indentifer %s\n",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"operator");
    ind++;
    //return (LEQ);
}

">=" {
    //printf("indentifer %s\n",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"operator");
    ind++;
    //return (GEQ);
}

"<" {
    //printf("indentifer %s\n",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"operator");
    ind++;
    //return (LESSER);
}

">" {
    //printf("indentifer %s\n",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"operator");
    ind++;
    //return (GREATER);
}

"&&" {
    //printf("indentifer %s\n",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"operator");
    ind++;
    //return (LAND);
}

"!" {
    //printf("indentifer %s\n",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"operator");
    ind++;
    //return (NOT);
}

"{" {
    //printf("%s",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(10 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"punctuators");
    ind++;
    // return CURLY_O;
}

"}" {
    //printf("%s",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(10 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"punctuators");
    ind++;
    // return CURLY_C;
}

"]" {
    //printf("%s",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(10 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"punctuators");
    ind++;
    // return SQUARE_C;
}

"[" {
    //printf("%s",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(10 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"punctuators");
    ind++;
    // return SQUARE_O;
}

"(" {
    //printf("%s",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(10 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"punctuators");
    ind++;
    // return BRACKET_O;
}

")" {
    //printf("%s",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(10 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"punctuators");
    ind++;
    // return BRACKET_C;
}

";" {
    //printf("%s",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(10 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"punctuators");
    ind++;
    // return SEMICOLON;
}

":" {
    //printf("%s",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(10 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"punctuators");
    ind++;
    // return COLON;
}

"." {
    //printf("%s",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(10 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"punctuators");
    ind++;
    // return DOT;
}

"->" {
    //printf("%s",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(10 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"punctuators");
    ind++;
    // return POINTER;
}

"," {
    //printf("%s",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(10 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"punctuators");
    ind++;
    // return COMMA;
}

{identifier} {
    //printf("indentifer %s\n",yytext);
    symbolTable.lineNo[ind]=line_no;
    symbolTable.lexeme[ind]=malloc(100 * sizeof(char));
    strcpy(symbolTable.lexeme[ind],yytext);
    symbolTable.token_type[ind]= malloc(100 * sizeof(char));
    strcpy(symbolTable.token_type[ind],"identifier");
    ind++;
    //return (IDENTIFIER);
}

{space}+ {}


%%


int main(){


    yyin = fopen("data.txt", "r");
    yylex();
    for(int i=0;i<ind;i++){
        printf("%d",symbolTable.lineNo[i]);
        printf("\t");
        printf("%s",symbolTable.lexeme[i]);
        printf("\t");
        printf("%s",symbolTable.token_type[i]);
        printf("\n");
    }

    char temp[1000]="";
    int print_ind[100];
    for(int i=0;i<100;i++)print_ind[i]=-1;
    int j=0;
    for(int i=0;i<ind;i++){
        if(strcmp(symbolTable.lexeme[i],"printf")==0){
            print_ind[j]=i;
            j++;
        }
    }
    j=0;
    while(print_ind[j]!=-1){
        int x=print_ind[j]+1;
        char brac[]=")";
        while(strcmp(symbolTable.lexeme[x],brac)){
            strcat(temp,symbolTable.lexeme[x]);
            x++;
        }
        int cnt_spec=0;
        int cnt_var=0;
        int y=-1;
        for(int i=1;i<1000;i++){
            if(temp[i]=='%'){
                if(i+1<1000 && (temp[i+1]=='d' || temp[i+1]=='c' || temp[i+1]=='s' || temp[i+1]=='f')){
                    cnt_spec++;
                }
            } 
            if(temp[i]==34){
                y=i;
            }
        }
        if(y==-1){
            printf("invalid\n");
        }
        else{
        for(;y<1000;y++){
            if(temp[y]==','){
                cnt_var++;
            }
        }
        if(cnt_spec==cnt_var){
            printf("valid printf\n");
        }
        else{
            printf("invalid\n");
        }
        }
        j++;
        strcpy(temp,"");
    }

    return 0;
}