#include <stdio.h>

int main() {

    int numbers[3] = {10, 12, 11};
    int findNumber = 11;
    int size = 3;

    for(int i = 0; i<size; ++i) {
        if(numbers[i] == findNumber) {
            printf("Found @ %d \n",i);
        }
    }


    return 0;
}