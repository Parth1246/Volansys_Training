/*Two friends, Dragon and Sloth, are writing a computer science examination series. There are three subjects in this series: 
DSA, TOC, and DM. Each subject carries 100 marks.
You know the individual scores of both Dragon and Sloth in all 3 subjects. You have to determine who got a better rank.
The rank is decided as follows:
The person with a bigger total score gets a better rank
If the total scores are tied, the person who scored higher in DSA gets a better rank
If the total score and the DSA score are tied, the person who scored higher in TOC gets a better rank
If everything is tied, they get the same rank.*/

#include<stdio.h>

int main()
{
    int t;
    printf("enter the test cases\n");
    scanf("%d",&t);

    while(t--)
    {
        int dsa1,toc1,dm1;
        int dsa2,toc2,dm2;

        printf("enter the marks of dragon\n");
        scanf("%d %d %d",&dsa1,&toc1,&dm1);

        printf("enter the marks of sloath\n");
        scanf("%d %d %d",&dsa2,&toc2,&dm2);

        int sum1 = dsa1+toc1+dm1;
        int sum2 = dsa2+toc2+dm2;

        if(sum1>sum2)
        {
            printf("dragon\n");
        }
        else
        {
            printf("sloth\n");
        }

        if(sum1==sum2 && dsa1>dsa2)
        {
            printf("dragon\n");
        }
        if(sum1==sum2 && dsa1==dsa2)
        {
            printf("tie\n");
        }
        if(sum1==sum2 && dsa1<dsa2)
        {
            printf("sloth\n");
        }
    }
return 0;
}
