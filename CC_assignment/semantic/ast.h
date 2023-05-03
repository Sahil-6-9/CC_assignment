#ifndef AST_H
#define AST_H "ast.h"

union Value {
	int i;
	char c;
	float f;
};

struct Symbol {
	char* name;
    int num_values;
    int num_cols;
	union Value value[50];
	int data_type;
};

typedef struct SymbolStack {
	struct Symbol* symbols;
	int num_symbols;

	struct SymbolStack *next;
	struct SymbolStack *prev;
} SymbolStack;


typedef struct Node {
	char name[30];
	union Value value[50];
	struct Node* children[100];
	int data_type;
	int num_child;
} Node; 

#endif