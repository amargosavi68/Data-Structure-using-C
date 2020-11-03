# include <stdio.h> 
# include <conio.h> 
# include <stdlib.h> 

struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

typedef struct Node node; 
node *front = NULL; 
node *rear = NULL; 

node *start=NULL; 
node *top = NULL; 

node* getnode() 
{
	node *temp;
	temp=(node *) malloc( sizeof(node)) ; 
	printf("\n Enter data: "); 
	scanf("%d", &temp -> data); 
	temp -> next = NULL;
	return temp;
} 

void insert_beg() 
{ 
	node *temp;
	temp = getnode();
	if(top == NULL) 
	{ 
		top = temp; 
	} 
	else 
	{ 
		temp->next = top;
		top = temp;
	} 
	printf("\nData pushed into stack..\n");
}

void delete_beg() 
{ 
	node *temp;
	if(top == NULL) 
	{
		printf("\n\tStack Underflow \n"); 
		return; 
	}
	if(top->next == NULL) 
	{ 
		printf("\n\t Popped element is %d \n", top -> data);
		free(top);
		top = NULL;
	} 
	else
	{
		temp = top->next;
		printf("\n\t Popped element is %d \n", top -> data);
		free(top); 
		top = temp; 
	} 
} 

void display_stack()
{
	node *temp;
	if(top == NULL) 
	{ 
		printf("\n\n\t\t Stack is empty "); 
	} 
	else 
	{ 
		temp = top; 
		printf("\n\n\t\t Elements in the stack: \n"); 
		while(temp != NULL) 
		{ 
			printf("%5d ", temp -> data); 
			temp = temp -> next; 
		} 
	} 
}

void insertQ() 
{ 
	node *newnode; 
	newnode = getnode();
	if(front == NULL && rear == NULL) 
	{ 
		front = newnode; 
		rear = newnode;
	} 
	else 
	{ 
		rear -> next = newnode; 
		rear = newnode;
	} 
	printf("\nData Inserted into the Queue..\n");
}

void deleteQ() 
{ 
	node *temp;
	if(rear == NULL && front == NULL) 
	{ 
		printf("\n\n\t Empty Queue.."); 
		return; 
	} 
	temp = front; 
	front = front -> next; 
	printf("\n Deleted element from queue is %d \n", temp -> data);
	free(temp);
}

void displayQ() 
{ 
	node *temp;
	if(front == NULL && rear == NULL) 
	{ 
		printf("\n\n\t\t Empty Queue "); 
	} 
	else 
	{ 
		temp = front; 
		printf("\n\n\t Elements in the Queue are: "); 
		while(temp != NULL ) 
		{
			printf("%5d ", temp -> data); 
			temp = temp -> next; 
		}
		printf("\n");
	} 
} 
 
int main() 
{
	int ch, ch1;
	do 
	{
		printf("\n================Main Menu==============\n");
		printf("\n\t1. Stack \n\t2. Queue \n\t3. Exit \n");
		printf("\n Enter Your Choice:");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: 
					printf("\n***************Stack Menu*******************\n");
					printf("\n1.Insert At Begining \n2.Delete At Begining \n3.Display Stack \n4.Go back \nEnter Your Choice: ");
					scanf("%d", &ch1);
					switch(ch1)
					{
						case 1:
								insert_beg();
								break;
						case 2: 
								delete_beg();
					    		break;
					    case 3: 
					    		display_stack();
					    		break;
					    case 4: 
					    		break;
					    		
					    default:
					    		printf("\nWrong Choice..\n");
					    		break;
					}
					break;
					
			case 2: 
					printf("\n***************Queue Menu*******************\n");
					printf("\n1.Insert At Begining \n2.Delete At End \n3.Display Queue \n4.Go back \nEnter Your Choice: ");
					scanf("%d", &ch1);
					switch(ch1)
					{
						case 1:
								insertQ();
								break;
						case 2: 
					    		deleteQ();
								break;
					    case 3: 
					    		displayQ();
								break;
					    case 4: 
					    		break;
					    
					    default:
					    		printf("\nWrong Choice..\n");
					    		break;
					}
					break;
			case 3: 
					exit(0);
		}
	}while(ch >=1 && ch <=3);
}
