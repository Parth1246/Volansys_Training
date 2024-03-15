#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person {
char initials[4];
long int ssn;
int height;
struct person *father;
struct person *mother;
} *tom, *bill, *susan;
int main() {
tom = (struct person *)malloc( sizeof( struct person ) );
bill = (struct person *)malloc( sizeof( struct person ) );
susan = (struct person *)malloc( sizeof( struct person ) );
strncpy(tom->initials, "tj“, 2);
tom->ssn = 555235512;
tom->father = bill;
tom->mother = susan;
susan->height = 68;
/* Since tom is now a pointer, tom->mother->height is correct. */
printf(“\nTom's mother's height is: %d", tom->mother->height);
return 0;
}
