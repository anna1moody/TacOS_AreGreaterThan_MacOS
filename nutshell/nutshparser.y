%{
// This is ONLY a demo micro-shell whose purpose is to illustrate the need for and how to handle nested alias substitutions and how to use Flex start conditions.
// This is to help students learn these specific capabilities, the code is by far not a complete nutshell by any means.
// Only "alias name word", "cd word", and "bye" run.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.c"

int yylex(void);
int yyerror(char *s);
int runSetEnv(char *var, char *word);
int runPrintEnv(void);
int runUnsetEnv(char *var);
int runCD(char* arg);
int runCDn(void);
int runSetAlias(char *name, char *word);
int runPrintAlias();
int runRemoveAlias(char *name);
int runValExpansion(char *n);
%}

%union {char *string;}

%start cmd_line
%token <string> BYE SETENV PRINTENV UNSETENV CD STRING ALIAS END TILDE UNALIAS VALEXP

%%
cmd_line    :
	BYE END			                {exit(1); return 1;}
	| SETENV STRING STRING END		{runSetEnv($2, $3); return 1;}
	| PRINTENV END				{runPrintEnv(); return 1;}
	| UNSETENV STRING END			{runUnsetEnv($2); return 1;}
	| CD END					{runCDn(); return 1;}
	| CD TILDE END				{runCDn(); return 1;}
	| CD STRING END				{runCD($2); return 1;}
	| ALIAS STRING STRING END		{runSetAlias($2, $3); return 1;}
	| ALIAS END				{runPrintAlias(); return 1;}
	| UNALIAS STRING END	{runRemoveAlias($2); return 1;}
	| VALEXP END			{printf("second part, %s\n", $1);runValExpansion($1); return 1;}

%%

int yyerror(char *s) {
  printf("%s\n",s);
  return 0;
  }

int runSetEnv(char *var, char *word) {
	for (int i = 0; i < varIndex; i++) {
		if(strcmp(var, word) == 0){
			printf("Error, the variable:%s and word %s equal each other.\n", var, word);
			return 1;
		}
		else if((strcmp(varTable.var[i], var) == 0) && (strcmp(varTable.word[i], word) == 0)){
			printf("Error, the variable: %s and its corresponding word: %s already exist.\n", var, word);
			return 1;
		}
		else if(strcmp(varTable.var[i], var) == 0) {
			strcpy(varTable.word[i], word);
			return 1;
		}
	}
	strcpy(varTable.var[varIndex], var);
	strcpy(varTable.word[varIndex], word);
	varIndex++;

	return 1;
	
}

int runPrintEnv() {
	for (int i = 0; i < sizeof(varTable.var); i++) {
		if(strcmp(varTable.var[i], "") == 0) {
			return 1;
		} else {
			printf("%s=%s\n", varTable.var[i], varTable.word[i]);
		}
	}
	return 1;
}

int runUnsetEnv(char *var) {
        for (int i = 0; i < sizeof(varTable.var); i++) {
                if(strcmp(varTable.var[i], "") == 0) {
			printf("No %s variable exists.\n", var);
                        return 1;
                } else if (strcmp(varTable.var[i], var) == 0) {
                        strcpy(varTable.word[i], "");
                        return 1;
                }
        }
        return 1;
}

int runCD(char* arg) {

	if (arg[0] != '/') { // arg is relative path
		strcat(varTable.word[0], "/");
		strcat(varTable.word[0], arg);

		if(chdir(varTable.word[0]) == 0) {
			return 1;
		}
		else {
			getcwd(cwd, sizeof(cwd));
			strcpy(varTable.word[0], cwd);
			printf("Directory not found\n");
			return 1;
		}
	}
	else { // arg is absolute path
		if(chdir(arg) == 0){
			strcpy(varTable.word[0], arg);
			return 1;
		}
		else {
			printf("Directory not found\n");
                        return 1;
		}
	}
}

