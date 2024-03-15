#include<stdio.h>
#include<stdlib.h>

int main() {
    int num;
    FILE * fp;

    if((fp = fopen("file_io.txt","r")) != NULL) {
        fscanf(fp,"%d",&num);
        printf("%d\n",num);
    }
    else {
        printf("error\n");
        exit(0);
    }

    fclose(fp);


    return 0;
}