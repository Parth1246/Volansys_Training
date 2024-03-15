#include <stdio.h>

int sum(int ,int);

int main(){
    printf("this is a funnction pointer programe");
    int d=sum(2,6);
    int (*fptr)(int,int);
    fptr = &sum;
    int a= (*fptr)(2,6);
    printf("%d",a);
    return 0;
}

int sum(int a,int b){
    return a+b;
}
