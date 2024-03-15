struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};


void deleteNode(struct Node** head_ref, struct Node* del);
void deleteNodeAtGivenPos(struct Node** head_ref, int n);
void push(struct Node** head_ref, int new_data);
void printList(struct Node* head);
