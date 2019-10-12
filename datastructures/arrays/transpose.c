#include <stdio.h>

int main() {
	int m = 5;
	int n = 3;
	int matrix_1[5][3] = {{1, 2, 3}, {1, 4, 5}, {6, 7, 8}, {12, 9, 10}, {11, 12, 13}};
	int matrix_2[3][5];
	
	//transpose 
	for(int i = 0; i < m; ++i ) {
		for(int j = 0; j < n; ++j) {
			matrix_2[j][i] = matrix_1[i][j];
		}
	}
	
	printf("Transpose of the matrix\n");
	
	for(int i = 0; i < n; ++i ) {
		for(int j = 0; j < m; ++j) {
			printf("%d ", matrix_2[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}