#include <math.h>
#include <stdio.h>

#define PI 3.14

typedef struct _shape{

   float side_s;   // side length of square

   float length_r; // length and width of rectangle
   float width_r; 

   float base_t;   // parameters for triangle 
   float height_t;

   float radius_c; // radius of circle

   float (*area)(struct _shape*);

   char type;

}SHAPE;


float area_s(SHAPE* obj){

   float area = (obj->side_s)*(obj->side_s);

    return area;
}

float area_r(SHAPE* obj){

   float area = (obj->length_r)*(obj->width_r);

    return area;
}


float area_t(SHAPE *obj){

    float area = ((obj->base_t)*(obj->height_t))/2;

    return area;
}

float area_c(SHAPE *obj){

    float area = (PI)*(obj->radius_c)*(obj->radius_c);

    return area;

}


int main(){

    SHAPE object;

    printf("Enter the type of shape :");
    printf("\nS:square \nR:rectangle \nT:triangle \nC:circle\n :: ");
    scanf("%c",&object.type);


    switch(object.type)
    {
        case 'S':
            printf("Enter side length of square : ");
            scanf("%f",&object.side_s);
            object.area = area_s;
            printf("Area : %.3f\n",object.area(&object));
            break;

        case 'R':
            printf("Enter the length and width of rectangle :");
            scanf("%f %f",&object.length_r,&object.width_r);
            object.area = area_r;
            printf("Area : %.3f\n",object.area(&object));
            break;

        case 'T':
            printf("Enter side base and height of triangle :");
            scanf("%f %f",&object.base_t,&object.height_t);
            object.area = area_t;
            printf("Area : %.3f\n",object.area(&object));
            break;

        case 'C':
            printf("Enter radius of circle :");
            scanf("%f",&object.radius_c);
            object.area = area_c;
            printf("Area : %.3f\n",object.area(&object));
            break;
    

        default :
            break;
    }


    return 0;
}