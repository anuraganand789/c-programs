#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
char* now();

void main() {
  //system("ls");
  //printf("%s \n", now());
  char comment[80];
  char cmd[120];
  fgets(comment, 80, stdin);
  sprintf(cmd, "ec '%s %s' >> reports.log", comment, now());
  system(cmd);
  puts(strerror(errno));
}

char* now() {
  time_t time_value;
  time(&time_value);
  return asctime( localtime(&time_value) );;
}
