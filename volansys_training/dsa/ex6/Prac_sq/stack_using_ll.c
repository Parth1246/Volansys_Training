#include<stdio.h>
#include<stdlib.h>

struct stack {
    int data;
    struct stack * next;
};

struct stack * push(struct stack * head,int x) {
    
    struct stack * temp = (struct stack *)malloc(sizeof(struct stack));
    if(head==NULL) {
        temp->data = x;
        temp->next = NULL;

        head = temp;
    }
    else {
        temp->data = x;
        temp->next = head;

        head = temp;
    }
}

struct stack * pop(struct stack * head) {
    struct stack * ptr;
    int item;
    if(head==NULL) {
        printf("popping is not possible\n");
    }
    else {
    item = head->data;
    ptr = head;
    head = head->next;
    free(ptr);
    printf("\n%d data is popped\n\n",item);
    }

    return head;
}

void display(struct stack * head) {
    struct stack * ptr;
    ptr = head;
    if(head == NULL) {
        printf("nothing to print here\n");
    }
    else {
        while(ptr!=NULL) {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
        }
    }
}

int main() {
    struct stack * head = NULL;
    
    
    printf("lets push some data\n");
    head = push(head,5);
    head = push(head,7);
    head = push(head,9);

    display(head);

    printf("\nlets pop one data\n");
    head = pop(head);
    display(head);
    head = pop(head);
    display(head);

    return 0;
}