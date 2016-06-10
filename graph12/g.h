#include<stdio.h>
#include<stdlib.h>
#include "Character_stack.h"
#include "q.h"

//#define MAX 100
typedef struct Graph
{
char label[MAX];
int adj[MAX][MAX];
int count;
}GRAPH;

int calad(char c,GRAPH G,char ad[MAX],int *out,int index[MAX]);

