#include <stdio.h>
#include <string.h>

struct {
    unsigned int age : 3;
}Age;

int main(){

    Age.age=4;
    printf("%d\n",Age.age);

    Age.age=7;
    printf("%d\n",Age.age);

    return 0;
}
