#include<stdio.h>

int main() {
    int a,b ,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);

    int mat1[a][b],mat2[c][d],mul[a][d];
    printf("enter ele for mattrix 1\n");
    for(int i=0;i<a;i++) {
        for(int j=0;j<b;j++) {
            scanf("%d",&mat1[i][j]);
        }
    }

    printf("enter ele for mattrix 2\n");
    for(int i =0;i<c;i++) {
        for(int j=0;j<d;j++) {
            scanf("%d",&mat2[i][j]);
        }
    } 
    sleep(1);

    printf("the mattrix 1 is given below\n");
    for(int i=0;i<a;i++) {
        for(int j=0;j<b;j++) {
            printf("%d\t",mat1[i][j]);
        }
        printf("\n");
    }

    sleep(1);

    printf("the mattrix 2 is given below\n");
    for(int i=0;i<c;i++) {
        for(int j=0;j<d;j++) {
            printf("%d\t",mat2[i][j]);
        }
        printf("\n");
    }


    for(int i=0;i<a;i++) {
        for(int j=0;j<d;j++) {
            mul[i][j] = 0;
            for(int k =0;k<d;k++) {
                mul[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("after multiplication\n");
    sleep(1);
    for(int i=0;i<a;i++) {
        for(int j=0;j<d;j++) {
            printf("%d\t",mul[i][j]);
        }
        printf("\n");
    }

    return 0;
}