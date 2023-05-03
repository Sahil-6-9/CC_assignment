%{
#include <stdio.h> 
#include <string.h>
#include<stdlib.h>
#include "ast.h"

int yylex(void);
extern FILE *yyin;

struct SymbolTable {
	char name[30];
	int return_type;
        int num_parameters;
        int parameter_types[100];
	struct Node* definition;

	char symbol[50][30];
        int num_symbols;
};

struct SymbolTable symbol_table[100];
int num_symbols = 0;
int num_functions = 0;
int current_scope = 0;

struct Node* add_node(struct Node* root, struct Node* child) {
        root->children[root->num_child++] = child;
        return root;
}

void preorderTraversal(Node* root)
{
        if(!root)
                return;

        printf("%s\n", root->name);
        for(int i=0; i<root->num_child; i++)
        {
                preorderTraversal(root->children[i]);
        }
}

int dataType = -1;

%}

%union { struct Node* node; }

%token <node> IDENTIFIER DECIMAL INTEGER STRING CHARACTER
%token <node> INT FLOAT CHAR VOID
%token <node> IF ELSE FOR WHILE SWITCH CASE DEFAULT
%token <node> BREAK CONTINUE RETURN
%token <node> MAIN PRINTF
%token <node> '='

%left <node> OR
%left <node> AND
%left <node> EQ NE
%left <node> '<' '>' GE LE
%left <node> '+' '-'
%left <node> '*' '/' '%'
%right <node>  '!'

%type <node> s program statements datatype primitive_literal integer_literal functions function formal_parameters formal_parameter actual_parameters main variable array_access statement printf compound function_call jump return looping declaration declaration_list array_declaration value_list value_block non_array_declaration expression operand assignment loop_expression for while switch case if conditional

%%

s       : program       
        { 

                for(int i=0; i<num_functions; i++) {
                        preorderTraversal(symbol_table[i].definition);
                }
                return 1;    
        }

program         
        : functions main
        {
                // $$ = (Node*)malloc(sizeof(Node));
                // strcpy($$->name, "program");
                // add_node($$, $1);
                // add_node($$, $2);
                // preorderTraversal($$);
        } 
        ;

statements      
        : statements statement
        {
                $$ = (Node*)malloc(sizeof(Node));
                strcpy($$->name, "statements");
                $$->num_child = 0;
                add_node($$, $1);
                add_node($$, $2);
        }
        | 
        {
                $$ = NULL;
        }
        ;

datatype        
        : INT 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                dataType = 0;
        }
        | FLOAT 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                dataType = 1;
        }
        | CHAR 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                dataType = 2;
        }
        ;

primitive_literal       
        : integer_literal 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | DECIMAL 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        ;

integer_literal         
        : INTEGER 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | CHARACTER 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        ;

functions       
        : functions function
        {
                // $$ = (Node*)malloc(sizeof(Node));
                // strcpy($$->name, "functions");
                // add_node($$, $1);
                // add_node($$, $2);
        }
        | 
        ;

function        
        : datatype IDENTIFIER '(' formal_parameters ')' '{' statements '}'
        { 
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $4);
                add_node($$, $7);

                symbol_table[num_functions].definition = $$;
                strcpy(symbol_table[num_functions].name, $2->name);
                symbol_table[num_functions].num_symbols = 0;

                for(int i=0; i<num_functions; i++) {
                        if(strcmp(symbol_table[num_functions].name, symbol_table[i].name) == 0) {
                                yyerror("Redeclaration of function\n");
                                break;
                        }
                }

                num_functions++;
        }
        | VOID IDENTIFIER '(' formal_parameters ')' '{' statements '}'
        { 
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $4);
                add_node($$, $7);

                symbol_table[num_functions].definition = $$;
                strcpy(symbol_table[num_functions].name, $2->name);
                symbol_table[num_functions].num_symbols = 0;

                for(int i=0; i<num_functions; i++) {
                        if(strcmp(symbol_table[num_functions].name, symbol_table[i].name) == 0) {
                                yyerror("Redeclaration of function\n");
                                break;
                        }
                }

                num_functions++;
        }
        | IDENTIFIER '(' formal_parameters ')' '{' statements '}'
        { 
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $3);
                add_node($$, $6);

                symbol_table[num_functions].definition = $$;
                strcpy(symbol_table[num_functions].name, $1->name);
                symbol_table[num_functions].num_symbols = 0;

                for(int i=0; i<num_functions; i++) {
                        if(strcmp(symbol_table[num_functions].name, symbol_table[i].name) == 0) {
                                yyerror("Redeclaration of function\n");
                                break;
                        }
                }

                num_functions++;
        }
        ;

