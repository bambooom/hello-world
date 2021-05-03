// ex15: pointers, dreaded pointers

#include <stdio.h>

int main(int argc, char *argv[])
{
  // create two arrays we care about
  int ages[] = { 23, 43, 12, 89, 2 }; // like an container, one solid block memory
  char *names[] = {
    "Alan", "Frank",
    "Mary", "John", "Lisa"
  }; // names are array of character pointers, each point to a string

  // safely get the size of ages
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  // first way using indexing
  for (i = 0; i < count; i++) {
    printf("%s has %d years alive.\n", names[i], ages[i]);
  }

  printf("---\n");

  // setup the pointers to the start of the arrays
  int *cur_age = ages;
  char **cur_name = names; // two level of pointer

  // second way using pointers
  for (i = 0; i < count; i++) {
    printf("%d: %p: %s has %d years old.\n", i, cur_name + i, // cur_name+i print out the real address
      *(cur_name + i), *(cur_age +i));
    // use * means get me the value, not commonly used
  }

  int height = 100;
  int *cur_height = &height; // & means get the address of height

  cur_height++; // pointers are just integers, large intergers

  printf("---\n");

  // third way, pointers are just arrays
  for (i = 0; i < count; i++) {
    printf("%s has %d years old again.\n", cur_name[i], cur_age[i]);
    // pretend they are just arrays, modern ways
  }

  printf("---\n");

  // 4th way with pointers om a stupid complex way
  // if need code very fast
  for (cur_name = names, cur_age = ages;
        (cur_age - ages) < count; cur_name++, cur_age++) {
    printf("%s lived %d years so far.\n", *cur_name, *cur_age);
  }

  return 0;
}
