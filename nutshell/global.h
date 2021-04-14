#include "stdbool.h"
#include <limits.h>

struct evTable {
   char var[128][100];
   char word[128][100];
};

struct aTable {
	char name[128][100];
	char word[128][100];
};

struct bcTable {
        char command[128][100];
        int argCount[128];
        char comArgs[128][100];
        char temp[128][100];
        char input[128][100];
        char output[128][100];
        char patternArgs[128][100];
	char pathsTemp[128][100];

        bool in, out, isDouble, isErr, stderr_stdoutput;
};

char cwd[PATH_MAX];

struct evTable varTable;

struct aTable aliasTable;

int aliasIndex, varIndex, nodeIndex, bcIndex, inputIndex, outputIndex;
struct bcTable commandTable;
bool runInBackground, aliasExp, pattern;

char* subAliases(char* name);

struct Graph
{
    int vertices;
    struct node** array;
};

struct pair {
    int vertex;
    char* value;
};

struct node
{
    struct pair* info;
    struct node* next;

};

struct Graph* graph;
char* subAliases(char* name);

char* args(char* name);
