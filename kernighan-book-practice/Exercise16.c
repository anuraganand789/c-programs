#include<stdio.h>

int main(int const argc, char **argv){
    int ch;

    while((ch = getchar()) != EOF) putchar(ch);

    printf("EOF is equal to %d\n", ch);
}
