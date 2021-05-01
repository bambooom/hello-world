// ex13: for-loops and array of strings

#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;

  // for-loop doesn’t run if i < argc is false
  for (i = 1; i < argc; i++) { // argv[0] will be just `./ex13`
    printf("arg %d: %s\n", i, argv[i]); // just print out all cli arguments
  }

  // array of strings:
  // combining the `char *str = "blah"` syntax
  // with the `char str[] = {'b','l','a','h'}` syntax to construct a two-dimensional array
  char *states[] = {
    "California", "Oregon", "Washington", NULL, "Texas"
  };

  int num_states = 5; // set it larger than the length of states[], then it will print out garbage for last one

  // states[1] = argv[1];

  for (i = 0; i < num_states; i++) {
    printf("state %d: %s\n", i, states[i]); // NULL will print out like `(null)`
  }

  return 0;
}
