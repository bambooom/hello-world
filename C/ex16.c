// ex16: structs and pointers to them

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// it's like Object
struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
  // malloc: memory allocator, gives chunk of memory with size
  struct Person *who = malloc(sizeof(struct Person));
  assert(whi != NULL);

  // if not using ->, then need to deref who and use dot . to accsess name
  // (*who).name = strdup(name);
  who->name = strdup(name);
  who->age = age;
  who->height = height;
  who->weight = weight;

  return who;
}

void Person_destroy(struct Person *who)
{
  assert(who != NULL); // abort if who=NULL false
  free(who->name); // need to free memory by yourself
  free(who);
}

void Person_print(struct Person *who)
{
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
  // struct Person alice;
  // alice.name;
  // make two people structures
  struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
  struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

  // print them out and where they are in memory
  printf("Joe is at memory location %p:\n", joe);
  Person_print(joe);
  printf("Frank is at memory location %p: \n", frank);
  Person_print(frank);

  // make everyone age 20 years and print them again
  joe->age += 20;
  joe->height -= 2;
  joe->weight += 40;
  Person_print(joe);

  frank->age += 20;
  frank->weight += 20;
  Person_print(frank);

  // desctroy them bothe so we clean up
  Person_destroy(joe);
  // Person_destroy(NULL);
  Person_destroy(frank);

  return 0;
}
