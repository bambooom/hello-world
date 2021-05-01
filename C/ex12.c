// ex12: sizes and array, in C need to always care about sizeof

#include <stdio.h>

int main(int argc, char *argv[])
{
  // arrays of data is central, for now, using `type name[] = {initializer};` to create array
  // array in C holds a whole piece of memory, not slices with links (like in python?)

  int areas[] = { 10, 12, 13, 14, 20 };
  char name[] = "Zed";
  char full_name[] = {
    'Z', 'e', 'd',
    ' ', 'A', '.', ' ',
    'S', 'h', 'a', 'w', '\0' // if no last '\0', it will get some garbage chunk
  };
  // to C, name and full_name are identical methods of creating a char array

  // sizeof() -> how big things are in *bytes*
  // > C is all about the size and location of pieces of memory, and what you do with them.

  // Warning: On some systems may need to change %ld in this code
  // to a %u since it will use unsigned ints
  areas[0] = name[1];

  printf("The size of an int: %ld\n", sizeof(int)); // can put an data type in sizeof()
  // on my Mac, above result is 4, which means an int is 4 bytes in size, 32-bit CPU
  printf("The size of areas (int []): %ld\n", sizeof(areas));
  // 4 * 5 = 20 bytes
  printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));
  printf("The first area is %d, the 2nd %d.\n", areas[0], areas[1]);

  printf("The size of a char: %ld\n", sizeof(char)); // -> 1
  printf("The size of name (char[]): %ld\n", sizeof(name)); // -> 4, last nul byte, won't be printed out
  printf("The number of chars: %ld\n", sizeof(name) / sizeof(char));

  printf("The size of full_name (char[]): %ld\n", sizeof(full_name)); // -> 12
  printf("The number of chars: %ld\n", sizeof(full_name) / sizeof(char));

  printf("name=\"%s\" and full_name =\"%s\"\n", name, full_name);

  return 0;
}
