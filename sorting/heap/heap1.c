#include <stdio.h>
#define MAX 100
void display(int arr[], int size);
void heapSort(int arr[], int size);
void minHeap(int arr[], int size);

int main() {
	int size,i,n;
	int arr[MAX];

	printf("\n ENTER THE SIZE OF THE ARRAY : ");
	scanf("%d",&size);

	printf("\n ENTER THE VALUES IN ARRAY : ");
	n=size;
	arr[0]=-1;
	for(i=1;i<size+1;i++)
		scanf("%d",&arr[i]);
	
	
	display(arr, n+1);

	
	heapSort(arr, n+1);

	display(arr, n+1);

	return 0;
}

void display(int arr[], int size) {
	int i;
	for(i = 1; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void heapSort(int arr[], int size)
{
	int i, j, tmp, sorted[size];
	sorted[0] = -1;	


	for(i = size , j = 1; i >= 1; i--, j++) 
	{
		minHeap(arr, i);
		sorted[j] = arr[1];
		arr[1] = arr[i - 1];
	}

	for(i = 0; i < size; i++)
	{
		arr[i] = sorted[i];
	}
}

void minHeap(int arr[], int size) 
{
	int i, left, right, tmp, val;

	for(i = size / 2; i >= 1; i--) 
	{

		/*taking 1 as the start index
		if parent node = i
		so left child = 2i and 
		right child = 2i+1*/
		
		tmp = i;
		left = (2 * i);
		right = (2 * i) + 1;

		if(left < size && arr[left] < arr[tmp]) 
		{
			tmp = left;
		}

		if(right < size && arr[right] < arr[tmp]) 
		{
			tmp = right;
		}

		if(tmp != i)
		 {
			val = arr[i];
			arr[i] = arr[tmp];
			arr[tmp] = val;
			minHeap(arr, size);
		}
	}
}
