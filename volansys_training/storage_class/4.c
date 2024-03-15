#include<stdio.h>

int sum = 343; // global initialisation of sum
static int a,b=4;
//to use global variable at anywhere 
//just take extern int variable name in that func block
int func(int a,int b)
{
    int sum;
    sum = a+b;

    // now this sum willl return 343 value 
    return sum;
}

int main()
{
    //int sum = func(3,5);
    printf("the value of sum is %d",sum);
    printf("the value of a and b is %d and %d \n",a,b);

    return 0;
 }
