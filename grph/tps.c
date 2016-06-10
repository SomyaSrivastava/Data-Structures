#include"g.h"
#include<stdio.h>

void main()
{
	int in,i;
	char c,d,s;
	int ch;
	char tps[MAX];
	GRAPH G;
	int k=0;
	init(&G);
	while(1)
	{
	printf("\nMENU \n1.CREATE NODE \n2.CREATE EDGE \n 0 TO EXIT \nENTER CHOICE :");
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
	default :
			exit(1);
	}
	}

	for(i=0;i<G.count;i++)
	{
		indegree(G.label[i],G,in);
		if(in==0)
		{
			tps[k]=G.label[i];
			k++;			
			removenode(G.label[i],G);
		}
	}
	puts(tps);

}

