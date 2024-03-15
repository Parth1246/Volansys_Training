#include<stdio.h>

int main()
{
    int t;
    printf("enter the no of test cases\n");
    scanf("%d",&t);

    while(t--)
    {
        int frnd;
        printf("howmany friend needs party\n");
        scanf("%d",&frnd);

        int a[frnd];
        for(int i=0;i<frnd;i++)
        {
            printf("enter the days of party\n");
            scanf("%d",&a[i]);
        }
        
        int temp;
        for(int i=0;i<frnd;i++)
        {   for(int j=i+1;j<frnd;j++)
            {
                if(a[i]>a[j])
                {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                }
            }
        }
        printf("after sorting this array\n");

        for(int i=0;i<frnd;i++)
        {
            printf("%d\t",a[i]);
        }
        int count=0;

        for(int i=0;i<frnd;i++)
        {
            if(a[i]==a[i+1])
            {
                count++;
                printf("\ndev couldnt give party to his %d friend\n",count);
                printf("so dev can give party to his %d friend",(frnd-count));
            }
        }
    }
}
