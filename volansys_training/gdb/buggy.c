#include<stdio.h>

int main()
{
    int balance = 100, target = 1000 , year = 0;
    float rate = 0.1;

    do{
        float interest = balance * rate ; 
        balance = balance + interest;
        year++;
    }while(balance >= target);

    printf("%d No of years to achive target balance.\n",year);

    return 0;
}
