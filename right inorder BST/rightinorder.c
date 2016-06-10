#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct rinthread
{
	int value;
	struct rinthread *left,*right;
	int rthread;
}RINTHREAD;

RINTHREAD *createnode(int data)
{
	RINTHREAD *nNode=(RINTHREAD *)malloc(sizeof(RINTHREAD));
	nNode->left=nNode->right=NULL;
	nNode->rthread=0;
	nNode->value=data;
	return nNode;
}

void inorder(RINTHREAD *R)
{
if(!R)
	return;
else
	{
		inorder(R->left);
		printf("%d->",R->value);
		if(!R->rthread)
			inorder(R->right);

	}


}

int insert(RINTHREAD **R,int data)
{
	RINTHREAD *nNode=createnode(data);
	
	RINTHREAD *ptr,*pptr;
	if(!nNode)
		return 0;
	else if(!*R)
		{*R=nNode;return 1;}
	else
	{
		RINTHREAD *ptr=*R;
		RINTHREAD *pptr=NULL;
		
		while(ptr)
		{
			pptr=ptr;
			if((ptr->value)>data)
				ptr=ptr->left;
			else if(ptr->value < data && ptr->rthread == 0)
				ptr=ptr->right;
			else
				break;

		}
	
	
	if(pptr->value > data)
	{
		pptr->left=nNode;
		nNode->right=pptr;// RTHREAD
		nNode->rthread=1;
	}

	if(pptr->value < data)
	{
		pptr->right=nNode;
		pptr->rthread=0;
	}
	
	return 1;		
	}
}

void init(RINTHREAD **R)
{
*R=NULL;
}


void main()
{
RINTHREAD *R;
int ch,data;
init(&R);

while(1)
{
printf("\n1.INSERT \n2.EXIT \n");
scanf("%d",&ch);
switch(ch)
{
case 1 : 
		printf("\n ENTER VALUE TO BE INSERTED :\n");
		scanf("%d",&data);
		if(insert(&R,data))
			inorder(R);
		else
			printf("\nERROR");		
		break;
case 2 :
		exit(1);

}

}


}
