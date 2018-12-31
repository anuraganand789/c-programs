#include <stdio.h>
#include <stdlib.h>

int main() {

  char card_name[3];
  puts("Enter the card name - ");
  scanf("%2s" , card_name);
  printf("You entered %2s\n", card_name);

  int ival = 0;
  if(card_name[0] == 'K') {
    ival = 10;
  } else if (card_name[0] == 'Q') {
    ival = 10;
  } else if (card_name[0] == 'J') {
    ival = 10;
  } else if (card_name[0] == 'A') {
    ival = 11;
  } else {
    //if we are here then that means, user has entered a digit
    ival = atoi(card_name);
  }

  printf("The card value is %i\n" , ival);
  return 0;
}
