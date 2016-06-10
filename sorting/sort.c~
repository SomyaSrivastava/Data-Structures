#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 50

void disp(int ar[MAX],int size)
{
	int i;
	if(size>0)
	{
		for(i=0;i<size;i++)
			printf("%d ",ar[i]);
	}
	else
		printf("\nEMPTY LIST !");

}

int isort(int ar[MAX],int size)
{
	int i,j;
	int temp;
	
	
	for(i=1;i<size;i++)
	{	
		temp=ar[i];		
		for(j=i;j>0 && ar[j-1]>temp ;j--)
		{
		
				ar[j]=ar[j-1];
				ar[j-1]=temp;
				printf("\n");
				disp(ar,size);
		}
		
	
	}
}


void bubble(int ar[MAX],int size)
{
	int j,i;
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
			{
				if(ar[j]<ar[i])
				swap(&ar[j],&ar[i]);
				
			}
		printf("\n");
		disp(ar,size);
	}
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;

}

void selection(int ar[MAX],int size)
{
	int i,j;
	int min,pos,flag;
	
	for(i=0;i<size;i++)
	{
		flag=0;		
		min=ar[i];
		for(j=i;j<size;j++)
		{
		 if(ar[j]<min)
			{
				min=ar[j];
				pos=j;
				flag=1;
			}
		}
		if(flag==1)
			swap(&ar[i],&ar[pos]);
		printf("\n");
			disp(ar,size);
	}
}



void shell(int ar[MAX],int size)
{
	int i,j,k,q;
	int temp;
	int GAP=1;
	int G[MAX],R[MAX];
	j=k=0;
		for(i=2;i<size;i++)
		{
		   for(j=2;j<=i-1;j++)
			{
				if(i%j==0)
				 continue;
				else
					G[k++]=i;
			}
		}	
	for(q=k;q>=0;q--)
	{
		GAP=G[q];
		for(i=GAP;i<size;i++)
		{	
			temp=ar[i];			
			for(j=i;j>GAP-1 && ar[j-GAP]>=temp;j=j-GAP)
			{
				ar[j]=ar[j-GAP];	
			}
			ar[j]=temp;
		}
	}
}

void main()
{

	int size,i;
	int ar[MAX];

	printf("\n ENTER THE SIZE OF THE ARRAY : ");
	scanf("%d",&size);

	printf("\n ENTER THE VALUES IN ARRAY : ");

	for(i=0;i<size;i++)
		scanf("%d",&ar[i]);
	
	printf("\n UNSORTED ARRAY : \n");

	disp(ar,size);

	//isort(ar,size);
	//bubble(ar,size);
	//selection(ar,size);
	shell(ar,size);
	//msort(ar,0,size-1);

	printf("\n SORTED ARRAY : \n");
	disp(ar,size);


}
