#include"g.h"
/*
#include<stdio.h>
#include<stdlib.h>
#include "Character_stack.h"
#include "q.h"

//#define MAX 100
typedef struct Graph
{
char label[MAX];
int adj[MAX][MAX];
int count;
}GRAPH;

int calad(char c,GRAPH G,char ad[MAX],int *out,int index[MAX]);
*/
void init(GRAPH *G)
{
int i,j;
G->count=0;
G->label[0]='\0';
for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			G->adj[i][j]=0;
		}
	}

}

int searchnode(char s,GRAPH G)
{
int i;
for(i=0;i<G.count;i++)
{
	if(G.label[i]==s)
		break;
}
if(i==G.count)
	return -1;
else 
	return i;
}

int createnode(char c,GRAPH *G)
{
int s;
if(G->count > MAX || G->count==MAX)
	return 0;
else if(searchnode(c,*G)!=-1)
	return 1;
else
	{
		G->label[G->count]=c;
		G->count++;
		
		return 1;
	}
}

int createdge(char s,char d,GRAPH *G)
{
int i,j;
i=searchnode(s,*G);
j=searchnode(d,*G);
if(i==-1 && j==-1)
	return 0;
else
{
	G->adj[i][j]=1;
	return 1;
}

}

int outdegree(char s,GRAPH G,int *out)
{
int i,j;
*out=0;
i=searchnode(s,G);
if(i==-1)
	return 0;
else
{
	for(j=0;j<G.count;j++)
	{
		if(G.adj[i][j]==1)
			++(*out);
	}
	return 1;
}

}
int indegree(char s,GRAPH G,int *in)
{
int i,j;
*in=0;
i=searchnode(s,G);
if(i==-1)
	return 0;
else
{
	for(j=0;j<G.count;j++)
	{
		if(G.adj[j][i]==1)
			++(*in);
	}
	return 1;
}

}

int removenode(char c,GRAPH *G)
{
int i,k,j;
i=searchnode(c,*G);
if(i==-1)
	return 0;

else if(G->label[i+1]!='\0')
	{
		G->label[i]=G->label[i+1];	
		
		for(k=0;k<G->count;k++)
		{
			G->adj[i][k]=G->adj[i+1][k];
		}
		for(j=0;j<G->count;j++)
		{
			G->adj[j][i]=G->adj[j][i+1];
		}
	}

G->count--;
return 1;
}

int removedge(char s,char d,GRAPH *G)
{
 int i,j;
 i=searchnode(s,*G);
 j=searchnode(d,*G);
 
 if(i==-1 || j==-1)
  	return 0;
  else
  {
  	G->adj[i][j]=0;
  }

	return 1;

}

void displayG(GRAPH G)
{
int i,j;
if(G.label[0]=='\0')
{
	printf("\n EMPTY MATRIX ! ");
}
else
{
	printf("  %c",G.label[0]);
	for(i=1;i<G.count;i++)
	{
		printf(" %c",G.label[i]);
	}
	printf("\n");
	for(i=0;i<G.count;i++)
	{
		printf("%c ",G.label[i]);
		for(j=0;j<G.count;j++)
		{
			printf("%d ",G.adj[i][j]);
		}
		printf("\n");
	}
}
}
int calad(char c,GRAPH G,char ad[MAX],int *out,int index[MAX])
{
int i,j;
*out=0;
int k=0;
i=searchnode(c,G);
if(i==-1)
	return 0;
else
{
	for(j=0;j<G.count;j++)
	{
		if(G.adj[i][j]==1)
			{
				ad[k]=G.label[j];
				index[k]=j;
				++k;			
				++(*out);
			}
	}
	return 1;
}

}

void BFS(GRAPH G)
{
	int j,i;
	char ad[MAX];
	int out=0;
	QUEUE Q;
	int v[MAX]={0};
	int index[MAX];
	char bfs[MAX];
	int k=0;
	char elem;
	initQ(&Q);

	for(j=0;j<G.count;j++)
	{
		if(!v[j])
		{	
			if(calad(G.label[j],G,ad,&out,index))
			{
				if(enque(&Q,G.label[j]))
				{
					v[j]=1;
				}

				if(dequeue(&Q,&elem))
				{
					bfs[k]=elem;
					++k;
				}

				for(i=0;i<out;i++)
				{
					if(!v[index[i]])
					{
						
						enque(&Q,ad[i]);
						v[index[i]]=1;
					}
				}

				while(!isEmptyQ(Q))
				{
					if(enque(&Q,elem))
					{
						bfs[k]=elem;
						++k;
					}
				}
			}
	
		}
	}
puts(bfs);

}

