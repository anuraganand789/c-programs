#include<stdio.h>

void print2DArray(int **, int, int);

int main() {
	int row = 5;
	int col = 2;
	int a1[] = {1, 2, 3, 4, 5};
	int a2[] = {0, 2, 4, 6, 8};
	int a3[] = {1, 3, 5, 7, 9};
	int *a1_2[] = {a1, a2};
	int *aofa[3] = {a1, a2, a3};
	
	print2DArray(a1_2, row, col);
	
	return 0;
}

void print2DArray(int **arrOfArr, int row, int col) {
	for(int i = 0; i < col; ++i) {
		printf("\n");
		for(int j = 0; j < row; ++j) {
			printf("%d ", *((*(arrOfArr + i)) + j));
		}
	}
}