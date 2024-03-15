#include <stdio.h>
int mul(int ,int);

int main(){
    int a,b,product;
    printf("enter first value : \n");
    scanf("%d",&a);
    printf("enter the second value : \n");
    scanf("%d",&b);
    product=mul(a,b);
    printf("%d is the multiplication of 2 numbers",product);
}

int mul(int a, int b)
{
    int result= a*b;
    return result;
}
