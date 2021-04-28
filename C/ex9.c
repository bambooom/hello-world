// ex9: while loop

#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0; // if not initiate i, will get warning: variable 'i' is uninitialized when used here
  // but most of the version of C on most of the platform, it will auto initialized with 0,
  // but do not count on this, alway initialize an variable

  // this while loop just print out 0 to 24
  while (i < 25) {
    printf("%d\n", i);
    i++;
  }

  int j = 25;
  // this print out from 25 to 0
  while(j >= 0) {
    printf("%d\n", j);
    j--;
  }

  return 0;
}
