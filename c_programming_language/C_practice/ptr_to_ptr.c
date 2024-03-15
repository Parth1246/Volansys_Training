/// this is a example of pointer to pointer problem

#include<stdio.h>
int main()
{
    int var;
    int *ptr;
    int **ptrptr;

    printf("enter the val of var: \t");
    scanf("%d",&var);

    ptr = &var;
    ptrptr=&ptr;

    printf("so the val at var is %d\n",var);
    printf("so the val at ptr is %d\n",*ptr);
    printf("so the val at ptrptr is %d\n",**ptrptr);
    return 0;
}
