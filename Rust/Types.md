# Types

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
