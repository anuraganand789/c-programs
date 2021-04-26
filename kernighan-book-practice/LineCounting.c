#include<stdio.h>

int main(int argc, char **argv){
    int numberOfLines = 0;
    int ch;

    while((ch = getchar()) != EOF) {
        if(ch == '\n') {
            ++numberOfLines;
        }
    }

    printf("Total number Of lines = %d.\n", numberOfLines);
}
