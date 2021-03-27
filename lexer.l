//what neill has

%{
#include "tokens.h"
%}

%x EXPECT_STRING

DIGIT		[0-9]
META		[\[\]{},:]
QUOTE		["]
NOTQUOTE	[^"]


%%

{QUOTE}			{ BEGIN(EXPECT_STRING); return META;}

<EXPECT_STRING>{NOTQUOTE}*		return STRING_LITERAL;
<EXPECT_STRING>{QUOTE}			{BEGIN(INITIAL); return META; }

[ \t\r\n]		{/* whitesapce - do nothing */}
[A-Z][a-z]*		return NAME;
[a-z]+			return WORD;
{DIGIT}+|{DIGIT}*"."{DIGIT}+	return NUMBER;

{META}			return META;