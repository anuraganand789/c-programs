#include<stdio.h>

int main(int const argc, char **argv){
    int c = getchar();

    //while(c != EOF){
    //    putchar(c);
    //    c = getchar();
    //}

    while((c = getchar()) != EOF) putchar(c);
}
