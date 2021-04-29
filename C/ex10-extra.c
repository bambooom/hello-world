#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("ERROR: You need one argyment.\n");
    // this is how you abort a program
    return 1;
  }

  int i  = 0;
  char* res = argv[1];
  // if write as `char first_name[] = argv[1]`, will get error: array initializer must be an initializer list or string literal
  // C seems need to know the size when initializing array
  // but using `char* res` can do initializing without knowing the size

  for (i = 0; argv[1][i] != '\0'; i++) {
    char letter = argv[1][i];

    switch (letter) {
      case 'A':
        res[i] = 'a';
        break;
      case 'B':
        res[i] = 'A';
        break;
      case 'C':
        res[i] = 'c';
        break;
      case 'D':
        res[i] = 'd';
        break;
      case 'E':
        res[i] = 'e';
        break;
      case 'F':
        res[i] = 'f';
        break;
      case 'G':
        res[i] = 'g';
        break;
      default:
        break;
    }
    // until here, only transformed A-G to a-g, not filter out
  }

  printf("%s\n", res);
  return 0;
}
