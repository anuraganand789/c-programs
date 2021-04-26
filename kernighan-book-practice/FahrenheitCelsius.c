#include<stdio.h>

static int fahrToCelsius(int);
static void printFahrCelsiusTable(int, int);

void main(){
    int fahr = 0;
    int upper, step;

    upper = 300;
    step  = 20;

    while(fahr <= upper){
        printFahrCelsiusTable(
            fahr,
            fahrToCelsius(fahr)
        );
        fahr += step;
    }
}

static int fahrToCelsius(int const fahr){
    return 5 * (fahr - 32) / 9;
}

static void printFahrCelsiusTable(int const fahr, int const celsius){
    printf("Fahrenheit %3d -> Celsius %3d.\n", fahr, celsius);
}
