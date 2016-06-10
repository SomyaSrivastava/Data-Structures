#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct Multiqueue
{
	int q[MAX];
	int rear[MAX],front[MAX];
	int bound[MAX];
	int size[MAX];
	int cat;
	int count;

}MQ;

void initMQ(MQ *mq,int cat,int size[MAX])
{
	int i;
	mq->count=0;
	mq->rear[0]=mq->front[0]=-1;
	mq->bound[0]=size[0]-1;
	for(i=0;i<cat;i++)	
		mq->size[i]=size[i];
	mq->cat=cat;
	
	for(i=1;i<cat;i++)
	{
		mq->bound[i]=size[i]+mq->bound[i-1];	
	}
	
	for(i=1;i<cat;i++)
	{
		mq->front[i]=mq->rear[i]=mq->bound[i-1];
	}
	printf("\n BOUNDS :- ");
	for(i=0;i<cat;i++)
	{
		printf("\n %d",mq->bound[i]);
	}
	printf("\n fronts - rears :- ");
	for(i=0;i<cat;i++)
	{
		printf("\n %d - %d",mq->front[i],mq->rear[i]);
	}
}
int isEmptyMQ(MQ mq,int cat)
{
	if(cat <= mq.cat && cat!=0 && mq.front[cat]==mq.bound[cat-1] )
		return 1;
	
	else if(cat <= mq.cat && cat==0 && mq.front[0]==-1)
		return 1;
	else
		return 0;

}	

int isFullMQ(MQ mq,int cat)
{
	if(cat <= mq.cat && mq.rear[cat]==mq.bound[cat])
		return 1;
	else
		return 0;

}	


void showMQ(MQ mq)
{

int i;
 int j;

	for(i=0;i<mq.cat;i++)
	{
		if(!isEmptyMQ(mq,i))
		{
			printf("\n CATEGORY : %d \n",i+1);
			for(j=mq.front[i];j<=mq.rear[i];j++)
			{
				printf(" %d ",mq.q[j]);	
			}
		}
		else
		continue;
	}
		
	

}

int enq(MQ *mq,int cat,int data)
{
if(cat<=mq->cat)
	{	
	if(!isFullMQ(*mq,cat))
	{
		if(isEmptyMQ(*mq,cat))
		{
			mq->front[cat]++;

		}
		mq->rear[cat]++;
		mq->q[mq->rear[cat]]=data;
		mq->count++;
		return 1;	
	}
	}
	else
		return 0;
}

int deq(MQ *mq,int cat,int *data)
{
int i;
if(cat<=mq->cat)
	{
	if(!isEmptyMQ(*mq,cat))
	{
		*data=mq->q[mq->front[cat]];	
		if(cat == 0 && mq->rear[cat]==0)
		{
			mq->rear[cat]=mq->front[cat]=-1;
			
		}
		else if(mq->rear[cat]==mq->bound[cat-1]+1)
		{
			
			--(mq->front[cat]);
			 --(mq->rear[cat]);

		}
		else
		{
			for(i=mq->front[cat];i<mq->rear[cat];i++)
			{
				mq->q[i]=mq->q[i+1];

			}
			--(mq->rear[cat]);
	
		}
		mq->count--;
		
		return 1;
	}
	}
else
		return 0;
}

void main()
{
MQ mq;
int size[MAX],data,cat,i,ch;
printf("\n ENTER THE NUMBER OF CATEGORIES : ");
scanf("%d",&cat);
printf("\n ENTER THE SIZE OF EACH CATEGORY : ");
for(i=0;i<cat;i++)
	scanf("%d",&size[i]);
initMQ(&mq,cat,size);

while(1)
{
	printf("\nMENU \n1.ENQUE \n2.DEQUEUE \n3.DISPLAY \nANY OTHER NUMBER TO EXIT \nENTER YOUR CHOICE : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 :
			printf("\n ENTER THE CATEGORY : ");
			scanf("%d",&cat);
			printf("\n ENTER THE DATA :");
			scanf("%d",&data);
			if((enq(&mq,cat-1,data)))
				showMQ(mq);
			else
				printf("\nCANNOT ENQUEUE ! ");
			break;	
		case 2 :
			printf("\n ENTER THE CATEGORY : ");
			scanf("%d",&cat);
			if((deq(&mq,cat-1,&data)))
				{
				showMQ(mq);
				printf("\n %d is deleted from cat %d \n",data,cat);
				}
			else
				printf("\nCANNOT DEQUEUE ! ");
			break;	
		case 3 :
			showMQ(mq);
			break;
		default : 
			exit(1);
	}


}

}



