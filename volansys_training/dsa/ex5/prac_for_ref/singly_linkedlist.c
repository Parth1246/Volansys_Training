#include<stdlib.h>
#include<stdio.h>

struct node 
{
	int data;
	struct node * next;
};

struct node * insert_start(struct node * head,int data) {
	
	printf("enter data\n");
	struct node * ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->next = head;

	return ptr;

}

struct node * insert_end(struct node * head,int data) {
	struct node * ptr = NULL;
	struct node * p = head;
	ptr = (struct node *)malloc(sizeof(struct node));

	while(p!=NULL) {
	p = p->next;
	}
	p->next = ptr;
	ptr->data = data;
	ptr->next = NULL;

	head = ptr;
	
	return head;

}


struct node * deletion_start(struct node * head) {
	struct node * ptr;
	if(head==NULL){
	printf("NULL\n");
	}	
	ptr = head;
	head = head->next;
	free(ptr);

	return head; 
}



struct node * deletion_end(struct node * head) {
	struct node * p , * q;
	p = head;
	q = head->next;

	while(q->next!=NULL) {
	p = p->next;
	q = q->next;
	}
	p->next = NULL;
	free(q);

	return head;
}

void bubbleSort(struct node *head) {

	int swapp, i;
	struct node *ptr1;
	struct node *lptr = NULL;

	if (head == NULL)
	printf("the list is NULL\n");

	do
	{
		swapp = 0;
		ptr1 = head;

		while (ptr1->next != lptr)
		{
			if (ptr1->data > ptr1->next->data)
			{
				swap(ptr1, ptr1->next);
				swapp = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}while(swapp);


}

void swap(struct node *a, struct node *b) {

	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}


int search(struct node * head,int data) {

	struct node * temp = NULL;
	struct node * p = head;
	int count = 1;


	while(p->next!=NULL) {
	if(p->data == data) {
		return count;
	}
	else {
	p = p->next;
	count++;
	}
	}
	
}

void print_linkedlist(struct node * head) {

	while(head!=NULL) {
	printf("ele = %d\n",head->data);
	head = head->next;
	}
}

int main() {

	struct node *prev,*head,*p;
    	int data,i,flag,n,opt,s_method;
	
	printf("enter number of elements\n");
	scanf("%d",&n);
	head = NULL;
	
	for(i=0;i<n;i++) {
	p = (struct node *)malloc(sizeof(struct node));
	scanf("%d",&p->data);
	p->next = NULL;

	if(head==NULL)
	head = p;
	else
	prev->next = p;

	prev = p;
	}
	printf("before sorting linked list\n");
	print_linkedlist(head);


	printf("after sorting the list \n");
	bubblesort(head);
	print_linkedlist(head);
	getchar();


	printf("\nso enter 1 for linear search and 2 for binary search\n");
	scanf("%d",&s_method);

	int element;
	printf("enter number\n");
	scanf("%d",&element);

	if(s_method == 1) {
	int index = search(head,element);
	printf("index = %d\n",element);
	}
	
	printf("\n\n");
	print_linkedlist(head);
	printf("enter 0 for STACK | 1 for QUEUE\n");
	scanf("%d",&flag);

	if(flag == 0) { 
	head = insert_start(head,12);
	print_linkedlist(head);
	}
	else {
	head = insert_end(head,45);
	print_linkedlist(head);
	}

	
	printf("if you want to delete ele\n");
	printf("press 1 for deletion at start and 2 for deletion at end\n");
	scanf("%d",&opt);


	if(opt = 1) { 
	head = deletion_start(head);
	print_linkedlist(head);
	}
	else {
	head = deletion_end(head);
	print_linkedlist(head);
	}
	
	return 0;	
}
