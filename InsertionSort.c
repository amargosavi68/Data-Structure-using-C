#include<stdio.h>

void InsertionSort(int a[], int n)
{
	int i,j,key;
	for(j = 1; j < n; j++)
	{
		key = a[j];
		i = j-1;
		while(i >= 0 && a[i] > key)
		{
			a[i+1] = a[i];
			i--;
			a[i+1] = key;
		}
		//printf("%d ---- %d ---- %d\n",a[i],a[j],j);
	}
	printf("\nSorted array is: \n");
	for(i = 0; i < n; i++)
	{
		printf("%d  ",a[i]);
	}
}
void main()
{
	int n,a[100];
	int i;
	printf("Enter value of N: ");
	scanf("%d",&n);
	printf("\nEnter %d Elements: ",n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	InsertionSort(a,n);
}
