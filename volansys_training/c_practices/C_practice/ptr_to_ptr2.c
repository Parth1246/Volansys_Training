#include<stdio.h>
int main()
{
    char *names[]={"parth","nayan","pm","romil"};
    int i=0;
    for(i=0;i<4;i++)
    {
        printf("names[%d] is %s\n",i+1,names[i]);
    }
    return 0;
}
