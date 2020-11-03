/* 
//Program: WAP to insert the element in the array at position...

#include<stdio.h>

void main()
{
	int array[500]={3,4,5,6,7,3,6};
	int element,position,count=7,i,j=7;
	printf("\nEnter element to be insert: ");
	scanf("%d",&element);
	printf("\nEnter position of element to be insert: ");
	scanf("%d",&position);
	while(position<=j)
	{
		array[j+1]=array[j];
		j--;
	}
	array[position]=element;
	for(i=0; i<8; i++)
	{
		printf("%d ",array[i]);
	}
}
*/

//Program: WAP to reverse a linked list.
#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList
{
	int data;
	struct LinkedList *next;
}node;

node *head = NULL, *tail = NULL, *temp = NULL;

void main()
{
	int i, j,n;
	printf("\nEnter the number of element: ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		temp = (node *)malloc(sizeof(node));
		printf("\nEnter data: ");
		scanf("%d",&temp->data);
		temp->next = NULL;
		if(i==0)
		{
			head = temp;
			tail = temp;
		}
		tail->next = temp;
		tail = temp;
	}
	printf("\n");
	temp = head;
	for(i=0; i<n; i++)
	{
		printf("%d  ->  ",temp->data);
		temp = temp->next;
	}
	
	
}




