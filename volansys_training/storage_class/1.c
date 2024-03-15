#include<stdio.h>

int func(int a,int b)
{
    auto int sum;
    sum = a+b;
    return sum;
}
int main()
{
    int sum = func(4,5);
    printf("%d\n",sum);
    return 0;
}
