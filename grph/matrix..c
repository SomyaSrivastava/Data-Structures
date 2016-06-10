#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct Graph
{
char label[MAX];
int adj[MAX][MAX];
int count;
int weight[MAX][MAX];
}GRAPH;

