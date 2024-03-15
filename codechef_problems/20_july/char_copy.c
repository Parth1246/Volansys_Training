#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//3rd way
static char buf[] = "hola";

int main() {
    char str1[] = "hey there";

    char * ptr;
    char * p = buf;

    printf("str1 = %s\n",str1);

    //2nd way
    ptr = (char *)malloc(sizeof(str1));
    strcpy(ptr,str1);

    //1st way - wont work
    /* *ptr = str1;
    strcpy(ptr,str1);
    */


    printf("ptr = %s\n",ptr);
    printf("p = %s\n",p);
    free(ptr);
    return 0;
}