#include <stdio.h>


void print_string ( char *string_val) {
  //print the the string
  printf("the supplied string value is %s \n" ,  string_val);
  printf ("The sizeof input string is %lu \n" , sizeof(string_val));
}

void skip(char *msg){
  puts(msg+6);
}

void main() {
  int age = 12;

  printf(" address in the memory %p \n" , &age);

  int *age_address = &age;

  printf(" address age %p \n" , age_address);

  printf(" size of int %lu \n" , sizeof(int));

  char first_name[] = "Anurag";
  print_string(first_name);

  char *last_name = "Anand";
  print_string(last_name);

  printf(" %p \n" , first_name);
  printf(" %p \n" , &first_name);

  int doses[] = {1, 3, 2, 1000};
  printf(" Issue does %i \n" , 0[doses]);

  char *msg_from_amy = "Don't call me";
  skip(msg_from_amy);
}
