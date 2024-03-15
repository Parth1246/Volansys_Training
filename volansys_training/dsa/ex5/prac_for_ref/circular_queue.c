#include<stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1,rear = -1;

int isFull() {
	if((front == rear + 1) || (front == 0 && rear == SIZE - 1))
		return 1;
	else {
		return 0;
	}
}

int isEmpty() {
	
	if(front == -1) 
		return 1;

	else
		return 0;
}

void enqueue(int k) {

	if(isFull()) printf("the queue is already full\n");

	else {
		if(front == -1) 	
			front = 0;
		
		rear = (rear+1)%SIZE;
		items[rear] = k;
		printf("inserted element is %d\n",k);	
	}
}

void dequeue() {
	int ele;
	if(isEmpty()) {
		printf("the queue is already null\n");
	}
	else {
	ele = items[front];
		if(front == rear) {
			front = -1;
			rear  = -1;
		}	
		else {
		front = (front+1)%SIZE;
		}
	printf("\n%d element is deleted",ele);
	}
}

void display() {

	int i;
	if(isEmpty())
		printf("thies queue has nothing to print\n");

	else {
	printf("\n front->%d",front);
	printf("\n items-> ");

	for(i = front;i != rear;i = (i+1)%SIZE ) {
	printf("%d",items[i]);
	}

	printf("%d\n",items[i]);
	printf("rear->%d",rear);
	}
}
int main() {
	dequeue();
	
	enqueue(1);
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(5);
	
	enqueue(8);

	display();
	dequeue();

	display();

	return 0;
}













