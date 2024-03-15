#include<stdio.h>
#include<stdlib.h>

int main() {

    char arr[255];
    FILE * ptr;
    ptr = fopen("file_io2.txt","r");

    fscanf(ptr,"%s",arr);
    printf("1: %s\n",arr);

    fgets(arr,255,(FILE *)ptr);
    printf("2: %s\n",arr);

    fgets(arr,255,(FILE *)ptr);
    printf("3: %s\n",arr);
    

    fclose(ptr);
    return 0;
}