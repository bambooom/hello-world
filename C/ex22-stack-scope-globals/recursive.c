#include "dbg.h"

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

  scope_demo(count); // this is recursice, but won't cause stack overflow
}

int main()
{
  int count = 0;
  scope_demo(count);
  return 0;
}
