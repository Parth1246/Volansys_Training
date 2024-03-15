#include<stdio.h>


#define MAX 5

//create an empty array of size 5 
int data[MAX],front =-1, rear = -1;

void enqueue(int value) {

	if(rear == MAX-1) 
		printf("the queue is full\n");
	else {
	if(front == -1) 
		front = 0;
	rear++;
	data[rear] = value;
	printf("inserted->%d\n",value);
	}
}

void dequeue() {
	if(front == -1)
		printf("this queue is empty\n");
	else
	{
		printf("deleted item %d\n",data[front]);
		front++;
		if(front>rear) front = rear = -1;
	}
}
void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = *a;
}


void manage_queue(int x) {
    int i=0;
    if(rear == MAX - 1 && front == 0){
    printf("ele %d removed\n",data[front]);
    }

    while(i!= rear) {
        swap(&data[i],&data[i+1]);
        i++;
    }

    data[rear] = x;
}

void display() {
	if(rear == -1) 
	printf("this list is null\n");

	else
	{
	int i;
	printf("the elements are \n");
	for(int i = front;i<=rear;i++) {
	printf("%d\n",data[i]);}
	}
}

int main() {
	
	//on empty queue you cant perform dequeue
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);

	//display all the 5 ele
	display();

    manage_queue(6);
	//now dequeue the first ele
	//dequeue();

	display();
    manage_queue(7);
    display();

	return 0;

}
