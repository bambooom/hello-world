#include "ex22.h"
#include "dbg.h"

const char *MY_NAME = "Zed A. Shaw";

void scope_demo(int count)
{
  log_info("count is: %d", count);

  if (count > 10) { // new scope block, another `count` variable, not the same as outter one
    int count = 100;  // BAD! Bugs! // local to this block

    log_info("count in this scope is %d", count); // 100 here
  }

  log_info("count is at exit: %d", count);

  count = 3000;

  log_info("count after assign: %d", count); // 3000, not impact the caller's version of variable
}

int main(int argc, char *argv[])
{
  // test out THE_AGE accessors
  log_info("My name: %s, age: %d", MY_NAME, get_age()); // Zed A. Shaw, 37

  set_age(100);

  log_info("My age is now: %d", get_age()); // 100

  // test out THE_SIZE extern
  log_info("THE_SIZE is: %d", THE_SIZE); // 1000
  print_size(); // 1000

  THE_SIZE = 9;

  log_info("THE_SIZE is now %d", THE_SIZE); // 9
  print_size(); // 9, actually changing in that file

  // test the ratio function static, `ratio` inside update_ratio is maintained between function calls
  log_info("Ratio at first: %f", update_ratio(2.0)); // 1.000000
  log_info("Ratio again: %f", update_ratio(10.0)); // 2.000000
  log_info("Ratio once more: %f", update_ratio(300.0)); // 10.000000

  // test the scope demo
  int count = 4;
  scope_demo(count); // 4, 4, 3000
  scope_demo(count * 20); // 80, 100(in if scope), 80, 3000

  log_info("count after calling scope_demo: %d", count); // 4, change inside function not affecting outter count

  return 0;
}
