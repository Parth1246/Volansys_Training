#include"lib.h"
#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * next;
};

struct node * createlist(void)
{
    int n,i;
    struct node * head,* p;
    printf("enter number of elements:\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        if(i == 0)
        {
            head = (struct node *)malloc(sizeof(struct node *));
            p = head;
        }
        else
        {
            p->next = (struct node *)malloc(sizeof(struct node *));
            p = p->next;
        }
        scanf("%d",&(p->data));
    }
    p->next = NULL;
    return (head);
}

struct node * insertatfirst(struct node * head,int data)
{
    struct node * ptr =(struct node *)malloc(sizeof(struct node *));
    ptr->next = head;
    ptr->data = data;
    
    return ptr;
}

struct node * insertatlast(struct node * head,int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = data;

    struct node * p = head;
    
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

struct node * insertatindex(struct node * head,int data,int index)
{
    struct node * ptr =(struct node *)malloc(sizeof(struct node *));
    struct node * p = head;

    int i=1;

    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct node * insertafterdata(struct node * head,int data_comp,int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = data;

    struct node * p = head;
    struct node * q = head->next;

    while(p->data != data_comp)
    {
        p = p->next;
        q = q->next;
    }
    p->next = ptr;
    ptr->next = q;

    return head;
}

int display(struct node *p)
{
    int count =1;
    while(p!=NULL)
    {
        printf("%d data at pos %d\n",p->data,count);
        count++;
        p = p->next;
    }
    printf("\n");
}
