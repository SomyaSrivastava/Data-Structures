#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct AVLnode
{
	int value;
	struct AVLnode *left,*right;
	int height;
}AVL;

void initAVL(AVL **r)
{
	*r=NULL;
}


AVL* createAvlNode(int data)
{ 
	AVL* nNode;
	nNode=(AVL*)malloc(sizeof(AVL));
	nNode->left=nNode->right=NULL;
	nNode->value=data;
	nNode->height=0;
	return nNode;
}

int max(int lh,int rh)
{
if(lh > rh)
	return lh;
else
	return rh;
}

void cal_height(AVL *r)
{
	if(r->left!=NULL && r->right!=NULL )
		r->height= max(r->left->height,r->right->height)+1;
	else if(r->left==NULL && r->right==NULL )
		r->height = 0;
	else if(r->left!=NULL && r->right==NULL)
		r->height=r->left->height + 1;
	else if(r->left==NULL && r->right!=NULL)
		r->height=r->right->height + 1;
}
void update_heights(AVL *r)
{
	if(r==NULL)
		return;

	if(r->left != NULL)
		cal_height(r->left);
	if(r->right != NULL)
		cal_height(r->right);
	cal_height(r);
	
}
int diff_height(AVL *r)
{
if(r->left && r->right)
	return abs(((r->left->height)-(r->right->height)));
else if(r->left)
	return r->left->height +1;
else if(r->right)
	return r->right->height +1;
else 
	return 0;
}

void RightRo(AVL **pivot)
{
	AVL *temp=(*pivot)->left;
	(*pivot)->left=(*pivot)->left->right;
	temp->right=*pivot;
	*pivot=temp;
}
void LeftRo(AVL **pivot)
{
	AVL *temp=(*pivot)->right;
	(*pivot)->right=(*pivot)->right->left;
	temp->left=*pivot;
	*pivot=temp;
}

int insert(AVL **r,int data)
{
	/*AVL *ptr;
	AVL *parent;
	
	
	ptr=parent=*r;*/

	AVL *nNode=createAvlNode(data);
	
	if(!nNode)
		return 0;
	else if(*r==NULL)
	{
		*r=nNode;
		 return 1;
	}

	if(data < (*r)->value)
	{
		insert(&((*r)->left),data);
		cal_height(*r);
		//printf("value : %d hieght : %d",(*r)->value,(*r)->height);
		if(diff_height(*r)==2)
		{	
			if(data < (*r)->left->value) //LL IMBALANCE
				RightRo(r);
			else 				//LR IMBALANCE
				{

					LeftRo(&((*r)->left));
					RightRo(r);
				}

		}
	update_heights(*r);
	}

	if(data > (*r)->value)
	{
		insert(&((*r)->right),data);
		cal_height(*r);
		//printf("value : %d hieght : %d",(*r)->value,(*r)->height);
		if(diff_height(*r)==2)
		{	
			if(data < (*r)->right->value) //RR IMBALANCE
				LeftRo(r);
			else 				//LR IMBALANCE
				{

					RightRo(&((*r)->right));
					LeftRo(r);
				}

		}
	update_heights(*r);

	}


}

void displayAVL(AVL *r)
{
if(r==NULL)
	return;
else
	{
		displayAVL(r->left);
		printf(" %d (height = %d) \n",r->value,r->height);
		displayAVL(r->right);
	}
}

void main()
{

AVL *root;
int ch,data;
initAVL(&root);

while(1)
{

printf("\nMENU \n1.CREATE NODE \n2.DISPLAY \n3.EXIT \nENTER YOUR CHOICE : ");
scanf("%d",&ch);
	switch(ch)
	{
		case 1 :
			printf("\n ENTER DATA FOR THE NODE : ");
			scanf("%d",&data);
	
			if(insert(&root,data))
				displayAVL(root);	
			else
				printf("\n ERROR ");
			break;
		case 2 :
			displayAVL(root);
			break;
		case 3 :
			exit(1);
		default :
				printf("\nWRONG CHOICE");

	}
}
}
