%{
 #include "parser.tab.h"  
void showError();

%}

%x EXPECT_STRING

DIGIT		[0-9]
META		[\[\]{},:<>|\\\&]
ALPHA		[a-zA-Z]
TILDE		[~]
DOT			[.]

QUOTE		["]
NOTQUOTE	[^"]


%%
bye								return END;
{QUOTE}							BEGIN(EXPECT_STRING);
<EXPECT_STRING>{NOTQUOTE}*		{printf("Found a string: %s\n", yytext); return STRING_LITERAL;}
<EXPECT_STRING>{QUOTE}			BEGIN(INITIAL);

[ \t\r\n]						{/* whitesapce - do nothing */}
true|false						return BOOLEAN_LITERAL;
null							return NULL_LITERAL;
{DIGIT}+|{DIGIT}*\.{DIGIT}+     {printf("Found a number: %f\n", strtod(yytext, NULL)); return NUMBER_LITERAL;}

{META}	return yytext[0];
;		return SEMICOLON;
.		{return UNDEFINED;}

%%

<string_condition>{VARSTART}        {printf("found var\n"); 
                                    BEGIN(var_exp_condition);
                                    yylval.string = strdup(yytext);
                                    printf("string %s\n", yylval.string);
                                     return STRING;
                                     printf("string %s\n", yylval.string);}
<string_condition>[}]          {printf("finish } \n"); BEGIN(INITIAL);}