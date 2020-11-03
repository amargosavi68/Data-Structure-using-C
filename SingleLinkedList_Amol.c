# include <stdio.h> 
# include <conio.h> 
# include <stdlib.h> 

struct slinklist
{ 
	int data; 
	struct slinklist *next;
}; 
typedef struct slinklist node; 
node *start = NULL; 

int menu() 
{ 
	int ch; 
	printf("\n 1.Create a list "); 
	printf("\n--------------------------"); 
	printf("\n 2.Insert a node at beginning ");
	printf("\n 3.Insert before the Node");
	printf("\n 4.Insert a node at middle");
	printf("\n 5.Insert after the Node"); 
	printf("\n 6.Insert a node at end");
	printf("\n--------------------------"); 
	printf("\n 7.Delete a node from beginning");
	printf("\n 8.Delete before the Node");
	printf("\n 9.Delete a node from Middle");
	printf("\n 10.Delete after the Node"); 
	printf("\n 11.Delete a node from Last");  
	printf("\n--------------------------"); 
	printf("\n 12. Display List ");
	printf("\n 13. Count nodes "); 
	printf("\n 14. Exit "); 
	printf("\n\n Enter your choice: "); 
	scanf("%d",&ch); 
	return ch; 
}

node* getnode() 
{
	node * newnode; 
	newnode = (node *) malloc(sizeof(node)); 
	printf("\n Enter data: "); 
	scanf("%d", &newnode -> data); 
	newnode -> next = NULL; 
	return newnode; 
}

int countnode(node *ptr)
{ 
	int count=0;
	while(ptr != NULL) 
	{
		count++; 
		ptr = ptr -> next; 
	} 
	return (count); 
}

void createlist(int n)
{
	int i;
	node *newnode; 
	node *temp;
	for(i = 0; i < n; i++)
	{
		newnode = getnode();
		if(start == NULL)
		{
			start = newnode;
		}
		else
		{
			temp = start;
			while(temp -> next != NULL)
				temp = temp -> next;
			temp -> next = newnode;
		}
	}
}

void traverse() 
{
	node *temp;
	temp = start; 
	printf("\n The contents of List (Left to Right): \n\t"); 
	if(start == NULL) 
	{
		printf("\n Empty List"); 
		return; 
	}
	else
	{
		while(temp != NULL) 
		{
			printf("%d-->", temp -> data); 
			temp = temp -> next;
		}
	} 
	printf(" X\n"); 
}

void rev_traverse(node *start) 
{
	if(start == NULL) 
	{ 
		return; 
	} 
	else 
	{ 
		rev_traverse(start -> next); 
		printf("%d -->", start -> data); 
	} 
}

void insert_at_beg()
{ 
	node *newnode; 
	newnode = getnode();
	if(start == NULL) 
	{ 
		start = newnode; 
	} 
	else 
	{ 
		newnode -> next = start; 
		start = newnode; 
	} 
}

 
void insert_before()
{ 
	node *new_node, *temp, *preptr; 
	int val=0;
	new_node = getnode();
	printf("\nEnter the value before which data has to insert: ");
	scanf("%d",&val);
	temp = start; 
	while(temp -> data != val && temp->next != NULL)
	{
		preptr = temp;
		temp = temp -> next;		
	}
	if (temp->next == NULL)
	{
		printf("\nGiven Node is not in the list.");
	}
	else
	{
		new_node->next = temp;
		preptr->next = new_node;
	}
}


void insert_at_mid()
{ 
	node *newnode, *temp, *prev; 
	int pos, nodectr, ctr = 1; 
	newnode = getnode();
	printf("\n Enter the position: "); 
	scanf("%d", &pos); 
	nodectr = countnode(start);
	if(pos > 1 && pos < nodectr) 
	{ 
		temp = prev = start; 
		while(ctr < pos) 
		{
			prev = temp;
			temp = temp -> next; 
			ctr++;
		}
		prev -> next = newnode; 
		newnode -> next = temp; 
	} 
	else 
		printf("position %d is not a middle position", pos); 
}

void insert_after()
{ 
	node *new_node, *temp; 
	int val=0;
	new_node = getnode();
	printf("\nEnter the value after which data has to insert: ");
	scanf("%d",&val);
	temp = start; 
	while(temp->data != val && temp->next != NULL)
	{
		temp = temp->next;		
	}
	if (temp->next == NULL)
	{
		printf("\nGiven Node is not in the list.");
	}
	else
	{
		new_node->next = temp->next;
		temp->next = new_node;
	}
}
 
