#include<stdio.h>
#include<string.h>

int main() {
    char str[] = "Parth;India;21;5000.0";

    char name[20];
    char country[20];
    unsigned int age;
    float salary;


    //sscanf(str,"%[a-zA-Z ];%[a-zA-Z];%u;%f",name,country, &age, &salary);
    //scanf("%[^;];%[^;];%u;%f",name,country,&age,&salary);
    
    printf("%s %s %u %f\n",name,country,age,salary);

    return 0;
}