void DFS(GRAPH G)
{
	int j,i;
	char ad[MAX];
	int out=0;
	STACK S;
	int v[MAX]={0};
	int index[MAX];
	char dfs[MAX];
	int k=0;
	char elem;
	initS(&S);

	for(j=0;j<G.count;j++)
	{
		if(!v[j])
		{	
			if(calad(G.label[j],G,ad,&out,index))
			{
			
				
				if(push(&S,G.label[j]))
				{
					v[j]=1;
				}

				if(pop(&S,&elem))
				{
					dfs[k]=elem;
					++k;
				}

				for(i=0;i<out;i++)
				{
					if(!v[index[i]])
					{
						
						push(&S,ad[i]);
						v[index[i]]=1;
					}
				}

				while(!is_Empty(S))
				{
					if(pop(&S,&elem))
					{
						dfs[k]=elem;
						++k;
					}
				}
			}
	
		}
	}
puts(dfs);

}



/*
void main()
{
GRAPH G;
char c,s,d;
int ch,i;
int out,in;
char ad[MAX];
int index[MAX];

init(&G);

while(1)
{
	printf("\nMENU \n1.CREATE NODE \n2.CREATE EDGE \n3.CALCULATE OUT DEGREE \n4.CALCULATE IN DEGREE \n5.REMOVE EDGER \n6.REMOVE NODE \n7.DISPLAY \n8.CALCULATE ADJACENT NODES \n9.DFS \n10.BFS \n 0 TO EXIT \nENTER CHOICE :");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1 :	printf("\n ENTER NODE : ");
			getchar();			
			scanf("%c",&c);
			
			if(createnode(c,&G))
				displayG(G);
			else 
				printf("\n ERROR");
			break;
	case 2 :
			printf("\n ENTER SOURCE NODE : ");
			getchar();
			scanf("%c",&s);
			
			printf("\n ENTER DESTINATION NODE : ");
			getchar();
			scanf("%c",&d);
			
			if(createdge(s,d,&G))
				displayG(G);
			else 
				printf("\n ERROR");
			break;

	case 3 :
			
			printf("\n ENTER SOURCE NODE : ");
			getchar();			
			scanf("%c",&s);
			if(outdegree(s,G,&out))
				printf("\n OUTDEGREE IS %d",out);
			else 
				printf("\n ERROR");
			break;
	case 4 :
			printf("\n ENTER SOURCE NODE : ");
			getchar();			
			scanf("%c",&s);
			
			if(indegree(s,G,&in))
				printf("\n INDEGREE IS %d",in);			
			else 
				printf("\n ERROR");
			break;
	case 5 :
			printf("\n ENTER SOURCE NODE : ");
			getchar();			
			scanf("%c",&s);
			

			printf("\n ENTER DESTINATION NODE : ");
			getchar();			
			scanf("%c",&d);
			
			if(removedge(s,d,&G))
				displayG(G);
			else 
				printf("\n ERROR");
			break;
	case 6 :
			printf("\n ENTER NODE : ");
			getchar();		
			scanf("%c",&c);
		
			if(removenode(c,&G))
				displayG(G);
			else 
				printf("\n ERROR");
			break;
	case 7 :
			displayG(G);
			break;
	case 8 :
			printf("\n ENTER NODE : ");
			getchar();		
			scanf("%c",&c);

			if(calad(c,G,ad,&out,index))
			{
				for(i=0;i<out;i++)
				{
					printf("%c is adjacent to %c (%d index) \n",c,ad[i],index[i]);
				}			
			}
			else {printf("\n ERROR");}break;
	case 9 : 
			DFS(G);
			break;
	case 10 :
			BFS(G);
			break;	

	default :
				exit(0);
	}
}			



}

*/





















