
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
void *head = NULL;

int main()
{
    InsertNode(&head, 45, 1);
    InsertNode(&head, 15, 7);
    InsertNode(&head, 79, 8);
    InsertNode(&head, 90, 5);
    InsertNode(&head, 10, 6);
    InsertNode(&head, 55, 4);
    InsertNode(&head, 12, 3);
    InsertNode(&head, 20, 9);
    InsertNode(&head, 50, 2);
    Displaylist(head);


    Sortlist(&head, 1);
    printf("\n\n");
    Displaylist(head);

    reverse(&head);
    printf("\n\n");
    Displaylist(head);

}