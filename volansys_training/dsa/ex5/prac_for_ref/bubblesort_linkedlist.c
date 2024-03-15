#include<stdio.h>
#include<stdlib.h>

struct node {

	int data;
	struct node * next;
};

void insertatstart(struct node ** head,int data) {

	struct node * temp  = (struct node *)malloc(sizeof(struct node));
	temp->data = data;

	temp->next = *head;
	*head = temp;	

}

void bubblesort(struct node * head) {
	int swapped,i;
	struct node * ptr;
	struct node * temp = NULL;

	if(head==NULL) {
	printf("this list is NULL\n");
	}

	do {

	swapped = 0;
	ptr = head;

	while(ptr!=temp) {

	if(ptr->data > ptr->next->data) {
	swap(ptr,ptr->next);
	swapped = 1;
	}
	ptr = ptr->next;

	}
	temp = ptr;

	}while(swapped);

}

void printlist(struct node *head) {
	if(head ==NULL) {
	printf("this linked list is null\n");
	}
	else {
	struct node * temp = head;
	while(temp!=NULL) {
	printf("%d\n",temp->data);
	temp = temp->next;
	}
	}

}

void swap(struct node *a,struct node *b) {

	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}
