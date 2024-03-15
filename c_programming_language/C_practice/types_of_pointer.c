#include<stdio.h>
#include<stdlib.h>

int main() {
    int a = 10;
    int * p = (int *)malloc(sizeof(int));
    p = &a;
    printf("%d\n",*p);
    free(p);
    printf("after freeing the pointer *p = %d\n",*p);

    return 0;
}