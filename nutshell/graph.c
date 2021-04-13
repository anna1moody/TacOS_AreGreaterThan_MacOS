//sourced from https://www.geeksforgeeks.org/graph-and-its-representations/ because I have forgotten how to code this
#include <stdio.h>
#include <stdlib.h>
#include "global.h"




struct node* newNode(struct Graph* graph, int vertex, char *value)
{   
    struct pair* newPair = (struct pair*) malloc(sizeof(struct pair));
    newPair->value = value;
    newPair->vertex = vertex;
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->info = newPair;
    newNode->next = NULL;
    //printf("creating a new node, value = %s, vertex = %d, nodeIndex = %d\n", newNode->info->value, newNode->info->vertex, nodeIndex);
    nodeIndex += 1;
    return newNode;
}



void addEdge(struct Graph* graph, struct node* n1, struct node* n2)
{
    //printf("adding edge\n");
    graph->array[n1->info->vertex] = n1;
    //printf("n2 info %s, %d\n", n2->info->value, n2->info->vertex);
    //printf("n1 info %s %d\n", n1->info->value, n1->info->vertex);
    graph->array[n1->info->vertex]->next = n2;
    //printf("graph n1 info %s %d\n", graph->array[n1->info->vertex]->info->value, graph->array[n1->info->vertex]->info->vertex);
    graph->array[n2->info->vertex] = n2;
    //printf("graph n2 info %s %d\n", graph->array[n2->info->vertex]->info->value, graph->array[n2->info->vertex]->info->vertex);

    
}
void printGraph(struct Graph* graph)
{
    for (int v = 0; v < nodeIndex; ++v)
    {
        struct node* pCrawl = graph->array[v];
        printf("\n Adjacency list of vertex %d\n head ", v);

        printf("-> \"%s\" which is in vertex %d", pCrawl->info->value, pCrawl->info->vertex);
        if (pCrawl->next != NULL)
            printf("-> \"%s\" which is in vertex %d", pCrawl->next->info->value, pCrawl->next->info->vertex);

        printf("\n");
    }
}
void deleteEdge(struct Graph* graph, struct node* n1, struct node* n2) {
    //printGraph(graph);
    graph->array[n1->info->vertex]->next = NULL;
    bool found = false;
    for (int v = 0; v < nodeIndex; v++) {
        if (graph->array[v]->next != NULL && strcmp(graph->array[v]->next->info->value, n2->info->value) == 0) {
            found = true;
        }
    }
    if (!found && (n2->next == NULL)) {
        graph->array[n2->info->vertex] == NULL;
        nodeIndex--;
    }
    //printGraph(graph);
}

bool isCyclicUtil(struct Graph* graph, int vertex, bool* visited[], bool* recStack[])
{
    if (recStack[vertex]) {
        return true;
    }
    if (visited[vertex]) {
        return false;
    }


        /* Mark the current node as visited and part of recursion stack
        if (graph->array[vertex]->next != NULL) {
            printf(" info %s %d %d next %s %d\n", graph->array[vertex]->info->value, vertex, graph->array[vertex]->info->vertex, graph->array[vertex]->next->info->value, graph->array[vertex]->next->info->vertex);
        }
        else {
            printf(" info %s %d %d \n", graph->array[vertex]->info->value, vertex, graph->array[vertex]->info->vertex);

        }
        */
        visited[vertex] = true;
        recStack[vertex] = true;

        // Recur for all the vertices adjacent to this vertex

        if (graph->array[vertex]->next != NULL && isCyclicUtil(graph, graph->array[vertex]->next->info->vertex, visited, recStack)) {
            return true;
        }
            
    recStack[vertex] = false;  // remove the vertex from recursion stack
    return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
bool isCyclic(struct Graph* graph)
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool* visited[nodeIndex];
    bool* recStack[nodeIndex];
    for (int i = 0; i < nodeIndex; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function to detect cycle in different
    // DFS trees

    for (int i = 0; i < nodeIndex; i++) {
        if (isCyclicUtil(graph, i, visited, recStack)) {
            //printf("there is a cycle\n");
            return true;
        }
    }
    return false;
}

