#include "String_stack.h"
/* 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 2
typedef struct stack
{
	char st[MAX];
	int top;
}STACK;

void init(STACK *s); //initialize the top variable
int is_Empty(STACK s);//check weather top == -1
int is_Full(STACK s);//check weather top == MAX - 1
int push(STACK *s, char elem[MAX]); // increment the top and push the element in the stack.
int pop(STACK *s, char *elem);//decrement the top and pop the element from the stack.
void display(STACK s); // print top-number of values from stack.
char peek(STACK s);//peek function to view the last value in the stack


void main()
{
	STACK s;
	int ch;
	char data,last;
	char d[MAX];
	
	init(&s);
	
	while(1)
	{
		printf("\n  MENU : ");
		printf("\n 1.PUSH ? ");
		printf("\n 2.POP ? ");
		printf("\n 3.DISPLAY ? ");
		
		printf("\n 4.PEEK ? ");
		printf("\n 5.EXIT ? ");
		printf("\n ENTER YOUR CHOICE : ");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1 :

						printf("\n ENTER THE EXPRESSION TO BE PUSHED : ");
						getchar();						
						gets(d);
						
						if(push(&s,d))
							display(s);
						else
							printf("\n PUSH OPERATION UNSUCCESSFULL ! ");				
						
						break;					
				
			case 2 :
						if(pop(&s,&data))
							printf("\n POPPED ELEMENT : %c",data);
						else
							printf("\n POP OPERATION UNSUCCESSFULL ! ");				
						break;					
			
			case 3 :
						display(s);
						break;
			case 5 :
						printf("\n THANK YOU FOR USING APPLICATION ! \n");
						exit(1);
						
			case 4 :
												
						last=peek(s);
						printf("\n LAST VALUE IN THE STACK IS : %c",last);
						break;			
			default :
						printf("\n WRONG CHOICE ! ");
		}
	}

}
*/
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
int push(STACK* s,char elem[MAX])
{
	int i=0;
	if(is_Full(*s))
		return 0;
	else
		{
			while(elem[i]!='\0')
			{
				s->top++;
				s->st[s->top]=elem[i];
				i++;
			}
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
	}
	else
	printf("\n STACK IS EMPTY ! ");
}

char peek(STACK s)
{
	char last;
	if(is_Empty(s))
		return '\0';
	else
	{
		last=s.st[s.top];
		return last;
	}	


}




