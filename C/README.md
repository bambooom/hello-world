> This directory just contains the exercises and notes when I'm learning the learn-c-the-hard-way course.

## Preparation
As I'm currently using macOS Catalina, and I previously installed and run Xcode, so no other preparation needed.

```sh
$ gcc
clang: error: no input files
$ cc
clang: error: no input files
$ cc --version
Apple clang version 12.0.5 (clang-1205.0.22.9)
Target: x86_64-apple-darwin20.3.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```

Quickly to check everything is prepared, just make a really simple C program, `ex0.c`:

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
  printf("Hello!\n");

  return 0;
}
```

And then do `make`:

```sh
$ make ex0
cc     ex0.c   -o ex0
# or use cc
$ cc ex0.c -o ex0

# then run it
$ ./ex0
Hello!
```

### Do not use IDE
The book said so, but for me it's kind of too hard to use unfamiliar editor.
I will stick to vscode for now.
Maybe I will try to use vim later as I'm really not good at it.

## Debugging intro (from ex4)
Use `gdb` on Linux, use `lldb` on OSX.
For more advanced tool, use `Valgrind` on Linux, use `AddressSanitizer` on OSX.

List the quick reference of `lldb` here since I only have OSX now.

- `run [args]` Start your program with `[args]`.
- `breakpoint set --name [file:]function` Set a break point at `[file:]function`. You can also use `b`, which is way easier.
- `thread backtrace` Dump a backtrace of the current calling stack. Shorthand is `bt`.
- `print expr` Print the value of expr. Shorthand is `p`.
- `continue` Continue running the program. Shorthand is `c`.
- `next` Next line, but step over function calls. Shorthand is `n`.
- `step` Next line, but step into function calls. Shorthand is `s`.
- `quit` Exit LLDB.
- `help` List the types of commands. You can then get help on the class of command as well as the command itself.
- `cd`, `pwd`, `make` just like running these commands in your shell.
- `shell` Quickly start a shell so you can do other things.
- `clear` Clear a breakpoint.
- `info break`, `info watch` Show information about breakpoints and watchpoints.
- `attach -p pid` Attach to a running process so you can debug it.
- `detach` Detach from the process.
- `list` List out the next ten source lines. Add a `-` to list the previous ten sources.


## Memorizing operators (ex5)
> only copy those operators I'm not familiar with here:

> https://www.tutorialspoint.com/cprogramming/c_operators.htm
### Logical Operators
- `&` bitwise and
- `|` bitwise or
- `^` bitwise xor
- `~` bitwise ones compliment
- `<<` bitwise shift left
- `>>` bitwise shift right

### Assignment Operators
- `<<=` assign shift-left-equal
- `>>=` assign shift-right-equal
- `&=` assign and-equal
- `^=` assign xor-equal
- `|=` assign or-equal

### Data Operators
- `sizeof()` get the size of
- `[]` array subscript
- `&` address of
- `*` value of
- `->` structure dereference
- `.` structure reference

## Memorizing syntax (ex6)
> The technical term for processing the symbols and keywords of a programming language is *lexical analysis*. The word for one of these symbols or keywords is a *lexeme*.

### Keywords
- `auto` : Give a local variable a local lifetime.
- `break` : Exit out of a compound statement.
- `case` : A branch in a switch-statement.
- `char` : Character data type.
- `const` : Make a variable unmodifiable.
- `continue` : Continue to the top of a loop.
- `default` : Default branch in a switch-statement.
- `do` : Start a do-while loop.
- `double` : A double floating point data type.
- `else` : An else branch of an if-statement.
- `enum` : Define a set of `int` constants.
- `extern` : Declare an identifier is defined externally.
- `float` : A floating point data type.
- `for` : Start a for-loop.
- `goto` : Jump to a label.
- `if` : Starts an if-statement.
- `int` : An integer data type.
- `long` : A long integer data type.
- `register` : Declare a variable be stored in a CPU register.
- `return` : Return from a function.
- `short` : A short integer data type.
- `signed` : A signed modifier for integer data types.
- `sizeof` : Determine the size of data.
- `static` : Preserve variable value after its scope exits.
- `struct` : Combine variables into a single record.
- `switch` : Start a switch-statement.
- `typedef` : Create a new type.
- `union` : Start a union-statement.
- `unsigned` : An unsigned modifier for integer data types.
- `void` : Declare a data type empty.
- `volatile` : Declare a variable might be modified elsewhere.
- `while` : Start a while-loop.

### syntax structure

```c
if (TEST) {
  CODE;
} else if (TEST) {
  CODE;
} else {
  CODE;
}
```

```c
switch (OPERAND) {
  case CONSTANT:
    CODE;
    break;
  default:
    CODE;
}
```

```c
while (TEST) {
  if (OTHER_TEST) {
    continue;
  }
  if (OTHER_TEST) {
    break;
  }
  CODE;
}

