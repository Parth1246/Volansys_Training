#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // when str is initialised we can split the string
    char str[] = "lets do it togather okay hey im fine ";

    // to print words
    int word_counter = 0;
    char *ptr = strtok(str, " ");
    while (ptr != NULL)
    {
        ++word_counter;
        printf("%s\n", ptr);
        ptr = strtok(NULL, " ");
    }

    printf("total word counted = %d\n",word_counter);
    return 0;
}