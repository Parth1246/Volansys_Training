#include <stdio.h>
void change(int *num){
    printf("before adding value insdie fn num=%d\n",*num);
    (*num) += 100;
    printf("after adding value insdie function num =%d\n",*num);
}
int main(){
    int x=100;
    printf("before fn call x=%d\n",x);
    change(&x);
    printf("after function call x=%d\n",x);
    return 0;
}
