#include <stdio.h>

typedef union {
  short count;
  float weight;
  float volume;
} Quantity;

void main() {
  printf("Learning Union \n");
  //c89 way of initialization
  Quantity q = {10};
  printf("count : %i \n" , q.count);
  Quantity q2 = {.weight = 1.5};
}
