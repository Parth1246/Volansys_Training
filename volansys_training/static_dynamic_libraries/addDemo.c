#include<stdio.h>
#include "heyMath.h"

int main() {
    int x = 20,y = 30;
    printf("\n%d + %d = %d\n",x,y,add(x,y));
    printf("\n%d - %d = %d\n",x,y,sub(x,y));
    return 0;
}
