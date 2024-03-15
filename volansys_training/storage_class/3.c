#include<stdio.h>

int sum;

int func(int a,int b)
{
    sum = a+b;
    return sum;
}

int main()
{

    printf("%d\n",sum);
}
