#include<stdio.h>
void main()
{
	int n,i,j;
	printf("\nEnter a number: ");
	scanf("%d",&n);
	printf("\n");
	for(i=(n*2)+n,j=1; j<=(n+1)*2; j++,i+=2)
	{
		printf("%d ",i);
	}
	
}
