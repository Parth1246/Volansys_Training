// problem statement


/*There is an ATM machine. Initially, it contains a total of K units of money. N people (numbered 1 through N) want to withdraw money; for each valid i, the i-th person wants to withdraw Ai units of money.

The people come in and try to withdraw money one by one, in the increasing order of their indices. Whenever someone tries to withdraw money, if the machine has at least the required amount of money, it will give out the required amount. Otherwise, it will throw an error and not give out anything; in that case, this person will return home directly without trying to do anything else.

For each person, determine whether they will get the required amount of money or not.*/

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
