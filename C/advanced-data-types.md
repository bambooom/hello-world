## Data Types
- `int` : An integer data type, default 32 bits in size
- `double` : A large floating point data type.
- `float` : A smaller floating point data type.
- `char` : single 1 byte character
- `void` : Declare a data type empty. a function return nothing, or pointer has no type as `void *thing`
- `enum` : Define a set of `int` constants.

## Type Modifiers
- `unsigned` : doesn't have negative numbers, larger upper bound but nothing lower than 0
- `signed` : include both negative and position numbers, half the upper bound
- `long` : larger storage, bigger numbers
- `short` : smaller storage, takes half the space

## Type Qualifiers
- `const` : Make a variable unmodifiable, value won't change after initialized
- `volatile` : compiler should leave this alone and not do any optimizations to it
- `register` : Declare a variable be stored in a CPU register. Forces the compiler to keep this variable in a register. Often compiler is better at figuring out where to put variables. Do this only if assuring an improvement in speed.

## Type Conversion
C do stepped type promotion, promotes smaller side to match larger side of an expression. Order like:
- long double
- double
- float
- int (but only `char` and `short int`)
- long

Use explicit casting operations to make it exactly what you want. eg:
```c
long + char - int * double
```
casts to:
```c
(double)long - (double)char - (double)int * double
```

Always promote up, not down. Don't cast `long` into `char` unless you know what you're doing.

## Type Sizes
`stdint.h` defines a set of exact sized integer types

- `int8_t` 8-bit signed integer
- `uint8_t` 8-bit unsigned integer
- `int16_t` 16-bit signed integer
- `uint16_t` 16-bit unsigned integer
- `int32_t` 32-bit signed integer
- `uint32_t` 32-bit unsigned integer
- `int64_t` 64-bit signed integer
- `uint64_t` 64-bit unsigned integer

The following N can be 8, 16, 32, 64
- `INT(N)_MAX` Maximum positive number of the signed integer of bits (N), such as INT16_MAX.
- `INT(N)_MIN` Minimum negative number of signed integer of bits (N).
- `UINT(N)_MAX` Maximum positive number of unsigned integer of bits (N). Since it's unsigned, the minimum is 0 and can't have a negative value.

Many other macros and typedefs in `stdint.h`


Todo:
- read `stdint.h` write out all the available size identifiers
- create a program that prints out examples of each type
