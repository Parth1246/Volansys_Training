#include<stdio.h>
#include<stdlib.h>
int sum(int,int);
void greetgmexe();
void greetgn();

int main()
{
    int (*ptr)(int,int);
    ptr = sum;
    greetgmexe(ptr);
    return 0;
}
int sum(int a,int b)
{
    return a+b;
}
void greetgmexe(int (*ptr)(int,int))
{
    printf("the sum of a and b is %d\n",ptr(4,6));
}
void greetgn(int (*ptr)(int,int))
{
    printf("the sum of a and b is %d\n",ptr(2,3));
}

