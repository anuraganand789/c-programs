#include <stdio.h>

int main() {
	int length = 5;
	int data[]  = {1, 2, 3, 4, 5};
	int pos;
	
	printf("Enter the position on which element needs to be deleted\n");
	
	scanf("%d", &pos);
	
	if(pos > length) {
		printf("There are only %d elements in the array\n", pos);
		return 1;
	}
	
	pos = pos - 1;
	
	while((pos+1) < length) {
		data[pos] = data[pos + 1];
		++pos;
	}
	
	data[pos] = -1;
	
	for(int i = 0; i < length; ++i) {
		printf("%d\n", data[i]);
	}
 	
	return 0;
}