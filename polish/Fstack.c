#include "Fstack.h"

/*#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct Fstack
{
	float st[MAX];
	int top;
}FSTACK;

void initF(FSTACK *s); //initialize the top variable
int is_EmptyF(FSTACK s);//check weather top == -1
int is_FullF(FSTACK s);//check weather top == MAX - 1
int pushF(FSTACK *s, float elem); // increment the top and push the element in the stack.
int popF(FSTACK *s, float *elem);//decrement the top and pop the element from the stack.
void displayF(FSTACK s); // print top-number of values from stack.*/

/*void main()
{
	FSTACK s;
	int ch;
	float data;
	
	initF(&s);
	
	while(1)
	{
		printf("\n  MENU : ");
		printf("\n 1.PUSH ? ");
		printf("\n 2.POP ? ");
		printf("\n 3.DISPLAY ? ");
		printf("\n 4.EXIT ? ");
		printf("\n ENTER YOUR CHOICE : ");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1 :

						printf("\n ENTER THE VALUE TO BE PUSHED : ");
					
						scanf("%f",&data);
						
						if(pushF(&s,data))
							displayF(s);
						else
							printf("\n PUSH OPERATION UNSUCCESSFULL ! ");				
						
						break;					
				
			case 2 :
						if(popF(&s,&data))
							printf("\n POPPED ELEMENT : %f",data);
						else
							printf("\n POP OPERATION UNSUCCESSFULL ! ");				
						break;					
			
			case 3 :
						displayF(s);
						break;
			case 4 :
						printf("\n THANK YOU FOR USING APPLICATION ! \n");
						exit(1);
						
			default :
						printf("\n WRONG CHOICE ! ");
		}
	}

}
*/
void initF(FSTACK *s)
{
s->top=-1;
}
int is_EmptyF(FSTACK s)
{
if(s.top==-1)
	return 1;
else 
	return 0;
}
int is_FullF(FSTACK s)
{
	if(s.top==(MAX-1))
		return 1;
	else
		return 0;
}
int pushF(FSTACK* s,float elem)
{
	
	if(is_FullF(*s))
		return 0;
	else
		{
			s->top++;
			s->st[s->top]=elem;
			return 1;
		}
}
int popF(FSTACK* s,float *elem)
{
	if(is_EmptyF(*s))
		return 0;
	else
	{
		*elem=s->st[s->top];
		s->top--;
		return 1;
	}	
}
void displayF(FSTACK s)
{
	int k;
	int i=s.top;
	
	if(!is_EmptyF(s))
	{
		for(k=0;k<=i;k++)
		{	
		printf("%f -> ",s.st[k]);
		}
	}
	else
	printf("\n STACK IS EMPTY ! ");
}

float peekF(FSTACK s)
{
	float last;
	if(is_EmptyF(s))
		return '\0';
	else
	{
		last=s.st[s.top];
		return last;
	}	


}




