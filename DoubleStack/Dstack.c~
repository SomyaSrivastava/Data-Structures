#include<stdio.h>
#include<malloc.h>
typedef struct Dstack
{
	int *stack;
	int size;
	int top[2];
}Dstack;
int init(Dstack* D,int size);
int push(Dstack* D,int cat,int value);
int pop(Dstack* D,int cat,int* value);
int is_full(Dstack D);
int is_empty(Dstack D,int cat);
void display(Dstack D,int cat);

void main()
{
Dstack D;
int size,ch,value,cat;
printf("\n ENTER THE SIZE OF THE DOUBLE STACK : ");
scanf("%d",&size);
if(init(&D,size))
	printf("DOUBLE STACK IS INITIALIZED . \n");
else
	printf("UNSUCCESSFULL INITIALIZATION OF DOUBLE STACK \n");


while(1)
{
	printf(" MENU\n  ");
	printf("1.PUSH\n");
	printf("2.POP\n");
	printf("3.DISPLAY\n");
	printf("4.EXIT\n");
	printf(" \n ENTER YOUR CHOICE : ");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1 :
				printf("\n ENTER CATEGORY : ");
				scanf("%d",&cat);
				printf("\n ENTER VALUE : ");
				scanf("%d",&value);
				if(push(&D,cat,value))
					display(D,cat);
				else
					printf("\n UNSUCCESSFULL PUSH");
				break;		
		case 2 :	printf("\n ENTER CATEGORY : ");
				scanf("%d",&cat);
				if(pop(&D,cat,&value))
					{
						printf("\n POPPED ELEMENT IS : %d ",value);
						display(D,cat);
					}
				else
					printf("\n UNSUCCESSFULL POP");
								
				break;
		case 3 :
				printf("\n ENTER CATEGORY : ");
				scanf("%d",&cat);				
				display(D,cat);
				break;
		case 4 :		
				exit(1);
		default :
				printf("\n WRONG CHOICE ");
	}
}
}
int init(Dstack* D,int size)
{
		
		D->size=size;
		if(!(D->stack=(int*)malloc(sizeof(int)*(size))))
				return 0;
		else
		{
			D->top[0]=0;
			D->top[1]=(size-1);
			return 1;
		}
}
int is_full(Dstack D)
{
	if(D.top[0]==D.top[1])
		return 1;
	else
		return 0;

}
int is_empty(Dstack D,int cat)
{
	if((cat==1 && D.top[0]==0)||(cat==2 && D.top[1]==(D.size-1)))
		return 1;
	else
		return 0;
}
int push(Dstack* D,int cat,int value)
{

	if(is_full(*D))
		return 0;
	else
	{
		D->stack[D->top[cat-1]]=value;
		if(cat==1)
			D->top[0]++;
		else
			D->top[1]--;

		return 1;	
	}	
}
int pop(Dstack* D,int cat,int* value)
{
	if(is_empty(*D,cat))
		return 0;
	else
		{
			*value= D->stack[D->top[cat-1]];
			if(cat==1)
				D->top[0]--;
			else
				D->top[1]++;

			return 1;		
		}

}
void display(Dstack D,int cat)
{
int i;
if(cat==1)
{
for(i=0;i<D.top[0];i++)
	printf("%d ",D.stack[i]);
}
else
{
for(i=(D.size-1);i>D.top[1];i--)
	printf("%d ",D.stack[i]);
}


}
