#include<stdio.h>

int linearsearch(int arr[],int size,int x) {
	int i;
	for(i=0;i<size;i++) {
	if(arr[i]==x)
		return i;
	}
	return -1;
}

void printarray(int arr[],int size) {
	int i;
	for(i=0;i<size;i++) {
	printf("element %d = %d\n",i,arr[i]);
	}
}

int main() {

	int arr[] = {12,1,54,6,78};
	int x,index;
	int size_arr = sizeof(arr)/sizeof(arr[0]);

	printarray(arr,size_arr);

	printf("enter the element to know its index in array\n");

	scanf("%d",&x);

	index = linearsearch(arr,size_arr,x);

	if(index == -1)
		printf("elements is not available in array\n");

	else
		printf("index of element %d is %d\n",x,index);


	return 0;
}
