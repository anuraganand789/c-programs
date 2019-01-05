#include <stdio.h>

typedef struct  {
  const char *food;
  float excerciseHour;
} Prefrences;
typedef struct  {
  const char *name;
  const char *species;
  int age;
  int numberOfTeeth;
  Prefrences prefer;
} Fish;



void label(Fish);
void catalog(Fish);


  
void main() {
  Fish snappy = {"Snappy", "Piranha", 4, 69, {"Meat", 7.5}};
  label(snappy);
  snappy.age = 12;
  printf("%i\n" , snappy.age);
  catalog(snappy);
}

void label(Fish aFish) {
  printf("Name :- %s - age :- %i\n", aFish.name, aFish.age);
}

void catalog(Fish aFish) {
  printf("%s is a %s with %i teeth. He is %s and %i yeats old\n", aFish.species, "Fish", aFish.numberOfTeeth, aFish.name, aFish.age);
  printf("His Favorite Food :- %s", aFish.prefer.food);
  printf("He works out for %f \n", aFish.prefer.excerciseHour);
}

