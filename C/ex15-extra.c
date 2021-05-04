// Rewrite ex15.c to use a function for each of the ways of printing out things

#include <stdio.h>

void first(char *names[], int ages[], int count)
{
  int i = 0;
  for (i = 0; i < count; i++) {
    printf("%s has %d years alive.\n", names[i], ages[i]);
  }

  printf("---\n");
}

void second(char **cur_name, int *cur_age, int count)
{
  int i = 0;
  for (i = 0; i < count; i++) {
    printf("%d: %p: %s has %d years old.\n", i, cur_name + i, // cur_name+i print out the real address
      *(cur_name + i), *(cur_age +i));
  }
  printf("---\n");
}

void third(char **cur_name, int *cur_age, int count)
{
  int i = 0;
  for (i = 0; i < count; i++) {
    printf("%s has %d years old again.\n", cur_name[i], cur_age[i]);
  }

  printf("---\n");
}

void fourth(char *names[], int ages[], int count)
{
  int *cur_age = ages;
  char **cur_name = names;

  for (cur_name = names, cur_age = ages;
        (cur_age - ages) < count; cur_name++, cur_age++) {
    printf("%p, %p: %s lived %d years so far.\n", cur_name, cur_age,  *cur_name, *cur_age);
  }

  printf("---\n");
}

int main(int argc, char *argv[])
{
  int ages[] = { 23, 43, 12, 89, 2 };
  char *names[] = {
    "Alan", "Frank",
    "Mary", "John", "Lisa"
  };

  int count = sizeof(ages) / sizeof(int);

  first(names, ages, count);

  int *cur_age = ages;
  char **cur_name = names;
  second(cur_name, cur_age, count);
  third(cur_name, cur_age, count);
  fourth(names, ages, count);
}
