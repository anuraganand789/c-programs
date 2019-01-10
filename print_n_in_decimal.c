#include <stdio.h>

#define max(a, b) ( (a) > (b) ? (a) : (b))
#define printmax(a, b) printf(#a #b " running for max.. %d is max " , max(a, b))
void printd(int);

void main() {
  printd(12);
  //printf("Max : %d \n" , max(2,3));
  printmax(12, 14);
}

void printd(int num) {
  if(num < 0) putchar('-');

  int dividend = num / 10;
  int remainder = num % 10;

  if(dividend) printd(dividend);

  putchar(remainder + '0');

}
