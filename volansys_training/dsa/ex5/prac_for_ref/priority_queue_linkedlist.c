// C code to implement Priority Queue using Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	int priority;

	struct node* next;

}Node;

Node* newNode(int d, int p)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = d;
	temp->priority = p;
	temp->next = NULL;

	return temp;
}

int peek(Node** head)
{
	return (*head)->data;
}

void pop(Node** head)
{
	Node* temp = *head;
	(*head) = (*head)->next;
	free(temp);
}

// Function to push according to priority
void push(Node** head, int d, int p)
{
	Node* start = (*head);

	// Create new Node
	Node* temp = newNode(d, p);

	if ((*head)->priority > p) {

		// Insert New Node before head
		temp->next = *head;
		(*head) = temp;
	}
	else {

		// Traverse the list and find a position to insert new node
		while (start->next != NULL && start->next->priority < p) {
			start = start->next;
		}

		// Either at the ends of the list or at required position
		temp->next = start->next;
		start->next = temp;
	}
}

int isEmpty(Node** head)
{
	return (*head) == NULL;
}

struct node * sortlist(void * pq) {
        int temp;
        int swapp, i;
        struct node * ptr1 = NULL;
        ptr1 = (struct node *)pq;

	    struct Node *lptr = NULL;

	    /* Checking for empty list */
	    if (pq == NULL)
	    	return;

	    do
	    {
	    	swapp = 0;
	    	ptr1 = pq;

	    	while (ptr1->next != lptr)
	    	{
	    		if (ptr1->priority > ptr1->next->priority)
	    		{
	    			swap(ptr1, ptr1->next);
	    			swapp = 1;
	    		}
	    		ptr1 = ptr1->next;
	    	}
	    	lptr = ptr1;
	    }
	    while (swapp);


}

int main()
{
    int sorting_method;
	Node* pq = newNode(4, 1);
	push(&pq, 5, 2);
	push(&pq, 6, 3);
	push(&pq, 7, 0);

	while (!isEmpty(&pq)) {
		printf("%d ", peek(&pq));
		pop(&pq);
	}

    printf("\n");

    pq = sortlist(pq);
    while (!isEmpty(&pq)) {
		printf("%d ", peek(&pq));
		pop(&pq);
	}
    printf("\n");

	return 0;
}
