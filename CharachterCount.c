#include <stdio.h>

void main() {
  long characterCount;

  while(getchar() != EOF) {
    ++characterCount;
  }

  printf("%ld \n" , characterCount);
}