formal_parameters       
        : formal_parameters ',' formal_parameter 
        {
                $$ = (Node*)malloc(sizeof(Node));
                strcpy($$->name, "formal_parameters");
                $$->num_child = 0;
                add_node($$, $1);
                add_node($$, $3);
        }
        | formal_parameter 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        |  
        {
                $$ = NULL;
        }
        ;

formal_parameter        
        : datatype variable 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        ;

actual_parameters       
        : actual_parameters ',' variable 
        {
                $$ = (Node*)malloc(sizeof(Node));
                strcpy($$->name, "actual_parameters");
                $$->num_child = 0;
                add_node($$, $1);
                add_node($$, $3);
        }
        | variable 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        |  
        {
                $$ = NULL;
        }
        ;

main    
        : datatype MAIN '(' ')' '{' statements '}'
        { 
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $6);

                symbol_table[num_functions].definition = $$;
                strcpy(symbol_table[num_functions].name, $2->name);
                symbol_table[num_functions].num_symbols = 0;

                num_functions++;
        } 
        | MAIN '(' ')' '{' statements '}' 
        { 
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $5);

                symbol_table[num_functions].definition = $$;
                strcpy(symbol_table[num_functions].name, $1->name);
                symbol_table[num_functions].num_symbols = 0;

                num_functions++;
        } 
        | VOID MAIN '(' ')' '{' statements '}' 
        { 
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $6);

                symbol_table[num_functions].definition = $$;
                strcpy(symbol_table[num_functions].name, $2->name);
                symbol_table[num_functions].num_symbols = 0;

                num_functions++;
        } 
        ;

variable        
        : IDENTIFIER 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | MAIN 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | PRINTF 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | array_access 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        ;

array_access    
        : IDENTIFIER '[' expression ']' 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $1);
                add_node($$, $3);
        }
        | IDENTIFIER '[' expression ']' '[' expression ']' 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $1);
                add_node($$, $3);
                add_node($$, $6);
        }
        ;

statement       
        : conditional 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
	| expression ';' 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | assignment ';' 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | declaration ';'
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | looping 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | compound 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | printf ';' 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | jump ';' 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | return ';' 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
	| case 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | ';'  
        {
                $$ = NULL;
        }
        ;

conditional     
        : if 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | switch 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        ;

printf  
        : PRINTF '(' STRING ')'
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $3);
        }
        | PRINTF '(' STRING ',' actual_parameters ')' 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $3);
                add_node($$, $5);
        }
        ;

compound        
        : '{' statements '}' 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
        }
        ;

function_call   
        : IDENTIFIER '(' actual_parameters ')' 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $3);
        }
        ;

jump    
        : BREAK 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | CONTINUE
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        } 
        ;

return  
        : RETURN expression 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $2);
        }
        | RETURN 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        ;

looping 
        : while 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | for 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        ;

declaration     
        : datatype declaration_list
        {
                $$ = (Node*)malloc(sizeof(Node));
                strcpy($$->name, "declaration");
                $$->num_child = 0;
                add_node($$, $1);
                add_node($$, $2);            
        } 
        ;

declaration_list        
        : declaration_list ',' array_declaration
        {
                $$ = (Node*)malloc(sizeof(Node));
                strcpy($$->name, "declaration_list");
                $$->num_child = 0;
                add_node($$, $1);
                add_node($$, $3);
                $$->data_type = $1->data_type;
        }
        | declaration_list ',' non_array_declaration
        {
                $$ = (Node*)malloc(sizeof(Node));
                strcpy($$->name, "declaration_list");
                $$->num_child = 0;
                add_node($$, $1);
                add_node($$, $3);

                $$->data_type = $1->data_type;
        }
        | array_declaration 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | non_array_declaration
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        } 
        ;

array_declaration       
        : IDENTIFIER '[' expression ']' 
        | IDENTIFIER '[' expression ']' '[' expression ']' 
        | IDENTIFIER '[' expression ']' '=' '{' value_list '}' 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $7;
        }
        | IDENTIFIER '[' ']' '=' '{' value_list '}'
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $6;
        }
        | IDENTIFIER '[' expression ']' '[' expression ']' '=' '{' value_list '}'
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $10;
        }
        | IDENTIFIER '[' ']' '[' expression ']' '=' '{' value_list '}'
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $9;
        }
        | IDENTIFIER '[' expression ']' '[' expression ']' '=' '{' value_block '}'
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $10;
        }
        | IDENTIFIER '[' ']' '[' expression ']' '=' '{' value_block '}'
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $9;
        }
	| IDENTIFIER '[' ']' '[' expression ']'
        | IDENTIFIER '[' expression ']' '=' STRING 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $6;
        }
        | IDENTIFIER '[' ']' '=' STRING 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $5;
        }
        ;

