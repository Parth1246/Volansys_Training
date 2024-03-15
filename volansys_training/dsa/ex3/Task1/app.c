#include<stdio.h>
#include<stdlib.h>
#include"lib.h"

int main()
{
    struct node *head,*second,*third;
    head =(struct node *)malloc(sizeof(struct node));
    second =(struct node *)malloc(sizeof(struct node));
    third =(struct node *)malloc(sizeof(struct node));

    //linking first and second node
    head->data = 7;
    head->next = second;

    //linking second and third node
    second->data = 11;
    second->next = third;

    //linking third and head node 
    third->data = 66;
    third->next = head;

    printf("circular linked list\n");
    print_linkedlist(head);

    printf("after insertion at first\n");
    head = insertatfirst(head,49);
    print_linkedlist(head);

    printf("after insertion at last\n");
    head = insertatlast(head,81);
    print_linkedlist(head);

    return 0;

}
