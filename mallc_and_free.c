#include <stdio.h>
#include <stdlib.h>

void main() {
  int *age = malloc(sizeof(int));
  int a = 12;
  printf("%li \n" , sizeof(age));
  printf("%p \n", age);
  printf("%li \n" , sizeof(a));
  free(age);
}
