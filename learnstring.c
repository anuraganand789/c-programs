#include <stdio.h>
#include <string.h>

void reverse(char *str);

void main() {
  char first_name[] = "Anurag";
  reverse(first_name);
  printf("%s\n" , first_name);
}

void reverse(char *str) {
  int len = strlen(str);
  int l = 0;
  int r = len - 1;
  while( l < r) {
    char temp = *(str + l);
    *(str + l) = *(str + r);
    *(str + r) = temp;
    ++l; --r;
  }
}