int runCDn() {
	if (chdir(varTable.word[1]) == 0){
	    getcwd(cwd, sizeof(cwd));
        strcpy(varTable.word[0], cwd);
		return 1;
	}
	printf("there was an error\n");
	return 1;
}

int runSetAlias(char *name, char *word) {
	if (strcmp(name, word) == 0){
		printf("Error, expansion of name:\"%s\"  and word:\"%s\" would create a loop.\n", name, word);
		return 1;
	}
	struct node* n1;
	struct node* n2;
	bool createdName = false;
	bool createdWord = false;
	//printf("nodeIndex %d graph size: %d\n", nodeIndex, graph->vertices);
	int i;
	for (i = 0; i < nodeIndex; i++){
		//printf("start of node: alias index: %d of %d\n", i, aliasIndex);
		//printf("node index: %d\n", nodeIndex);
		struct node* n = graph->array[i];

			if (strcmp(name, n->info->value) == 0){
				//printf("createdName: %s = %s\n", n->info->value, name);
				n1 = n;
				createdName = true;
			}
			if (strcmp(word, n->info->value) == 0){
				//printf("createdWord: %s = %s\n", n->info->value, word);
				n2 = n;
				createdWord = true;
			}
		
	}
		if(!createdName){
			n1 = newNode(graph, nodeIndex, name);
		}
		if(!createdWord){
			n2 = newNode(graph, nodeIndex, word);
		}
		addEdge(graph, n1, n2);
	
	
	//printf("nodeIndex %d\n", nodeIndex);
	//printGraph(graph);
	//printf(" n: %s  w: %s\n", name, word);
	if (isCyclic(graph)){
		printf("Error, expansion of name:\"%s\"  and word:\"%s\" would create a loop.\n", name, word);
		deleteEdge(graph, n1, n2);
		return 1;
	}
	/*if (strcmp(name, word) == 0) {
			printf("Error, expansion of name:\"%s\"  and word:\"%s\" would create a loop.\n", name, word);
			return 1;
	}

	for (int i = 0; i < aliasIndex; i++) {
		if((strcmp(aliasTable.name[i], word) == 0) && (strcmp(aliasTable.word[i], name) == 0)){
			printf("Error, expansion of \"%s\" would create a loop.\n", name);
			return 1;
		}
		else if(strcmp(aliasTable.name[i], name) == 0) {
			printf("%s %s %s %s\n", aliasTable.name[i], name, aliasTable.word[i], word);
			strcpy(aliasTable.word[i], word);
			return 1;
		}
	}*/
			
	
		
	
	printf(" %s %s\n",  name, word);

	strcpy(aliasTable.name[aliasIndex], name);
	strcpy(aliasTable.word[aliasIndex], word);
	aliasIndex++;
	return 1;
}

int runPrintAlias() {
	
	for (int i = 0; i < aliasIndex; i++) {
		if(strcmp(aliasTable.name[i], "") == 0) {
			return 1;
		} else {
			printf("%s=%s\n", aliasTable.name[i], aliasTable.word[i]);
		}
	}
	if (aliasIndex == 0) {
		printf("There are no available aliases\n");
	}
	return 1;
}

int runRemoveAlias(char *name) {
	if(aliasIndex == 0){
		printf("Error, the alias table is empty\n");
		return 1;
	}
	bool found = false;
	for (int i = 0; i < aliasIndex; i++) {
		if(strcmp(aliasTable.name[i], name) == 0) {
			strcpy(aliasTable.name[i], aliasTable.name[aliasIndex-1]);
			strcpy(aliasTable.word[i], aliasTable.word[aliasIndex-1]);
			strcpy(aliasTable.name[aliasIndex-1], aliasTable.name[aliasIndex]);
			strcpy(aliasTable.word[aliasIndex-1], aliasTable.word[aliasIndex]);
			aliasIndex--;
			found = true;
		}
	}
	if (!found){
		printf("Error, alias with the name %s is not in the alias table\n", name);
	}
	
	return 1;
}

int runValExpansion(char *n){
		printf("this is a valExpansion of: %s\n", n);
		return 1;

}