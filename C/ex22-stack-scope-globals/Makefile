CFLAGS=-Wall -g -DNDEBUG

all: clean target

target: ex22.o ex22_main

ex22.o:
	cc $(CFLAGS) -c -o ex22.o -c ex22.c

ex22_main:
	cc $(CFLAGS) ex22_main.c ex22.o -o ex22_main

clean:
	rm -f ex22.o ex22_main