void insert_at_end()
{ 
	node *newnode, *temp; 
	newnode = getnode();
	if(start == NULL) 
	{ 
		start = newnode; 
	} 
	else 
	{ 
		temp = start; 
		while(temp -> next != NULL) 
			temp = temp -> next; 
		temp -> next = newnode; 
	} 
}

void delete_at_beg() 
{
	node *temp;
	if(start == NULL) 
	{ 
		printf("\n No nodes are exist.."); 
		return ; 
	} 
	else 
	{ 
		temp = start; 
		start = temp -> next; 
		free(temp);
		printf("\n Node deleted "); 
	} 
}

void delete_before()
{ 
	node *temp, *preptr; 
	int val=0;
	printf("\nEnter the value before which data has to be delete: ");
	scanf("%d",&val);
	temp = start; 
	while(temp->next-> data != val && temp->next != NULL)
	{
		preptr = temp;
		temp = temp -> next;		
	}
	if (temp->next == NULL)
	{
		printf("\nGiven Node is not in the list.");
	}
	else
	{
		preptr->next = temp->next;
		free(temp);
	}
}

void delete_at_mid()
{
	int ctr = 1, pos, nodectr; 
	node *temp, *prev; 
	if(start == NULL) 
	{ 
		printf("\n Empty List..");
		return ; 
	} 
	else 
	{ 
		printf("\n Enter position of node to delete: "); 
		scanf("%d", &pos); 
		nodectr = countnode(start); 
		if(pos > nodectr) 
		{
			printf("\nThis node doesnot exist"); 
		}
		if(pos > 1 && pos < nodectr) 
		{
			temp = prev = start; 
			while(ctr < pos) 
			{
				prev = temp;
				temp = temp -> next;
				ctr ++;
			}
			prev -> next = temp -> next; 
			free(temp);
			printf("\n Node deleted.."); 
		}
		else
		{
			printf("\n Invalid position..");
		}
	} 
} 

void delete_after()
{ 
	node *temp, *preptr; 
	int val=0;
	printf("\nEnter the value before which data has to be delete: ");
	scanf("%d",&val);
	temp = start; 
	while(temp -> data != val && temp->next != NULL)
	{
		preptr = temp;
		temp = temp -> next;		
	}
	if (temp->next == NULL)
	{
		printf("\nGiven Node is not in the list.");
	}
	else
	{
		preptr = temp;
		temp = temp->next;
		preptr->next = temp->next;
		printf("\n%d is deleted..\n",temp->data);
		free(temp);
	}
}

void delete_at_last()
{
	node *temp, *prev; 
	if(start == NULL) 
	{ 
		printf("\n Empty List.."); 
		return ; 
	} 
	else 
	{ 
		temp = start; 
		prev = start;
		while(temp -> next != NULL) 
		{
			prev = temp;
			temp = temp -> next; 
		}
		prev -> next = NULL; 
		free(temp);
		printf("\n Node deleted "); 
	} 
} 

int main()
{
	int ch, n; 
	while(1) 
	{
		ch = menu(); 
		switch(ch) 
		{
			case 1:
				if(start == NULL)
				{
					printf("\n Number of nodes you want to create: ");
					scanf("%d", &n); 
					createlist(n);
					printf("\n List created.."); 
				}
				else
					printf("\n List is already created.."); 
				break;
				
			case 2: 
				insert_at_beg(); 
				break;
			
			case 3: 
				insert_before(); 
				break;
				
			case 4: 
				insert_at_mid(); 
				break;
					
			case 5: 
				insert_after(); 
				break;
			
			case 6: 
				insert_at_end(); 
				break;
				
			case 7: 
				delete_at_beg(); 
				break;
				
			case 8: 
				delete_before(); 
				break;
				
			case 9: 
				delete_at_mid(); 
				break;
				
			case 10: 
				delete_after(); 
				break;
			
			case 11: 
				delete_at_last(); 
				break;
				
			case 12: 
				traverse(start); 
				break;
				
			case 13: 
				printf("\n No of nodes : %d ", countnode(start)); 
				break;
				
			case 14: 
				exit(0); 
			
			default:
				printf("\nWrong choice..");
				break;
		}
	} 
	return 0;
}
