#include<stdio.h>

int count = 0;

void towers_of_hanoi(int n, char *a, char *b, char *c)
{
	if(n == 1)
	{
		count++;
		printf("\n% 5d: Move %d from %s to %s.",count,n,a,c);
	}
	else
	{
		towers_of_hanoi(n-1,a,c,b);
		count++;
		printf("\n% 5d: Move %d from %s to %s.",count,n,a,c);
		towers_of_hanoi(n-1,b,a,c);
	}
}

void main()
{
	int n;
	printf("\nEnter the value of n:");
	scanf("%d", &n);
	towers_of_hanoi(n,"Tower 1", "Tower 2", "Tower 3");
}
