/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Insertion.c
 * Author: anuraganand
 *
 * Created on 12 October 2019, 9:57 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void	printArrayOfInts(int*, int);
void	insertionSort(int*, int);
int main(int argc, char** argv) {
	int arr[10] = {11, 0, 9, 4, 6, 3, 2, 11, 91, 65};
	int arrSize = 10;
	
	insertionSort(&arr[0], arrSize);
	printArrayOfInts(&arr[0], arrSize);
	
	return (EXIT_SUCCESS);
}

void printArrayOfInts(int* ptrToArrOfInts, int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", ptrToArrOfInts[i]);
	}
	printf("\n");
}

void insertionSort(int* arr, int sizeOfArray) {
	int endIndex = sizeOfArray - 1;
	int beginIndex	=	0;
	int currValue	=	-1;
	int backwardIndex	=	-1;
	while(beginIndex	<=	endIndex) {
		
		currValue=	arr[beginIndex];
		backwardIndex	=	beginIndex-1;
		
		while(backwardIndex > -1 && arr[backwardIndex] > currValue) {
			arr[backwardIndex+1]	=	arr[backwardIndex];
			--backwardIndex;
		}
		//+1 is done to negate the effect of --backwardIndec in the while loop
		arr[backwardIndex+1]	=	currValue;
		++beginIndex;
	}
}



