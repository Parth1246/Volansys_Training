#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <unistd.h>

int main()
{
    struct node *head = NULL;

    head = create_list();
    printf("\nthe linked list is given below\n");
    display(head);
    sleep(1);

    printf("after deletion of first element\n");
    head = delete_first(head);
    display(head);
    sleep(1);

    printf("after deletion of last element\n");
    head = delete_last(head);
    display(head);
    sleep(1);

    printf("after deletion of 1st index\n");
    head = deleteatindex(head, 1);
    display(head);
    sleep(1);

    int n;
    printf("enter the element you want to delete\n");
    scanf("%d", &n);
    head = deleteatkey(head, &n);
    printf("\nafter deletion of desired data\n");
    display(head);
    sleep(1);

    // using stuct next , prev method
    printf("\nafter reverse the list\n");
    head = reverse_list(head);
    display(head);
    sleep(1);

    // using recursive method
    printf("\nafter reverse the list\n");
    reverse_list_rec(head);
    printf("size of list: %d\n", length_list(head));
    sleep(1);

    if(delete_list(head)) {
        printf("the list is deleted finallyy\n");
    }
    return 0;
}
