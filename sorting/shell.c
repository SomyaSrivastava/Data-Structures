# include <stdio.h>
# include <malloc.h>

void shell_sort(int *a,int n)
{
	int inner, outer;
   	int value;
   	int interval = 1;
   	int i = 0;
   
	while(interval <n/3)
		interval = 3*interval + 1;
	while(interval>0)
	{
		printf("iteration %d#:",i);
  		display(a,n);
  		for(outer = interval; outer < n; outer++)
		{
     		value = a[outer];
     		inner = outer;
			while(inner > interval-1 && a[inner - interval] >= value)
			{
	            a[inner] = a[inner - interval];
	            inner -=interval;
	            printf(" item moved :%d\n",a[inner]);
     		}
     		a[inner] = value;
     		printf(" item inserted :%d, at position :%d\n",value,inner);
  		}
  		interval = (interval-1) /3;           
  		i++;
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
	shell_sort(a,n);
	printf("\nSorted array using shell sort is :");
	display(a,n);
	return 0;
}
