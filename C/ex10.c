// ex10: switch statement

#include <stdio.h>

int main(int argc, char *argv[])
{
  // if (argc != 2) {
  //   printf("ERROR: You need one argyment.\n");
  //   // this is how you abort a program
  //   return 1; // return that’s not 0 indicates to the OS that the program had an error.
  // }

  int i = 0;
  int j = 1;
  char letter; // charater can initialize without any value? no warning here

  for (j = 1; j <= argc - 1; j ++) { // loop over arguments
    for (i = 0; letter = argv[j][i], letter != '\0'; i++) {
      // char letter = argv[1][i];
      // printf("%c\n", letter);

      switch (letter) {
        case 'a':
        case 'A':
          printf("%d: 'A'\n", i);
          break;

        case 'e':
        case 'E':
          printf("%d: 'E'\n", i);
          break;

        case 'i':
        case 'I':
          printf("%d: 'I'\n", i);
          break;

        case 'o':
        case 'O':
          printf("%d: 'O'\n", i);
          break;

        case 'u':
        case 'U':
          printf("%d: 'U'\n", i);
          break;

        case 'y':
        case 'Y':
          // why i > 2?
          if (i > 2) {
            // it's only sometimes Y
            printf("%d: 'Y'\n", i);
            // break;
          }
          break;

        default:
          printf("%d: %c is not a vowel\n", i, letter);
      }
    }
  }

  return 0;
}
