#include <stdio.h>
#include "ex22.h"
#include "dbg.h"

int THE_SIZE = 1000;

static int THE_AGE = 37;
// kind of inverse of extern, variable only used in this .c file
// and should not be available to other parts of the program
// ** Keep in mind that static at the file level (as with THE_AGE here) is different than in other places

int get_age()
{
  return THE_AGE;
}

void set_age(int age)
{
  THE_AGE = age;
}

// If declare a variable in a function static, then that variable acts like a static defined in the file,
// but it's only accessible from that function.
// rarely used in modern C programming, hard ti use with threads
double update_ratio(double new_ratio)
{
  static double ratio = 1.0; // ratio is maintained between function calls

  double old_ratio = ratio;
  ratio = new_ratio;

  return old_ratio;
}

void print_size()
{
  log_info("I think size is: %d", THE_SIZE);
}
