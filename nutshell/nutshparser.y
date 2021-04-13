%{
// This is ONLY a demo micro-shell whose purpose is to illustrate the need for and how to handle nested alias substitutions and how to use Flex start conditions.
// This is to help students learn these specific capabilities, the code is by far not a complete nutshell by any means.
// Only "alias name word", "cd word", and "bye" run.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <errno.h>
#include "graph.c"

void resetPATH();
void getPATHS(char** paths);

int yylex(void);
int yyerror(char *s);
int yyparse();

int runSetEnv(char *var, char *word);
int runPrintEnv(void);
int runUnsetEnv(char *var);
int runCD(char* arg);
int runCDn(void);
int runSetAlias(char *name, char *word);
int runPrintAlias();
int runRemoveAlias(char *name);
int runBasic(char *name);
bool wildCardHelper(char* curFile, char* arg);
char* runWildCard(char *card, char *arg);

int argCount = 0;
int inputCounter = 0;
int outputCounter = 0;

void fixComTable(char *name);
void addArguments(char *arg);
void fixArguments();
void fixIO(char *arg);

void stderror(char *arg);
void stderr_stdout();
%}

%union {char *string;}

%start cmd_line
%token <string> BYE SETENV PRINTENV UNSETENV CD STRING ALIAS END TILDE UNALIAS VALEXP BASIC AND INPUT OUTPUT DOUBLE STDERR STDERRSTDOUT

//%nterm <string> basic
%nterm <string> command
%nterm <string> args
%nterm <string> meta
%nterm <string> err

%%
cmd_line    :
	BYE END			                {exit(1); return 1;}
	| SETENV STRING STRING END		{runSetEnv($2, $3); return 1;}
	| PRINTENV END				{runPrintEnv(); return 1;}
	| PRINTENV meta args			{runPrintEnv(); return 1;}
	| UNSETENV STRING END			{runUnsetEnv($2); return 1;}
	| CD END				{runCDn(); return 1;}
	| CD TILDE END				{runCDn(); return 1;}
	| CD STRING END				{runCD($2); return 1;}
	| ALIAS STRING STRING END		{runSetAlias($2, $3); return 1;}
	| ALIAS END				{runPrintAlias(); return 1;}
	| UNALIAS STRING END			{runRemoveAlias($2); return 1;}
	| command args                          {addArguments("null"); fixArguments(); runBasic($1); return 1;}
	;
/*
basic:
        BASIC                                   {$$ = $1; fixComTable($1); addArguments($1);}
        ;
*/

command:
	STRING					{$$ = $1; fixComTable($1); addArguments($1);}
	;

args:
        STRING args                             {$$ = $1; addArguments($1); fixIO($1);}
        | meta args
	| err args								
	| END					
        ;

meta:
        INPUT                                   {inputCounter++; commandTable.in = 1; commandTable.out = 0;}
        | OUTPUT                                {outputCounter++; commandTable.in = 0; commandTable.out = 1;}
	| DOUBLE				{outputCounter++; commandTable.isDouble = true; commandTable.in = 0; commandTable.out = 1;};
        ;

err:
	STDERR					{outputCounter++; stderror($1);}
	| STDERRSTDOUT				{stderr_stdout();}
	;

%%

bool wildCardHelper(char* curFile, char* arg){
	if (*arg == '\0' && *curFile == '\0'){
		return true;
	}

	if(*arg == '*' && *(arg+1) != '\0' && *curFile == '\0'){
		return false;
	}
	
	if (*arg == '?' || *arg == *curFile){
		return wildCardHelper(curFile+1, arg+1);
	}
	
	if(*arg == '*'){
		return wildCardHelper(curFile, arg+1) || wildCardHelper(curFile+1, arg);
	}
	return false;
	
}

char* runWildCard(char* card, char* arg){
	DIR *d;
	struct dirent *dir;
	d = opendir(".");
	if (d){
		while ((dir = readdir(d)) != NULL){
			if (wildCardHelper(dir->d_name, arg)){
				return dir->d_name;
			}
		}
	}
	printf("Error, couldn't find a matching file to %s\n", arg);
	return arg;
}

void fixComTable(char *name) {
        strcpy(commandTable.command[0], name);
}

