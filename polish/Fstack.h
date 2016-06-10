#include<stdio.h>
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
void displayF(FSTACK s); // print top-number of values from stack.


