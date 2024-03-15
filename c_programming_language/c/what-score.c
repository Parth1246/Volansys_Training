#include<stdio.h>

int main()
{
    int t; 
    printf("enter the test case:\t");
    scanf("%d",&t);

    while(t--)
    {
        int n; 
        printf("\nenter the no of solution you made\n");
        scanf("%d",&n);
        int a[11]={0}; 
        int problem,score;
        for(int i=0;i<n;i++)
        {
            printf("enter the problem\t");
            scanf("%d",&problem);
            printf("enter the score\t");
            scanf("%d",&score);

            if(problem>0 && problem<=8)
            {
                if(score>a[i])
                {
                    a[i] = score;
                }
            }
        }
        int sum=0;
        for(int i=0;i<9;i++)
        {
            sum=sum+a[i];
        }
        printf("the sum is %d\n",sum);
    }
    return 0;
}
