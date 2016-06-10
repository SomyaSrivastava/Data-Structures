#include<stdio.h>
#include<stdlib.h>
#define MAXQ 100

typedef struct queue
{
char q[MAXQ];
int front;
int rear;
}QUEUE;

void displayQ(QUEUE Q);
int isEmptyQ(QUEUE Q);
void initQ(QUEUE *Q);
int isFullQ(QUEUE Q);
int dequeue(QUEUE *Q,char *data);
int enque(QUEUE *Q,char data);

