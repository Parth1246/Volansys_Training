#include<stdio.h>
#include<stdlib.h>

struct queue {
    int data;
    struct queue * next;
};

struct queue * front;
struct queue * rear;

struct queue * enqueue(struct queue * head,int x) {
    struct queue * ptr = (struct enqueu *)malloc(sizeof(struct queue));
    ptr->data = x;

    if(front==NULL) {
        //to set element on first place = front
        front = ptr;
        rear = ptr;
        front->next = NULL;
        rear->next = NULL;
    }
    else {
        //to set element after rear 
        rear->next = ptr;
        rear = ptr;
        rear->next = NULL;
    }
}

struct queue * dequeue(struct queue * head) {
    struct queue * ptr;
    if(front ==NULL) {
        printf("dequeue is not possible\n");
        return;
    }
    else {
        ptr = front;
        front = front->next;

        free(ptr);
    }
}

void display(struct queue * head) {
    struct queue * ptr = front; 
    if(front == NULL) {
        printf("there is no queue\n");
    }
    else {
        while(ptr!=NULL) {
            printf("%d\n",ptr->data);
            ptr = ptr->next;
        }
    }
}

int main() {
    printf("lets make queue using linked list\n");
    struct queue * head = NULL;

    printf("lets enqueue some data\n");
    
    head = enqueue(head,5);
    head = enqueue(head,7);
    head = enqueue(head,9);
    head = enqueue(head,11);

    display(head);
    printf("lets dequeue \n");
    head = dequeue(head);
    head = dequeue(head);

    printf("after dequeuing 2 times\n");
    display(head);

    return 0;
}