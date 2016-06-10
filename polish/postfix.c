#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include "Character_stack.h"
#include"Fstack.h"

void evaluate_post(char post[MAX],float *result);
void evaluate_pre(char pre[MAX],float *result);
void topostfix(char in[MAX],char post[MAX]);
void toprefix(char ine[MAX],char pre[MAX]);
int getprecedence(char c);
int is_operator(char c);
char *strrev(char *str);

void main()                                                                                                  
{
	char post[MAX];	
	char pre[MAX];
	char in[MAX];
	float result;
	printf("\n ENTER INFIX EXPRESSION :");
	scanf("%s",in);
	
	topostfix(in,post);
	printf("\n POSTFIX EXPRESSION : \n %s \n",post);
	toprefix(in,pre);
	printf("\n");

	evaluate_post(post,&result);
	printf("%f",result);
	printf("\n");

	/*evaluate_pre(pre,&result);
	printf("%f",result);
	printf("\n");*/

}

void topostfix(char in[MAX],char post[MAX])
{
	STACK op;
	char c,ch;
	int i,j,k;
	j=0;
	k=0;
	
	init(&op);

	for(i=0;in[i]!='\0';i++)
	{
		if(is_operator(in[i]))
			{
					if(!is_Empty(op) && in[i]!=')' && in[i]!='(')
					{
						if(getprecedence(peek(op))<getprecedence(in[i]))
						{
							push(&op,in[i]);
						}
						else if(getprecedence(peek(op))>getprecedence(in[i])||getprecedence(peek(op))==getprecedence(in[i]))
						{	
							pop(&op,&c);
							post[j]=c;
							j++;
							push(&op,in[i]);
						}
					}
					else if(is_Empty(op))
						push(&op,in[i]);
								
					
					else if(in[i]=='(')
						push(&op,in[i]);
					
					else if(in[i]==')')
					{						
						while(peek(op)!='(')
						{
							pop(&op,&c);
							post[j]=c;
							j++;							
						}
						pop(&op,&c);
					}
			}
		
		else
			{
					post[j]=in[i];
					j++;	
			}
	}
	while(op.top!=-1)
	{
		pop(&op,&c);
		post[j]=c;
		j++;	
	}
	post[j]='\0';
}
int getprecedence(char c)
{
	if(c=='+' || c=='-')
		return 1;
	else if(c=='*' || c=='/' || c=='%')
		return 2;
	else if(c=='^')
		return 3;
	else if(c=='(' || c==')')
		return 0;

}
int is_operator(char c)
{
	int i;
	int ar[MAX];
	switch(c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '{':
		case '}':
		case '[':
		case ']':
		case '(':
		case ')':
				return 1; break;
		
			
				break;	
		default :
				return 0;break;	
	}
}
void toprefix(char ine[MAX],char pre[MAX])
{
	char *post;
	char *in;

	post=(char *)malloc(sizeof(char)*MAX);
	STACK op;
	char c,ch;
	int i,j,k;
	float result;
	j=0;
	k=0;
	
	in=strrev(ine);
	init(&op);

	for(i=0;in[i]!='\0';i++)
	{
		if(is_operator(in[i]))
			{
					if(!is_Empty(op) && in[i]!=')' && in[i]!='(')
					{
						if(getprecedence(peek(op))<getprecedence(in[i]))
						{
							push(&op,in[i]);
						}
						else if(getprecedence(peek(op))>getprecedence(in[i])||getprecedence(peek(op))==getprecedence(in[i]))
						{	
							pop(&op,&c);
							post[j]=c;
							j++;
							push(&op,in[i]);
						}
					}
					else if(is_Empty(op))
						push(&op,in[i]);
								
					
					else if(in[i]==')')
						push(&op,in[i]);
					
					else if(in[i]=='(')
					{						
						while(peek(op)!=')')
						{
							pop(&op,&c);
							post[j]=c;
							j++;							
						}
						pop(&op,&c);
					}
			}
		
		else
			{
					post[j]=in[i];
					j++;	
			}
	}
	while(op.top!=-1)
	{
		pop(&op,&c);
		post[j]=c;
		j++;	
	}
	post[j]='\0';
	pre=strrev(post);
	printf("\n PREFIX EXPRESSION : \n %s \n",pre);

	evaluate_pre(pre,&result);
	printf("%f",result);
	printf("\n");
}
char * strrev(char *str)

{

    int i = strlen(str)-1,j=0;

    char ch;
    while(i>j)
    {
        ch = str[i];
        str[i]= str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

float p_op(char op,float a,float b)
{
	switch(op)
	{
	case '+' :
			return (float)a+(float)b;break;
	case '*' :
			return (float)a*(float)b;break;
	case '-' :
			return (float)a-(float)b;break;
	case '/' :
			return (float)a/(float)b;break;
	case '^' :
			//return pow((float)a,(int)b);
			break;	
	}
}

void evaluate_post(char post[MAX],float *result)
{
	FSTACK s;
	int n;
	int i=0;
	int j=0;
	float a,b;
	initF(&s);
	n=strlen(post);
	while(i<n)
	{
		if(!is_operator(post[i]))
		{
			pushF(&s,(float)(post[i]-'0'));
			i++;
		}
		else
		{
			popF(&s,&a) && popF(&s,&b);
			*result=p_op(post[i],a,b);
			pushF(&s,*result);
			i++;
		}
}
popF(&s,result);

		
}
void evaluate_pre(char pre[MAX],float *result)
{
	char *rev;
	rev=strrev(pre);
	evaluate_post(rev,result);
}
