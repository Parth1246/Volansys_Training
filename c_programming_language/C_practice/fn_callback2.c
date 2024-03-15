#include<stdio.h>
int sum(int,int);
int sub(int,int);

int display(int (*fptr)(int,int))
{
    fptr(5,1);
    printf("%d",fptr(5,1));
}


int main()
{
    display(sum);
    display(sub);
    return 0;
}

int sum(int a,int b)
{
    return (a+b);
}
int sub(int a,int b)
{
    return (a-b);
}

