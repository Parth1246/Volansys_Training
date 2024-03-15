struct node
{
    int data;
    struct node * prev;
    struct node * next;
};

struct node * insertatbeg(struct node * head,int data);
struct node * insertatlast(struct node * tail,int data);
struct node * insertatpos(struct node * head,int data,int index);
int print(struct node * head);
int searchdata(void * head,int data,int searching_method);
struct node * middle(struct node *first,struct node *last);