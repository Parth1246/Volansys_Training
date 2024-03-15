#include <stdio.h>
#include <string.h>

struct test
{
    int a;
    float b;
    char str[50];
};

//2nd way
void copied_struct(struct test *a, struct test *b)
{
    *b = *a;
}

int main()
{
    struct test A, B;
    A.a = 5;
    A.b = 1.2580;
    strcpy(A.str, "hey there");

    printf("The value of A.a = %d\n", A.a);
    printf("The value of A.b = %f\n", A.b);
    printf("the value of A.str = %s\n", A.str);

    copied_struct(&A, &B);

    /*
        1st way
        B = A;
    */
    printf("the value of B.a = %d\n", B.a);
    printf("The value of B.b = %f\n", B.b);
    printf("the value of B.str = %s\n", B.str);

    return 0;
}