#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int age(int, long, double);

//compare number for ascending operations
int compareScores(const void *input1, const void *input2) {
  int num1 = * (int *) input1;
  int num2 = * (int *) input2;

  return (num1 < num2) ? -1 : (num1 > num2) ? 1 : 0;
}

//Compare numbers for descending operations
int compareScoresDesc(const void *input1, const void *input2) {
  return compareScores(input2, input1);
}

typedef struct {
  int width;
  int height;
} Rectangle;

int compareAreas(const void *rect1, const void *rect2) {
  Rectangle rectangle1 = * (Rectangle *) rect1;
  Rectangle rectangle2 = * (Rectangle *) rect2;

  int area1 = (rectangle1.width) * (rectangle1.height);
  int area2 = (rectangle2.width) * (rectangle2.height);

  return compareScores(&area1, &area2);
}

int compareStrings(const void *str1, const void *str2) {
  char *word1 = * (char **) str1;
  char *word2 = * (char **) str2;

  return strcmp(word1, word2);
}

void main() {
  int (*pointerToAgeFunction) (int, long, double) = age;
  Rectangle rect1 = {12, 14};
  Rectangle rect2 = {13, 5};

  if(0 > compareAreas(&rect1, &rect2)) {
    printf("Area of rectangle1 is smaller than area of rectangle2");
  } else {
    printf("Area of rectangle1 is bigger than area of rectangle2");
  }

  char *names[] = {"Anurag", "Anand", "Nishant", "Gupta"};
  qsort(names, 4, sizeof(char *), compareStrings);
  for(int i = 0; i < 4; ++i) {
    printf("%s \n", names[i]);
  }

  //Array of Pointers
  int (* functions []) (const void*, const void*) = { compareScores, compareStrings, compareAreas };
}

int age(int a, long l, double d) {}
