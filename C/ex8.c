// ex8: if, else-if, else

#include <stdio.h>

// argc is the number of the arguments
int main(int argc, char *argv[])
{
  int i = 0;

  // in C, no Boolean type.
  // **Any integer that’s 0 is false or otherwise it’s true.**
  if (argc == 1) {
    printf("You haven't provide any input argument.\n");
  } else if (argc == 2) {
    printf("The input argument is %s.\n", argv[1]);

  } else if (argc > 2 && argc < 4) { // argc > 1 resulted in 1 or 0, not True or False like in Python or JS
    printf("Here's your arguments:\n");

    for (i = 0; i < argc; i++) {
      printf("%s ", argv[i]);
    }
    printf("\n");

  } else {
    printf("You have too many arguments. You suck.\n");
  }

  return 0;
}

/*
➔ ./ex8
You only have one argument. You suck.

➔ ./ex8 aa
Here's your arguments:

./ex8 aa
➔ ./ex8 aa bb
Here's your arguments:

./ex8 aa bb
➔ ./ex8 aa bb cc
You have too many arguments. You suck.
## `./ex8` is also count as an argument
*/
