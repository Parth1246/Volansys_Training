#include <stdio.h>
#include "sampleMul.h"
#include "sampleAdd.h"
#include "sampleDivide.h"
#include "sampleSub.h"

void main()
{
	int a = 0, b = 0;
#ifdef DECORATE
	printf("###############################\r\n");
#endif
	printf("Enter first value:");
	scanf("%d", &a);
	printf("Enter second value:");
	scanf("%d", &b);
	printf("Addition of %d and %d is %d\r\n", a, b, sampleAdd(a,b));
	printf("Multiplication of %d and %d is %d\r\n", a, b, sampleMultiply(a,b));
    printf("divsion of %d and %d is %d\n",a,b,sampleDivide(a,b));
    printf("subtraction of %d and %d is %d\n",a,b,sampleSub(a,b));

#ifdef DECORATE
	printf("###############################\r\n");
#endif
}
