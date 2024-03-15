#include<stdio.h>
#include<syscall.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/stat.h>


int main(void) {


    mkdir("a",751);
    mkdir("b",751);
    mkdir("c",751);
    mkdir("d",751);
    mkdir("e",751);

    //rmdir("a");
    //rmdir("b");
    //rmdir("c");
    //rmdir("d");
    //rmdir("e");

    return 0;
}