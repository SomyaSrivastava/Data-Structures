#include"polynomial.h"
/*#include<stdio.h>
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
 
 void main()
 {
 	LIST L;
	TERM T;
	int r,x;
	NODE* new_node;
	int pos,ch;
 	initialise(&L); // Initialising the list to null
	while(1)
	{	
		printf("\n MENU");	
		printf("\n 1.BUILD POLYNOMIAL : ");
		printf("\n 2.DISPLAY : ");
		printf("\n 3.EVALUATE : ");	
		printf("\n 4.EXIT");
		printf("\n ENTER YOUR CHOICE : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
		
					printf("\n TERM NUMBER %d : ",L.count+1);
					printf("\n ENTER COEEFICIENT :");
					scanf("%d",&T.coeff);
					printf(" ENTER POWER : ");
					scanf("%d",&T.pow);
					
					new_node=createNode(T); 
					
					if(build(&L,T))
						displayAll(L);
					else
						printf("\nINSERT UNSUCCESSFULL !");

					break;
			case 2 :
					displayAll(L);
					break;

			case 3 :
					printf("\n ENTER THE VALUE OF x :");
					scanf("%d",&x);
					r=evaluate(L,x);
					printf("\n RESULT : %d\n",r);
					break;
			case 4 :
					exit(1);			
			default :
					printf("\n wrong choice!");
		}

	}

 }
 */
 
 void initialise(LIST* L)				//INITIALIZATION OF LIST
 {
 	 L->head=NULL;
 	 L->tail=NULL;
 	 L->count=0;
 }
 
 NODE* createNode(TERM T)				// NODE CREATION
 {

	 NODE* new_node;
 	 new_node=(NODE*) malloc(sizeof(NODE)); 
 	 
 	 if(new_node!=NULL)
 	 {
 	 	new_node->next=new_node->prev=NULL;
 	 	new_node->T.coeff=T.coeff;
		new_node->T.pow=T.pow;
	
 	 }
 	 
	return new_node;
 }


 void displayAll(LIST L)                     //NODE DISPLAY
 {
	NODE *ptr;

	ptr = L.head;
	if(ptr!=NULL)
	{
		while(ptr != NULL) 
		{ 
			printf("%dx^%d +", ptr->T.coeff,ptr->T.pow); 
			ptr = ptr->next; 
		} 
		printf("\nTotal number of elements : %d\n",L.count);
	}
	else
		printf("\n POLYNOMIAL IS EMPTY!");
 }
 
 int build(LIST* L,TERM T)                //SEARCH
 {
 	int pos=0;
	NODE* ptr;
	int temp;
	ptr = L->head; 

	if(ptr==NULL)
  		{
  			L->head=L->tail=createNode(T);
  			L->count++;
  			
  		}
	else if(L->tail->T.pow > T.pow)
		{
			if(append(L,T))
				return 1;
			else
				return 0;		
		} 
	else if(L->head->T.pow < T.pow)
		{
			if(addAtBeg(L,T))
				return 1;
			else
				return 0;
		}
	else
	{
		while(ptr != NULL) 
		{ 
			if(ptr->T.pow > T.pow && ptr->next->T.pow < T.pow  )
				break;

			else if(ptr->T.pow == T.pow)
				break;				
			else
			{
				pos++;
				ptr=ptr->next;
			}
						
		}
		 if(ptr->T.pow > T.pow )
		{
			if(insertAtPosition(L,(pos+1),T))		
				return 1;
			else 
			return 0;
		}
				

		else if(ptr->T.pow == T.pow)
		{
			ptr->T.coeff=ptr->T.coeff +T.coeff;
			{
				if(ptr->T.coeff==0)
				{
					delete(L,pos);
				}
				
			}
		return 1;					
		}
	
	}
}
 int insertAtPosition(LIST* L,int pos,TERM T)			// INSERTION
 {
  	NODE *temp,*ptr;
  	int count=0;
  	
  	if(pos > L->count)
  		return 0;

  	  	
       if(pos < (L->count+1)/2)
  	{
  		ptr=L->head;
  		while(count < pos)
  		{
  			ptr=ptr->next;
  			count++;
  		}
  		
  		temp=createNode(T);
  		
  		temp->next = ptr;
 		
 		if(ptr->prev !=NULL)
 		{
 			temp->prev=ptr->prev;
 			ptr->prev->next=temp;
 		} 		
 		else
 			L->head=temp;
 		
 		ptr->prev=temp;
 		++L->count;
 		return 1; 		
  	}
  	
  	else
  	{
  		ptr=L->tail;
  		count=L->count;
  		while(count > pos)
  		{
  			ptr=ptr->prev;
  			count--;
  		}
  		
  		temp=createNode(T);
  		temp->prev=ptr;
  		
  		if(ptr->next != NULL)
  		{
  			ptr->next->prev=temp;
  			temp->next=ptr->next;
  		}
  		
  		else
  			L->tail=temp;
  		
		ptr->next=temp;
  		L->count++;
  		return 1; 		
  	}
}
 int addAtBeg(LIST* L,TERM T)			// ADD AT BEG
{
		NODE* ptr;
		ptr=L->head;
		if(L->head=createNode(T))
		{
			L->head->next=ptr;
			ptr->prev=L->head;
			L->count++;
			return 1;
		}
		else
			return 0;
}
 int append(LIST* L,TERM T)			//ADD AT END
{
		NODE* ptr;
		ptr=L->tail;
		if(L->tail=createNode(T))
		{
		ptr->next=L->tail;
		L->tail->prev=ptr;
		L->count++;
		return 1;
		}
}

int delete(LIST *L,int pos)
{
		 	NODE *ptr;
		 	int count=0;
		 	
		 	if(pos >= L->count)
		 		return 0;
		 		
		 	if(pos==0 && L->count!=1)
		 	{
		 		ptr=L->head;
		 		ptr->next->prev=NULL;
		 		L->head=ptr->next;
		 		free(ptr);
		 		L->count--;
		 		return 1;
		 	}
		 	if(pos==0 && L->count==1)
		 	{
		 		ptr=L->head;
		 		free(ptr);
		 		L->count--;
		 		return 1;
		 	}
		 	if(pos == L->count-1)
		 	{
		 		ptr=L->tail;
		 		ptr->prev->next=NULL;
		 		L->tail=ptr->prev;
		 		free(ptr);
		 		L->count--;
		 		return 1;
		 	}	
		 	

		 	if(pos < (L->count+1)/2)
		  	{
		  		ptr=L->head;
		  		while(count < pos)
		  		{
		  			ptr=ptr->next;
		  			count++;
		  		}	
		  	}
		  	
		  	else
		  	{
		  		ptr=L->tail;
		  		count=L->count;
		  		while(count > pos+1)
		  		{
		  			ptr=ptr->prev;
		  			count--;
		  		} 		
		  	}
		  	
		  	ptr->prev->next=ptr->next;
		  	ptr->next->prev=ptr->prev;
		  	L->count--;
		  	
		 return 1; 	
 }
int evaluate(LIST L,int x)
{
	NODE *ptr;
	int r=0;
	ptr = L.head;
	if(ptr!=NULL)
	{
		while(ptr->next!=NULL) 
		{ 
			r = r + (ptr->T.coeff * (x^ptr->T.pow)); 
			ptr = ptr->next; 
		} 
		printf("\n RESULT : %d\n",r);
		return r;
	}
	else
		{printf("\n POLYNOMIAL IS EMPTY!");return 0;}
 
} 

 

