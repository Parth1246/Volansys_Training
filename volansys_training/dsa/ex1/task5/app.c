#include<stdio.h>
#include<stdlib.h>
#include"lib.h"


//global variable head that points to struct node datatype
struct node * head;

int main()
{
    //initialised head  to null
    head = NULL;
    head = createlist();
    display(head);

    printf("insertion of 5 at first\n");
    head = insertatfirst(head,5);
    display(head);

    printf("insertion of 9 at last\n");
    head = insertatlast(head,9);
    display(head);

    printf("insertion of 13 at 5th index\n");
    head = insertatindex(head,13,5);
    display(head);

    printf("insertion of 4 after 13\n");
    head = insertafterdata(head,13,4);
    display(head);
    
    free(head);
    return 0;
}
