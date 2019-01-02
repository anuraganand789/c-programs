#include <stdio.h>

void main() {
  int contestants[] = {1, 2, 3};

  int *choice = contestants;
  printf(" %i \n", *choice);
  contestants[0] = 2;
  printf(" %i \n", *choice);
  contestants[1] = contestants[2];
  contestants[2] = *choice;

  for(int i =0; i<3; ++i) {
    printf(" %i : %i \n" , i, contestants[i]);
  }
  
  printf(" I'm going to pick contestant number %i \n" , contestants[2]);
  printf(" %i \n", *choice);
  printf(" %i \n" , *(choice + 1));
}
