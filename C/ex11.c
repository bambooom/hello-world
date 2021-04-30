// ex11: arrays and strings

#include <stdio.h>

int main(int argc, char *argv[])
{
  int numbers[4] = { 0 }; // this actually fill out the array with 4 `0`
  char name[4] = { 'a' }; // string, only the first char is set to `a`, different with array
  // array will be filled with 0 after the first `a` in the initializer, so the string is correctly terminated by a '\0' character.

  // char name[4] = { 'a', 'a', 'a', 'a' };
  // ↑ if doing this when initializing, since no space for `\0` nul byte, it will print out rubbish

  // first print them out raw
  printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
  printf("name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]);
  printf("name: %s\n", name);

  // set up the numbers
  numbers[0] = 1;
  numbers[1] = 'x'; // if assign a character here, print %d converts a character to a integer, what's this integer from?
  numbers[2] = 3;
  numbers[3] = 'd';

  // set up the name
  name[0] = 'Z';
  name[1] = 'e';
  name[2] = 'd';
  name[3] = '\0'; // string in C need this nul byte to terminate,
  // if no nul byte is set, when print out, it will output rubbish, some random chunk when C hit nul byte

  // then print them out initialized
  printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
  printf("name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]); // if using %d to print out name[i], they really convert to some integer
  printf("name: %s\n", name); // C language doesn’t differentiate between a string and an array of characters

  // another way to use name, typically used, especially not known the string length
  // * actually means pointer, but seems no need to dive deep now
  char *another = "Zed";
  printf("another: %s\n", another);
  printf("another each: %c %c %c %c\n", another[0], another[1], another[2], another[3]);


  char *another2 = "Banana";
  another2[0] = 'C'; // this will cause runtime error: [1]    52394 bus error  ./ex11
  // seems that the character in thie string cannot be changed?

  printf("another2: %s\n", another2);

  return 0;
}

// interesting fact: good C code should avoid using C style stirngs

// extra: If an array of characters is 4 bytes long, and an integer is 4 bytes long, then can you treat
// the whole name array like it’s just an integer? Hint: memcpy
