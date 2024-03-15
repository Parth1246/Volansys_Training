#include<stdio.h>
#include<stdlib.h>

struct node {

	int data;
	struct node * next;
};

struct node * sortedmerge(struct node * a , struct node * b);
void frontbacksplit(struct node * source, struct node **frontref,struct node ** backref);

void mergesort(struct node **headref) {

	struct node * head = *headref;
	struct node * a = NULL;
	struct node * b = NULL;

	//first check if ele = 0 or 1 , sorting not possible
	if(head == NULL || head->next == NULL) {
	return ;
	}	

	// now split this head in to two diff node a and b
	// store those saperated node in to a and b 
	// thats why pass the ref of a and b 
	frontbacksplit(head,&a,&b);

	//sort the list recursively

	mergesort(&a);
	mergesort(&b);

	// merge those two sorted lists togather
	*headref = sortedmerge(a,b);
}

void frontbacksplit(struct node * head,struct node **a,struct node ** b) {

	struct node * slow = head;
	struct node * fast = head->next;
	
	while(fast!=NULL) {
	fast = fast->next;
	if(fast!=NULL) {
	slow = slow->next;
	fast = fast->next;
	}

	*a = head;
	*b = slow->next;
	slow->next = NULL;

	}
}

struct node * sortedmerge(struct node *a , struct node * b) {
	
	struct node * result = (struct node *)malloc(sizeof(struct node));
/*
	//base case for either one partition is null
	if(a == NULL) {
	return (b);
	}
	else if(b == NULL) {
	return (a);
	}
*/

	//take value from either a or b and do rec

	if(a->data <= b->data) {
	result = a;
	result->next = sortedmerge(a->next,b);
	}
	else {
	result = b;
	result->next = sortedmerge(a,b->next);
	}

	return (result);

}

struct node * newnode(int data) {
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	
	temp->data = data;
	temp->next = NULL;

	return temp;
}

void push(struct node **head,int data) {

	struct node * newnode = (struct node *)malloc(sizeof(struct node));

	newnode->data = data;
	newnode->next = *head;

	*head = newnode;

}


struct node * insertion(struct node * head, int data) {

	struct node * temp = head;
	
	//insertion at first

	temp->data = data;
	temp->next = head;

	return temp;

}

void printlist(struct node * head) {

	struct node * temp = head;

	while(temp!=NULL) {
	printf("%d\n",temp->data);
	temp = temp->next;
	}
}


int main() {

	struct node * head = NULL;

	head = newnode(21);
	push(&head,1);
	push(&head,5);
	push(&head,19);
	
	printlist(head);

	mergesort(&head);
	printlist(head);
	getchar();

	return 0;
}
