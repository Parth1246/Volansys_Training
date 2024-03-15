#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ASCENDING 0
#define DECENDING 1

void get_points(int *X, int *Y, int size);
void print_missing_point(int *X, int *Y, int size);

int main()
{

    int T; // number of test cases
    scanf("%d", &T);

    while (T--)
    {

        int N; // number of rectangle
        scanf("%d", &N);

        int points_n = 4 * N - 1;

        int *X_Points = (int *)malloc(sizeof(int) * points_n);
        int *Y_Points = (int *)malloc(sizeof(int) * points_n);

        get_points(X_Points, Y_Points, points_n);

        print_missing_point(X_Points, Y_Points, points_n);
    }
}

void get_points(int *X, int *Y, int size)
{

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &X[i]);
        scanf("%d", &Y[i]);
    }
}

int compare(const void *a, const void *b)
{

    return (*(int *)a - *(int *)b);
}

void print_missing_point(int *X, int *Y, int size)
{

    qsort(X, size, sizeof(int), compare);
    qsort(Y, size, sizeof(int), compare);

    int save;

    int flag = 0;
    for (int i = 0; i < size - 1; i += 2)
    {

        if (X[i] != X[i + 1])
        {
            save = X[i];
            flag = 1;
            break;
        }
    }

    if (flag)
        printf("%d ", save);
    else
        printf("%d ", X[size - 1]);


    flag = 0;
    for (int i = 0; i < size - 1; i += 2)
    {

        if (Y[i] != Y[i + 1])
        {
            save = Y[i];
            flag = 1;
            break;
        }
    }

    if (flag)
        printf("%d ", save);
    else
        printf("%d ", Y[size - 1]);
        
}