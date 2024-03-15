#include <stdio.h>
#include <string.h>

/* define a union */
union Data{
    int i;
    float j;
    char str[20];
};

int main(){
    union Data data;

/* so as u declare a data variable with union Data data type */

    /* now give value to its member */
    data.i=10;
    printf("%d\n",data.i);
    data.j=20.49;
    printf("%f\n",data.j);
    strcpy(data.str,"Practice");
    printf("%s\n",data.str);

    /* now we will print this members */
    printf("%d\n",data.i);
    printf("%f\n",data.j);
    printf("%s\n",data.str);

return 0;
}
