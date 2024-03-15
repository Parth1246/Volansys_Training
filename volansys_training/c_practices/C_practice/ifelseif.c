#include <stdio.h>

int main(){
    int maths;
    printf("enter the marks of subjects respectively \n");
    scanf("%d",&maths);

    if(maths>90)
    {
        printf("congrats you re really doing good in maths");
    }
    else if(maths<90 && maths>70)
    {
        printf("you need to work more hard in maths");
    }
    else{
        printf("do revise everyday whatever you taught");
    }
return 0;
}
