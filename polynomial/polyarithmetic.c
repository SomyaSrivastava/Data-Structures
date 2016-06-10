#include<stdio.h>
#include<stdlib.h>
#include"polynomial.h"
void add(LIST *L3,LIST L1,LIST L2);
void sub(LIST *L4,LIST L1,LIST L2);
void mul(LIST *L5,LIST L1,LIST L2);
void main()
{
	int ch;
	int x;
	NODE *new_node;
	TERM T;
	LIST L1,L2,L3,L4,L5;
	initialise(&L1);
	initialise(&L2);
	initialise(&L3);
	initialise(&L4);
	initialise(&L5);

	while(1)
	{
		printf("\n WHICH LIST DO YOU WISH TO BUILD ? ENTER 0 FOR FIRST LIST AND 1 FOR SECOND AND 2 TO STOP: ");
		scanf("%d",&ch);			
		if(ch==0)
		{
			for(;;)
			{
				printf("\nDO YOU WISH TO QUIT BUILDING THIS LIST ? ENTER '3' IF YES :");
				scanf("%d",&x);
				
				if(x!=3)
				{				
					printf("\n TERM NUMBER %d : ",L1.count+1);
					printf("\n ENTER COEEFICIENT :");
					scanf("%d",&T.coeff);
					printf(" ENTER POWER : ");
					scanf("%d",&T.pow);
					new_node=createNode(T); 
		
					if(build(&L1,T))
					displayAll(L1);
					else
					printf("\nINSERT UNSUCCESSFULL !");
				}
				else
					break;
			}

		}

		else if(ch==1)
		{
			for(;;)
			{
				printf("\nDO YOU WISH TO QUIT BUILDING THIS LIST ? ENTER '3' IF YES :");
				scanf("%d",&x);
				if(x!=3)
				{
					printf("\n TERM NUMBER %d : ",L2.count+1);
					printf("\n ENTER COEEFICIENT :");
					scanf("%d",&T.coeff);
					printf(" ENTER POWER : ");
					scanf("%d",&T.pow);
					new_node=createNode(T); 
					if(build(&L2,T))
						displayAll(L2);
					else
						printf("\nINSERT UNSUCCESSFULL !");
				}
				else
					break;
			}
		}
		else if(ch==2)
			break;
	}

	//add(&L3,L1,L2);
	//sub(&L4,L1,L2);
	mul(&L5,L1,L2);
}
void add(LIST *L3,LIST L1,LIST L2)
{
	NODE *ptr1,*ptr2;
	TERM T;
	ptr1=L1.head;
	ptr2=L2.head;
	
	while(ptr1 !=NULL)
	{
		build(L3,ptr1->T);
		ptr1=ptr1->next;
	}
	
	while(ptr2 !=NULL)
	{
		build(L3,ptr2->T);
		ptr2=ptr2->next;
	}
	displayAll(*L3);
}

void sub(LIST *L4,LIST L1,LIST L2)
{
	NODE *ptr1,*ptr2;
	TERM T;
	ptr1=L1.head;
	ptr2=L2.head;
	
	while(ptr1 !=NULL)
	{
		build(L4,ptr1->T);
		ptr1=ptr1->next;
	}
	
	while(ptr2 !=NULL)
	{
		ptr2->T.coeff=-ptr2->T.coeff;
		build(L4,ptr2->T);
		ptr2=ptr2->next;
	}
	displayAll(*L4);
}
void mul(LIST *L5,LIST L1,LIST L2)
{
	NODE *ptr1,*ptr2;
	TERM T;
	ptr1=L1.head;
	ptr2=L2.head;
	
	
	while(ptr1 !=NULL)
	{
		while(ptr2 !=NULL)
		{
			ptr2->T.coeff = ptr1->T.coeff * ptr2->T.coeff;
			ptr2->T.pow = ptr1->T.pow + ptr2->T.pow;
			build(L5,ptr2->T);
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
	
	displayAll(*L5);
}
