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

bool isCyclicUtil(struct Graph* graph, int dest, bool visited[], bool* recStack)
{
    if (visited[dest] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[dest] = true;
        recStack[dest] = true;

        // Recur for all the vertices adjacent to this vertex
        for (int i = 0; i < (graph->V); i++) {
            struct AdjListNode* node = graph->array[i];
            int dest = node->dest->vert;

            if (!visited[graph->array[i]] && isCyclicUtil(graph, dest, visited, recStack))
                return true;
            else if (recStack[graph->array[i]])
                return true;
        }
        
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
bool isCyclic(struct Graph* graph)
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool* visited = new bool[V];
    bool* recStack = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function to detect cycle in different
    // DFS trees
   
    for (int i = 0; i < V; i++)
        if (isCyclicUtil(graph, i, visited, recStack))
            return true;

    return false;
}