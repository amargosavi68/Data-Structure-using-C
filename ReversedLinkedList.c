//Reverse the linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList
{
	int data;
	struct LinkedList *next;
}node;

node *temp1 = NULL, *head = NULL, *temp2=NULL; //*last = NULL,

void main()
{
	int n,i;
	printf("\nEnter total number of item: ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		temp1 = (node*)malloc(sizeof(node));
		printf("\nEnter %dth element: ",i+1);
		scanf("%d",&temp1->data);
		temp1->next = NULL;
		if(i==0)
		{
			head = temp1;
			temp2 = temp1;
		}
		else
		{
			temp2->next = temp1;
			temp2 = temp1;
		}
	}
	temp1 = head;
	printf("\nNodes are as follows: \n\n");
	for(i=0; i<n; i++)
	{
		printf("| %d | %d |-->",temp1->data,temp1->next);
		temp1 = temp1->next;
	}
	
	printf("\nReversed Linked List is : \n\n");
	
	temp1 = head;
	temp2 = head->next;
//	printf("\n%d", temp2->data);
	for(i=0; i<n-1; i++)
	{
		head = temp2;
		if(i==0)
		{
			temp1->next = NULL;
		}
		temp2 = head->next;
		head->next = temp1;
		temp1 = head;
	}
	temp1 = head;
	for(i=0; i<n; i++)
	{
		printf("| %d | %d |-->",temp1->data,temp1->next);
		temp1 = temp1->next;
	}
}
