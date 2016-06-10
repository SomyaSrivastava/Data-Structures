#include "g.h"
#include<stdio.h>
void warshall(GRAPGH G);
void floyd_warshall(GRAPGH G);
void create_graph(GRAPH *G);
void main()
{
GRAPH G;
create_graph(&G);
warshall(G);
floyd_warshall(G);
}
void create_graph(GRAPH *G)
{
char c,s,d;
int ch,i;
int out,in;
char ad[MAX];
int index[MAX];

init(&G);

while(1)
{
	printf("\nMENU \n1.CREATE NODE \n2.CREATE EDGE \n3.REMOVE EDGE \n4.REMOVE NODE \n5.DISPLAY \n.0 TO EXIT \nENTER CHOICE :");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1 :
			printf("\n ENTER NODE : ");
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
			
	case 4 :
	case 5 :
			
	case 6 :
			displayG(G);
			break;

	default :
				exit(0);
	}
}			



}






}

