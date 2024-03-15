struct node * createlist(void);
struct node * insertatfirst(struct node * head,int data);
struct node * insertatlast(struct node * head,int data);
struct node * insertatindex(struct node * head,int data,int index);
struct node * insertafterdata(struct node * head,int data_comp,int data_put);
int display(struct node *p);