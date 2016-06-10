#include<stdio.h>
#include<malloc.h>
#include"singly.h"

void main()
{
	LIST L;
	int value;
	init(&L);

	printf("\nCREATE LIST : enter 0 to exit appending");

	while(1)
	{
	scanf("%d",&value);
	if(value)
		{
			if(append(&L,value))
				display(L);
			else
				printf("\n ERROR IN APPENDING !");
		}
	else
		break;
	}
	printf("\nTHE SORTED LIST IS : ");
	sort(&L);
	display(L);

}
void sort(LIST* L)
{
	NODE *ptr;
	int temp;
	ptr=L->head;
	if(!is_empty(*L))
		{
			while(ptr->next!=NULL)
			{
				if(ptr->data > ptr->next->data)
				{
					temp=ptr->data;
					ptr->data=ptr->next->data;
					ptr->next->data=temp;

				}
				ptr=ptr->next;

			}
		}
	else
		printf("\nLIST IS EMPTY");
}
