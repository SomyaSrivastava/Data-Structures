#include<stdio.h>
#include<stdlib.h>

#define SIZE 11

int hashfn(int data)
{
	return data%SIZE;
}

int insert(int ar[SIZE],int data)
{
	int key,i;
	i=0;

	key=hashfn(data);
	while(ar[key]!=0)
	{		
		key=hashfn(hashfn(data)+(i*i));	
		i++;
	}

	if(key<SIZE)
		{
			ar[key]=data;
			return 1;
		}
	else	

		{
			key=0;
			i=0;
			while(ar[key]!=0)
			{		
				key=hashfn(hashfn(data)+(i*i));	
				i++;
			}
			if(key<SIZE)
			{
				ar[key]=data;
				return 1;
			}
			else
				return 0;

		}

}

void disp(int ar[SIZE])
{	
	int i;
	printf("key  data\n");
	for(i=0;i<SIZE;i++)
		printf("[%d]  %d\n",i,ar[i]);

}


void main()
{
	int ar[SIZE]={0};
	int data;
	while(1)
	{
		printf("\n ENTER THE DATA , 0 TO EXIT : ");
		scanf("%d",&data);
		if(data!=0)
			if(insert(ar,data))
				disp(ar);
			else
				printf("\n ERROR");
		else
			exit(1);

	}
}
