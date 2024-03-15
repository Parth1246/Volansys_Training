#include<stdio.h>
int b=34;

int fun(int a)
{
    static int myvar=98;
    printf("the value of myvar is %d\n",myvar);
    myvar++;

    return a+myvar;
}
int main()
{
    int b=344;
    int t=5;
    while(t--)
    {
    int val; 
    val = fun(b);
    }
    return 0;
}
