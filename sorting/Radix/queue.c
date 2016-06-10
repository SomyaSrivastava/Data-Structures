#include"q.h"
/*
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


void main()
{
QUEUE Q;
int ch,i;
int data;
initQ(&Q);

while(1)
{
	printf("\n MENU \n1.ENQUE \n2.DEQUEUE \n3.DISPLAY \n4.EXIT \nENTER YOUR CHOICE : ");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1 :
			printf("\n ENTER DATA : ");
			getchar();
			scanf("%d",&data);
			if(enque(&Q,data))
			{
				displayQ(Q);
			}
			else
			printf("\nERROR");
			break;
		
	case 2 :
			if(dequeue(&Q,&data))
			{
				displayQ(Q);				
				printf("\n %d is dequeud. ",data);
			}
			else
			printf("\nERROR");
			
			break;
	case 3 :
			displayQ(Q);
			break;
	case 4 :
			exit(1);
	default :
			printf("wrong choice !");
	}

}

}
*/


void initQ(QUEUE *Q)
{
Q->front=Q->rear=-1;
}

int isEmptyQ(QUEUE Q)
{
if(Q.rear==-1)
	return 1;
else
	return 0;

}

int isFullQ(QUEUE Q)
{
	if(Q.rear== (MAXQ -1))
		return 1;
	else
		return 0;
}

int enque(QUEUE *Q,int data)
{
if(isFullQ(*Q))
	return 0;
else
	{
		++(Q->rear);
		Q->q[Q->rear]=data;
		if(Q->front==-1)
			++(Q->front);		
		return 1;
	}
}

int dequeue(QUEUE *Q,int *data)
{
	int i;
	if(isEmptyQ(*Q))
		return 0;
	else
	{
		 	*data=Q->q[Q->front];
			i=Q->front;
						
			while(i!=Q->rear)
			{
				Q->q[i]=Q->q[i+1];
				i++;		
			}			
			//(Q->front)--;
			
			if(Q->front==Q->rear)
				--(Q->front);
			--(Q->rear);
			
			return 1;
	}
}

void displayQ(QUEUE Q)
{
	int i;
	for(i=0;i<=Q.rear;i++)
		printf(" %d -> ",Q.q[i]);
}


