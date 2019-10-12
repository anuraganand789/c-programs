/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Selection.c
 * Author: anuraganand
 *
 * Created on 12 October 2019, 9:11 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void selectionSort(int*, int);
void printArrayOfInts(int*, int);
//Array , array start index, array end index [inclusive]
int minIntInTheArray(int*, int, int);
void swap(int*, int*);

int main() {
	int arr[10] = {11, 0, 9, 4, 6, 3, 2, 11, 91, 65};
	int arrSize = 10;

	selectionSort(&arr[0], arrSize);
	printArrayOfInts(&arr[0], arrSize);

	return (EXIT_SUCCESS);
}

void printArrayOfInts(int* ptrToArrOfInts, int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", ptrToArrOfInts[i]);
	}
	printf("\n");
}

int minIntInTheArray(int* arr, int start, int end) {
	int min = start;

	for (int i = start+1; i <= end; ++i) {
		if (arr[min] > arr[i]) min = i;
	}
	return min;
}

void selectionSort(int* arr, int size) {
	int beginIndex = 0;
	int endIndex = size - 1;
	int temp = -1;
	while (beginIndex <= endIndex) {
		int minIndex = minIntInTheArray(arr, beginIndex, endIndex);
		
		swap(&arr[minIndex], &arr[beginIndex]);
		
		//move to next interation
		++beginIndex;
	}
}

void swap(int* first, int* second) {
	int temp	=	*first;
	*first		=	*second;
	*second		=	temp;
}



