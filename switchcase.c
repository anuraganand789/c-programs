#include <stdio.h>

int main() {
  char case_letter = 'H';
  switch(case_letter) {
  case 'H' :
    puts("We have an H");
    break;
  case 'A' :
    puts("We have an 'A'");
    break;
  default:
    puts("we neither have 'A' not 'H'");
  }
  return 0;
}
