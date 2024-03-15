#include<stdio.h>
#include<stdlib.h>

#define MAX 5
	
int count = 0;

struct node 
{
	int data[MAX];
	int top;
};

typedef struct node st;


//create the empty stack

void createstack(st * s) {

	s->top = -1;
}

//check if stack is full
int isFull(st *s) {
	if(s->top == MAX-1) {return 1;}
	else{
	return 0;}
}

//check if stack is empty
int isEmpty(st * s) {
	if(s->top == -1) {return 1;}
	else{
	return 0;}
}

//push the data into stack

void push(st * s,int data) {
	if(isFull(s))
	printf("The stack is full\n");
	else {
	s->top++;
	s->data[s->top] = data;
	}
	count++;
}

void pop(st * s) {
	
	if(isEmpty(s))
	printf("the stack is empty\n");
	else {
	printf("data poped = %d\n",s->data[s->top]);
	s->top--;
	}
	count--;
	printf("\n");
}

void printstack(st * s) {

	printf("the stack is ");
	for(int i=0;i<count;i++) {
	printf("%d",s->data[i]);
	}
	printf("\n");
}


int main() {

	st *s = (st *)malloc(sizeof(st));
	createstack(s);

	push(s,1);
	push(s,2);
	push(s,3);
	push(s,4);

	printstack(s);
	
	pop(s);

	printf("after popping\n");
	printstack(s);

	return 0;
}





















