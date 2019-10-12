#include <stdio.h>

int main() {
	int arraySize = 10;
	int data[arraySize];
	
	printf("Enter number of array elements, you want to enter !!!");
	int noOfArrayElements = 0;
	scanf("%d", &noOfArrayElements);

	for(int i = 0; i<noOfArrayElements; ++i) {
		scanf("%d", &data[i]);
	}

	//
	printf("Printing data in the array\n");
	for(int i =0; i<noOfArrayElements; ++i) {
		printf("%d\n", data[i]);
	}

	return 0;
}


