// This is ONLY a demo micro-shell whose purpose is to illustrate the need for and how to handle nested alias substitutions and how to use Flex start conditions.
// This is to help students learn these specific capabilities, the code is by far not a complete nutshell by any means.
// Only "alias name word", "cd word", and "bye" run.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "global.h"

char *getcwd(char *buf, size_t size);
int yyparse();

struct Graph* createGraph(int vertices)
{
    graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->array = malloc(vertices * sizeof(struct node));

    int i;
    for (i = 0; i < vertices; ++i)
        graph->array[i] = NULL;

    return graph;
}

int main()
{
    aliasIndex = 0;
    varIndex = 0;
    bcIndex = 0;
    nodeIndex = 0;
    inputIndex = 0;
    outputIndex = 0;
    runInBackground = false;
    aliasExp = false;
    Aexp = false;

    getcwd(cwd, sizeof(cwd));

    // Environment Variable Table
    strcpy(varTable.var[varIndex], "PWD"); // print working directory; path of the working directory
    strcpy(varTable.word[varIndex], cwd);
    varIndex++;
    strcpy(varTable.var[varIndex], "HOME"); // home directory of the user
    strcpy(varTable.word[varIndex], cwd);
    varIndex++;
    strcpy(varTable.var[varIndex], "PROMPT"); // shell prompt
    strcpy(varTable.word[varIndex], "nutshell");
    varIndex++;
    strcpy(varTable.var[varIndex], "PATH"); // list of paths to be searched to find a command's executable file
    strcpy(varTable.word[varIndex], ".:/bin"); // starts at .:/bin
    varIndex++;
    struct Graph* graph = createGraph(128);

    // Basic Command Table
    strcpy(commandTable.command[bcIndex], "");
    strcpy(commandTable.comArgs[bcIndex], "");
    strcpy(commandTable.temp[bcIndex], "");
    strcpy(commandTable.input[bcIndex], "");
    strcpy(commandTable.output[bcIndex], "");
    strcpy(commandTable.pathsTemp[bcIndex], "");
    commandTable.in = 0;
    commandTable.out = 0;
    commandTable.isDouble = 0;
    commandTable.isErr = 0;
    commandTable.stderr_stdoutput = 0;
    bcIndex++;

    system("clear");
    while(1)
    {
        printf("[%s]>> ", varTable.word[2]); // design of shell
        yyparse();
	if(commandTable.isErr) {
		//yylex();
		//commandTable.isErr = 0;
	}
    }

   return 0;
}
