#include<stdio.h>
#include<limits.h>

void main()
{
    int T, A[INT_MAX], B, N, sum = 0;
    int i,j, count;
    
    scanf("%d", &T);
    for (i=1; i<=T; i++)
    {
        count = 0;
        scanf("%d", &N);
        scanf("%d", &B);
        for(j = 0; j<N; j++)
        {
            scanf("%d", &A[i]);
        }
        for(j=0; j < N; j++)
        {
            sum += A[j];
            count++;
            if(sum > B)
            {
                sum -= A[j];
                count--;
            }
        }
        printf("Case #%d: %d",i,count);
        printf("\n");
    }
}
