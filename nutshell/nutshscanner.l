%{
// This is ONLY a demo micro-shell whose purpose is to illustrate the need for and how to handle nested alias substitutions and how to use Flex start conditions.
// This is to help students learn these specific capabilities, the code is by far not a complete nutshell by any means.
// Only "alias name word", "cd word", and "bye" run.
#include "nutshparser.tab.h"
#include <string.h>
#include <stdbool.h>
#include "global.h"



char* subAliases(char* name){
    for (int i = 0; i < aliasIndex; i++) {
        if(strcmp(aliasTable.name[i], name) == 0) {
            return aliasTable.word[i];
        }
    }
    return name;
}
bool ifAlias(char* name){
    for (int i = 0; i < aliasIndex; i++) {
        if(strcmp(aliasTable.name[i], name) == 0) {
            return true;
        }
    }
    return false;
}

bool isVar(char *var){
    for (int i = 0; i < varIndex; i++){
        if(strcmp(varTable.var[i], var) == 0){
            return true;
        }
    }
    return false;
}



%}
%array
%option noyywrap
%x string_condition
%x var_exp_condition
%x var_in_string

CHAR            [.A-Za-z0-9?*!<>:&\/_-][.A-Z?*a-z0-9!<>:&\/_-]*
ANYCHAR         [)(*&%$#@!`;,\.a-zA-Z0-9<>:'/*_=~ -][)(*&%$#@!`;,\.a-zA-Z0-9<>:'/*_=~ -]*
META            [|\"]+
WHITESPACE      [\t ]+
QUEST           [?]


%%
<var_exp_condition>{ANYCHAR}+     {  yylval.string = strdup(yytext); 
                                     bool found = false;
                                     for (int i = 0; i < varIndex; i++){
                                        if (strcmp(varTable.var[i], yytext) == 0){
                                            yylval.string = strdup(varTable.word[i]);
                                            found = true;
                                        }
                                     }
                                     if (!found){
                                        printf("Error, the inputted ${%s} is not an environment variable\n", yylval.string);}
                                     else{ printf(" %s\n", yylval.string);return STRING;}}
<var_exp_condition>[}]          {BEGIN(INITIAL);} 

<var_in_string>{ANYCHAR}+       {    bool found = false;
                                     for (int i = 0; i < varIndex; i++){
                                        if (strcmp(varTable.var[i], yytext) == 0){
                                            yylval.string = strdup(varTable.word[i]);
                                            found = true;
                                        }
                                     }
                                     if (!found){
                                        printf("Error, the inputted ${%s} is not an environment variable\n", yylval.string);}
                                     else{ return STRING;}}
<var_in_string>[}]              {BEGIN(string_condition);}

<string_condition>{ANYCHAR}+    { yylval.string = strdup(yytext); return STRING;}
<string_condition>"${"        { BEGIN(var_in_string);}
<string_condition>[}]          { BEGIN(string_condition);}
<string_condition>[\"]          { BEGIN(INITIAL);}

[ ]		            { }
bye                         { return BYE; }
setenv			    { return SETENV; }
printenv	            { return PRINTENV; }
unsetenv		    { return UNSETENV; }
cd		            { return CD; }
"~"                         { return TILDE; }
"unalias"                   { return UNALIAS; }
"alias"		            { return ALIAS; }

"<"                         { yylval.string = strdup(yytext); return INPUT; }
">"                         { yylval.string = strdup(yytext); return OUTPUT; }
">>"			    { yylval.string = strdup(yytext); return DOUBLE; }
"2>&1"                      { return STDERRSTDOUT; }
2>{CHAR}+                   { yylval.string = strdup(yytext); return STDERR; }

WHITESPACE          {}
[&]$              { runInBackground = true;}
"\n"		            { return END; }
"${"               {BEGIN(var_exp_condition);}
[\"]                 { BEGIN(string_condition); }

^{CHAR}+             { 
                        if(ifAlias(yytext)) {
                            aliasExp = true;
                            //source: https://www.cs.princeton.edu/~appel/modern/c/software/flex/flex.html
                            char *yycopy = strdup( subAliases(yytext) );
                            for ( int i = strlen(subAliases(yytext)) - 1; i >= 0; --i ){
                               unput( yycopy[i] );
                            }
                            free( yycopy );
                        } else {
                            yylval.string = strdup(yytext);
                            return STRING;
                        }
                     }
{CHAR}+          {
                   if (aliasExp){
                        aliasExp = false;
                        if(ifAlias(yytext)) {
                            aliasExp = true;
                            //source: https://www.cs.princeton.edu/~appel/modern/c/software/flex/flex.html
                            char *yycopy = strdup( subAliases(yytext) );
                            for ( int i = strlen(subAliases(yytext)) - 1; i >= 0; --i ){
                               unput( yycopy[i] );
                            }
                            free( yycopy );
                        } else {
                            yylval.string = strdup(yytext);
                            return STRING;
                        }
                 }
                 else{
                   yylval.string = strdup(yytext);
                   if (strchr(yylval.string, '?') != NULL){
                        //? is in the work
                        pattern = true;
                   }
                   if (strchr(yylval.string, '*')){
                        pattern = true;
                   }
                   return STRING;
                 }
              }
%%
