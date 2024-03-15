#include <stdio.h>
/*this is a first program of enum */

/*this is the way it's defined */
enum month
{
    jan,feb,mar,apr,amy,jun,jul,aug,sep,oct,nov,dec
        /*here jan will be stored as a 0 value and dec will be as 11 */
        /* or else if we want to initialize storing value from 1 then 
         * jan=1,feb,march,as its ... so it will  done like this
         */
};

enum boolean
{
    false,true
};

enum boolean iseven(int x)
{
    if(x%2==0){
        return true;
    }
    else
        return false;
}
int main(){
    int n;
    printf("enter the value");
    scanf("%d",&n);
    int result=iseven(n);

    if(result==true)
    {
        printf("even");
    }
    else
    {
        printf("odd");
    }
}
