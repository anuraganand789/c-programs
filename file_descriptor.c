#include <stdio.h>
//#include <st

#define READ "r"

void  main() {
  FILE* my_file = fopen("backslashC.c", READ);
  int stream_descriptor = fileno(my_file);
  putchar(stream_descriptor + '0');
  my_file = fopen("arrayandpointers.c", READ);
}
