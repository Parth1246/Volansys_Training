#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i=0;
    int a;
    int *ptr;

    while(i<=5)
    {
        printf("welcome to the volansys\n");
        ptr = malloc(30*sizeof(int));
        i++;
        free(ptr);
    }

    return 0;
}