do {
  CODE;
} while (TEST);
```

```c
for (INIT; TEST; POST) {
  CODE;
}
```

```c
// An enum creates a set of integer constants:
enum { CONST1, CONST2, CONST3 } NAME;
```

```c
// A goto will jumpt to a label, and is only used
// in a few useful situations like error detection and exiting
if (ERROR_TEST) {
  goto fail;
}

fail:
  CODE;
```

```c
// define function
// int= return value type, name=function name
int name(arg1, arg2) {
  CODE;
  return 0;
}
```

```c
// typedef DEFINITION IDENTIFIER ;
// unsigned char = Definition, byte = Identifier
typedef unsigned char byte;
```

```c
// A struct is a packaging of many base data types into a single concept,
// which are used heavily in C. (seems like Object in JS)
// [VARIABLE_NAME] is optional
struct NAME {
  ELEMENTS ;
} [VARIABLE_NAME];

// often combine with typedef
typedef struct [STRUCT_NAME] {
  ELEMENTS ;
} IDENTIFIER ;

// `union` creates something like a `struct`, but the elements will overlap in memory.
// simply memorize the form for now
union NAME {
  ELEMENTS ;
} [VARIABLE_NAME] ;
```

## Data Types

> https://en.wikipedia.org/wiki/C_data_types

[Notes](./advanced-data-types.md)

## Function declaration: K&R vs ANSI syntax

> K&R syntax is obsolete, you can skip it unless you have to maintain very old code.

```c
// K&R syntax
int foo(a, p)
    int a;
    char *p;
{
    return 0;
}