void addArguments(char *arg) {
	int pCount = 0;

        if(strcmp(arg, "null") == 0) {
                strcpy(commandTable.comArgs[argCount], "NULL");
		argCount++;
        } else if(inputCounter > 0 || outputCounter > 0) {
		//Skip adding argument if input or output
	} else {
		if (strchr(arg, '?') != NULL || strchr(arg, '*') != NULL) {
			pCount = argCount;
			char temp[100];
			DIR *d;
			struct dirent *dir;
			d = opendir(".");
			if (d){
				while ((dir = readdir(d)) != NULL){
					if (wildCardHelper(dir->d_name, arg)){
						strcpy(commandTable.comArgs[argCount], dir->d_name);
						argCount++;
					}
				}
				for(int i=pCount;i<=argCount;i++) {
					for(int j=i+1;j<=argCount-1;j++) {
						if(strcmp(commandTable.comArgs[i],commandTable.comArgs[j]) < 0) {
							strcpy(temp,commandTable.comArgs[i]);
							strcpy(commandTable.comArgs[i],commandTable.comArgs[j]);
							strcpy(commandTable.comArgs[j],temp);
						}
					}
				}
			}
			pattern = true;
                } else {
			pattern = false;
			strcpy(commandTable.comArgs[argCount], arg);
			argCount++;
		}
        }
		
}

void fixArguments() {
	if(argCount == 2 || argCount == 3) {
                return;
        } else {
                int j = argCount - 2;
                for(int i = 1; i < j; i++) {
                        strcpy(commandTable.temp[0], commandTable.comArgs[i]);
                        strcpy(commandTable.comArgs[i], commandTable.comArgs[j]);
                        strcpy(commandTable.comArgs[j], commandTable.temp[0]);
                        j--;
                }
        }
}

void resetArguments() {
        for(int i = 0; i < argCount; i++) {
                strcpy(commandTable.comArgs[i], "");
		strcpy(commandTable.input[i], "");
		strcpy(commandTable.output[i], "");
        }
	commandTable.in = 0;
	commandTable.out = 0;
	commandTable.isDouble = 0;
	commandTable.stderr_stdoutput = 0;
	inputIndex = 0;
	outputIndex = 0;
	inputCounter = 0;
        outputCounter = 0;
}

void fixIO(char *arg) {
	if(outputCounter > 0) {
                strcpy(commandTable.output[outputIndex], arg);
                //commandTable.out = 0;
                //commandTable.in = 0;
                outputIndex++;
                outputCounter--;
        } else if(inputCounter > 0) {
		strcpy(commandTable.input[inputIndex], arg);
		//commandTable.in = 0;
		//commandTable.out = 0;
		inputIndex++;
		inputCounter--;
	}
}

void stderror(char *arg) {
	char fixed[strlen(arg) - 2];
	for(int i = 2; i < strlen(arg); i++) { // Clip 2> from output path
		fixed[i-2] = arg[i];
	}
	printf("%s\n", fixed);
	strcpy(commandTable.output[1], fixed);
}

void stderr_stdout() {
	commandTable.stderr_stdoutput = true; // Flag I/O redirection from 
}

void resetPATH() {
        strcpy(varTable.word[3], ".:/bin");
}

void getPATHS(char** paths) {
        char *str = malloc(128 * sizeof(char));
        strcpy(str, varTable.word[3]);
        int init_size = strlen(str);
        char delim[] = ":";

        char *ptr = strtok(str, delim);

        int pathCount = 0;
        while (ptr != NULL)
        {
                paths[pathCount] = ptr;
                pathCount++;
                ptr = strtok(NULL, delim);
        }
}

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

//wondering if that i should be varIndex
int runPrintEnv() {
	if(commandTable.output[0] != "") {
		printf("There is output file: %s\n", commandTable.output[0]);
	}
	for (int i = 0; i < sizeof(varTable.var); i++) {
		if(strcmp(varTable.var[i], "") == 0) {
			return 1;
		} else {
			printf("%s=%s\n", varTable.var[i], varTable.word[i]);
		}
	}
	resetArguments();
	printf("Output is clean: %s\n", commandTable.output[0]);
	argCount = 0;
	return 1;
}

