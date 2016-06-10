#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node* next;
	struct node* prev;
}NODE;

typedef struct list
{
	NODE* head;
	NODE* tail;
	int count;
}LIST;

int init(LIST* L);
int isEmpty(LIST L);
NODE* createNode(int value);
int append(LIST* L,int value);
int addatbeg(LIST* L,int value);
int insert(LIST* L,int value,int pos);
int delete(LIST* L,int pos,int* item);
NODE* search(LIST L,int value);
void display(LIST L);

void main()
{
int value,pos,ch,item;
NODE* ptr;
LIST L;

if(init(&L))
	printf("\n LIST IS INITIALIZED");
else
	printf("\n LIST CAN NOT BE INITIALIZED ");
while(1)
{
	printf("\nMENU \n1.INSERT \n2.APPEND \n3.ADD AT BEGINNING \n4.SEARCH \n5.DELETE \n6.DISPLAY \n7.EXIT : ");
	printf("\nENTER YOUR CHOICE: ");
	scanf("%d",&ch);	

	switch(ch)
	{
		case 1 :
				printf("\nENTER THE DATA : ");
				scanf("%d",&value);
				printf("\nENTER THE POSITION : ");
				scanf("%d",&pos);
				if(insert(&L,value,pos))
					display(L);
				else
					printf("\n UNSUCCESSFULL INSERTION");
				break;

		case 2 :	printf("\nENTER THE DATA : ");
				scanf("%d",&value);
				if(append(&L,value))
					display(L);
				else
					printf("\n UNSUCCESSFULL APPEND");
						
				break;
		case 3 :
				printf("\nENTER THE DATA : ");
				scanf("%d",&value);
				if(addatbeg(&L,value))
					display(L);
				else
					printf("\n UNSUCCESSFULL ADDITION AT BEGINNING ");
				break;
		case 4 :	
				printf("\nENTER THE DATA TO BE SEARCHED FOR : ");
				scanf("%d",&value);
				ptr=search(L,value);
				if(ptr)
					printf("\n SEARCH SUCCESSFULL");
				else 
					printf("\n UNSUCCESSFULL SEARCH");
				break;

		case 5 :	printf("\nENTER THE POSITION AT WHICH YOU NEED DELETEION : ");
				scanf("%d",&pos);
				if(delete(&L,pos,&item))
					{
						printf("%d has been deleted.\n",item);
						display(L);
					}
				else
					printf("\n UNSUCCEFULL ADDITION AT BEGINNING ");
				break;
		case 6 :
				display(L);
				break;
		
		case 7 :
				exit(0);
		default :
				printf("\n WRONG CHOICE !");

		}
	}
}

int init(LIST* L)
{
	L->head=NULL;
	L->tail=NULL;
	L->count=0;
	return 1;
}
int isEmpty(LIST L)
{
	if(L.head==NULL && L.tail==NULL)
		return 1;
	else
		return 0;
}

NODE* createNode(int value)
{
	NODE* ptr;
	if(ptr=(NODE*)malloc(sizeof(NODE)))
	{
		ptr->next=NULL;
		ptr->prev=NULL;
		ptr->data=value;
	}
	return ptr;
}

int append(LIST* L,int value)
{
	NODE* ptr;
	ptr=createNode(value);
	
	
	
	if(isEmpty(*L))
		{
			L->head=ptr;
			L->tail=ptr;			
			L->count++;
			return 1;		
		}

	else
		{

			ptr->prev=L->tail;	
			L->tail->next=ptr;		
			L->tail=ptr;	
			L->count++;
			return 1;		
		}

	return 0;
}

int insert(LIST* L,int value,int pos)
{
	NODE* ptr;
	NODE* new_node;
	int count=0;
		
	ptr=L->head;
	//printf("%d",L->count);
	if(pos > L->count+1)
		{return 0;}

	else if(pos==0)
	{
		addatbeg(L,value);		
	}	
	
    else if(pos==L->count)
		{
			append(L,value);
		}
	else
	{
		while(ptr!=NULL && count!=pos)
		{		
			ptr=ptr->next;
			count++;
		}
		if(ptr)
		{
			new_node=createNode(value);
			new_node->prev=ptr->prev->next;
			new_node->next=ptr;
			L->count++;
			return 1;
		}
	}		
}	
int delete(LIST* L,int pos,int* item)
{
	NODE* ptr;
	int count=0;
	ptr=L->head;
	if(pos>L->count)
		return 0;
	else if(pos==0)
	{	
		ptr->next->prev=NULL;
		L->head=ptr->next;
		free(ptr);
		return 1;	
	}	

	else if(pos==L->count)
	{
		ptr->prev->next=NULL;
		L->tail=ptr->prev;
		free(ptr);
		return 1;
	}

	else
	{
		while(ptr!=NULL && count!=pos)
		{		
			ptr=ptr->next;
			count++;
		}
		ptr->next->prev=ptr->prev;		
		ptr->prev->next=ptr->next;
		free(ptr);		
		return 1;
	}


}
NODE* search(LIST L,int value)
{
	NODE* ptr;
	ptr=L.head;	
	while(ptr!=NULL && ptr->data!=value)
	{
		ptr=ptr->next;
	}

	return ptr;
}
void display(LIST L)
{
	NODE* ptr;	
	ptr=L.head;
	if(ptr)
	{	
		while(ptr!=NULL)
		{
		printf("%d-> ",ptr->data);
		ptr=ptr->next;
		}
	}
	else
		printf("\n DOUBLY LINKED LIST IS EMPTY");
}
int addatbeg(LIST* L,int value)
{
	NODE *newnode;
	newnode=createNode(value);
	if(!isEmpty(*L))
	{
		newnode->next=L->head;	
		L->head->prev=newnode;
		L->head=newnode;
		L->count++;		
		return 1;
	}
	else
	{
		L->head=newnode;
		L->count++;
		return 1;
	}
}


































