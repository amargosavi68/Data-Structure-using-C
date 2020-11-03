#include<stdio.h>
#include<stdlib.h>


typedef struct Stack
{
	int data;
	struct Stack *next;
}node;

node *head = NULL, *temp=NULL;

int count = 0, ch;


void view()
{
	if(count>=1)
	{
		temp = head;
		while(temp->next!=NULL)
		{
			printf("%d  %d  | ",temp->data,temp->next);
			temp = temp->next;
		}
		printf("%d  %d  | ",temp->data,temp->next);
		printf("\n");
	}
	else
	{
		printf("Sorry, stack is empty..\n\n");
	}
	
}

void push()
{
	temp = (node *)malloc(sizeof(node));
	printf("\nEnter Data: ");
	scanf("%d",&temp->data);
	if(count<1)
	{
		temp->next = NULL;
		head = temp;
		count++;
	}
	else
	{
		temp->next = head;
		head = temp;
		count++;
	}
	
}

void pop()	// 10 20 30 40
{
	if(count>0)
	{
		temp = head;
		head = head->next;
		printf("\n%d is Poped..\n",temp->data);
		free(temp);
		count--;
	}
	else
	{
		printf("\nSorry, Stack is empty..\n");
	}
	
}


void main()
{
	do
	{	
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();
					break;
					
			case 2: pop();
					break;
					
			case 3: view();
					break;
					
		}
	}while(ch>=1 && ch<=3);
	
}
