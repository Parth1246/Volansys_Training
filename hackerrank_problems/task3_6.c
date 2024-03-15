#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// 0 = black
// 1 = white

struct stack
{
    int data;
    struct stack *next;
};

int no_iteration = 0;

void sort(struct stack **h)
{
    no_iteration = 0;
    struct stack *temp1;
    struct stack *temp2;
    struct stack *temp;
    
    for (temp1 = *h; temp1 != NULL; temp1 = temp1->next)
    {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
        {
            if (temp2->data < temp1->data)
            {
                ++no_iteration;
                temp = temp1->next;
                temp1->next = temp2->next;
                temp2->next = temp;
            }
        }
    }
}

struct stack *insertatlast(struct stack *head, int data)
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = data;

    struct stack *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;

    return head;
}

void display(struct stack *head)
{
    struct stack *ptr;
    ptr = head;

    if (head == NULL)
    {
        printf("nothing to print here\n");
    }

    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }

    printf("\n");
}

int no_0s = 0, no_1s = 0;

struct stack *insertion(struct stack *head)
{
    printf("No of 0s = %d\n\t\tNo of 1s = %d\n", no_0s, no_1s);

    if (no_0s > 9 || no_1s > 9)
    {
        printf("data limit exceeded...\n");
        display(head);
        exit(0);
    }

    else
    {
        struct stack *temp = (struct stack *)malloc(sizeof(struct stack));

        int entry;
        printf("\tenter the 0 or 1\n\t\t");
        scanf("%d", &entry);

        if (entry == 0)
        {
            no_0s++;
        }

        else if (entry == 1)
            no_1s++;

        else
        {
            printf("invalid data...\n");
            display(head);
            exit(0);
        }

        if (head == NULL)
        {
            temp->data = entry;
            temp->next = NULL;

            head = temp;
        }

        else
        {
            temp->data = entry;
            temp->next = head;

            head = temp;
        }
    }
}

struct stack *deletion(struct stack *head)
{
    struct stack *ptr;
    int item;

    if (head == NULL)
    {
        printf("no cookies to pay due...\n");
    }

    else
    {
        item = head->data;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("\n%d data is due\n\n", item);
    }

    if (item == 0)
    {
        no_0s--;
    }

    else
    {
        no_1s--;
        head = insertatlast(head, 0);
        no_0s++;
    }

    return head;
}

int count = 0;

int main()
{
    struct stack *head = NULL;

    printf("welcome to carrom problem...\n");
    sleep(1);

    int cookies_count = 0;
    int i = 1;

    while (1)
    {
        cookies_count += count;

        if (cookies_count > 18)
        {
            printf("no more data can be taken...\n");
            break;
        }

        else
        {
            printf("enter number of cookies you got %d time\n", i++);
            scanf("%d", &count);

            if (count == 0)
            {
                head = deletion(head);
            }
            else
            {
                for (int j = 0; j < count; j++)
                {
                    head = insertion(head);
                }
            }
            sort(&head);
            printf("no of iteration = %d\n", no_iteration);
        }
    }
    display(head);
    return 0;
}