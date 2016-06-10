 #include<stdio.h>
 
 struct node
 {
 	int data;
 	struct node *next; 
 	struct node *prev; 
  };
 
 struct list
 {
 struct node *head;
 struct node *tail;
 int count;
 };
 
 //Function prototyping
 void initialise(struct list *l);
 struct node* createNode(int data);
 int insertAtPosition(struct list *l,int pos,int data);
 void displayAll(struct list *l);
 int delete(struct list *l,int pos);
 struct node* search(struct list *l,int data,int *pos);
 
 int main()
 {
 	struct list l;
 	int choice,data,pos;
 	initialise(&l); // Initialising the list to null
 
 	
 
	 while(1)
	 {
	 	printf("\nEnter the choice \n1->Insert a Node\n2->Display\n3->delete\n4->Search By Data\n0->Exit\n");
 		scanf("%d",&choice);
	 
	 	switch(choice)
	 	{
	 	
	 	case 1:
	 		printf("Enter the position where node is to be added\n");
	 		scanf("%d",&pos);
	 		
	 		printf("Enter the data to be added \n");
	 		scanf("%d",&data);
	 		
	 		if(! insertAtPosition(&l,pos,data))
	 			printf("Successfully inserted \n");
	 		else
	 			printf("Error occured \n");	
	 	break;
	 	
	 	case 2:
	 		displayAll(&l);
	 	break;	
	 	
	 	case 3:
	 		printf("Enter the position where node is to be deleted\n");
	 		scanf("%d",&pos);
	 	
	 		if( ! delete(&l,pos))
	 			printf("Successfully deleted \n");
	 		else
	 			printf("Error occured \n");
	 	break;
	 	
	 	case 4:
	 		printf("Enter the data to be searched \n");
	 		scanf("%d",&data);
	 		
	 		if(search(&l,data,&pos) != NULL)
	 			printf("Found at position %d\n",pos);
	 		else
	 			printf("Not found\n");	
	 		
	 	break;
	 	
	 	case 0:
	 		printf("\nThanks for using the software\n");
	 		exit(0);
	 	break;	
	 	
	 	default:
	 		printf("Enter a valid choice\n");
	 	}
	 }		
 return 0;
 }
 
 
 void initialise(struct list *l)
 {
 	 l->head=NULL;
 	 l->tail=NULL;
 	 l->count=0;
 }
 
 struct node* createNode(int data)
 {
 	 struct node *temp;
 	 temp=(struct node *) malloc(sizeof(struct node)); 
 	 
 	 if(temp!=NULL)
 	 {
 	 	temp->next=temp->prev=NULL;
 	 	temp->data=data;
 	 }
 	 
 	 return temp;
 }
 
 void displayAll(struct list *l)
 {
	struct node *ptr;

	ptr = l->head; 
	while(ptr != NULL) 
	{ 
		printf("->|%d|", ptr->data); 
		ptr = ptr->next; 
	} 
	printf("\nTotal number of elements %d\n",l->count);
 }
 
  int insertAtPosition(struct list *l,int pos,int data)
 {
  	struct node *temp,*ptr;
  	int count=0;
  	
  	if(pos > l->count)
  		return 1;

  	if(l->head==NULL)
  		{
  			l->head=l->tail=createNode(data);
  			l->count++;
  			return 0;
  		}
  	
  	  	
  	if(pos < (l->count+1)/2)
  	{
  		ptr=l->head;
  		while(count < pos)
  		{
  			ptr=ptr->next;
  			count++;
  		}
  		
  		temp=createNode(data);
  		
  		temp->next = ptr;
 		
 		if(ptr->prev !=NULL)
 		{
 			temp->prev=ptr->prev;
 			ptr->prev->next=temp;
 		} 		
 		else
 			l->head=temp;
 		
 		ptr->prev=temp;
 		l->count++;
 		return 0; 		
  	}
  	
  	else
  	{
  		ptr=l->tail;
  		count=l->count;
  		while(count > pos)
  		{
  			ptr=ptr->prev;
  			count--;
  		}
  		
  		temp=createNode(data);
  		temp->prev=ptr;
  		
  		if(ptr->next != NULL)
  		{
  			ptr->next->prev=temp;
  			temp->next=ptr->next;
  		}
  		
  		else
  			l->tail=temp;
  		
		ptr->next=temp;
  		l->count++;
  		return 0; 		
  	}
  	
 
  	
 return 1; 		
 }
 

 int delete(struct list *l,int pos)
 {
 	struct node *ptr;
 	int count=0;
 	
 	if(pos >= l->count)
 		return 1;
 		
 	if(pos==0)
 	{
 		ptr=l->head;
 		ptr->next->prev=NULL;
 		l->head=ptr->next;
 		free(ptr);
 		l->count--;
 		return 0;
 	}
 	
 	if(pos == l->count-1)
 	{
 		ptr=l->tail;
 		ptr->prev->next=NULL;
 		l->tail=ptr->prev;
 		free(ptr);
 		l->count--;
 		return 0;
 	}	
 	

 	if(pos < (l->count+1)/2)
  	{
  		ptr=l->head;
  		while(count < pos)
  		{
  			ptr=ptr->next;
  			count++;
  		}	
  	}
  	
  	else
  	{
  		ptr=l->tail;
  		count=l->count;
  		while(count > pos+1)
  		{
  			ptr=ptr->prev;
  			count--;
  		} 		
  	}
  	
  	ptr->prev->next=ptr->next;
  	ptr->next->prev=ptr->prev;
  	l->count--;
  	
 return 0; 	
 }
 
 struct node* search(struct list *l,int data,int *pos)
 {
 	*pos=0;
	struct node *ptr;
	ptr = l->head; 
	while(ptr != NULL) 
	{ 
		if(ptr->data==data)
		{
			return ptr;
		} 
		
		else
		{	
			ptr = ptr->next;
			*pos= *pos +1 ;
		}	 
	}
	
	  return NULL;
 	
 
 }
