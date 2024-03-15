#include<stdio.h>
#include<stdlib.h>

int binarysearch(int arr[],int low,int high,int ele) {
	
	if(high>=low) {
	int mid = low + (high - low)/2 ;

	if(arr[mid] == ele) {
	return mid;
	}

	if(arr[mid]>ele) {
	return binarysearch(arr,low,mid -1,ele);
	}

	if(arr[mid]<ele) {
	return binarysearch(arr,low,mid+1,ele);
	}
	}
}

void printarray(int arr[],int size) {
	int i;
	for(i = 0;i < size; i++) {
	printf("%d\n",arr[i]);
	}
}

int main() {
	int arr[] = {2,4,9,47,58,69,125};
	int size = sizeof(arr) / sizeof(arr[0]);
	int ele,index;
	
	printarray(arr,size);
	
	printf("enter the element you want to get index of \n");
	scanf("%d",&ele);
	index = binarysearch(arr,0,size-1,ele);

	if(index == -1)
		printf("failure\n");

	else
		printf("%d ele got found on %d index\n",ele,index);
	
	return 0;

}
