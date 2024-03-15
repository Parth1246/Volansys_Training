#include<stdio.h>
#include<stdlib.h>


struct node {

	int data;
	struct node * next;

};

void insert(struct node **head,int data) {

	struct node * new = (struct node *)malloc(sizeof(struct node));

	if(new==NULL) {
	printf("no memory allocation\n");
	}

	else {

	new->data = data;
	new->next = NULL;

	if(*head == NULL) {
	*head = new;
	}

	else {
	struct node * temp = *head;
	while(temp!=NULL) {
	temp = temp->next;
	}
	temp->next = new;
	}
	}
}

void display(struct node *head) {
	while(head!=NULL) {
	printf("%d\n",head->data);
	head = head->next;
	}
}

struct node * lastnode(struct node * head) {

	struct node * temp = head;
	while(temp!= NULL &&	temp->next!=NULL) {
	temp = temp->next;
	}
	return temp;
}
	
struct node * partition(struct node *first ,struct node *last) {

	struct node * pivot = first;
	struct node * front = first;
	int temp=0;

	while(front!=NULL && front!= last) {
	if(front->data < last->data) {
	pivot = first;
	temp = first->data;
	first->data = front->data;
	front->data = temp;
	}
	front = front->next;
	}
	temp = first->data;
	first->data = front->data;
	front->data = temp;

	return pivot;
}

void quicksort(struct node * first,struct node * last) {

	if (first->data == last->data)
	{
		return;
	}
	struct Node *pivot = parition(first, last);
	if (pivot != NULL && pivot->next != NULL)
	{
		quicksort(pivot->next, last);
	}
	if (pivot != NULL && first != pivot)
	{
		quicksort(first, pivot);
	}

}

int main() {

	struct node * head = NULL;
	insert(&head,24);
	insert(&head,2);
	insert(&head,4);
	insert(&head,82);
	insert(&head,18);
	insert(&head,95);
	insert(&head,13);


	printf("before sorting\n");
	display(head);

	quicksort(head,lastnode(head));

	display(head);

	return 0;

}























}
