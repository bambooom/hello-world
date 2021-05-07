// ex17: heap and stack memory allocation

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// use C preprocessor (CPP) to create constant settings, reliable ways
#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
  int id;
  int set;
  char name[MAX_DATA]; // fixed in size
  char email[MAX_DATA];
};

struct Database {
  struct Address rows[MAX_ROWS]; // not pointer, will be 100 Address, fixed size
};

struct Connection {
  FILE *file;
  struct Database *db;
};

// die: used to kill and exit the program with an error
void die(const char *message)
{
  // set external variable error for error return from a function
  if (errno) {
    // the print the error message
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  exit(1);
}

void Address_print(struct Address *addr)
{
  printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

// FILE functions: fopen, fread, fclose, rewind, works on FILE struct, defined in C standard lib

void Database_load(struct Connection *conn)
{
  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1)
    die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode)
{
  // anytime call malloc, it's heap, others are stack or similar, care about malloc first
  struct Connection *conn = malloc(sizeof(struct Connection)); // will be large
  if (!conn)
    die("Memory error");

  // allocating large data on the heap
  conn->db = malloc(sizeof(struct Database));
  if (!conn->db)
    die("Memory error");

  if(mode == 'c') {
    conn->file = fopen(filename, "w");
  } else {
    conn->file = fopen(filename, "r+"); // need r+, otherwise, cannot write

    if (conn -> file) {
      Database_load(conn);
    }
  }

  // NULL is 0, so boolean works, NULL will evaluate to false
  if (!conn->file)
    die("Failed to open the file");

  return conn;
}

void Database_close(struct Connection *conn)
{
  if (conn) {
    if (conn->file)
      fclose(conn->file);
    if (conn->db)
      free(conn->db);
    free(conn);
  }
}

void Database_write(struct Connection *conn)
{
  rewind(conn->file);

  int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1)
    die("Failed to write databse");

  rc = fflush(conn-> file);
  if (rc == -1)
    die("Cannot flush databse.");
}

void Database_create(struct Connection *conn)
{
  int i = 0;
  // it's on stack, no pointers
  for (i = 0; i < MAX_ROWS; i++) {
    // make a protortype to initialize it
    struct Address addr = {.id = i, .set = 0};
    // then just assign it
    conn->db->rows[i] = addr;
  }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
  // "get the i element of rows, which is in db, which is in conn, then get the address of (&) it"
  struct Address *addr = &conn->db->rows[id];
  if (addr->set) {
    printf("%d, %s %s\n", id, addr->name, addr->email);
    die("Already set, delete it first");
  }

  addr->set = 1;

  // WARNING: bug here
  char *res = strncpy(addr->name, name, MAX_DATA);
  // demonstrate the strncpy bug
  if (!res)
    die("Name copy failed");

  res = strncpy(addr->email, email, MAX_DATA);
  if (!res)
    die("Email copy failed");
}

void Database_get(struct Connection *conn, int id)
{
  struct Address *addr = &conn->db->rows[id];

  if (addr->set) {
    Address_print(addr);
  } else {
    die("ID is not set");
  }
}

void Database_delete(struct Connection *conn, int id)
{
  // temporary local Address, initializing its id and set fields,
  // and then simply copying it into the rows array by assigning it to the element I want
  // this makes sure that all fields except set and id are initialized to zeros
  // shouldn't use `memcpy` to do these kind of struct copying operations
  struct Address addr = {.id = id, .set = 0};
  conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
  int i = 0;
  struct Database *db = conn->db;

  for (i = 0; i < MAX_ROWS; i++) {
    struct Address *cur = &db->rows[i];

    if (cur->set) {
      Address_print(cur);
    }
  }
}

int main(int argc, char *argv[])
{
  if (argc < 3)
    die("USAGE: ex17 <dbfile> <action> [action params]");

  char *filename = argv[1];
  char action = argv[2][0];
  struct Connection *conn = Database_open(filename, action);
  int id = 0;

  if (argc > 3) id = atoi(argv[3]); // `atoi` convert string to int
  if (id >= MAX_ROWS) die("There's not that many records.");

  switch (action) {
    case 'c':
      Database_create(conn);
      Database_write(conn);
      break;

    case 'g':
      if (argc != 4)
        die("Need an id to get");

      Database_get(conn, id);
      break;

    case 's':
      if (argc != 6)
        die("Need id, name, email to set");

      Database_set(conn, id, argv[4], argv[5]);
      Database_write(conn);
      break;

    case 'd':
      if (argc != 4)
        die("Need id to delete");

      Database_delete(conn, id);
      Database_write(conn);
      break;

    case 'l':
      Database_list(conn);
      break;

    default:
      die("Invalid action: c=create, g=get, s=set, d=del, l=list");
  }

  Database_close(conn);
  return 0;
}
