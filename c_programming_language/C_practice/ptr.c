#include <stdio.h>

int main(){
    int var=20;
    int *ip;
    ip=&var;

    printf("the value of var=%d\n",var);
    printf("the value of var=%d\n",*ip);
    printf("the address value of the var=%x\n",ip);
    printf("the vallue of var add is %x",&var);
    return 0;
}
