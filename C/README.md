> This directory just contains the exercises and notes when I'm learning the
learn-c-the-hard-way course.

## Preparation
As I'm currently using macOS Catalina, and I previously installed and run Xcode, so no other preparation needed.

```sh
$ gcc
clang: error: no input files
$ cc
clang: error: no input files
$ cc --version
Apple clang version 11.0.3 (clang-1103.0.32.62)
Target: x86_64-apple-darwin19.6.0
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
