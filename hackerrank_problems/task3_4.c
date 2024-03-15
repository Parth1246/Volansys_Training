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

int total_cookies = 0;

int main()
{
    int rewarded_cookies;

    int no_black = 0, no_white = 0;
    char resultant[18];
    int arr[18];

    int daa = 1;
    while (total_cookies != 18)
    {
        printf("enter the no. of cookies you got at your %d\n", daa++);
        scanf("%d", &rewarded_cookies);

        total_cookies += rewarded_cookies;

        if (total_cookies > 18)
        {
            printf("ok you have got all the cookies in your hand\n");
            exit(0);
        }
        else
        {
            printf("enter 0 for white color cookies & enter 1 for black color cookies\n");

            // scanning the colors cookies
            for (int i = 0; i < rewarded_cookies; i++)
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
            int *q = &arr[total_cookies - 1];

            // printing the array
            for (int i = 0; i < total_cookies; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");

            // we will traverse the array
            for (int j = 0; j < total_cookies; j++)
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

            printf("black cookies = %d\n", no_black);
            printf("white cookies = %d\n", no_white);

            if (no_black > 9 || no_white > 9)
            {
                printf("please enter cookies of each color less then 9\n");
                exit(0);
            }
            /*
                        for (int i = 0; i < total_cookies; i++)
                        {
                            printf("%c ", resultant[i]);
                        }
            */
            clock_t t;
            t = clock();

            for (int i = 0; i < total_cookies; i++)
            {
                for (int j = i + 1; j < total_cookies; j++)
                {
                    if (arr[i] > arr[j])
                    {
                        swap(&arr[i], &arr[j]);
                    }
                }
            }

            t = clock() - t;
            double time_taken = ((double)t);

            // printf("fun() took %f microsec. to execute \n", time_taken);

            printf("\nno of iterations needed = %d\n", iterations);

            printf("\nthe first cookies is %d\nthe last cookies is %d\n", arr[0], arr[total_cookies - 1]);

            for (int i = 0; i < total_cookies; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n\n");
        }
    }
    return 0;
}