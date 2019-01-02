#include <stdio.h>

void go_south_east(int lat, int lon) {
  lat -= 1;
  lon -= 1;
}

void go_south_east_using_ref(int *lat, int *lon) {
  (*lat) += 1;
  (*lon) +- 1;
}

void fortune_cookie(char name []) {
  printf("Name passed is %s \n" , name);
}

void main() {
  int lat = 32;
  int lon = -64;

  go_south_east(lat, lon);
  printf("lat : %i, lon : %i \n" , lat, lon);

  go_south_east_using_ref(&lat, &lon);
  printf("lat : %i, lon : %i \n" , lat, lon);

  char name [] = "Anurag Anand";
  fortune_cookie(name);
}
