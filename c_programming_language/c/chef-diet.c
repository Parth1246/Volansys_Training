/*Chef decided to go on a diet during the following N days (numbered 1 through N). 
 * Part of the diet plan is to eat K grams of protein during each day. 
 * For each valid i, 
 * Chef wants to buy Ai grams of protein in the morning of the i-th day 
 * and then eat K grams of protein as part of his dinner.
 * If he has any protein remaining, he can store it
 * and use it in later dinners. Initially, Chef is storing 0 grams of protein.

Determine whether Chef will have enough protein all the time during his diet.
In case he will not have enough, find the first day on which Chef will be unable to eat K grams of protein. */



#include<stdio.h>

int main()
{
    int t;
    printf("enter the number of test cases\t");
    scanf("%d",&t);

    while(t--)
    {
        int n,k;
        printf("enter the number of days\n");
        scanf("%d",&n);
        printf("enter the grm of protien you want to eat/day\n");
        scanf("%d",&k);

        int arr[n];
        int sum=0;
        int count =0;
        for(int i=0;i<n;i++)
        {
            printf("enter the protien you take each day\t");
            scanf("%d",&arr[i]);
        }
     

        for(int i=0;i<n;i++)
        {
            sum= sum + arr[i];
            if(sum >= k)
            {
                sum=sum-k;
                count++;    
            }
            else{
                printf("\n No %d\n",i+1);
                break;
            }
            if(count==n)
            {
                printf("\n Yes\n");
            }
        }
    }
    return 0;
}
