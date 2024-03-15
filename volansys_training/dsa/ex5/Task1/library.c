#include<stdlib.h>
#include<stdio.h>

struct node 
{
    int data;
    struct node * next;
};

struct node * createlist(void)
{
    int n,i;
    struct node * head,* p;
    printf("enter number of elements:\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        if(i == 0)
        {
            head = (struct node *)malloc(sizeof(struct node));
            p = head;
        }
        else
        {
            p->next = (struct node *)malloc(sizeof(struct node));
            p = p->next;
        }
        scanf("%d",&(p->data));
    }
    p->next = NULL;
    return (head);
}



struct node * insertatfirst(struct node * head,int data)
{
    struct node * ptr =(struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    
    return ptr;
}

struct node * insertatlast(struct node * head,int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node * p = head;
    
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

struct node * insertatindex(struct node * head,int data,int index)
{
    struct node * ptr =(struct node *)malloc(sizeof(struct node));
    struct node * p = head;

    int i=1;

    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct node * sortedmerge(struct node * a,struct node * b) {
    struct node * result = NULL;
    if(a == NULL) {
        return b;
    }
    else if(b == NULL) {
        return a;
    }
    else {
        if(a->data <= b->data) {
            result = a;
            result->next = sortedmerge(a->next,b);
        }
        else {
            result = b;
            result->next = sortedmerge(a,b->next);
        }
    }
    return result;
}

void split(struct node * head,struct node **a,struct node **b) {
    struct node * fast , * slow;
    slow = head;
    fast = head->next;

    while(fast!= NULL) {
        fast = fast->next;
        if(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *a = head;
    *b = slow->next;
    slow->next = NULL;
}

void mergesort(struct node ** ptr1) {
    struct node *head = *ptr1;
    struct node *a, *b;
    if((head==NULL)||(head->next==NULL)) {
        return head;
    }
    split(head,&a,&b);
    mergesort(&a);
    mergesort(&b);

    *ptr1 = sortedmerge(a,b);
}

struct node * sortlist(void * head,int sorting_method) {
    struct node * ptr1 = NULL;
    ptr1 = (struct node *)head;

    if(sorting_method == 1) {
        //Merge sort
        mergesort(&ptr1);
    }

    else if(sorting_method == 2) {
        //radix sort
        printf("please select 1 or 3 for now\n");
    }

    else if(sorting_method == 3) {
        //bubble sort
        
        int temp;
        int swapp, i;
	    struct Node *lptr = NULL;

	    /* Checking for empty list */
	    if (head == NULL)
	    	return;

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
	    }
	    while (swapp);
    }
    else {
        printf("enter valid input\n");
    }   
}

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct node * middle(struct node *first,struct node *last) {
    if(first == NULL) {
        return NULL;
    }

    struct node * slow = first;
    struct node * fast = first->next;

    while(fast!=last) {
        fast = fast->next;
        if(fast!=last) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

int searchdata(void * head,int data,int searching_method) {
    if(searching_method == 1) {
        //linear search
        struct node * ptr = head;
        while(ptr != NULL) {
            if(ptr->data == data) {
                return 1;
            }
            else {
            ptr = ptr->next;
            }
        }
    }
    else if(searching_method == 2) {
        //binary search
        struct node * start = head;
        struct node * last = NULL;

        do {
            struct node * mid = middle(start,last);

            if(mid == NULL) {
                return NULL;
            }
            else if(mid->data == data) {
                return mid;
            }
            else if(mid->data < data) {
                start = mid->next; //mid = mid+1
            }
            else {
                last = mid;  //mid = mid-1
            }
        }while(last!=NULL || last != start);

        return NULL;

    }
    else {
        printf("please enter as given below\n1:Linear Search\n2:Binary Search\n\n");
    }
}

int display(struct node *p)
{
    int count =1;
    while(p!=NULL)
    {
        printf("%d data at pos %d\n",p->data,count);
        count++;
        p = p->next;
    }
    printf("\n");
}