value_list      
        : primitive_literal 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | value_list ',' primitive_literal
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $3;

                $$->data_type = $1->data_type;
        }
        ;

value_block     
        : '{' value_list '}'
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
        }
        | '{' value_list '}' ',' value_block
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;

                $$->data_type = $2->data_type;
        }
        ;

non_array_declaration   
        : IDENTIFIER 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | IDENTIFIER '=' expression
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$->data_type = $3->data_type;
        }
        ;

expression      
        : '!' expression
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $2);
        }
        | '+' expression
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $2);
        }
        | '-' expression
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $2);
        }
        | expression '+' expression
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $1);
                add_node($$, $3);
                $$->data_type = $1->data_type;
        }
        | expression '-' expression 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $1);
                add_node($$, $3);
                $$->data_type = $1->data_type;
        }
        | expression '*' expression 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $1);
                add_node($$, $3);
                $$->data_type = $1->data_type;
        }
        | expression '/' expression
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $1);
                add_node($$, $3);
                $$->data_type = $1->data_type;
        }
        | expression '%' expression 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $1);
                add_node($$, $3);

                if($1->data_type != 1 || $3->data_type != 0) {
                        yyerror("INT REQUIRED IN %");
                }
                $$->data_type = $1->data_type;
        }
        | expression '<' expression 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $1);
                add_node($$, $3);
                $$->data_type = $1->data_type;
        }
        | expression '>' expression 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $1);
                add_node($$, $3);
                $$->data_type = $1->data_type;
        }
        | expression EQ expression 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $1);
                add_node($$, $3);
                $$->data_type = $1->data_type;
        }
        | expression NE expression 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $1);
                add_node($$, $3);
                $$->data_type = $1->data_type;
        }
        | expression GE expression 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $1);
                add_node($$, $3);
                $$->data_type = $1->data_type;
        }
        | expression LE expression 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $1);
                add_node($$, $3);
                $$->data_type = $1->data_type;
        }
        | expression AND expression 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $1);
                add_node($$, $3);
                $$->data_type = $1->data_type;
        }
        | expression OR expression 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
                add_node($$, $1);
                add_node($$, $3);
                $$->data_type = $1->data_type;
        }
        | '(' expression ')' 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $2;
        }
        | operand 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        ;

operand         
        : variable 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | function_call 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | primitive_literal 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        ;

assignment      
        : variable '=' expression 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $1->data_type = $2->data_type;
                $$ = $2;
                add_node($$, $1);
                add_node($$, $3);
        }
        ;

loop_expression         
        : expression
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        } 
        | assignment 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
        }
        | 
        {
                $$ = NULL;
        }
        ;

for     
        : FOR '(' loop_expression ';' loop_expression ';' loop_expression ')' statement 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $3);
                add_node($$, $5);
                add_node($$, $7);
                add_node($$, $9);
        }
        | FOR '(' declaration ';' loop_expression ';' loop_expression ')' statement 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $3);
                add_node($$, $5);
                add_node($$, $7);
                add_node($$, $9);
        }
        ;

while   
        : WHILE '(' loop_expression ')' statement 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $3);
                add_node($$, $5);
        }
        ;

switch  
        : SWITCH '(' expression ')' statement 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $3);
                add_node($$, $5);
        }
        ;

case    
        : CASE integer_literal ':' statement 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $2);
                add_node($$, $4);
        }
        | DEFAULT ':' statement 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $3);
        }
        ;

if      
        : IF '(' expression ')' statement 
        { 
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $3);
                add_node($$, $5);
        }
        | IF '(' expression ')' statement ELSE statement 
        {
                $$ = (Node*)malloc(sizeof(Node));
                $$ = $1;
                add_node($$, $3);
                add_node($$, $5);
                add_node($$, $7);
        }
        ;

%%

void yyerror(const char* s) {
    printf("%s", s);
    exit(0);
    return;
}

int main() {
    yyin = fopen("input.txt", "r");
    yyparse();
    return 0;
}