#include<stdio.h>
#include<limits.h>
#define MAX 100

// priority queue using array

int Index = -1;
int pqVal[MAX];
int pqpPrioriry[MAX];


int isFull() {
	return Index==-1;
}

int isEmpty() {
	return Index==MAX-1;
}

void enqueue(int value,int priority) {
	if(!isFull()) {
	Index++;
	pqVal[Index] = value;
	pqPriority[Index] = priority;
	}
}


int peek() {
	int ind = -1;
	int highest_priority = INT_MIN;

	for(int i=0;i<=Index;i++) {
	if(highest_priority == pqPriority[i] && ind > -1 && pqVal[ind] < pqVal[i]) {
	highest_priority = pqPriority[i];
	ind = i;
	}
	else if(highest_priority < pqPriority[i]) {
	highest_priority = pqPriority[i];
	ind = i;
	}
	}

	return ind;
}

void dequeue() {
	if(!isEmpty()) {
	int ind = peek();

	for(int i =0;i<Index;i++) {
	pqVal[i] = pqVal[i+1];
	pqPriority[i] = pqPriority[i+1];
	}
	Index--;
	}
}	

void display() {
	int i;
	for(i = 0;i<= Index;i++) {
	printf("(%d,%d)\n",pqVal[i],pqPriority[i]);
	}
}


int main() {

	enqueue(5,1);
	enqueue(14,3);
	enqueue(25,4);
	enqueue(16,5);
	enqueue(12,2);	
	
	printf("before dequeue \n");
	display();

	dequeue();	
	dequeue();

	printf("after dequeue \n");
	display();

	return 0;
}







