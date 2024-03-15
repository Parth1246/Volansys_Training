

#include <stdio.h>
#include <stdlib.h>

int count = 0;

struct node
{
    int data;
    int Priority;
    struct node *link;
};

struct node *top1 = NULL;

struct node *temp = NULL;



void InsertNode(void **top, int data, int priority)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->Priority = priority;
    new_node->link = *(struct node **)top;
    (*(struct node **)top) = new_node;
}


int Displaylist(void *top)
{
    // printf("%p\n",top);
    top1 = (struct node **)top;
    if (top1 == NULL)
    {
        printf("NO DATA\n");
        return 0;
    }
    while (!(top1 == NULL))
    {
        printf("%d\n", top1->data);
        printf("P = %d\n", top1->Priority);
        top1 = top1->link;
    }
    top1 = NULL;
    return 0;
}


int getListlSize(void *top)
{
    top1 = (struct node **)top;
    while (!(top1 == NULL))
    {
        getListlSize(top1->link);
        // top1 = top1->link;
        count++;
    }
    top1 = NULL;
    return count;
}


void InsertNodeat(void **top, int data, int node_position)
{
    count = 0;
    count = getListlSize(*top);
    top1 = *(struct node **)top;
    if (node_position > count)
    {
        printf("Not allowed\n");
    }
    else
    {
        for (int i = 2; i < node_position; i++)
        {
            top1 = top1->link;
        }
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        struct node *temp;
        temp = top1->link;
        top1->link = new_node;
        new_node->data = data;
        new_node->link = temp;
    }
    top1 = NULL;
}

void DeleteNode(void **top)
{
    top1 = *(struct node **)top;
    struct node *temp;
    temp = top1->link;
    free(top1);

    (*(struct node **)top) = temp;
    top1 = NULL;
}


void DeleteNodeFrom(void **top, int node_position)
{
    count = 0;
    count = getListlSize(*top);
    top1 = *(struct node **)top;
    if (node_position > count)
    {
        printf("\nNot allowed\n");
    }
    else
    {
        for (int i = 2; i < node_position; i++)
        {
            top1 = top1->link;
        }
        temp = top1->link;
        top1->link = top1->link->link;
        free(temp);
        temp = NULL;
    }
    top1 = NULL;
}


void Sortlist(void **top, int sorting_method)
{
    struct node **h;
    int i, j, swapped;
    count = getListlSize(*top);
    switch (sorting_method)
    {
    case 1:
        // bubble sort
        for (i = 0; i <= count; i++)
        {
            h = top;
            swapped = 0;

            for (j = 0; j < count - i - 1; j++)
            {
                struct node *p1 = *h;
                struct node *p2 = p1->link;

                if (p1->Priority > p2->Priority)
                //if (p1->data > p2->data)
                {
                    /* update the link after swapping */
                    struct node *tmp = p2->link;
                    p2->link = p1;
                    p1->link = tmp;
                    *h = p2;
                    swapped = 1;
                }
                h = &(*h)->link;
            }
            /* break if the loop ended without any swap */
            if (swapped == 0)
                break;
        }
        break;

    case 2:
        // Quick Sort
        break;

    case 3:
        // Radix Sort
        break;

    default:
        printf("Enter Valid Value for Sorting Method (1,2 or 3)\n");
        break;
    }
}


void SearchData(void **top, int data, int searching_method)
{
    int a = 0;
    count = 0;
    count = getListlSize(*top);
    switch (searching_method)
    {
    case 1:
        // Linear Search
        for (int i = 1; i <= count; i++)
        {
            top1 = (struct node **)top;
            if (top1->data == data)
            {
                printf("%d is found\n", data);
                a++;
            }
            top1 = top1->link;
        }
        if (a == 0)
        {
            printf("%d is not found\n", data);
        }
        break;
    case 2:
        // Binary Search
        top1 = *(struct node **)top;
        break;

    default:
        printf("Enter Valid Value for Searching Method (1 or 2)\n");
        break;
    }
    top1 = NULL;
}

void deletelist(void **top)
{
    top1 = *(struct node **)top;
    while (!(top1->link == NULL))
    {
        temp = top1->link;
        free(top1);
        top1 = temp;
        temp = NULL;
    }
    *(struct node **)(top) = NULL;
    top1 = NULL;
}


void reverse(struct node **top)
{
    struct node *prev = NULL;
    struct node *current = *top;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    *top = prev;
}