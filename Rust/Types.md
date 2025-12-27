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

## Conversions

You can use the as operator to convert between integer types.
`as` conversions are infallible.

```rust
let a: u32 = 10;

// Cast `a` into the `u64` type
let b = a as u64;

// You can use `_` as the target type
// if it can be correctly inferred
// by the compiler. For example:
let c: u64 = a as _;
```

```rust
// A number that's too big
// to fit into a `u8`
let a: u16 = 255 + 1;
let b = a as u8;

// will perform truncation, Rust compiler will keep the last 8 bits of a u16 memory representation:
// 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 -> 0 0 0 0 0 0 0 0  (last 8 bits)
// Hence 256 as u8 is equal to 0. That's... not ideal, in most scenarios.
// In fact, the Rust compiler will actively try to stop you if it sees you trying to cast a literal value which will result in a truncation:
```

Use it exclusively for going from a smaller type to a larger type. To convert from a larger to smaller integer type, rely on the fallible conversion machinery

Reference: https://doc.rust-lang.org/reference/expressions/operator-expr.html#numeric-cast

## Strings

> https://doc.rust-lang.org/std/string/struct.String.html

## Structs

like class or object in other languages

```rust
struct Ticket {
    title: String,
    description: String,
    status: String
}

// Syntax: <StructName> { <field_name>: <value>, ... }
let ticket = Ticket {
    title: "Build a ticket system".into(),
    description: "A Kanban board".into(),
    status: "Open".into()
};

// Field access
let x = ticket.description;

// attach behaviour to structs by defining methods
impl Ticket {
    fn is_open(self) -> bool {
        // self as their first parameter
        // self is a keyword and represents the instance of the struct the method is being called on.
        self.status == "Open"
    }
}

// Syntax:
// impl <StructName> {
//    fn <method_name>(<parameters>) -> <return_type> {
//        // Method body
//    }
// }

// Method call syntax: <instance>.<method_name>(<parameters>)
let is_open = ticket.is_open();

// Static methods, doesn't take self as its first parameter
struct Configuration {
    version: u32,
    active: bool
}

impl Configuration {
    // `default` is a static method on `Configuration`
    fn default() -> Configuration {
        Configuration { version: 0, active: false }
    }
}

// Function call syntax: <StructName>::<method_name>(<parameters>)
let default_config = Configuration::default();

// use function call syntax for both:
// Function call syntax:
//   <StructName>::<method_name>(<instance>, <parameters>)
let is_open = Ticket::is_open(ticket);
// clear what is first parameter, prefer method call syntax when possible
```

## enum

An enumeration is a type that can have a fixed set of values, called variants.
In Rust, you define an enumeration using the enum keyword:

```rust
enum Status {
    ToDo,
    InProgress,
    Done,
}
```

match on it

```rust
enum Status {
    ToDo,
    InProgress,
    Done
}

impl Status {
    fn is_done(&self) -> bool {
        match self {
            Status::Done => true,
            // The `|` operator lets you match multiple patterns.
            // It reads as "either `Status::ToDo` or `Status::InProgress`".
            Status::InProgress | Status::ToDo => false
        }
    }
}
```

A `match` statement that lets you compare a Rust value against a series of **patterns**.
You can think of it as a type-level `if`.
If `status` is a `Done` variant, execute the first block;
if it's a `InProgress` or `ToDo` variant, execute the second block.
