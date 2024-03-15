#include<stdio.h>

void printarray(int arr[],int size_arr)
{
	int i;
	for(i=0;i<size_arr;i++) {
	printf("%d\n",arr[i]);
	}
}

void swap(int *a,int *b) {
	int temp_var = *a;
	*a = *b;
	*b = temp_var;	
}

void bubblesort(int arr[],int size_arr) {
	int i,j;
	for(i =0;i<size_arr-1;i++) {
		for(j =0;j<size_arr-i-1;j++) {
			if(arr[j]>arr[j+1]) {
			swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

int main() {
	int arr[] = {14,21,12,78,91,54,32};
	int size_arr = sizeof(arr)/sizeof(arr[0]);
	printf("the unsorted array is\n");
	printarray(arr,size_arr);

	bubblesort(arr,size_arr);

	printf("the sorting array is\n");
	printarray(arr,size_arr);

	return 0;
}
