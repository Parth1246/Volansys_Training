#include<stdio.h>
int sum(int a,int b)
{
    return a+b;
}
void greet()
{
    printf("hello world\n");
}
int main()
{
    printf("the sum of 1 & 2 is %d\n",sum(1,2));
    int (*fptr)(int,int);
    fptr = sum;
    int d = (*fptr)(4,6);
    printf("%d is sum of 1 & 2\n",d);
    return 0;
}
