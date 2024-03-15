#include<stdio.h>
#include<stdlib.h>

struct data {
    int n1,n2,n3;
};

int main(){
    struct data item;

    FILE * ptr;

    ptr = fopen("file_io.bin","r");

    if(ptr==NULL) {
        printf("error\n");
        exit(1);
    }

    fread(&item,sizeof(struct data),1,ptr);
    printf("n1 = %d,n2 = %d,n3 = %d\n",item.n1,item.n2,item.n3);

    fclose(ptr);
    return 0;    
}