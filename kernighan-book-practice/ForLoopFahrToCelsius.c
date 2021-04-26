#include<stdio.h>

static int const LOWER = 0;
static int const UPPER = 300;
static int const STEP  = 20;


static float fahrToCelsius(float);
static void printFahrCelsiusTable(float, float);

void main(){
    
    for(int fahr = LOWER; fahr < UPPER; fahr += STEP){
        printf("%3d %6.1f \n", fahr, fahrToCelsius(fahr));
    }
}

static float fahrToCelsius(float const fahr){
    return (5.0/9.0) * (fahr - 32);
}

static void printFahrCelsiusTable(float const fahr, float const celsius){
    printf("Fahrenheit %3.0f -> Celsius %6.1f.\n", fahr, celsius);
}
