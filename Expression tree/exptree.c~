#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

typedef struct ETnode
{
	char value;
	struct ETnode *left;
	struct ETnode *right;
}ETNODE;

typedef struct Nstack
{
	ETNODE *stack[50];
	int top;
}NSTACK;

int isoperator(char ch)
{
switch(ch)
	{
		case '+' :
		case '-' :
		case '*' :
		case '/' :
		case '%' :
		case '^' :
			return 1;
			break;
		default :
			return 0;
	}
}

void postorder(ETNODE *r)
{
if(!r)
	return;
else
	{
		postorder(r->left);
		postorder(r->right);
		printf("%c->",r->value);
	}
}

void initNSTACK(NSTACK *S)
{
S->top=-1;
}

int Npush(NSTACK *S,ETNODE *value)
{
if(isfull_nstack(*S))
	return 0;
else
	{
		S->stack[++(S->top)]=value;
		return 1;
	}
}

int Npop(NSTACK *S,ETNODE **value)
{
if(isempty_nstack(*S))
	return 0;
else
	{
		*value=S->stack[S->top];
		--S->top;
		return 1;
	}
}

int isempty_nstack(NSTACK S)
{
	if(S.top==-1)
		return 1;
	else
		return 0;

}

int isfull_nstack(NSTACK S)
{
	if(S.top==50)
		return 1;
	else
		return 0;

}
ETNODE *peek(NSTACK S)
{
	if(isempty_nstack(S))
		return NULL;
	else
		return S.stack[S.top];
}

ETNODE *createnode(char data)
{
ETNODE *nNode;
nNode=(ETNODE *)malloc(sizeof(ETNODE));
nNode->left=nNode->right=NULL;
nNode->value=data;
return nNode;
}

void initET(ETNODE **r)
{
*r=NULL;
}

int createET(char *exp,ETNODE **root)
{

NSTACK S;
int i=0;

initNSTACK(&S);

	while(exp[i]!='\0')
	{
		ETNODE *nNode=createnode(exp[i]);
		ETNODE *r,*l;
		
		if(isoperator(exp[i]))
		{
			Npop(&S,&r);
			Npop(&S,&l);
				
			nNode->left=l;
			nNode->right=r;
			
			Npush(&S,nNode);
		}

		else
			Npush(&S,nNode);
		
		i++;
	}

	*root=peek(S);
	return 0;
}

int performop(char op,int a,int b)
{

	switch(op)
	{
	case '+' : 
			return a+b;break;
	case '*' : 
			return a*b;break;

	case '-' : 
			return a-b;break;
	case '/' : 
			return a/b;break;

	case '%' : 
			return a%b;break;

	}

}

int evaluate(ETNODE *root)
{
	int a,b,c;
	if(root)
	{
		if(!isoperator(root->value))
			return (root->value - '0');
		a=evaluate(root->left);
		b=evaluate(root->right);
		c=performop((root->value),(int)a,(int)b);
		return c;

	}
}

int main()
{
ETNODE *root=NULL;
char exp[50];
int c;
printf("\n ENTER POSTFIX EXPRESSION : ");
scanf("%s",exp);

createET(exp,&root);
postorder(root);

c=evaluate(root);

printf("%d",c);
return 0;
}























