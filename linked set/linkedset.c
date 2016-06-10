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

void display(LIST L);
void union_list(LIST L1,LIST L2,LIST* L3);
void intersect_list(LIST L1,LIST L2,LIST* L4);


void main()
{
	LIST L1,L2,L3,L4;
	int value,r,ch;
	int d;
	NODE* new_node;
	NODE* ptr;
	int pos,a;

	if(init(&L1))
	printf("LIST 1 IS INITIALIZED");	
	else
	printf("INITIALIZATION ERROR");
	
	if(init(&L2))
	printf("LIST 2 IS INITIALIZED");	
	else
	printf("INITIALIZATION ERROR");	

	while(1)
	{
		printf("\nMENU \n1.APPEND \n2.DISPLAY \n3.UNION \n4.INTERSECTION \n5.EXIT \n");
		printf("\n ENTER YOUR CHOICE : ");		
		scanf("%d",&ch);		
		switch(ch)
		{
		case 1 :	
				printf("\n press 0 for list 1 or press 1 for list 2 : ");
				scanf("%d",&a);		
				printf("\n ENTER VALUE TO BE INSERTED : ");
				scanf("%d",&value);

				if(a==0)
				{
					if(append(&L1,value))
						display(L1);
					else
						display(L1);
				}
				else if(a==1)
				{
					if(append(&L2,value))
						display(L2);
					else
						display(L2);
				}			
				break;
	 	case 2 :
				printf("\n press 0 for list 1 or press 1 for list 2 or press 2 for list 3 or press 3 for list 4 : ");
				scanf("%d",&a);		

				printf("\n");
				if(a==0)
				{
					display(L1);
				}
				else if(a==1)
				{
					display(L2);
				}
				else if(a==2)
				{
					display(L3);
				}
				else if(a==3)
				{
					display(L4);
				}
				break;

		 case 3 :
				init(&L3);
				union_list(L1,L2,&L3);
				display(L3);

				break;
		case 4 :
				init(&L4);
				intersect_list(L1,L2,&L4);
				display(L4);
				break;
		case 5 :
				exit(1);
		default :
				printf("\n WRONG CHOICE \n");
	}
}
}

int init(LIST* L)
{
		L->head=NULL;
		L->last=NULL;
		return 1;
}


NODE* create_node(int value)
{
	NODE* ptr;
	ptr=(NODE*)malloc(sizeof(NODE));
	
	if(ptr!=NULL)
	{
		ptr->data=value;
		ptr->next=NULL;
		return ptr;
	}
	else 
		return NULL;
}


int is_empty(LIST L)
{
	if(L.head==NULL)
		return 1;
	else
		return 0;
}


int append(LIST* L,int value)
{
	NODE* new_node,*ptr;

	ptr=L->head;
	while(ptr!=NULL && ptr->data!=value)
		ptr=ptr->next;
	
	if(ptr==NULL)
	{
		new_node=create_node(value);
	
		if(new_node!=NULL)
			{
				if(is_empty(*L))
					L->last=L->head=new_node;
				else
					{
						L->last->next=new_node;		
						L->last=new_node;
					}
				return 1;
			}
	}

	else
		return 0;
		
}

void display(LIST L)
{
	NODE* ptr;
	ptr=L.head;
	while(ptr!=NULL)
	{
		printf(" %d -> ",ptr->data);
		ptr=ptr->next;
	}

}



void union_list(LIST L1,LIST L2,LIST* L3)
{
	NODE *ptr1,*ptr2;
	int value;	
	ptr1=L1.head;
	ptr2=L2.head;

	while(ptr1!=NULL)
	{
		value=ptr1->data;
		append(L3,value);
		ptr1=ptr1->next;
	}
	while(ptr2!=NULL)
	{
		value=ptr2->data;
		append(L3,value);
		ptr2=ptr2->next;	
	}

}


void intersect_list(LIST L1,LIST L2,LIST* L4)
{
	NODE *ptr1,*ptr2;
	int value;	
	
	

	for(ptr1=L1.head;ptr1!=NULL;ptr1=ptr1->next)
	{
	  for(ptr2=L2.head;ptr2!=NULL;ptr2=ptr2->next)
	  {
		if(ptr1->data==ptr2->data)
		  append(L4,ptr1->data);
	  }
	}

}
