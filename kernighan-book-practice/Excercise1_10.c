#include<stdio.h>

int main(int const argc, char **argv){
    int prev = 0;
    int curr;

    while((curr = getchar()) != EOF){
        if(curr == ' ' && prev == ' ') continue;

        if(curr == '\t') {
            putchar('\\'); 
            putchar('t'); 
        } else if(curr == '\b'){
            putchar('\\'); 
            putchar('b'); 
        } else if(curr == '\\'){
            putchar('\\'); 
            putchar('\\'); 
        } else {
            putchar(curr);
        }
            
        prev = curr;
    }
}
