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
  int *cur_age = ages; // create pointer to integer type of pointer
  // `char *` create a pointer to char, string is an array of chars
  char **cur_name = names; // create a pointer that points to names
  // `char *` is already a pointer to char => just a string
  // need two levels since names is 2-dimensional => need char ** for a pointer to (a pointer to char) type.

  // second way using pointers
  for (i = 0; i < count; i++) {
    printf("%d: %p: %s has %d years old.\n", i, cur_name + i, // cur_name+i print out the real address
      *(cur_name + i), *(cur_age +i));
    // use * means get me the value, not commonly used
    // *(cur_name + i) same as name[i]
  }

  int height = 100;
  int *cur_height = &height; // & means get the address of height

  cur_height++; // pointers are just integers, large intergers

  printf("---\n");

  // third way, pointers are just arrays
  for (i = 0; i < count; i++) {
    printf("%s has %d years old again.\n", cur_name[i], cur_age[i]);
    // pretend they are just arrays, modern ways
    // syntax to access an element of an array is the same for a pointer and an array.
  }

  printf("---\n");

  // 4th way with pointers om a stupid complex way, uses variaous pointer arithmetic methods
  // if need code very fast
  for (cur_name = names, cur_age = ages; // initialize by setting cur_name cur_age to the beginnning of names and ages
        (cur_age - ages) < count; cur_name++, cur_age++) { // test portion: compares the **distance** of the pointer cur_age from the start of ages
    printf("%p, %p: %s lived %d years so far.\n", cur_name, cur_age,  *cur_name, *cur_age);
    // The pointers cur_name and cur_age are now pointing at one element of the arrays that they work on
  }

  printf("---\n");
  // start at the end of arrays and go to beginning
  // for pointer to works in this loop, need to reset them to point to the beginning of the names and ages
  // as in the previous loop, they have been already moved to the end address of the arrays
  for (i = count - 1, cur_name = names, cur_age = ages; i >= 0; i--) {
    printf("%d: %s has %d years old again. %p, %p\n", i, names[i], ages[i], &names[i], &ages[i]); // this works
    printf("%d: %s has %d years old again.\n", i, cur_name[i], cur_age[i]);
    printf("%d: %s has %d years old again.\n", i, *(cur_name + i), *(cur_age + i));

  }

  return 0;
}
