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
    graph->array[n1->info->vertex] = n1;
    graph->array[n1->info->vertex]->next = n2;
    graph->array[n2->info->vertex] = n2;
    
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
}

bool isCyclicUtil(struct Graph* graph, int vertex, bool visited[], bool recStack[])
{

    if (recStack[vertex]) {
        return true;
    }
    if (visited[vertex]) {
        return false;
    }

    visited[vertex] = true;
    recStack[vertex] = true;

    if (graph->array[vertex]->next != NULL && isCyclicUtil(graph, graph->array[vertex]->next->info->vertex, visited, recStack)) {
        return true;
    }
            
    recStack[vertex] = false; 
    return false;
}

// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
bool isCyclic(struct Graph* graph)
{

    bool visited[nodeIndex];
    bool recStack[nodeIndex];
    for (int i = 0; i < nodeIndex; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < nodeIndex; i++) {
        if (isCyclicUtil(graph, i, visited, recStack)) { //there is a cycle
            return true;
        }
    }
    return false;
}

