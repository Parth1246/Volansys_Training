#include<stdlib.h>
#include"lib.h"
#include<stdio.h>


void print_linkedlist(struct node * head)
{
    struct node * ptr = head;

    do
    {
        printf("element %d \n",ptr->data);
        ptr = ptr->next;
    } while (ptr!=head);
    
}

struct node * insertatfirst(struct node * head,int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node * p = head->next;

    while(p->next!=head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;

    head = ptr;

    return head;
}

struct node * insertatlast(struct node * head,int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node * p = head->next;

    while(p->next!=head)
    {
        p=p->next;
    }
    p->next = ptr;
    ptr->next = head;

    ptr = head;

    return ptr;
}
