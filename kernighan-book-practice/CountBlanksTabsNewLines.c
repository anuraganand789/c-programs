#include<stdio.h>

int main(int const argc, char **argv){
    int numberOfBlanks   = 0;
    int numberOfTabs     = 0;
    int numberOfNewLines = 0;

    int ch;

    while((ch = getchar()) != EOF) {
        switch(ch){
            case ' '  : ++numberOfBlanks;   break;
            case '\t' : ++numberOfTabs;     break;
            case '\n' : ++numberOfNewLines; break;
            default   : break;
        }
    }

    printf("Blanks %d, Tabs %d, NewLines %d.\n", 
           numberOfBlanks,
           numberOfTabs,
           numberOfNewLines
           );
}
