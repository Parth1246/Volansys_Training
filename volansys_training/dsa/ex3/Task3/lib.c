#include<stdlib.h>
#include"lib.h"
#include<stdio.h>

struct node * insertatbeg(struct node * head,int data)
{
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    newnode->prev = NULL;
    newnode->next = head;
    
    head->prev = newnode;

    head = newnode;

    return head;
}

struct node * insertatlast(struct node * tail,int data)
{
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    newnode->next = NULL;
    newnode->prev = tail;

    tail->next = newnode;

    tail = newnode;

    return tail;
}

struct node * insertatpos(struct node * head,int data,int index)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new->data = data;

    struct node * temp = head;

    for(int i=1;i<index-1;i++)
    {
        temp = temp->next;
    }
    
    new->next = temp->next;
    temp->next->prev = new;
    temp->next = new;
    new->prev = temp;

    head = new;

    return head;
    
}

int print(struct node * head)
{
    struct node * temp = head;
    while(temp!=NULL)
    {
        printf("element %d\n",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node * middle(struct node *first,struct node *last) {
    if(first == NULL) {
        return NULL;
    }

    struct node * slow = first;
    struct node * fast = first->next;

    while(fast!=last) {
        fast = fast->next;
        if(fast!=last) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

int searchdata(void * head,int data,int searching_method) {
    if(searching_method == 1) {
        //linear search
        struct node * ptr = head;
        while(ptr != NULL) {
            if(ptr->data == data) {
                return 1;
            }
            else {
            ptr = ptr->next;
            }
        }
    }
    else if(searching_method == 2) {
        //binary search
        struct node * start = head;
        struct node * last = NULL;

        do {
            struct node * mid = middle(start,last);

            if(mid == NULL) {
                return NULL;
            }
            else if(mid->data == data) {
                return mid;
            }
            else if(mid->data < data) {
                start = mid->next; //mid = mid+1
            }
            else {
                last = mid;  //mid = mid-1
            }
        }while(last!=NULL || last != start);

        return NULL;

    }
    else {
        printf("please enter as given below\n1:Linear Search\n2:Binary Search\n\n");
    }
}