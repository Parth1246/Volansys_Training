#include <stdio.h>
void swap(int *,int *);

int main(){
    int a=10;
    int b=20;
    printf("before swapping th values in main a=%d , b=%d \n",a,b);
    swap(&a,&b);
    printf("after swapping values in a=%d , b=%d",a,b);
}
void swap(int *a,int *b)
{
    int temp;
    temp =*a;
    *a=*b;
    *b=temp;
    printf("after swapping values in fn a=%d,b=%d\n",*a,*b);
}