// ANSI syntax
int foo(int a, char *p)
{
    return 0;
}
```
ref:
* [c - Function declaration: K&R vs ANSI](https://stackoverflow.com/questions/3092006/function-declaration-kr-vs-ansi)
* [Alternative (K&R) C syntax for function declaration versus prototypes](https://stackoverflow.com/questions/1630631/alternative-kr-c-syntax-for-function-declaration-versus-prototypes)
* [kr c - What are the major differences between ANSI C and K&R C?](https://stackoverflow.com/questions/22500/what-are-the-major-differences-between-ansi-c-and-kr-c)

## Pointers
> `ages[i]`:
> To C, `ages` is a location in the computer's memory where all of these integers start.
> It's also an address, and the C compiler will replace `ages` anywhere you type it with the address of the very first integer in `ages`.
> Another way to think of `ages` is that it's the "address of the first integer in `ages`".
> But here's the trick: `ages` is an address inside the entire computer.
> It's not like `i` that's just an address inside `ages`.
> The `ages` array name is actually an address in the computer.

> C thinks your whole computer is one massive array of bytes.
> Obviously, this isn't very useful, but then what C does is layer on top of this massive array of bytes the concept of *types* and *sizes* of those types.
> how C is doing the following with your arrays:
> - Creating a block of memory inside your computer
> - Pointing the name `ages` at the beginning of that block
> - Indexing into the block by taking the base address of `ages` and getting the element that's `i` away from there
> - Converting that address at `ages+i` into a valid `int` of the right size, such that the index works to return what you want: the int at index i

> A pointer is simply an address pointing somewhere inside the computer’s memory with a type specifier so that you get the right size of data with it.

> It’s kind of like a combination of ages and i rolled into one data type. C knows where pointers are pointing, knows the data type they point at, the size of those types, and how to get the data for you. Just like with i, you can increment, decrement, subtract, or add to them. But, just like ages, you can also get values out, put new values in, and use all of the array operations.

> A pointer gives you raw, direct access to a block of memory so you can work with it.

### Practical Pointer Usage
four primary useful things you can do with pointers in C code:
- Ask the OS for a chunk of memory and use a pointer to work with it. This includes strings
and `structs`.
- Pass large blocks of memory (like large `structs`) to functions with a pointer, so you don't
have to pass the whole thing to them.
- Take the address of a function, so you can use it as a dynamic callback.
- Scan complex chunks of memory, converting bytes off of a network socket into data structures or parsing files

Nowadays, compilers performance is good enough. So you should go with arrays anytime you can,
and then only use pointers as a performance optimization if you absolutely have to.

### Pointer Lexicon
- `type *ptr` A pointer of type named ptr
- `*ptr` The value of whatever ptr is pointed at
- `*(ptr + i)` The value of (whatever ptr is pointed at plus i)
- `&thing` The address of thing
- `type *ptr = &thing` A pointer of type named ptr set to the address of thing
- `ptr++` Increment where ptr points, all pointers are just integers, a very large one
- `ptr->elem` Use ptr to struct/union to get elem

### What doesn't work the same on pointers and arrays
- `sizeof(cur_age)` get the size of the pointer, not the size of what it points at.

## Heap vs Stack Allocation (from ex17)

C is using real CPU's actual machinery, that involves a chunk of RAM called the stack and heap.
The difference depends on where you get the storage.

The **heap** is all the remaining memory in computer, and you access it with `malloc` to get more.
Each time call `malloc`, OS uses internal functions to register that piece of memory to you,
and then returns a pointer to it. Need to `free` to return to OS.
Not doing `free` will cause memory leak.

The **stack** is special region of memory that stores temporary variables,
which each function creates as locals to that function.
Each argument to a function is pushed onto the stack and then used inside the function.
It's really a stack data structure, so the last thing in is the first thing out.
The advantage of using a stack for this is simply that when the function exits,
the C compiler pops these variables off of the stack to clean up, to prevent memory leaks.

> If you didn't get it from malloc, or a function that got it from malloc, then it's on the stack.

3 primary problems:
- If you get a block of memory from `malloc`, and have that pointer on the stack, then when the function exits the pointer will get popped off and lost.
- If you put too much data on the stack (like large structs and arrays), then you can cause a stack overflow and the program will abort. In this case, use the heap with `malloc`.
- If you take a pointer to something on the stack, and then pass or return it from your function, then the function receiving it will segmentation fault (segfault), because the actual data will get popped off and disappear. You'll be pointing at dead space.

when a program exits, the OS will clean up all of the resources for you, but sometimes not immediately.
A common idiom is to just abort and let the OS clean up on error.

## Pointers to Functions (from ex18)
```c
int (*POINTER_NAME)(int a, int b)
```

- Write normal function declaration: `int callme(int a, int b)`
- Wrap the function name with the pointer syntax: `int (*callme)(int a, int b)`
- Change the name to the pointer name: `int (*compare_cb)(int a, int b)`

Then the variable name of the pointer is `compare_cb`,
but you can use it like it's a function.

Also works even if the function pointer returns a pointer to something:
- Write it: `char *make_coolness(int awesome_levels)`
- Wrap it: `char *(*make_coolness)(int awesome_levels)`, wrap the name only, outer `*` indicates that its return value is pointer
- Rename it: `char *(*coolness_cb)(int awesome_levels)`

To pass the function pointer to another function as parameters, need to use `typedef`,
which is a C keyword for making new names for other more complex types.
So after this `typedef int (*compare_cb) (int a, int b);`,
use the name `compare_cb` like it's a type.

## Debug tactics (from ex20)
1. You can't debug code by just looking at it.
2. Repeat the bug with an automated tes.
3. Run the progream under a debugger and valgrind and lint.
4. Find the backtrace and print out all the variables on the path.
5. Once you fix it, add check() to prevent it.

enable core dump on MacOS:
- https://steipete.com/posts/how-to-macos-core-dump/
- https://stackoverflow.com/questions/9412156/how-to-generate-core-dumps-in-mac-os-x

## Rules to following realted to the stack (from ex22)
-> [here](./ex22-stack-scope-globals/README.md)

## I/O functions should look up (from ex24)
- fscanf
- fgets
- fopen
- freopen
- fdopen
- fclose
- fcloseall
- fgetpos
- fseek
- ftell
- rewind
- fprintf
- fwrite
- fread
