%{
    #include <stdio.h> 
    #include <string.h>
    #include "ast.h"

    int yylex(void);
    extern FILE *yyin;
    extern int yylineno;
    extern char* yytext; 

    struct SymbolTable {
	    char name[30];
	    int return_type;
        int num_parameters;
        int parameter_types[100];
	    struct TreeNode* definition;
        char symbol[50][30];
    };

    struct SymbolTable symbol_table[100];
    int num_symbols = 0;
    int num_functions = 0;
    int current_scope = 0;

    struct TreeNode* add_node(struct TreeNode* root, struct TreeNode* child) {
        root->children[root->num_child++] = child;
        return root;
    }

    void preorderTraversal(TreeNode* root)
    {
            if(!root)
                    return;

            printf("%s\n", root->name);
            for(int i=0; i<root->num_child; i++)
            {
                    preorderTraversal(root->children[i]);
            }
    }

%}

%union { 
    struct TreeNode* nd_obj; 
}

%token <nd_obj> VOID CHARACTER PRINTFF INT FLOAT CHAR FOR IF ELSE WHILE SWITCH CASE DEFAULT BREAK CONTINUE TRUE FALSE NUMBER FLOAT_NUM ID STR RETURN MAIN
%right <nd_obj> '='
%left <nd_obj> OR
%left <nd_obj> AND
%left <nd_obj> EQ NE
%left <nd_obj> LE GE LT GT
%left <nd_obj> ADD SUBTRACT
%left <nd_obj> MULTIPLY DIVIDE MODULO
%right <nd_obj> NOT

%type <nd_obj> program functions function functionParameters functionParameter actualParameters main datatype body printStatement cases case condition statement variablelist variable array valueList valueBlock expression value relop return functionCall arrayAccess ifStatement else

%%

program: functions main 
| main
;

functions: functions function
| function
;

function:  datatype ID '(' functionParameters ')' '{' body return '}'
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $2;
    add_node($$, $4);
    add_node($$, $7);
    add_node($$, $8);

    symbol_table[num_functions].definition = $$;
    strcpy(symbol_table[num_functions].name, $2->name);

    num_functions++;
}
;

functionParameters: functionParameters ',' functionParameter
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy($$->name, "formalParameters");
    $$->num_child = 0;
    add_node($$, $1);
    add_node($$, $3);
}
| functionParameter
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
|
{
    $$ = NULL;
}
;

functionParameter: datatype ID
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
;

functionCall: ID '(' actualParameters ')' ';'
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $3);
}
;

actualParameters: actualParameters ',' value
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy($$->name, "actualParameters");
    $$->num_child = 0;
    add_node($$, $1);
    add_node($$, $3);
}
| value
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
|
{
    $$=NULL;
}
;

main: datatype MAIN '(' ')' '{' body return '}'
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $2;
    add_node($$, $6);
    add_node($$, $7);

    symbol_table[num_functions].definition = $$;
    strcpy(symbol_table[num_functions].name, $2->name);

    num_functions++;
}
;

datatype: INT
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| FLOAT
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| CHAR
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| VOID
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
;

body: FOR '(' statement ';' condition ';' statement ')' '{' body '}'
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $3);
    add_node($$, $5);
    add_node($$, $7);
    add_node($$, $10);
}
| ifStatement
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| WHILE '(' expression ')' '{' body '}'
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $3);
    add_node($$, $6);
}
| SWITCH '(' ID ')' '{' cases '}'
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $3);
    add_node($$, $6);
}
| statement ';'
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| body body
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $2);
}
| PRINTFF '(' printStatement ')' ';'
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $3);
}
| return
;

ifStatement: IF '(' expression ')' '{' body '}' else
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $3);
    add_node($$, $6);
    add_node($$, $8);
}
;

printStatement: STR ',' variablelist
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $3);
}
| STR
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
;

else: ELSE '{' body '}'
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $3);
}
|
{
    $$ = NULL;
}
;

cases: case cases
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $2);
}
| DEFAULT ':' body
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $3);
}
;

case: CASE NUMBER ':' body
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $2);
    add_node($$, $4);

}
;

condition: value relop value
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $2);
    add_node($$, $3);

}
| TRUE
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;

}
| FALSE
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;

}
;

statement: datatype variablelist
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $2);

}
| ID '=' expression
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $2;
    add_node($$, $3);
    add_node($$, $1);


}
| datatype ID '=' expression {
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $3;
    add_node($$, $4);
    add_node($$,$2);
}
| BREAK
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| CONTINUE
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
;

variablelist: variablelist ',' variable
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $3);
}
| variablelist ',' array
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $3);
}
| variable
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| array
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
;

variable: ID '=' expression
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($$, $3);
}
| ID
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
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
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    add_node($1, $2);
    $$ = $1;
}
| expression LT expression
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    add_node($2, $1);
    add_node($2, $3);
    $$ = $2;
}
| expression GT expression
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    add_node($2, $1);
    add_node($2, $3);
    $$ = $2;
}
| expression LE expression
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    add_node($2, $1);
    add_node($2, $3);
    $$ = $2;
}
| expression GE expression
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    add_node($2, $1);
    add_node($2, $3);
    $$ = $2;
}
| expression EQ expression
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    add_node($2, $1);
    add_node($2, $3);
    $$ = $2;
}
| expression NE expression
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    add_node($2, $1);
    add_node($2, $3);
    $$ = $2;
}
| expression ADD expression
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    add_node($2, $1);
    add_node($2, $3);
    $$ = $2;
}
| expression SUBTRACT expression
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    add_node($2, $1);
    add_node($2, $3);
    $$ = $2;
}
| expression MULTIPLY expression
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    add_node($2, $1);
    add_node($2, $3);
    $$ = $2;
}
| expression DIVIDE expression
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    add_node($2, $1);
    add_node($2, $3);
    $$ = $2;
}
| expression MODULO expression
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    add_node($2, $1);
    add_node($2, $3);
    $$ = $2;
}
| expression AND expression
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    add_node($2, $1);
    add_node($2, $3);
    $$ = $2;
}
| expression OR expression
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    add_node($2, $1);
    add_node($2, $3);
    $$ = $2;
}
| '(' expression ')'
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $2;
}
| value
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| arrayAccess
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
;

arrayAccess: ID '[' expression ']'
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| ID '[' expression ']' '[' expression ']'
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
;

relop: LT
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| GT
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| LE
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| GE
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| EQ
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| NE
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
;

value: NUMBER
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| FLOAT_NUM
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| CHARACTER
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
| ID
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
}
|
{
    $$ = NULL;
}
;

return: RETURN value ';'
{
    $$ = (TreeNode*)malloc(sizeof(TreeNode));
    $$ = $1;
    add_node($1, $2);
}
|
{
    $$ = NULL;
}
;

%%

int main() {
    yyin = fopen("input.txt", "r");
    yyparse();
    for(int i=0; i<num_functions; i++) {
        preorderTraversal(symbol_table[i].definition);
    }
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s : %d : %s\n", msg, yylineno, yytext);
}