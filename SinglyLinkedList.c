#include<stdio.h>
#include<stdlib.h>


/*Structure is defined here..*/
typedef struct SLL
{
	int data;
	struct SLL *next;
}node;


/*Pointer variables and global variables defined here globally..*/
node *temp=NULL, *temp1=NULL, *head=NULL, *tail=NULL, *prev=NULL, *succeed = NULL;
int count=0,key,position;



void insertNode()
{
	int ch2;
	int i;
	temp = (node*)malloc(sizeof(node));			//dynamically memory allocation..
	printf("\nEnter Data: ");
	scanf("%d",&temp->data);
	temp->next = NULL;
	if(count == 0)				// If there is no element in the list..
	{
		head = temp;
		tail = temp;
		count++;
		printf("\n%d inserted successfully..",temp->data);
	}
	else
	{
		printf("\nWhere you want to insert?");
		printf("\n1. At the Beginning \n2. At Position \n3. At the End \n4.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch2);
		switch(ch2)
		{
			case 1: /*Link temp to the head then make temp as head..*/
					temp->next = head;       
					head = temp;
					count++;
					printf("\n%d inserted successfully at beginning..",temp->data);
					break;
			
			case 2: 
					printf("\nEnter the position: ");
					scanf("%d",&position);
					if(position<=count)
					{
						temp1 = head;
						for( i = 1; i < position; i++) 
						{
							prev = temp1;		
							temp1 = temp1->next;
						}
						prev->next = temp;
						temp->next = temp1;
						count++;
						printf("\n%d inserted successfully at %d location..",temp->data,position);
					}
					else
					{
						printf("\nEnter valid position..");
					}
					break;
			
			case 3: 
					tail->next = temp; // updating the next field of tail and make temp as tail..
					tail = temp;
					count++;
					printf("\n%d inserted successfully at the end..",temp->data);
					break;
					
			default: 
					printf("\nSorry, wrong choice..");
					break;
		}
	}
}



/*Deletion of Node function goes here*/
void deleteNode()
{
	int i,flag=0;
	printf("\nEnter data to be deleted: ");
	scanf("%d",&key);
	temp=head;
	if(temp->data == key)
	{
		head = temp->next;
		count--;
		printf("\n%d deleted successfully..",temp->data);
		free(temp);
	}
	else
	{
		for( i = 2; i<= count; i++)
		{
			prev = temp;
			temp = temp->next;
			if(temp->data == key)
			{
				prev->next = temp->next;
				printf("\n%d is deleted successfully..",temp->data);
				count--;
				free(temp);
				flag = 1;
				break;
			}
		}
		if(flag==0)
		{
			printf("\n%d is not in the list.",key);
		}
	}
}




/*Display the List function goes here*/
void displayNode()
{
	int i;
	printf("\nThe Linked List is as follows: \n\n");
	temp = head;
	for( i = 1; i <= count; i++)
	{
		printf("| %d |--->",temp->data);
		temp = temp->next;
	}
	printf("NULL");
}



/*Searching of Node function goes here*/
void searchNode()
{
	int i,flag=0;
	if(count == 0)
	{
		printf("\nList is empty..");
	}
	else
	{
		printf("\nEnter the element that you want to search: ");
		scanf("%d",&key);
		temp = head;
		for( i = 1; i <= count; i++)
		{
			if(temp->data == key)
			{
				flag = 1;
				printf("%d is found at %d location", key,i);
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
		if(flag==0)
		{
			printf("\n%d is not in the list..",key);
		}
	}
	
}



/*Main function starts here..*/
void main()
{
	int ch;
	printf("\n\t================= Singly Linked List ========================\n");
	printf("\t1.INSERT\n\t2.DELETE\n\t3.DISPLAY\n\t4.SEARCH\n\t5.EXIT");
	do {

		printf("\n\nEnter your choice(in integer): ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insertNode();
					break;
					
			case 2: deleteNode();
					break;
					
			case 3: displayNode();
					break;
					
			case 4: searchNode();
					break;
					
			default: 
					printf("\nSorry, Wrong Choice..");
		}
		
	}while(ch>=1 && ch<=4);
}
