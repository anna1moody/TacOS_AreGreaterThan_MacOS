%{

#include "tokens.h"
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
{QUOTE}							BEGIN(EXPECT_STRING);
<EXPECT_STRING>{NOTQUOTE}*		return STRING_LITERAL;
<EXPECT_STRING>{QUOTE}			BEGIN(INITIAL);

[ \t\r\n]						{/* whitesapce - do nothing */}
true|false						return BOOLEAN_LITERAL;
null							return NULL_LITERAL;
{DIGIT}+|{DIGIT}*"."{DIGIT}+	return NUMBER_LITERAL;

{META}	return (int) yytext[0];
;		return SEMICOLON;
.		{showError(); return UNDEFINED;}

%%

void showError(){
	printf("other input");
}