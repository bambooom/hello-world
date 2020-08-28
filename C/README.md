> This directory just contains the exercises and notes when I'm learning the
learn-c-the-hard-way course.

## Beginning
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
$ ./ex0
Hello!
```
