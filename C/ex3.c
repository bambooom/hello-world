#include <stdio.h>

int main(int argc, char *argv[])
{
  int age = 10;
  // if not initialed age value like: `int age;`
  // later when it's used, it may be treadted as 0
  int height = 72;

  printf("I am %d years old.\n", age);
  // if remove `age` above and compile it will generate warnings
  // but you can still run `./ex3`, and you may get result like:
  // - I am 1511226408 years old.
  // or
  // - I am -452264160 years old.

  // you can always get some result, not like other language, python or javascript
  // they will exit and say that there are errors
  // and in c, anytime you see junk, see weird value, it's memory

  // to do the debugging, run `lldb ./ex3`
  // it will enter a lldb debugging proces

  // (lldb) target create "./ex3"
  // Current executable set to '/Users/mn/Project/hello-world/c/ex3' (x86_64).
  // (lldb) run
  // Process 9115 launched: '/Users/mn/Project/hello-world/c/ex3' (x86_64)
  // I am -272634336 years old.
  // I am 72 inches tall.
  // Process 9115 exited with status = 0 (0x00000000)
  // (lldb)

  printf("I am %d inches tall.\n", height);

  return 0;
}
