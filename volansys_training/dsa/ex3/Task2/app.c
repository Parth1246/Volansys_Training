
#include <stdio.h>
#include <stdlib.h>
#include"lib.h"


int main()
{
	struct Node* head = NULL;


	push(&head, 5);
	push(&head, 2);
	push(&head, 4);
	push(&head, 8);
	push(&head, 10);

	printf("Doubly linked list before deletion:\n");
	printList(head);

	int n = 1;

	deleteNodeAtGivenPos(&head, n);

	printf("\nDoubly linked list after deletion:\n");
	printList(head);

	return 0;
}
