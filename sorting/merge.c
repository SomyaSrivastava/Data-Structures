# include <stdio.h>
# include <malloc.h>

void merge(int *a,int low, int mid, int high)
{
	int i,j,k;
	int n1 = mid-low+1;
	int n2 = high-mid;
	int L[n1],R[n2];
	
	for (i = 0; i < n1; i++)
        	L[i] = a[low + i];
  	for (j = 0; j < n2; j++)
        	R[j] = a[mid + 1+ j];
	
	i=0;
	j=0;
	k=low; 
	
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
			a[k++] = L[i++];
		else
			a[k++] = R[j++];		
	}
	while(i<n1)
		a[k++] = L[i++];
	while(j<n2)
		a[k++] = R[j++];
}

void merge_sort(int *a,int low,int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void display(int a[],int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", a[i]);
   printf("\n");
}

int main()
{
	int *a,n,i;
	printf("\nEnter the size of the array : ");
	scanf("%d",&n);
	printf("\nEnter the elements of the array : ");
	a = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	merge_sort(a,0,n-1);
	printf("\nSorted array using merge sort is :");
	display(a,n);
	return 0;
}
