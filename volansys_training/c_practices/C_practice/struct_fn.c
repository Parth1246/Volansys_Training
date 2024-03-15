/*** this programe is all about passing structure as a function argument
 * author- parth varsani
 * date : 2-2-22 and time- 11:26 ***/


#include <stdio.h>
#include <string.h>
/*here first of all we define our structure*/
struct Book{
    int id;
    int price;
    char name[30];
};
/*here we have declared our function*/
void printbook(struct Book book);

int main(){
        struct Book book1;

        book1.id=561278;
        book1.price=599;
        strcpy(book1.name,"Stock Operator");

        printbook(book1);
        return 0;
}

void printbook(struct Book book){
    printf("the book id is %d\n",book.id);
    printf("the book price is %d\n",book.price);
    printf("the book name is %s\n",book.name);
}
