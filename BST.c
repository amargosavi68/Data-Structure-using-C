#include<stdio.h>
#include<stdlib.h>

typedef struct BST{
	int data;
	struct BST *left;
	struct BST *right;
}bst;


bst* GetNode(int data)
{
	bst *newNode = (bst*)malloc(sizeof(bst));
	newNode->left = NULL;
	newNode->data = data;
	newNode->right = NULL;
	return newNode;
}

bst* InsertNode(bst *root, int data)
{
	if(root == NULL)
	{
		root = GetNode(data);
		return root;
	}
	else if(data <= root->data)
	{
		root->left = InsertNode(root->left,data);
	}
	else
	{
		root->right = InsertNode(root->right, data);
	}
}

int Search(bst* root, int data)
{
	if(root == NULL) return 0;
	if(root->data == data) return 1;
	else if(data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);
}

void main()
{
	bst *root = NULL;
	int data;
	root = InsertNode(root, 5);
	root = InsertNode(root, 15);
	root = InsertNode(root,65);
	root = InsertNode(root, 59);
	root = InsertNode(root, 35);
	root = InsertNode(root,25);
	root = InsertNode(root, 54);
	root = InsertNode(root, 10);
	root = InsertNode(root,22);
	printf("\nEnter data to be searched: ");
	scanf("%d",&data);
	if(Search(root, data)==1)
	{
		printf("\nData is Found..");
	}
	else
	{
		printf("\nData is not found..");
	}
}
