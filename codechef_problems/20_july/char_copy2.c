#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str1[] = "hello";
    char *ptr;

    //assign the address of str to ptr
    ptr = str1;

    for (int i = 0; i < strlen(str1); i++)
    {
        printf("%c", ptr[i]);
    }

    //now changing the first charecter from ptr to see its reflaction on str
    ptr[0] = 'f';
    printf("\n");

    for (int i = 0; i < strlen(str1); i++)
    {
        printf("%c", ptr[i]);
    }
    printf("\n");

    printf("%s\n",str1);

    
    char * ptr2 = "hello";
    printf("%s\n",ptr2);

    //ptr2 = (char *)malloc(sizeof(str1));
    strcpy(ptr2,"there");

    printf("%s\n",ptr2);
    //printf("%s\n",str1);
    return 0;
}