#include<stdio.h>


#define no printf("NO");
#define yes printf("YES");

int main()
{
    int t;
    printf("enter no of case:\t");
    scanf("%d",&t);

    while(t--)
    {
        int n;
        printf("enter n:\t");
        scanf("%d",&n);

        char s[400];
        char r[400];
        
        printf("enter the binary s\t");
        scanf("%s",s);

        printf("enter the binary n\t");
        scanf("%s",r);
        
        int c1=0;
        int c2=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                c1++;
            }
             if(r[i]=='1')
            {
                c2++;
            }
        }

        int d1=0;
        int d2=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                d1++;
            }
             if(r[i]=='0')
            {
                d2++;
            }
        }

        if(c1==c2 && d1==d2)
        {
            yes
        }
        else
        {
            no
        }
    }
    return 0;
}
