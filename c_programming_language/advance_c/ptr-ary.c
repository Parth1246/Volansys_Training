#include<stdio.h>

void shift_element(unsigned int i)
{
    int *pvalue;

    for(pvalue = sorted_array[i]; i && *sorted_array[i-1]> *pvalue; i--)
    {
        sorted_array[i] = sorted_array[i-1];
    }
    sorted_array[i] = pvalue;
}

void insertion_sort(void)
{
    unsigned int i,len = array_length(arr);
    for(i=1;i<len;i++)
    {
        if(*sorted_array[i] < *sorted_array[i-1])
        {
            shift_element[i];
        }
    }
}

int main()
{
    int *sorted_array[100];
    return 0;
}
