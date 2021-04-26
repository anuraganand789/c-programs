#include<stdio.h>
#include<stdbool.h>

static bool isSpaceChar(int const ch){
    return ch == ' ' || ch == '\n' || ch == '\t';
}
int main(int const argc, char **argv){
    int currentChar = 0 ;
    int previousChar = 0;

    int numberOfLines = 0;
    int numberOfWords = 0;
    int numberOfChars = 0;

    while((currentChar = getchar()) != EOF){
        ++numberOfChars;

        if(currentChar == '\n')  { ++numberOfLines; }

        if( isSpaceChar(currentChar) && 
           !isSpaceChar(previousChar)){
            ++numberOfWords;
        }

        previousChar = currentChar;
    }

    printf("Chars %d, Words %d, Lines %d.\n", 
            numberOfChars,
            numberOfWords,
            numberOfLines
           );

}
