#include <stdio.h>
#include "test.h"

int yylex();
extern char* yytext;

int main() {
	while (1) {
		int token = yylex();
		if (token == 0) break;
	}
}