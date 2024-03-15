#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE * ptr;
    ptr = fopen("file_io2.txt","w");
    
    //2 ways to write in file

    fprintf(ptr,"this is test case\n");
    fputs("this is test case\n",ptr);
    
    fclose(ptr);
    return 0;
}