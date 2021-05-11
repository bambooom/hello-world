// ex18: pointers to functions
// main use of this is to pass callbacks to other functions, or to simulate classes and objects

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die from ex17. */
void die(const char *message)
{
  if (errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  exit(1);
}

// a typedef creates a fake type, in this case for a function pointer
// create a pointer to a function, later use `compare_cb` as a type
typedef int (*compare_cb) (int a, int b);

/**
 * A classic bubble sort function that uses the compare_cb to do the sorting.
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
  int temp = 0;
  int i = 0;
  int j = 0;
  int *target = malloc(count * sizeof(int));

  if (!target)
    die("Memory error.");

  memcpy(target, numbers, count * sizeof(int));

  for (i = 0; i < count; i++) {
    for (j = 0; j < count - 1; j++) {
      // use cmp callback like it's a normal function, it's just a pointer to it
      if (cmp(target[j], target[j + 1]) > 0) {
        temp = target[j + 1];
        target[j + 1] = target[j];
        target[j] = temp;
      }
    }
  }

  return target;
}

int sorted_order(int a, int b)
{
  return (a > b) - (a < b);
}

int reverse_order(int a, int b)
{
  return (a < b) - (a > b);
}

int strange_order(int a, int b)
{
  if (a == 0 || b == 0) {
    return 0;
  } else {
    return a % b;
  }
}

/**
 * Used to test that we are sorting things correctly by doing the sort and printing it out
 */
void test_sorting(int *numbers, int count, compare_cb cmp)
{
  int i = 0;
  int *sorted = bubble_sort(numbers, count, cmp);

  if (!sorted)
    die("Failed to sort as requested.");

  for (i = 0; i < count; i++) {
    printf("%d ", sorted[i]);
  }
  printf("\n");

  free(sorted);
}

void dump(compare_cb cmp)
{
  int i = 0;
  // this is like converting your function cmp to a string, and print out first 25 bytes
  unsigned char *data = (unsigned char *)cmp;
  for (i = 0; i < 25; i++) {
    printf("%02x:", data[i]);
  }
  printf("\n");
}

void destroy(compare_cb cmp)
{
  int i = 0;
  unsigned char *data = (unsigned char *)cmp;
  for (i = 0; i < 25; i++) {
    data[i] = i;
    // this is trying to override the executable code
    // which should cause bus error, as OS should protect executable code
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  if (argc < 2) die("USAGE: ex18 4 3 1 5 6");

  int count = argc - 1;
  int i = 0;
  char **inputs = argv + 1; //??

  int *numbers = malloc(count * sizeof(int));
  if (!numbers) die("Memory error.");

  for (i = 0; i < count; i++) {
    numbers[i] = atoi(inputs[i]);
  }

  test_sorting(numbers, count, sorted_order);
  test_sorting(numbers, count, reverse_order);
  test_sorting(numbers, count, strange_order);
  // 1. pass wrong function
  test_sorting(numbers, count, die);
  // will output warning:  incompatible function pointer types passing 'void (const char *)' to parameter of type 'compare_cb' (aka 'int (*)(int, int)')
  // compiler compares function's type and return

  // 2. pass NULL
  test_sorting(numbers, count, NULL);
  // won't have any compiler error
  // but run with segfault
  // debugger lldb show EXC_BAD_ACCESS

  free(numbers);

  printf("SORTED: ");
  dump(sorted_order);
  // this will print something like: 55:48:89:e5:89:7d:fc:89:75:f8:8b:45:fc:3b:45:f8:0f:9f:c1:80:e1:01:0f:b6:c1:
  // they are raw assembler byte code of the function itself
  // on Mac, can use an app called Hex Find to open ex18 to find the above sequence

  destroy(sorted_order); // debug this in ex20

  printf("REVERSE: ");
  dump(reverse_order); // beginning is same as the above, but should has different endings

  return 0;
}
