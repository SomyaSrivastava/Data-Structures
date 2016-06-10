#include<stdio.h>
#include<stdlib.h>
#include"singly.h"
#define MAX 9

int hashfn(int value)
{
int key;
key=value%10;
return key;
}

void main()
{
LIST L[MAX];
int ch,value,key,i;
for(i=0;i<MAX;i++)
	init(&L[i]);

while(1)
{
printf("\nMENU \n1.ENTER VALUES \n2.DISPLAY \n3.EXIT\n");
scanf("%d",&ch);

switch(ch)
{
	case 1 :
		printf("\n ENTER VALUE :");
		scanf("%d",&value);
		key=hashfn(value);
		insert(&L[key],value,0);
		printf("L[%d]->\n",key);		
		display(L[key]);
		break;

	case 2 :
		for(i=0;i<MAX;i++)
		{
		printf("\n key=%d \n",i);
		display(L[i]);
		}
		break;
	case 3 :
		exit(1);

}


}




}

