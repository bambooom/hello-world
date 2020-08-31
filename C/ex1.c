// `include` is like `import` in js, import a module into this file
// use *.h as header files
#include <stdio.h>

/* This is a comment. */
int main(int argc, char *argv[]) // main function need to return a `int`
// 2 arguments: `argc` is integer as argument count, an array of of character * strings (?) for arguments
{ // block
  int distance = 100; // variable declaration and assignment, syntax like `type name = value;`

  // this is also a cooment
  printf("You are %d miles away.\n", distance);
  /*
  try to break it by remove `distance` above like:
  printf("You are %d miles away.\n");

  if you still do `make ex1`
  compiler will output warnings like:

  ex1.c:14:20: warning: more '%' conversions than data arguments [-Wformat]
  printf("You are %d miles away.\n");
                  ~^
  1 warning generated.

  `man 3 printf` to read about this function
  */

  return 0; // gives OS the exit value
}
