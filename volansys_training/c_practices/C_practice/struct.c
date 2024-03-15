#include <stdio.h>
#include <string.h>
/* this is how strucutre is defined in which i have taken some diff data types as Book structure */
struct Book{
    char title[50];;
    char subject[50];
    int book_id;
    int book_price;
};

int main(){
        
        printf("this is my first structure programming code\n");
        struct Book book1; /* this is how declarations works of strucutre */ 
        /*now we will set data as those datatypes as given below */
        strcpy(book1.title,"The Stock Operator");
        strcpy(book1.subject,"Stock Market");
        book1.book_id=549876;
        book1.book_price=499;


        printf("the book title is : %s\n",book1.title);
        printf("the subject of book is : %s\n",book1.subject);
        printf("the book id is : %d\n",book1.book_id);
        printf("the book price is %d\n",book1.book_price);
return 0;
}
