# If

`if`, the most basic (but still surprisingly versatile!) type of control flow, is what you'll learn here.

## Further information

- [Control Flow - if expressions](https://doc.rust-lang.org/book/ch03-05-control-flow.html#if-expressions)

```rust
fn main() {
    let condition = true;
    let number = if condition { 5 } else { 6 };

    println!("The value of number is: {number}"); // 5
}
```

```rust
fn main() {
    let condition = true;

    let number = if condition { 5 } else { "six" };
    // this won't compile, as if and else block different data types

    println!("The value of number is: {number}");
}
```

```rust
fn main() {
    let mut counter = 0;

    let result = loop {
        counter += 1;

        if counter == 10 {
            break counter * 2;
        }
    };

    println!("The result is {result}");
}
```
