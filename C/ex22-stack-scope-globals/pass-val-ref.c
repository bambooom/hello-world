#include "dbg.h"

//pass by value
void increment(int count)
{
  count = count + 1;
  log_info("count inside increment function is %d", count);
}

//pass by ref
void incrementRef(int *count)
{
  *count = *count + 1;
  log_info("count inside incrementRef function is %d", *count);
}

int main() {
  int count = 0;
  log_info("count before pass by value function: %d", count);
  increment(count);
  log_info("count after pass by value function: %d", count);

  count = 0;
  log_info("count before pass by ref function: %d", count);
  incrementRef(&count);
  log_info("count after pass by ref function: %d", count);
  return 0;
}
