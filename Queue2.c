#include<stdio.h> 
#include<stdlib.h> 
#define MAX 3

int queue1[MAX]; 
int front = -1;
int rear = -1;

void insert(int data)
{
	if((front == 0 && rear == MAX-1) || (front == rear+1))
	{
		printf("Queue Overflow \n"); 
		return;
	}
	if(front == -1)
	{
		front = 0;
		rear = 0;
	}
	else
	{
		if(rear == MAX-1) 
			rear = 0;
		else
			rear = rear+1;
	}
	queue1[rear] = data ;
}

void deletion()
{
	if(front == -1)
	{
		printf("\nQueue Underflow. \n"); 
		return ;
	}
	printf("Element deleted from queue is : %d\n",queue1[front]); 
	if(front == rear)
	{
		front = -1; 
		rear=-1;
	}
	else
	{
		if(front == MAX-1) 
			front = 0;
		else
			front = front+1;
	}
}

void display()
{
	int frontpos = front,rearpos = rear; 
	if(front == -1)
	{
		printf("Queue is empty..\n"); 
		return;
	}
	printf("Queue elements :\n"); 
	if( frontpos <= rearpos ) 
		while(frontpos <= rearpos)
		{
			printf("%d ",queue1[frontpos]); 
			frontpos++;
		}
	else
	{
		while(frontpos <= MAX-1)
		{
			printf("%d ",queue1[frontpos]); 
			frontpos++;
		}
		frontpos = 0; 
		while(frontpos <= rearpos)
		{
			printf("%d ",queue1[frontpos]); 
			frontpos++;
		}
	}
	printf("\n\n");
}

int main()
{
	int choice,data; 
	do
	{
		printf("\n1.Insert\t 2.Delete\t 3.Display\t 4.Quit\n"); 
		printf("Enter your choice : "); 
		scanf("%d",&choice); 
		switch(choice)
		{
			case 1 :
				printf("\nInput the element for insertion in queue : "); 
				scanf("%d", &data);
				insert(data); 
				break;
			case 2 : 
				deletion(); 
				break; 
			case 3: 
				display(); 
				break; 
			case 4:
				break; 
			default:
				printf("Wrong choice\n");
		}
	}while(choice!=4);
	return 0;
}
