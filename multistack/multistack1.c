#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define CAT 50

struct multistack
{
	int data[MAX];
	int bound[CAT];
	int top[CAT];
	int cat;
	
};

void init(struct multistack* m,int size[],int cat);
int push(struct multistack* m,int data,int cat);
int pop(struct multistack* m,int *data,int cat);
int is_empty(struct multistack m,int cat);
int is_full(struct multistack m,int cat);

void main()
{
struct multistack m;
int cat,i,size[MAX],data,ch;
int d;
printf("\n ENTER THE NUMBER OF CATEGORIES : ");
scanf("%d",&cat);
printf("\n ENTER THE NUMBER ENTERIES IN EACH CATEGORY : ");
for(i=0;i<cat;i++)
	scanf("%d",&size[i]);
init(&m,size,cat);
while(1)
{
	printf("\n MENU : ");
	printf("\n1. PUSH ");
	printf("\n2. POP");
	printf("\n3. EXIT : ");
	scanf("%d",&ch);

	switch(ch)
	{
	case 1:

				printf("\n ENTER THE CATEGORY IN WHICH YOU WISH TO PUSH : ");
				scanf("%d",&cat);
				printf("\n ENTER THE DATA WHICH YOU WISH TO PUSH : ");
				scanf("%d",&data);
				if(push(&m,data,cat))
					printf("PUSH SUCCESSFULL \n");
				else
					printf("PUSH UNSUCCESSFULL \n");
				break;


	case 2 :
				printf("\n ENTER THE CATEGORY IN WHICH YOU WISH TO POP : ");
				scanf("%d",&cat);
				if(pop(&m,&d,cat))
					printf("%d POP SUCCESSFULL \n",d);
				else
					printf("POP UNSUCCESSFULL \n");
				break;
	case 3 :
				exit(1);
	deafault :
				printf("wrong choice");
		
}
}
}
void init(struct multistack* m,int size[],int cat)
{
	int i;
	m->cat= cat;
	m->bound[0]=size[0]-1;

	printf("\n BOUNDS :");
	for(i=0;i<cat;i++)
		{
		m->bound[i+1]=size[i+1]+m->bound[i];
		printf("%d ",m->bound[i]);
		
		}
	printf("\n");
	m->top[0]=-1;
	printf("\n TOPS :");
	for(i=0;i<cat;i++)
		{
		m->top[i+1]=(m->bound[i+1]-size[i+1]);
		printf("%d ",m->top[i]);
		}	
	printf("\n");

}
int push(struct multistack* m,int data,int cat)
{
	
	if(is_full(*m,cat))
		return 0;
	else 
		{
		m->top[cat]++;
	        m->data[m->top[cat]]=data;
		printf("%d IS PUSHED . \n",m->data[m->top[cat]]);
		return 1;
		}		
}
int pop( struct multistack* m,int* data,int cat)
{
	if(is_empty(*m,cat))
		return 0;
	
	else
		{
		*data=m->data[m->top[cat]];
		m->top[cat]--;
		return 1;
		}
}
int is_empty(struct multistack m,int cat)
{
	if(cat==0)
	{
		if(m.top[0]==-1)
		return 1;
	}
	else 
	{
		if(m.top[cat]==(m.bound[cat-1]-1))
		return 1;
		else
		return 0;
	}
}
int is_full(struct multistack m,int cat)
{
	if(m.top[cat]==(m.bound[cat]))
		return 1;
	else
		return 0;
}

