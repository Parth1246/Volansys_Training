#include<stdio.h>

int sum;

int func(int a,int b)
{
    auto int sum = a+b;
    return sum;
}

int main()
{
    /* here im not calling func's sum */
    printf("%d\n",sum);
    // it will print the value of global sum not func sum 
    return 0;
}
