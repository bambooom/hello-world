#ifndef _ex22_h
#define _ex22_h

// makes THE_SIZE in ex22.c available to other .c files
extern int THE_SIZE;
// extern tell compiler the variable exists but in another external location
// one .c file is going to use a variable that's been defined in another .c file
// here ex22.c has a variable THE_SIZE that will be accessed from ex22_main.c.
// ----
// if not adding `extern` keyword, the script can still be working
// but if entire declaration is missing, error "undeclared identifier" THE_SIZE

// gets and sets an internal static variable in ex22.c
int get_age();
void set_age(int age);

// updates a static variable that's inside update_ratio
double update_ratio(double ratio);

void print_size();

#endif
