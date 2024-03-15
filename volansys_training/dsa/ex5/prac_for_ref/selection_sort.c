#include <stdio.h>

void swap(int *a,int *b)
{
	int temp_var = *a;
	*a = *b;
	*b = temp_var;
}

void selectionsort(int arr[],int size_arr) {

	int i,j,min;
	for(i=0;i<size_arr-1;i++) {
	min = i;
	for(j=i+1;j<size_arr;j++) 
		if(arr[j] < arr[min]) 
			min = j;
	
	swap(&arr[min],&arr[j]);
} 	
}


void printarray(int arr[],int size_arr) {
	int i;
	for(i = 0;i<size_arr;i++) {
	printf("%d\n",arr[i]);
}
}

int main() {

	int arr[] = {12,71,145,325,45};
	int size_arr = sizeof(arr)/sizeof(arr[0]);

	selectionsort(arr,size_arr);
	printf("the sorted array is \n");
	printarray(arr,size_arr);

	return 0;

}
