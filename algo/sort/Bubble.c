/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bubble.c
 * Author: anuraganand
 *
 * Created on 12 October 2019, 8:54 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void bubbleSort(int*, int);
void printArrayOfInts(int*, int);
int main(int argc, char** argv) {
    int arr[10] = {11, 0, 9, 4, 6, 3, 2, 11, 91, 65};
    int arrSize = 10;
    bubbleSort(&arr[0], arrSize);
    printArrayOfInts(&arr[0], arrSize);
    return (EXIT_SUCCESS);
}
void printArrayOfInts(int* ptrToArrOfInts, int size) {
    for(int i=0; i<size; ++i) {
        printf("%d ", ptrToArrOfInts[i]);
    }
    printf("\n");
}
void bubbleSort(int* ptrToArrOfInts, int size) {
    char swapped = 0; 
    int end = size-1;
    int j = 0;
    int temp = -1;
    
    for(int i=0; i<size; ++i) {

        swapped = 0;
        j = 0;

        while(j<end) {
            if(ptrToArrOfInts[j]>ptrToArrOfInts[j+1]) {
                temp = ptrToArrOfInts[j];
                ptrToArrOfInts[j] = ptrToArrOfInts[j+1];
                ptrToArrOfInts[j+1] = temp;
                swapped = 1;
            }
            ++j;
        }
        
        if(!swapped) break;
    }
    
    printf("Sorting Completed.\n");
}

