#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
typedef struct stack
{
	char st[MAX];
	int top;
}STACK;

void init(STACK *s); //initialize the top variable
int is_Empty(STACK s);//check weather top == -1
int is_Full(STACK s);//check weather top == MAX - 1
int push(STACK *s, char elem); // increment the top and push the element in the stack.
int pop(STACK *s, char *elem);//decrement the top and pop the element from the stack.
void display(STACK s); // print top-number of values from stack.

void main()
{
	STACK s;
	int i;
	char d[MAX];
	char value;
	
	init(&s);
	
	printf("\n ENTER THE EXPRESSION TO BE PUSHED : ");						
	gets(d);
			
		for(i=0;d[i]!='\0';i++)
		{
			switch(d[i])
			{
				case '{' :
						if(push(&s,d[i]));
							
						else
							printf("\n PUSH UNSUCCESSFULL ");
						break;
				case '[' :
						if(push(&s,d[i]));
							
						else
							printf("\n PUSH UNSUCCESSFULL ");
						break;
				case '(' :
						if(push(&s,d[i]));
						else
							printf("\n PUSH UNSUCCESSFULL ");
						break;
				case '}' :
						if(pop(&s,&value))
						{
						if(value=='{')
							printf(" \n matched %c %c \n",value,'}');
						else
							printf(" \n unmatched %c %c \n",value,d[i]);
						}
						
						
						break;
				case ')' :
						if(pop(&s,&value))
						{
						if(value=='(')
							printf(" matched %c %c \n",value,')');
						else
							printf(" unmatched %c %c \n",value,d[i]);
						}
						
						
						break;
				case ']' :
						if(pop(&s,&value))
						{
						if(value=='[')
							printf(" matched %c %c \n",value,']');
						else
							printf(" unmatched %c %c \n",value,d[i]);
						}
					
						
						break;

				default :
						push(&s,d[i]);
			}
		}
	if(!is_Empty(s))
	{
		printf("unmatched : ");
		display(s);
	}
}																				
void init(STACK *s)
{
s->top=-1;
}
int is_Empty(STACK s)
{
if(s.top==-1)
	return 1;
else 
	return 0;
}
int is_Full(STACK s)
{
	if(s.top==(MAX-1))
		return 1;
	else
		return 0;
}
int push(STACK* s,char elem)
{
	if(is_Full(*s))
		return 0;
	else
		
			{	
				s->top++;
				s->st[s->top]=elem;
				return 1;
			}
}
int pop(STACK* s,char *elem)
{
	if(is_Empty(*s))
		return 0;
	else
	{
		*elem=s->st[s->top];
		s->top--;
		return 1;
	}	
}
void display(STACK s)
{
	int i;
	
	if(!is_Empty(s))
	{
		for(i=0;i<=s.top;i++)
			printf("%c -> ",s.st[i]);
		printf("\n");	
	}
	else
	printf("\n STACK IS EMPTY ! ");
}




