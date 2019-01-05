#include <stdio.h>

typedef struct {
  const char *food;
} Meal;

typedef struct  {
  Meal *meal;
  float excerciseHour;
} Prefrences;
typedef struct  {
  const char *name;
  const char *species;
  int age;
  int numberOfTeeth;
  Prefrences *prefer;
} Fish;



void label(Fish *);
void catalog(Fish *);


  
void main() {
  Meal meal = {"Meat"};
  Prefrences pref = {&meal, 7.5};
  Fish snappy = {"Snappy", "Piranha", 4, 69, &pref};
  label(&snappy);
  snappy.age = 12;
  printf("%i\n" , snappy.age);
  catalog(&snappy);
}

void label(Fish *aFish) {
  printf("Name :- %s - age :- %i\n", aFish->name, aFish->age);
}

void catalog(Fish *aFish) {
  printf("%s is a %s with %i teeth. He is %s and %i yeats old\n", (*aFish).species, "Fish", aFish->numberOfTeeth, aFish->name, aFish->age);
  printf("His Favorite Food :- %s\n", aFish->prefer->meal->food);
  printf("He works out for %f \n", aFish->prefer->excerciseHour);
}

