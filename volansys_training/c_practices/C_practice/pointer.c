#include <stdio.h>
int main(){
    int m=10,n,o;
    int *z =&m;
    printf("the value of variable m is %d\n",m);
    printf("the address of m is %p\n",z);
    printf("the value of z is %p\n",&m);
    printf("the value of m is %d\n",*z);
    return 0;
}
