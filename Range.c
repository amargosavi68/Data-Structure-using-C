#include<stdio.h>

void main()
{
	int n,i,num;
	printf("\nEnter a number: ");
	scanf("%d",&n);
	num = -(n*n);
	if(n>0)
	{
//		printf("%d ",num);
		for(i = 1; i < 3*n + 1; i++ )
		{
			printf("%d ",num);
			num = num + 2*i - 1;
		}
	}
}
