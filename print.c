#include<stdio.h>

int  main() {
  puts("C Rocks");
  int card_count = 10;
  if(card_count < 11) {
    puts("The deck is hot.. increase the bet");
  }

  char ex[20];
  puts("What's your boyfriend's name");
  scanf("%19s", ex);
  printf("This dude %s - is your Ex now :) " , ex);
  return 0;
}
