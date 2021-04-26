#include<stdio.h>

int main(int argc, char *argv[]){
    int numberOfChars = 0;

    while(getchar() != EOF) ++numberOfChars;

    printf("Total number of chars %d.\n", numberOfChars);
    return 0;
}
