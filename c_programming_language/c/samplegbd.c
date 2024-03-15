#include<stdio.h>

int main()
{
    int t;
    printf("enter the number of test case:\t");
    scanf("%d",&t);

    while(t--)
    {
        int n,k;

        printf("enter the number of people\t");
        scanf("%d",&n);
        int A[n];
        printf("enter the total amount that all thhese people wants to withdraw\t");
        scanf("%d",&k);
        for(int i=0;i<n;i++)
        {
            printf("enter the value of transaction \t");
            scanf("%d",&A[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]>k)
            {
                printf("0\t");
            }
            sum=sum+A[i];
            if(sum>k)
            {
                printf("0\t");
                sum = sum - A[i];
            }
            else
            {
                printf("1\t");
            }
        }
    }
    return 0;
}
