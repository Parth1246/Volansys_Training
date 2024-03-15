#include <stdio.h>
#include <string.h>

/* defined a union */

union parth{
    int i;
    float j;
    char arr[20];
};

int main(){
    union parth data;
    printf("the size of this parth union is %ld \n",sizeof(data));
    return 0;
}
