#include <stdio.h>

int main(){
    int a , b;
    printf("enter the age of a");
    scanf("%d",&a);
    printf("enter the age of b");
    scanf("%d",&b);

    if(a>b)
    {
        printf("the age of a is greater than b ");
    }
    else
    {
        printf("the age of b is greater than a ");
    }
    return 0;
}
