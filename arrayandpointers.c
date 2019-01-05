#include <stdio.h>

void hello();

void main() {
  char first_name[] = "Anurag";
  char *last_name = first_name;

  
  printf(" %p , %p " , first_name , last_name);
  last_name = "Anand";
  printf(" %p , %p " , first_name , last_name);

  printf("%s , %s\n" , first_name, last_name);

  char l[] = "abc";
  l[1] = 'o';
  printf("%s\n" , l);

  char *b = "abc";
  //b[1] = 'o';
  hello();
}

void hello(){}
