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
int push(STACK *s, char elem[MAX]); // increment the top and push the element in the stack.
int pop(STACK *s, char *elem);//decrement the top and pop the element from the stack.
void display(STACK s); // print top-number of values from stack.
char peek(STACK s);//peek function to view the last value in the stack

