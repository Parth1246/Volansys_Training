struct node {
    int data;
    struct node * next;
};

void print_linkedlist(struct node * head);
struct node * insertatfirst(struct node * head,int data);
struct node * insertatlast(struct node * head,int data);

