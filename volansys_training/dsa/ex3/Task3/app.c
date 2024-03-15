#include<stdio.h>
#include<stdlib.h>
#include"lib.h"

int main()
{
    struct node * head;
    struct node * second;
    struct node * tail;
    int data,choice_search;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    tail = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->prev = NULL;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = tail;

    tail->data = 30;
    tail->prev = second;
    tail->next = NULL;
    print(head);

    printf("after insertion of 40\n");
    head = insertatbeg(head,40); 
    print(head);
    
    printf("after insertion of 50\n");
    head = insertatbeg(head,50); 
    print(head);

    printf("after insertion of 60\n");
    head = insertatpos(head,60,2);
    print(head);

    printf("enter the data you want to find\n");
    scanf("%d",&data);
    printf("enter your choice for searching method\n1: Linear Search\n2: Binary Search\n\n");
    scanf("%d",&choice_search);

    if (searchdata(head,data,choice_search) == NULL) {
        printf("Value not present\n");
    }
    else {
        printf("Present\n");
    }

    return 0;
}
