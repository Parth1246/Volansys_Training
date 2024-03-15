/* this is a example of array to pointer */
#include<stdio.h>
int main()
{
    int var[]={10,20,30,40,50};
    int *ptr[5];
    for(int i=0;i<5;i++)
    {
        ptr[i]=&var[i];
    }
    for(int i=0;i<5;i++)
    {
        printf("the elements %d is %d",i+1,*ptr[i]);
    }
    return 0;
}
