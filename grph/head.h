#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct Graph
{
char label[MAX];
int adj[MAX][MAX];
int count;
}GRAPH;