int runUnsetEnv(char *var) {
        for (int i = 0; i < sizeof(varTable.var); i++) {
                if(strcmp(varTable.var[i], "") == 0) {
						printf("No %s variable exists.\n", var);
                        return 1;
                } else if (strcmp(var, "HOME") == 0) {
						printf("Error: cannot unset HOME\n");
						return 1;
				} else if (strcmp(var, "PATH") == 0) {
						printf("Error: cannot unset PATH\n");
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
	int i;
	for (i = 0; i < nodeIndex; i++){
		struct node* n = graph->array[i];
		if (strcmp(name, n->info->value) == 0){
			n1 = n;
			createdName = true;
		}
		if (strcmp(word, n->info->value) == 0){
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
	
	if (isCyclic(graph)){
		printf("Error, expansion of name:\"%s\"  and word:\"%s\" would create a loop.\n", name, word);
		deleteEdge(graph, n1, n2);
		return 1;
	}
	

	for (int i = 0; i < aliasIndex; i++) {
		if(strcmp(aliasTable.name[i], name) == 0) {
			strcpy(aliasTable.word[i], word);
			return 1;
		}
	}
		
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

int runBasic(char *name) {

        strcat(varTable.word[3], "/");
        strcat(varTable.word[3], commandTable.command[0]); //char name[][]; instead of char ** name;
        char ** paths = malloc(128 * sizeof(char*));
        getPATHS(paths);


	/*
	printf("Paths:\n");
        for(int i = 0; paths[i] != NULL; i++) {
                printf("%s\n", paths[i]);
        }*/
	/*
	for(int i = 0; paths[i] != NULL; i++) {
		strcat(paths[i], slash);
		strcat(paths[i], insertCom);
	}*/
	/*
	printf("Paths:\n");
	for(int i = 0; paths[i] != NULL; i++) {
		printf("%s\n", paths[i]);
	}
	*/


        char* arg_list[argCount];
		//printf("commandTable args: ");

        for(int i = 0; i < argCount; i++) {
				//printf("%s ", commandTable.comArgs[i]);
                arg_list[i] = commandTable.comArgs[i];
        }
        arg_list[argCount - 1] = NULL;
		//printf("\n");
		// Testing for arguments
	for(int i = 0; i < argCount-1; i++) {
		printf("%s\n", arg_list[i]);
	}
	
	// Testing for I/O redirection
	//printf("Input: %d\n", commandTable.in);
	//printf("Output: %d\n", commandTable.out);
	//printf("error->output: %d\n", commandTable.stderr_stdoutput);
	
	printf("Input:\n");
	for(int i = 0; i < inputIndex; i++) {
                printf("%s\n", commandTable.input[i]);
        }
	printf("Output:\n");
	for(int i = 0; i < outputIndex; i++) {
		printf("%s\n", commandTable.output[i]);
	}

	int errvalue;
	int sizePaths = sizeof paths / sizeof paths[0];
	bool didRun;
	bool runCount[sizePaths];	

        pid_t pid = fork();
        if (pid < 0) {
                exit(1);
        } else if (pid == 0) {
                if(commandTable.input[0] != "") { // Checks for directing input
			int fd0 = open(commandTable.input[0], O_RDONLY, O_APPEND); //fix input
			dup2(fd0, STDIN_FILENO);
			close(fd0);
		}

		if(commandTable.output[0] != "") { // Checks for directing output
			if(!commandTable.isDouble) {
				int fd1 = open(commandTable.output[0], O_WRONLY); //fix output
				dup2(fd1, STDOUT_FILENO);
				close(fd1);
			} else if (commandTable.isDouble) {
				int fd1 = open(commandTable.output[0], O_WRONLY | O_APPEND);
				dup2(fd1, STDOUT_FILENO);
				close(fd1);
			}
			if(commandTable.stderr_stdoutput) {
				int fd1 = open(commandTable.output[0], O_WRONLY);
				dup2(fd1, STDERR_FILENO);
				close(fd1);
			}
		}

		if(commandTable.output[1] != "") {
			int fd1 = open(commandTable.output[1], O_WRONLY);
			dup2(fd1, STDERR_FILENO);
			close(fd1);
		}	

		for(int i = 0; paths[i] != NULL; i++) {
                        execv(paths[i], arg_list);
			errvalue = errno;
			runCount[i] = errvalue;
                }
        }
	
	if (!runInBackground){
		runInBackground = false;
		wait(NULL);
	}

	//Error testing
	//for(int i = 0; sizePaths; i++) {
	//	printf("%d\n", runCount[i]);
	//}
	
	for(int i = 0; i < sizePaths; i++) {
		if(runCount[i] == 0) {
	                didRun = true;
                } else {
			errvalue = runCount[i];
		}
        }
        if(!didRun) {
                printf("The error generated was %d\n", errvalue);
                printf("That means: %s\n", strerror(errvalue));
		yylex();
        }

        free(paths);
        resetPATH();
        resetArguments();
        argCount = 0;
	runInBackground = false;
        return 1;
}
