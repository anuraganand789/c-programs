/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Merge.c
 * Author: anuraganand
 *
 * Created on 13 October 2019, 1:05 PM
 */

#include <stdio.h>
#include <stdlib.h>

void printArrayOfInts(int*, int);
void mergeAndSort(int*, int, int, int);
void splitArrays(int *, int, int);
int calculateMidPoint(int start, int end);
void swap(int* , int , int);
const int arrSize = 10;
int main(int argc, char** argv) {
	int arr[10] = {11, 0, 9, 4, 6, 3, 2, 11, 91, 65};
	int arrSize = 10;

	splitArrays(&arr[0], 0, arrSize-1);
	printArrayOfInts(&arr[0], arrSize);

	return (EXIT_SUCCESS);
}

void swap(int *arr, int left, int right) {
	int t = arr[left];
	arr[left] = arr[right];	
	arr[right] = t;
}

int calculateMidPoint(int start, int end) {
	return ((start - end) / 2) + end;
}

void printArrayOfInts(int* ptrToArrOfInts, int size) {
	for (int i = 0; i < size; ++i){
		printf("%d ", ptrToArrOfInts[i]);
	}
	printf("\n");
}

void splitArrays(int* arr, int start, int end) {
	if (start >= end ) return;

	if((end - start + 1) == 2) {
		if(arr[end] < arr[start]) swap(arr, start, end);
	       return;	
	}

	int m = calculateMidPoint(start, end);
	splitArrays(arr, start, m);
	splitArrays(arr, m + 1, end);
	mergeAndSort(arr, start, m, end);
}

void mergeAndSort(int* arr, int start, int mid, int end) {
	int totalElement = (end - start + 1);
	int* tempArr = malloc(sizeof(int) * totalElement);
	int l = start;
	int r = mid + 1;
	int t = 0;
	
	//copy the sequence of elements from different parts of array
	while(t < totalElement && l <= mid && r <= end) {
		if(arr[l] <= arr[r]){
			tempArr[t] = arr[l];
			++l;
		} else {
			tempArr[t] = arr[r];
			++r;
		}
		++t;
	}

	//copy remaining elelmets from left of mid in the source array in the temporary array
	while(l <= mid) {
		tempArr[t] = arr[l];
		++l;
		++t;
	}
	
	//copy remaining elelmets from right of mid in the source array in the temporary array
	while(r <= end) {
		tempArr[t] = arr[r];
		++r;
		++t;
	}

	//Now copy whole temporary array in the source array
	l = start;
	t = 0;
	while(t < totalElement) {
		arr[l] = tempArr[t];
		++l;
		++t;
	}
	free(tempArr);
	tempArr = NULL;

}
