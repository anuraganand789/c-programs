#include <stdio.h>
#include <limits.h>
#include <stdint.h>
void main() {
  int64_t age = 12;

  printf("%ld\n" , age * (CHAR_BIT/8));
}
