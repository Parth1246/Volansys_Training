#include<stdio.h>

int main() {
    system("ls ");

    printf("\nnow makinf few directories\n");

    mkdir("a",751);
    mkdir("b",751);
    mkdir("c",751);
    mkdir("d",751);
    mkdir("e",751);

    printf("after making few directories\n");
    system("ls ");
    return 0;
}