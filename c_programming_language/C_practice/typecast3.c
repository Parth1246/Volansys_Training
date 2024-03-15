#include <stdio.h>
#include <math.h>

int main()
{
    int a,b;
    printf("enter the value of a and b \n");
    scanf("%d %d", &a,&b);

    int sum;
    sum = ( a + b );
    printf("the sum is %d\n",sum);
    printf("the sum is %f",(float)sum);
}
