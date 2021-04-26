#include<stdio.h>

static float fahrToCelsius(float);
static void printFahrCelsiusTable(float, float);

void main(){
    float fahr = 0;
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

static float fahrToCelsius(float const fahr){
    return (5.0/9.0) * (fahr - 32);
}

static void printFahrCelsiusTable(float const fahr, float const celsius){
    printf("Fahrenheit %3.0f -> Celsius %6.1f.\n", fahr, celsius);
}
