#include <stdio.h>
#include "header.h"


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
	printf("Multiplication of %d and %d is %d\r\n", a, b, sampleMul(a,b));
#ifdef DECORATE
	printf("###############################\r\n");
#endif
}
