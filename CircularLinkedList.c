# include <stdio.h> 
# include <conio.h> 
# include <stdlib.h> 

struct cslinklist 
{
	int data; 
	struct cslinklist *next; 
}; 

typedef struct cslinklist node; 
node *start = NULL; 
int nodectr;

node* getnode() 
{ 
	node * newnode; 
	newnode = (node *) malloc(sizeof(node)); 
	printf("\n Enter data: "); 
	scanf("%d", &newnode -> data); 
	newnode -> next = NULL; 
	return newnode; 
}

int menu() 
{
	int ch; 
	printf("\n 1. Create a list "); 
	printf("\n 2. Insert a node at beginning "); 
	printf("\n 3. Insert a node at End"); 
	printf("\n 4. Delete a node from beginning"); 
	printf("\n 5. Delete a node from End"); 
	printf("\n 6. Display"); 
	printf("\n 7. Exit");
	printf("\n\n Enter your choice: "); 
	scanf("%d", &ch); 
	return ch; 
} 

void createlist(int n)
{
	int i;
	node *newnode; 
	node *temp;
	nodectr = n; 
	for(i = 0; i < n ; i++)
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
	newnode ->next = start;
}

void display()
{
	node *temp;
	temp = start; 
	printf("\n The contents of List (Left to Right): \n\t"); 
	if(start == NULL ) 
		printf("\n Empty List\n"); 
	else 
	{ 
		do 
		{ 
			printf("\t %d -->", temp -> data); 
			temp = temp -> next; 
		} while(temp != start); 
		printf(" X\n"); 
	} 
}

void cll_insert_beg()
{
	node *newnode, *last; 
	newnode = getnode(); 
	if(start == NULL) 
	{ 
		start = newnode; 
		newnode -> next = start; 
	} 
	else 
	{
		last = start; 
		while(last -> next != start) 
			last = last -> next;
		newnode -> next = start; 
		start = newnode; 
		last -> next = start; 
	} 
	printf("\n Node inserted at beginning..\n"); 
	nodectr++; 
} 

void cll_insert_end()
{ 
	node *newnode, *temp; 
	newnode = getnode(); 
	if(start == NULL ) 
	{ 
		start = newnode; 
		newnode -> next = start; 
	} 
	else 
	{ 
		temp = start; 
		while(temp -> next != start) 
			temp = temp -> next; 
		temp -> next = newnode; 
		newnode -> next = start; 
	} 
	printf("\n Node inserted at end..\n"); 
	nodectr++; 
}

void cll_delete_beg()
{ 
	node *temp, *last; 
	if(start == NULL) 
	{
		printf("\n No nodes exist..\n"); 
		getch(); 
		return ; 
	} 
	else 
	{
		last = temp = start; 
		while(last -> next != start) 
			last = last -> next;
		start = start -> next; 
		last -> next = start; 
		free(temp);
		nodectr--; 
		printf("\nNode deleted..\n"); 
		if(nodectr == 0) 
			start = NULL; 
	} 
}

void cll_delete_End()
{ 
	node *temp,*prev; 
	if(start == NULL) 
	{ 
		printf("\n No nodes exist..\n"); 
		getch(); 
		return ; 
	} 
	else 
	{ 
		temp = start; 
		prev = start;
		while(temp -> next != start) 
		{
			prev = temp;
			temp = temp -> next; 
		}
		prev -> next = start; 
		free(temp);
		nodectr--; 
		if(nodectr == 0) 
			start = NULL; 
		printf("\n Node deleted..\n"); 
	} 
}

void main()
{ 
	int result;
	int ch, n;
	while(1) 
	{ 
		ch = menu(); 
		switch(ch) 
		{
			case 1 : 
				if(start == NULL)
				{
				printf("\n Enter Number of nodes to create: "); 
				scanf("%d", &n);
				createlist(n);
				printf("\n\tList created..\n"); 
				}
				else
				printf("\n List is already Exist..\n"); 
				break;
				
			case 2 : 
				cll_insert_beg(); 
				break;
				
			case 3 : 
				cll_insert_end(); 
				break;
				
			case 4 : 
				cll_delete_beg();; 
				break;
				
			case 5 : 
				cll_delete_End();
				break;
				
			case 6 : 
				display(); 
				break;
				
			case 7 : 
				exit(0); 
		}
	} 
}
