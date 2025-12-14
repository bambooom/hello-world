# Types

Rust is a **statically typed language**.
Every single value in Rust has a type and that type must be known to the compiler at compile-time.

## Primitive types

## Integers

- `u32`, unsigned 32-bit integer
  - unsigned integer can only represent non-negative numbers (i.e. 0 or greater)
  - signed integer can represent both positive and negative numbers (e.g. -1, 12, etc.)
- `i32`, signed 32-bit integer
- bit width: 8, 16, 32, 64, 128

  - u32 can represent numbers from 0 to 2^32 - 1 (`u32::MAX`)
  - i32 can represent numbers from -2^31 to 2^31 - 1 (`i32::MIN` to `i32::MAX`)

## Literals

- **Literals** is a notation for representing a fixed values in source code, e.g. `42`

  - Rust compiler will try to infer the type of a literal based on how it's used
  - default type for integer literals is `i32`
  - add suffix to specify type, e.g. `2u64` is a 2 that's explicitly typed as a `u64`
  - `1_000_000` is the same as `1000000`, add underscores to improve readability of large numbers

## Arithmetic operators

- Precedence and associativity rules for arithmetic operators are the same as in mathematics.
- The division operator / performs integer division when used with integer types.
  - I.e. the result is truncated towards zero. For example, 5 / 2 is 2, not 2.5.
- **No automatic type coercion**, even if the conversion is lossless, need to do it explicitly
  - some exceptions, mostly related to references, smart pointers and ergonomics, covered later

## Floating-Point Types

> https://doc.rust-lang.org/book/ch03-02-data-types.html#floating-point-types

- denoted like `f32`, `f64`, default typ is `f64`
- All floating-point types are signed

```rust
fn main() {
    let x = 2.0; // f64

    let y: f32 = 3.0; // f32
}
```

## Declare variables

```rust
// let <variable_name>: <type> = <expression>;
let x: u32 = 42;

// type inference
let y = 42;
let z: u32 = y;
// compiler infers the type of y to be u32
```

### Function arguments

`greeting` has no input parameters and returns a reference to a string slice (`&'static str`).

```rust
// `fn` <function_name> ( <input params> ) -> <return_type> { <body> }
fn greeting() -> &'static str {
    // TODO: fix me 👇
    "I'm ready to __!"
}
```

```rust
// Spelling out the unit return type explicitly
//                   👇
fn test_welcome() -> () {
    assert_eq!(greeting(), "I'm ready to learn Rust!");
}

// return type can be omitted if it doesn't return anything
fn test_welcome() {
    assert_eq!(greeting(), "I'm ready to learn Rust!");
}
```

```rust
// better to omit return keywork when possible
fn greeting() -> &'static str {
    // This is the last expression in the function
    // Therefore its value is returned by `greeting`
    "I'm ready to learn Rust!"
}

// can also use `return` keyword
fn greeting() -> &'static str {
    // Notice the semicolon at the end of the line!
    return "I'm ready to learn Rust!";
}
```

```rust
// An input parameter, type &str (a string slice)
//        👇
fn greet(name: &str) -> String {
    format!("Hello, {}!", name)
}
```

## Booleans

if/else if/else

```rust
let number = 3;

if number < 5 {
    println!("`number` is smaller than 5");
} else if number >= 3 {
    println!("`number` is greater than or equal to 3, but smaller than 5");
} else {
    println!("`number` is smaller than 3");
}
```

```rust
let number = 3;
if number {
    // ERROR here: If the condition is not a boolean, you'll get a compilation error
    println!("`number` is not zero");
}
```

In Rust, if expressions are expressions, not statements: they return a value.
That value can be assigned to a variable or used in other expressions.
Like ternary operator in JS.

```rust
let number = 3;
let message = if number < 5 {
    "smaller than 5"
} else {
    "greater than or equal to 5"
};
// message is now "smaller than 5"
```

## Range

```rust
let mut sum = 0;
for i in 1..=5 {
    sum += i;
}
```

5 kinds of ranges in Rust:

- `1..5`: A (half-open) range. It includes all numbers from 1 to 4. It doesn't include the last value, 5.
- `1..=5`: An inclusive range. It includes all numbers from 1 to 5. It includes the last value, 5.
- `1..`: An open-ended range. It includes all numbers from 1 to infinity (well, until the maximum value of the integer type).
- `..5`: A range that starts at the minimum value for the integer type and ends at 4. It doesn't include the last value, 5.
- `..=5`: A range that starts at the minimum value for the integer type and ends at 5. It includes the last value, 5.

```rust
let end = 5;
let mut sum = 0;

for i in 1..(end + 1) {
    sum += i;
}
```
