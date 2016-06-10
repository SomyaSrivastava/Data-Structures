#include<stdio.h>
#include<stdlib.h>
#define MAX 100


merging(int ar[MAX],int low,int mid,int high)
{
	int i,j,k;
	
	int n1=mid-low+1;
	int n2=high-mid;
	
	int R[n2],L[n1];

	for(i=0;i<n1;i++)
		L[i]=ar[low+i];	
	for(j=0;j<n2;j++)
		R[j]=ar[mid+1+j];
	
	i=j=0;
	k=low;

	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
			ar[k++]=L[i++];
		else
			ar[k++]=R[j++];
	}
	while(i<n1)
		ar[k++]=L[i++];
	while(j<n2)
		ar[k++]=R[j++];

}
void msort(int ar[MAX],int low,int high)
{
	int mid;

	if(low<high)
	{
		mid=(low+high)/2;
		msort(ar,low,mid);
		msort(ar,mid+1,high);
		//printf("%d,%d,%d",low,mid,high);		
		merging(ar,low,mid,high);
	}
}

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
	msort(ar,0,size-1);

	printf("\n SORTED ARRAY : \n");
	disp(ar,size);


}
