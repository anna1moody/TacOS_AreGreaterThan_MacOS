%{
// This is ONLY a demo micro-shell whose purpose is to illustrate the need for and how to handle nested alias substitutions and how to use Flex start conditions.
// This is to help students learn these specific capabilities, the code is by far not a complete nutshell by any means.
// Only "alias name word", "cd word", and "bye" run.
#include "nutshparser.tab.h"
#include <string.h>
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
%x alias_shit

CHAR            [.A-Za-z0-9!\/_-][.A-Za-z0-9!\/_-]*
ANYCHAR            [)(*&%$#@!`;,\.a-zA-Z0-9'/*_=~ -][)(*&%$#@!`;,\.a-zA-Z0-9'/*_=~ -]*
META            [<>|\"&]+
WHITESPACE      [\t ]+

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
<alias_shit>{CHAR}*             {if(ifAlias(yytext)) {
                        printf("is alias: yytext: %s\n", yytext);
                        //source: https://www.cs.princeton.edu/~appel/modern/c/software/flex/flex.html
                           char *yycopy = strdup( subAliases(yytext) );
                           printf("yy copy: %s\n", yycopy);
                           for ( int i = strlen(subAliases(yytext)) - 1; i >= 0; --i ){
                               unput( yycopy[i] );
                               }
                           free( yycopy );
                    } else {
  
                        printf("uh not alias: yytext: %s\n", yytext);
                        for(int i = strlen(yytext)-1; i>=0; --i){
                            unput(yytext[i]);
                            }
                    }
                    return ALIAS;}

[ ]		            { }
bye                         { return BYE; }
setenv			    { return SETENV; }
printenv	            { return PRINTENV; }
unsetenv		    { return UNSETENV; }
WHITESPACE          {}

cd		            { return CD;}
"~"                 {return TILDE;}
"alias"		            {return ALIAS; }
"unalias"             {return UNALIAS;}
"\n"		            { return END; }
"${"               {BEGIN(var_exp_condition);}
[\"]                 { BEGIN(string_condition); }

^{CHAR}+             { 
                        printf("alias expansion: yytext: %s\n", yytext);
                        if(ifAlias(yytext)) {
                            printf("is alias: yytext: %s\n", yytext);
                            //source: https://www.cs.princeton.edu/~appel/modern/c/software/flex/flex.html
                            char *yycopy = strdup( subAliases(yytext) );
                            printf("yy copy: %s\n", yycopy);
                            for ( int i = strlen(subAliases(yytext)) - 1; i >= 0; --i ){
                               unput( yycopy[i] );
                            }
                            free( yycopy );
                        } else {
                            printf("not alias: yytext: %s\n", yytext);
                            yylval.string = strdup(yytext);
                            return STRING;
                        }
                        }
{CHAR}+          { printf(" yytext: %s\n", yytext);
                   yylval.string = strdup(yytext);
                   return STRING;
                 }
%%
