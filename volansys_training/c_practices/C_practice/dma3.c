#include<stdio.h>
#include<stdlib.h>

void read_array(int *a, int n);
int sum_array(int *a, int n);
void wrt_array(int *a, int n);
int main(){
    int *a, n;
    printf(“Input n: “);
    scanf(“%d”, &n);
    a = calloc (n, sizeof (int));
    if(ptr==NULL)
    {
        exit();
    }
    else
    {
    read_array(a, n);
    wrt_array(a, n);
    printf(“Sum = %d\n”, sum_array(a, n);
    }
}
void read_array(int *a, int n) {
    int i;
    for(i=0; i<n; i++){
    printf("enter element %d \n",i+1);
    scanf (“%d”, &a[i]);
    }
}
void sum_array(int *a, int n) {
    int i, sum=0;
    for(i=0; i<n; i++){
    sum += a[i];
    }
    return sum;
}
void wrt_array(int *a, int n) {
    int i;
    for(i=0;i<n;i++){
    printf("a[%d] ele is %d\n",i+1;a[i]);
    }
}
