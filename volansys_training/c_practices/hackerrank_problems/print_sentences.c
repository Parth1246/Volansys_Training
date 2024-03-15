#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // when str is initialised we can split the string

    char str[] = "lets do it togather.okay hey im fine.";

    // to print sentences
    int sentece_counter = 0;
    char *ptr = strtok(str, ".");
    while (ptr != NULL)
    {
        ++sentece_counter;
        printf("%s\n", ptr);
        ptr = strtok(NULL, ".");
    }

    printf("total sentence counted = %d\n",sentece_counter);
    return 0;
}