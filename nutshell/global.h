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
};

char cwd[PATH_MAX];

struct evTable varTable;

struct aTable aliasTable;

struct bcTable commandTable;

int aliasIndex, varIndex, bcIndex;

char* subAliases(char* name);

char* args(char* name);
