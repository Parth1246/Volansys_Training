struct node * createlist(void);
struct node * insertatfirst(struct node * head,int data);
struct node * insertatlast(struct node * head,int data);
struct node * insertatindex(struct node * head,int data,int index); 
int sortList(struct node * head,int sorting_method);
int searchdata(void * head,int data,int searching_method);
int display(struct node *p);
void swap(int *a,int *b);
struct node * sortedmerge(struct node * a,struct node * b);
void split(struct node * head,struct node **a,struct node **b);
void mergesort(struct node ** ptr1);
int searchdata(void * head,int data,int searching_method);
struct node * middle(struct node *first,struct node *last);