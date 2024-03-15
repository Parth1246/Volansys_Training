#include<stdio.h>
#include<stdlib.h>

struct data {
    int n1,n2,n3;
};

int main(){
    struct data item;
    int a = 10;

    FILE * ptr;
    
    if((ptr = fopen("file_io.bin","w"))==NULL) {
        printf("Error\n");
        exit(1);
    }
    else {
        item.n1 = 1;
        //item.n2 = 2;
        //item.n3 = 3;


        fwrite(&item,sizeof(struct data),1,ptr);
        fread(&item,sizeof(struct data),1,ptr);
        printf("%d\n",a);
    }
    fclose(ptr);

    return 0;    
}