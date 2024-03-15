#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_array(int arr[],int size_arr)
{
	int i;
	for(i=0;i<size_arr;i++) {
		printf("%d\n",arr[i]);
	}
}

void insertion_sort(int arr[],int size_arr)
{
	int i,j,key;
	for(i=1;i<size_arr;i++) {
	key = arr[i];
	j = i - 1;

	while(j>=0 &&arr[j]>key) {
	arr[j+1] = arr[j];
	j = j-1;
	}
	arr[j+1] = key;
	}
}



int main()
{
	int arr[]={12,14,8,95,4};
	int size_arr = sizeof(arr)/sizeof(arr[0]);

	insertion_sort(arr,size_arr);
	print_array(arr,size_arr);
	
	return 0;
}
