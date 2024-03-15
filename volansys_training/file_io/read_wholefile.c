#include<stdio.h>
#include<stdlib.h>

int main() {

    FILE * ptr;
    char ch;
    
    ptr = fopen("file_io2.txt","r");

    if(ptr==NULL) {
        printf("error\n");
        exit(1);
    }

    printf("the content of this file is given below\n");

    do{
        ch = fgetc(ptr);
        printf("%c",ch);
    }while(ch!=EOF);

    fclose(ptr);

    return 0;
}