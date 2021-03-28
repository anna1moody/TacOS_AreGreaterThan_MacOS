%{
#include <stdio.h>

int yylex();
int yyparse();
void yyerror(char* e);
%}

%token STRING_LITERAL NUMBER_LITERAL BOOLEAN_LITERAL NULL_LITERAL SEMICOLON
%token UNDEFINED

%%

prog:
	stmts
;

stmts:
	  %empty
	| stmt stmts { printf("Valid JSON\n"); } ;

stmt:
	  '{' key_value_list '}'
	| STRING_LITERAL{ printf("You've entered a string - %s", $1);}
	| NUMBER_LITERAL{ printf("You've entered a number - %d", $1)}
	| BOOLEAN_LITERAL
	| NULL_LITERAL ;

	/*
	A comma-separated list. Three different patterns here now, to represent
	lists with no items, one item, or multiple items.
	*/
key_value_list:
	  %empty
	| key_value
	| key_value_list ',' key_value ;

key_value:
	  STRING_LITERAL ':' stmt ;


%%

void yyerror(char* e) {
	printf("Error: %s\n", e);
}

int main() {
	yyparse();
	return 0;
}