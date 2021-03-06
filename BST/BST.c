#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Tnode
{
	int data;
	struct Tnode *left,*right;
}TNODE;

void init(TNODE** r);
TNODE* createNode(int data);
void insert(TNODE** r,int data);
TNODE* search(TNODE* r,int data);
TNODE* rec_search(TNODE* r,int data);
TNODE* rec_insert(TNODE *r,int data);
void posttraversal(TNODE* r);
void intraversal(TNODE* r);
void pretraversal(TNODE* r);
int delete(TNODE** r,int data);

void main()
{
int ch,data,c,s;

TNODE *r;
TNODE *searched;
TNODE *newNode;
//printf("\n ENTER DATA FOR ROOT NODE : ");
//scanf("%d",&data);
init(&r);

while(1)
{
	printf("\nMENU \n1.insert \n2.search \n3.display \n4.delete \n5.exit");
	printf("\n ENTER YOUR CHOICE : ");
	scanf("%d",&ch);
	switch(ch)
		{
			case 1 :
				 printf("\n ENTER DATA TO INSERT : ");
				 scanf("%d",&data);
				 printf("\n FOR RECURSIVE INSERTION PRESS 0 ELSE PRESS 1 : ");
				 scanf("%d",&c);
				 if(c)	
				         insert(&r,data);
				 else 
					rec_insert(r,data);
					 break;
			case 2 :
				 printf("\n ENTER DATA TO BE SEARCHED  : ");
				 scanf("%d",&data);
				 printf("SEARCH RECURSIVELY ? (1 if yes , 0 if no) :");
				 scanf("%d",&s);
				 if(s)	
					searched=rec_search(r,data);
				 else
				 	searched=search(r,data);
					 

				 if(searched!=NULL)
						printf("\n NODE SEARCHED!");
					 else
						printf("\n UNSUCCESSFULL SEARCH");
	 			break;
			case 3 :
				 printf("\n WHICH TYPE OF TRAVERSAL ? \n1.PREORDER \n2.POSTORDER \n3.INORDER \nENTER YOUR CHOICE : ");
				 scanf("%d",&c);
				 switch(c)
				 {
					case 1 :						
					        pretraversal(r);
						break;					
					case 2 :
						posttraversal(r);
						break;
					case 3 :
						intraversal(r);
						break;
				 }
				 break;
		     case 4 :
				printf("\n ENTER THE DATA OF THE NODE TO BE DELETED : ");
				scanf("%d",&data);
				if(delete(&r,data))
					printf("%d is deleted.",data);
				else
					printf("\n UNSUCCESSFULL DELETION!");				
				break;
		    case 5 :
				exit(0);
		    default :
				printf("\n WRONG CHOICE ");			
		
		}
	}

}


void init(TNODE**r)
{
	*r=NULL;
}

TNODE* createNode(int data)
{
	TNODE* newnode;
	newnode=(TNODE*)malloc(sizeof(TNODE));
	newnode->right=NULL;
	newnode->left=NULL;
	newnode->data=data;
	return newnode;
}

void insert(TNODE**r,int data)
{
	TNODE* ptr;
	TNODE* newNode;
	TNODE* parent;

	ptr=*r;
	newNode=createNode(data);
	if(*r==NULL)
	{
		*r=newNode;
	    	return;
	}
	while(ptr)	
	{	
		parent=ptr;
		if(ptr->data < data)
			{
				ptr=ptr->right;
			}
		else if(ptr->data > data)
			{
				ptr=ptr->left;
			}
	}
		
	if(parent->data > data)
	{
		parent->left = newNode;
	}
	
	else if(parent->data < data)
	{
		parent->right = newNode;
	}
}

TNODE* search(TNODE* r,int data)
{
	TNODE* ptr;
	ptr=r;
	
	while(ptr!=NULL && ptr->data !=data)
	{
		if(ptr->data > data)
			ptr=ptr->left;
		else if(ptr->data < data)
			ptr=ptr->right;
	}
	return ptr;
}

TNODE* rec_search(TNODE* r,int data)
{
	if(data==r->data)
		return r;
	else if(data < r->data)
		return rec_search(r->left,data);
	else if(data > r->data)
		return rec_search(r->right,data);
}

void pretraversal(TNODE* r)
{
	if(r)
	{
		printf("|%d|->",r->data);		
		pretraversal(r->left);
		pretraversal(r->right);
		
	}
	else
		return;
}
void intraversal(TNODE* r)
{
	if(r)
	{				
		intraversal(r->left);
		printf("|%d|->",r->data);
		intraversal(r->right);
	}
	else
		return;
}
void posttraversal(TNODE* r)
{
	if(r!=NULL)
	{
		posttraversal(r->left);
		posttraversal(r->right);
		printf("|%d|->",r->data);
	}
	else
		return;
}

int delete(TNODE** r,int data)
{
	TNODE* ptr;
	TNODE* parent;
	TNODE* p;
	TNODE* d;
	ptr=*r;
	parent=NULL;
	
	while(ptr->data!=data)
	{
		parent=ptr;
		if(ptr->data > data)
			ptr=ptr->left;
		else if(ptr->data < data)
			ptr=ptr->right;
	}

	if(ptr!=NULL)
	{
	
	  if(ptr->left==NULL && ptr->right==NULL) 
		{
			if(parent==NULL)
			{
				*r=NULL;
				free(ptr);
				return 1;
			}
			
			else if(parent->right==ptr)			
			{
				free(ptr);				
				parent->right=NULL;
				return 1;
			}
			
			else if(parent->left==ptr)			
			{				
				free(ptr);
				parent->left=NULL;
				return 1;
			}
		
		 }
		
		else if(ptr->left!=NULL && ptr->right==NULL)
		{
			if(parent->right==ptr)
			{
				parent->right=ptr->left;
				free(ptr);
				return 1;
			}
			else if(parent->left==ptr)
			{
				parent->left=ptr->left;
				free(ptr);
				return 1;
			}
		}
		else if(ptr->right!=NULL && ptr->left==NULL)
		{
			if(parent->right==ptr)
			{
				parent->right=ptr->right;
				free(ptr);
				return 1;
			}
			else if(parent->left==ptr)
			{
				parent->left=ptr->right;
				free(ptr);
				return 1;
			}
		}
		
		else if(ptr->left!=NULL && ptr->right!=NULL)
		{
			
				d=ptr->right;
				while(d)
				{
					p=d;
					d=d->left;
				}

				ptr->data=p->data;
				delete(&ptr->right,p->data);
		}
	}
	

	else 
		return 0;

}

TNODE* rec_insert(TNODE *r,int data)
{
TNODE* newNode;
	if(r==NULL)
	{
		newNode=createNode(data);
		return newNode;
	}
	else if(data < r->data)
	{
		r->left=rec_insert(r->left,data);
	}
	else if(data>r->data)
	{
		r->right=rec_insert(r->right,data);
	}
}



















































