#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main() {

    struct node * head;
    int choice_sort,data,choice_search;
    //initialised head  to null
    head = NULL;
    head = createlist();
    printf("\n");
    display(head);

    printf("insertion of 5 at first\n");
    head = insertatfirst(head,5);
    display(head);

    printf("insertion of 9 at last\n");
    head = insertatlast(head,9);
    display(head);

    printf("insertion of 13 at 5th index\n");
    head = insertatindex(head,13,5);
    display(head);

    printf("enter your choice for sorting\n\n1: Merge Sort\n2: Raddix Sort\n3: Bubble Sort\n");
    scanf("%d",&choice_sort);
    sortlist(head,choice_sort);

    display(head);  

    return 0;
}
