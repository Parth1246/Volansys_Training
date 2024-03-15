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
        int *p = &arr[0];
        int *q = &arr[toatl_cookies - 1];

        // printing the array
        for (int i = 0; i < toatl_cookies; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

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

        clock_t t;
        t = clock();
        for (int i = 0; i < toatl_cookies; i++)
        {
            if (p == q)
            {
                break;
            }
            if ((*p == 1 && *q == 1))
            {

                if (q - 1 == p)
                    break;

                q--;
            }
            else if (*p == 0 && *q == 0)
            {

                if (p + 1 == q)
                    break;

                p++;
            }
            else if (*p == 0 && *q == 1)
            {
                if (p + 1 == q)
                    break;

                p++;
                q--;
            }
            else if (*p == 1 && *q == 0)
            {

                swap(p, q);

                if (p + 1 == q)
                {
                    break;
                }

                p++;
                q--;
            }
        }
        t = clock() - t;
        double time_taken = ((double)t); // in seconds

        printf("fun() took %f microsec. to execute \n", time_taken);
        
        printf("\nno of iterations needed = %d\n", iterations);

        printf("\nthe first cookies is %d\nthe last cookies is %d\n", arr[0], arr[toatl_cookies - 1]);

        for (int i = 0; i < toatl_cookies; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}