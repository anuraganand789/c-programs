
#include <stdio.h>

void moveMaxAtTheTop(int*, int, int);
void printArray(int*, int);
void swap(int*, int, int);
void heapsort(int*, int);

int main()
{
	//l = 2 * p +1;
	//p = (l - 1)/2
	int arr[] = {12, 10, 14, 11, 16};
	int sizeOfArray = 5;

	printf("array not sorted -> ");
	printArray(arr, sizeOfArray);
	int lastIndex = sizeOfArray;
	int parent = (sizeOfArray / 2) - 1;

	//prepare Heap
	for(int currParent = parent; currParent>=0; --currParent) {
		moveMaxAtTheTop(arr, sizeOfArray, currParent);
	}

	heapsort(&arr[0], sizeOfArray);

	printf("After heapsort -> ");
	printArray(arr, sizeOfArray);
	return 0;
}
void heapsort(int *arr, int sizeOfArray){
	int lastIndex = sizeOfArray - 1;
	while(lastIndex >= 0) {
		swap(arr, 0, lastIndex);
		//Balance heap at root
		moveMaxAtTheTop(arr, lastIndex, 0);
		--lastIndex;
	}                              
}
void swap(int* arr, int start, int end) {
	int t      = arr[start];
	arr[start] = arr[end];
	arr[end]   = t;
}

void printArray(int* arr, int size) {
	for(int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void moveMaxAtTheTop(int* arr, int sizeOfArray, int parentIndex) {
	int prevParent = parentIndex;
	int largest = parentIndex;
	int lC = 2 * parentIndex + 1;
	int rC = 2 * parentIndex + 2;

	while(largest < sizeOfArray) {
		prevParent = largest;
		//check with left child
		if(lC < sizeOfArray && arr[lC] > arr[largest]) largest = lC;

		//check with right child
		if (rC < sizeOfArray && arr[rC] > arr[largest]) largest = rC;
		//if nothing happens then break
		else if(largest == prevParent) break; 

		swap(arr, largest, prevParent);

		lC = 2 * largest + 1;
		rC = 2 * largest + 2;
	}
}

