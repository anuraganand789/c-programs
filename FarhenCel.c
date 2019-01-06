#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int farheToCel(int farhen) {
  int val = (5 * (farhen  - 32)) / 9;
  return val;
}

void main() {
  printf("%d \n" , farheToCel(20));
  int c ;
  //while((c = getchar()) != EOF) {
  // putchar(c);
  //}
  printf("%d \n" , (getchar() != EOF));
  printf(" %d \n " , EOF);
}
