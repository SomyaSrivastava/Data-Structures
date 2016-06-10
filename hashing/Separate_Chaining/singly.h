#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}NODE;

typedef struct list
{
	NODE* head;
	NODE* last;
}LIST;

//Function prototyping
int init(LIST* L);
NODE* create_node(int value);
int is_empty(LIST L);
int append(LIST* L,int value);
int insert(LIST* L,int value,int pos);
NODE* search(LIST L,int data);
int delete(LIST* L,int pos,int *d);
void display(LIST L);

