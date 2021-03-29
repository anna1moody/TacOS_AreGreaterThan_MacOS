%{
#include <stdio.h>
#include <stdlib.h>

%}

%token STRING_LITERAL NUMBER_LITERAL BOOLEAN_LITERAL NULL_LITERAL SEMICOLON END
%token UNDEFINED

%type <number> NUMBER_LITERAL
%type <string> STRING_LITERAL

%union {
	char string[20];
	int number;
}

%%

prog:
	stmts
;

stmts:
	  %empty
	| stmt stmts { printf("Valid JSON\n"); } ;

stmt:
	  '{' key_value_list '}'
	| STRING_LITERAL
	| NUMBER_LITERAL
	| BOOLEAN_LITERAL
	| END{ printf("goodbye ya sexy coder girl ;D \n"); exit(0);}
	| NULL_LITERAL ;

	/*
	A comma-separated list. Three different patterns here now, to represent
	lists with no items, one item, or multiple items.
	*/
key_value_list:
	  %empty
	| key_value
	| key_value_list ',' key_value;

key_value:
	  STRING_LITERAL ':' stmt;


%%
#include "lex.yy.c"

int main() {
	yyparse();
	yylex();
	return 0;
}

void yyerror(char* e) {
	printf("Error: %s\n", e);
}

int yywrap() {
	return 1;
}