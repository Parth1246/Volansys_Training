#include<stdio.h>
#include<stdlib.h>
#include"lib.h"

struct node
{
    int data;
    struct node *next;
};

struct node *create_list(void)
{
    struct node *p, *head;
    int n, k;

    printf("how many numbers you wanna print\n");
    scanf("%d", &n);

    for (k = 0; k < n; k++)
    {
        if (k == 0)
        {
            head = (struct node *)malloc(sizeof(struct node));
            p = head;
        }
        else
        {
            p->next = (struct node *)malloc(sizeof(struct node));
            p = p->next;
        }
        scanf("%d", &(p->data));
    }
    p->next = NULL;

    return head;
}

struct node *delete_first(struct node *head)
{
    struct node *p = head;
    head = head->next;
    free(p);

    return head;
}

struct node *delete_last(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head;
}

struct node *deleteatindex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;

    for (int i = 1; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
}

struct node *deleteatkey(struct node *head, int *value)
{
    struct node *p = head;
    struct node *q = head->next;

    while (p->data != *value, q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == *value)
    {
        p->next = q->next;
        free(q);
    }
    else {
        printf("data not found...\n");
    }

    return head;
}

int delete_list(struct node *head)
{
    if (head == NULL)
    {
        printf("\nNo linked list\n");
    }
    else
    {
        struct node *temp;
        temp = head->next;
        while (head->next != NULL)
        {
            temp = temp->next;
            free(head);
            head = temp;
        }
        free(head);
    }

    return 1;
}

struct node *reverse_list(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    head = prev;

    return head;
}

int reverse_list_rec(struct node *head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        reverse_list_rec(head->next);
        printf("%d\n", head->data);
    }
}

int *get_list_size(struct node *head, int *length)
{
    length = 1;
    if (head == NULL)
    {
        printf("0\n");
    }
    else
    {
        while (head->next != NULL)
        {
            length++;
        }
    }
    return length;
}

int length_list(struct node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    return 1 + length_list(head->next);
}

int display(struct node *head)
{
    int count = 1;
    if (head == NULL)
    {
        printf("the linked list is empty\n");
    }
    else
    {
        while (head != NULL)
        {
            printf("element %d is at node %d\n", head->data, count);
            count++;
            head = head->next;
        }
        printf("\n");
    }
}