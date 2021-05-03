// ex14-extra

#include <stdio.h>
#include <ctype.h>
#include <string.h> // to use strlen

void print_letters(char arg[]);

void print_arguments(int argc, char *argv[])
{
  int i = 0;

  for (i = 0; i < argc; i++) {
    print_letters(argv[i]); // will define this function later
  }
}

void print_letters(char arg[])
{
  int i = 0;
  int len = strlen(arg);
  for (i = 0; i < len; i++) { // no need to rely on '\0' terminator
    char ch = arg[i];

    if (isalpha((int)ch) || isblank((int)ch)) {
      printf("'%c' == %d ", ch, ch); // convert character to ASCII key code
    }
  }

  printf("\n");
}

// main function typically is put in the end of the file
int main(int argc, char *argv[])
{
  print_arguments(argc, argv);
  return 0;
}
