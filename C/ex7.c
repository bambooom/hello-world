// ex7: variables and types

#include <stdio.h>

int main(int argc, char *argv[])
{
  int distance = 100;
  float power = 2.345f; // f indicate float
  double super_power = 56789.4532; // float is smaller than double
  char initial = 'A'; // char is only 1 character
  char first_name[] = "Zed"; // char xx[] is the string
  char last_name[] = "Shaw";

  printf("You are %d miles away.\n", distance); // 100, %d output integer
  printf("You have %f levels of power.\n", power); // 2.345000, %f output floating number
  printf("You have %f awesome super powers.\n", super_power); // 56789.453200
  printf("I have an initial %c.\n", initial); // A, just character
  printf("I have a first name %s.\n", first_name); // the string
  printf("I have a last name %s.\n", last_name);
  printf("My whole name is %s %c. %s.\n", first_name, initial, last_name); //  Zed A. Shaw

  int bugs = 100;
  double bug_rate = 1.2;

  printf("You have %d bugs at the imaginary rate of %f.\n", bugs, bug_rate);
  // 100, 1.200000

  long universe_of_defects = 1L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L * 8L;
  // really long large number
  // the above number is too big, overflow
  // warning: overflow in expression; result is -9223372036854775808 with type 'long'
  // when overflow, the result is go to negative
  printf("The entire universe has %ld bugs.\n", universe_of_defects);

  unsigned long universe_of_defects_unsigned = 2 * 1024 * 1024 * 1024;
  //  warning: overflow in expression; result is -2147483648 with type 'int'
  printf("Try big unsigned long: %ld.\n", universe_of_defects_unsigned);

  double expected_bugs = bugs * bug_rate;
  printf("You are expected to have %f bugs.\n", expected_bugs);
  // convert to floating 120.000000

  double part_of_universe = expected_bugs / universe_of_defects;
  printf("That is only a %e portion of the universe.\n", part_of_universe);
  // 1.117587e-07

  // this makes no sense, just a memo of something weird
  char nul_byte = '\0'; // this indicates a null byte
  int care_percentage = bugs * nul_byte;
  printf("Which means you should care %d%%.\n", care_percentage);
  // %% output the percentage literally,if only one %, compilation error => warning: invalid conversion specifier '\x0a'
  // -> 0%
  printf("Try to print nul_byte with %%d: %d.\n", nul_byte); // 0
  // printf("Try to print nul_byte with %%s: %s.\n", nul_byte);
  // ↑ compilation error: warning: format specifies type 'char *' but the argument has type 'char'
  printf("Try to print nul_byte with %%c: %c.\n", nul_byte); // just nothing?

  return 0;
}
