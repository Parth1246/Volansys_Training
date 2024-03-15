#include <stdio.h>

int main(){
    int a;
    printf("enter the value of a : \n");
    scanf("%d",&a);

    if(a>5){
        printf("the value is greater than 0\n");
        if(a>=5){
            printf("the value is greter or equal to 5");
        }
    }
    return 0;
}
