#include<stdio.h>
int main()
{
    int a=54;
    float b=5.256;
    void *ptr;
    ptr=&a;
    printf("the value of a is %d\n",*((int *)ptr));

    return 0;
}
