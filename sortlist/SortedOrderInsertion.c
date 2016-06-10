#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node*next;
}NODE;

typedef struct List
{
	NODE* head;
	NODE* last;
	int count;

}LIST;


void init(LIST *L)
{
	L->head=NULL;
	L->last=NULL;
	L->count=0;
}
NODE *createnode(int data)
{
	NODE *ptr;
	ptr=(NODE *)malloc(sizeof(NODE));
	ptr->data=data;
	ptr->next=NULL;
	return ptr;	
	
}
int insert(LIST *L,int data)
{
	NODE *ptr,*nNode,*pptr;

	nNode=createnode(data);
	if(nNode==NULL){return 0;}	

	ptr=L->head;
	
	if(ptr==NULL) // if list is empty
	{
		L->head=nNode;
		L->last=nNode;
	}
	
	else // if list is not empty
	{
		
		if(nNode->data > L->last->data) // if new data is greater than last element's data 
		{
			L->last->next=nNode; // add at end.
			L->last=nNode;
		}
		else if(nNode->data < L->head->data) // if new data is lesser than head's data
		{
			nNode->next=L->head; // add at beginning
			L->head=nNode;
		}

		else 
		{		
			while(!(nNode->data > ptr->data  && nNode->data < ptr->next->data) ) // when  new data is in between last node's data and head's data
				{
					pptr=ptr; // parent pointer (not used)				
					ptr=ptr->next;//searching for place for insertion
				}
				nNode->next=ptr->next;//when place is found then we insert in middle.
				ptr->next=nNode;
		}
		
	}


	L->count++;
	return 1;
}
void disp(LIST L)
{
	NODE *ptr;
	ptr=L.head;
	while(ptr!=NULL)
	{
		printf("%d-> ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

void main()
{
LIST L;
int data;
init(&L);
while(1)
{

printf("\nENTER VALUE : 0 TO EXIT : ");
scanf("%d",&data);

if(data)
{
	if(insert(&L,data))
		disp(L);
	else
		printf("ERROR");

}
else
	exit(1);



}


}
