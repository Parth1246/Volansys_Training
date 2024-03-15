#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char str[100];
    char *ptr;

    strcpy(str,"parth varsani");
    // so thiis is memory sizing //
    ptr=malloc(100*sizeof(char));

    if(ptr==NULL)
    {
        fprintf(stderr,"Error-unable to allocate memory");
    }
    else
    {
        strcpy(ptr,"parth varsani is in volansys");
    }
    printf("Name = %s",ptr);
    printf("\nthe str is %s",str);

    //now we will do resizing of memory allocation//
    ptr=realloc(ptr,100*sizeof(char));
     if(ptr==NULL)
    {
        fprintf(stderr,"Error-unable to allocate memory");
    }
    else
    {
        strcpy(ptr,"parth varsani is in bvm college");
    }
    printf("\nName = %s",ptr);
    printf("\nthe str is %s",str);

    free(ptr);
}
