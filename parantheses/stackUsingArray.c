#include <stdio.h>

#define MAX 5

struct stack 
{
	int array[MAX];
	int top;
};

void init(struct stack *s); //initialize the top variable
int isEmpty(const struct stack *s);//check weather top == -1
int isFull(const struct stack *s);//check weather top == MAX - 1
int push(struct stack *s, int elem); // increment the top and push the element in the stack.
int pop(struct stack *s, int *poppedELem);
void printValues(const struct stack s); // print top-number of values from stack.

void main()
{
	struct stack *s = (struct stack *) malloc( sizeof(struct stack) );
	char option; //weather to try again or not.
	int caseValue; // operation to be performed.
	int data; // value to be pushed in.
	int poppedELem; // value refrence returned from pop function.
	
	init(s);
	
	printf("\t****Welcome to our Stack implementation program****\n");
	
	
	do
	{
	
	printf("\tEnter\n\t 1.To perform push operation.\n\t2.Enter 2 for pop operation.\n\t3.To print values\n");
	scanf("%d",&caseValue);
	
	switch(caseValue)
	{
		case 1:	
				if(!isFull(s))
				{
					printf("\tEnter the value to push\n");
					scanf("%d",&data);
				}
				
				if(push(s, data))
					printf("\tThe stack is full\n");
				else
					printf("\tValue successfully added\n");
				break;
				
		case 2:
				if(pop(s,&poppedELem))
					printf("\tThe stack is empty\n");
				else
					printf("\tValue deleted: %d from stack\n",poppedELem);
				break;
				
		case 3:
				if(isEmpty(s))
					printValues(*s);
				else
					printf("\tStack isEmpty\n");
				break;
				
		default:
				printf("\tWrong option entered\n");
				break;	
	}
	
	printf("\n\tEnter 'y' or 'Y' to continue else to exit\n");
	scanf(" %c", &option);
	
	}while(option == 'y' || option == 'Y');
		
}


void init(struct stack *s)
{
	s->top = -1;
}

int isFull(const struct stack *s)
{
	if(s->top == MAX - 1)
		return 0;
	else
		return 1;	
}

int isEmpty(const struct stack *s)
{
	if(s->top == -1)
		return 0;
	else
		return 1;
}

int push(struct stack *s, int elem)
{
	if( isFull(s) )
	{
		s->top++;
		s->array[s->top] = elem;
		return 0; // data successfully added to the stack.
	}
	else
	{
		return 1;//failure data can't be added to the stack.	
	}	
}

int pop(struct stack *s, int *lastElem)
{
	if( isEmpty(s) )
	{
		*lastElem = s->array[s->top];
		s->top--;
		return 0; // popped out value is assigned to pointer Variable successfully.
	}
	else
	{
		return 1; // stack is empty, data cannot be popped out.		
	}
}

void printValues(const struct stack s)
{
	printf("\tPrinting Values\n");
	int noOfValues = s.top;
	int i = 0;
	do
	{
		printf("%d ",s.array[i]);
		i++;
	}while(i <= s.top);
	
}

