#include<stdio.h>
#include<stdlib.h>
#define MAXQ 100

typedef struct queue
{
int q[MAXQ];
int front;
int rear;
}QUEUE;

void displayQ(QUEUE Q);
int isEmptyQ(QUEUE Q);
void initQ(QUEUE *Q);
int isFullQ(QUEUE Q);
int dequeue(QUEUE *Q,int *data);
int enque(QUEUE *Q,int data);

