#include<stdio.h>
#include<stdlib.h>

int n, top = -1, *stack;

void push(int x){
	if(top==n) return;
    else {
	    stack[++top]=x;
    }
}

int pop(){
	if(top==-1) return -1;
	return stack[top--];
}

int peek(){
	if(top==-1) return -1;
	return stack[top];
}

void display(){
	for(int i=top ; i>-1 ; i--) printf("%d ",stack[i]);
	printf("\n\n");
}

int main(){
	
	n = 10;
	
	printf("Initializing the stack with size 10\n\n");
	
	stack = (int*)malloc(n*sizeof(int));
	
	printf("Pushing elements into the stack\n1\n2\n3\n4\n\n");
	
	push(1);
	push(2);
	push(3);
    push(4);
	
	printf("list is given below\n");
	display();
	
	printf("The top of the stack = %d\n\n",peek());

    pop();
    pop();
	
	display();
	
	return 0;
}