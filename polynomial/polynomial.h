#include<stdio.h>
#include<malloc.h>
#include<stdlib.h> 
#include<math.h>
typedef struct term
 {
 	int coeff;
	int pow;
 }TERM;
typedef struct node
{
	TERM T;
	struct node* prev;
	struct node* next;
}NODE;
 
typedef struct list
 {
 	NODE* head;
 	NODE* tail;
 	int count;
 }LIST;
 
 //Function prototyping
 void initialise(LIST* L);
 NODE* createNode(TERM T);
 int insertAtPosition(LIST *L,int pos,TERM T);
 int addAtBeg(LIST* L,TERM T);
 int append(LIST* L,TERM T);
 void displayAll(LIST L);
 int build(LIST* L,TERM T);
 int delete(LIST *L,int pos);
 int evaluate(LIST L,int x);

