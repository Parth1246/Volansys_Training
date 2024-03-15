#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int iterations = 0;

void swap(int *a, int *b)
{
    ++iterations;
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int toatl_cookies;

    int no_black = 0, no_white = 0;
    char resultant[toatl_cookies];

    printf("enter the total number of cookies\n");
    scanf("%d", &toatl_cookies);

    if (toatl_cookies > 18 && toatl_cookies < 2)
    {
        printf("please enter number below 18\n");
        exit(0);
    }
    else
    {

        printf("enter 0 for white color cookies & enter 1 for black color cookies\n");
        int arr[toatl_cookies];
        int resultant[toatl_cookies];

        // scanning the colors cookies
        for (int i = 0; i < toatl_cookies; i++)
        {
            scanf("%d", &arr[i]);
            if (arr[i] == 1 || arr[i] == 0)
            {
                continue;
            }
            else
            {
                printf("please enter 0 or 1\n");
                exit(0);
            }
        }

        // printing the array
        for (int i = 0; i < toatl_cookies; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        
        quickSort(arr, 0, toatl_cookies - 1);
/*
        // we will traverse the array
        for (int j = 0; j < toatl_cookies; j++)
        {
            if (arr[j] == 0)
            {
                no_black++;
                resultant[j] = 'w';
            }
            else
            {
                no_white++;
                resultant[j] = 'b';
            }
            // now we have number of each color cookies
        }

        if (no_black > 9 || no_white > 9)
        {
            printf("please enter cookies of each color less then 9\n");
            exit(0);
        }

        for (int i = 0; i < toatl_cookies; i++)
        {
            printf("%c ", resultant[i]);
        }

        // now sorting the array

        for (int i = 0; i < toatl_cookies; i++)
        {
            for (int j = i + 1; j < toatl_cookies; j++)
            {
                if (arr[i] > arr[j])
                {
                    swap(&arr[i], &arr[j]);
                }
            }
        }

        /*
                for (int i = 0; i < no_black; i++)
                {
                    arr[i] = 0;
                    resultant[i] = 'w';
                }

                for (int i = no_black; i < toatl_cookies; i++)
                {
                    arr[i] = 1;
                    resultant[i] = 'b';
                }
        */

        printf("\nno of iterations needed = %d\n", iterations);

        printf("\nthe first cookies is %d\nthe last cookies is %d\n", arr[0], arr[toatl_cookies - 1]);

        for (int i = 0; i < toatl_cookies; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        /*
                for (int i = 0; i < toatl_cookies; i++)
                {
                    printf("%c ", resultant[i]);
                }
                printf("\n");
        */
    }
    return 0;
}