#include<stdio.h>
#include<stdlib.h>

int n,front=-1,rear=-1,*queue;

void enqueue(int x) {
    if(rear == n-1) {
        printf("this queue is full\n");
    }
    else if(front==-1 && rear==-1) {
        front=0; 
        rear=0;

        queue[rear] = x;
    }
    else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if(front == -1) {
        printf("this queue is already null\n");
    }
    else {
        printf("%d ele is dequing\n",queue[front]);
        front++;
    }
}

void display() {
    for(int i = front;i<=rear;i++) {
        printf("%d\n",queue[i]);
    }
}

int main() {
    printf("enter no of elements\n");
    scanf("%d",&n);

    queue = (int *)malloc(n*sizeof(int));

    enqueue(1);
    enqueue(2);
    enqueue(3);

    display();
    dequeue();

    printf("after dequing\n");
    display();

    return 0;
}