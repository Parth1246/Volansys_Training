/*Chef is a software developer, so he has to switch between different languages sometimes. Each programming language has some features, which are represented by integers here.

Currently, Chef has to use a language with two given features A and B. He has two options --- switching to a language with two features A1 and B1, or to a language with two features A2 and B2. All four features of these two languages are pairwise distinct.

Tell Chef whether he can use the first language, the second language orneither of these languages (if no single language has all the required features*/pv


#include<stdio.h>

int main()
{
    int t;
    printf("enter the no of test cases:\t");
    scanf("%d",&t);

    while(t--)
    {
        int a,b,a1,b1,a2,b2;
        scanf("%d %d %d %d %d %d",&a,&b,&a1,&b1,&a2,&b2);
        int ans = 0;
        if((a == a1 && b == b1) || (a==b1 && b==a1))
        {
            ans = 1;
            
        }
        else if((a==a2 && b==b2)||(a==b2 && b==a2))
        {
            ans=2;
        
        }
        else
        {
            ans = 0;
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
