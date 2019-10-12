/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearch.c
 * Author: anuraganand
 *
 * Created on 12 October 2019, 4:10 PM
 */

#include <stdio.h>

/*
 * 
 */

int calculateMidPoint(int start, int end);
int binarySearch(int* arr, int find, int size);

int main(int argc, char** argv) {

    int numbers[5] = {3, 6, 10, 11, 12};
    int index = binarySearch(&numbers[0], 11, 5);
    printf("%d found @ index %d\n", 3, index);
    return 1;
}

//handling integer overflow
int calculateMidPoint(int start, int end) {
    return ((start - end)/2) + end;
}

int binarySearch(int* arr, int find, int size) {
    int s = 0;
    int e = size - 1 ;
    int m = -1;
    int val = -1;
    while(s>=0 && e>=0 && s<e) {
        m = calculateMidPoint(s, e); 
        val = arr[m];
        
        if(val == find) break;
        
        if(val < find) s = m+1;
        else e = m-1;
    }
    return m;
}