// ex14: writing and using functions

#include <stdio.h>
#include <ctype.h> // can access to isalpha and isblank

// forward declarations
// it makes declarations of functions first, and define those functions later
// so that this function can be used anywhere in this file
// do not need to care about the function define order
// if not declared first, you must write functions in the order of appearance
// and sometimes if calling in circle, ordering functions not working
int can_print_it(char ch);
void print_letters(char arg[]);
// > help C out by telling it ahead of time if you’re going to use functions
// > it hasn’t encountered yet in the file. That’s what the forward declarations do.

void print_arguments(int argc, char *argv[])
{
  int i = 0;

  for (i = 0; i < argc; i++) {
    print_letters(argv[i]); // will define this function later
    // if not declared before, will cause error warning: implicit declaraction
  }
}

void print_letters(char arg[])
{
  int i = 0;
  for (i = 0; arg[i] != '\0'; i++) {
    char ch = arg[i];

    if (can_print_it(ch)) {
      printf("'%c' == %d ", ch, ch); // convert character to ASCII key code
    }
  }

  printf("\n");
}

int can_print_it(char ch)
{
  return isalpha((int)ch) || isblank((int)ch);
  // isalpha belong to standard c library (libc, -lc)
  // test a character whether it's alphabetic (lower or upper case both ok)
  // syntax like: `isalpha(int c);` need to convert to int, based on ASCII code
  // returns zero if a character not alphabetic

  // isblank same as isalpha
  // test a character whether it's space or tab character, `\t` or ` `
  // returns zero if false
}

// main function typically is put in the end of the file
int main(int argc, char *argv[])
{
  print_arguments(argc + 1, argv);
  // if add + 1 to argc, there will be segmentation fault
  // can try to use lldb (on MacOS) to debug
  // `run` and `thread backtrace` to find where segfault started and ended in line of file
  return 0;
}
