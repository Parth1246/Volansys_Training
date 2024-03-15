#include<stdio.h>
#include<stdlib.h>

int main() {
    int num;
    FILE * fp;

    fp = fopen("file_io.txt","w");

    if(fp == NULL) {
        printf("Error\n");
        exit(1);
    }
    else {
        printf("enter the data\n");
        scanf("%d",&num);

        fprintf(fp,"%d\n",num);
        fclose(fp);

    }

    return 0;
}