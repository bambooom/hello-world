> This directory contains the exercises and notes for learning Rust via [100 Exercises To Learn Rust](https://rust-exercises.com/100-exercises/)

All exercises are from the [`main` branch of the GitHub repository](https://github.com/mainmatter/100-exercises-to-learn-rust).

All solutions are in the [`solutions` branch of the GitHub repository](https://github.com/mainmatter/100-exercises-to-learn-rust/tree/solutions).

## Preparation

- [Install Rust](https://rust-lang.org/tools/install/)
- [Install rust-analyzer extension for VSCode](https://marketplace.visualstudio.com/items?itemName=rust-lang.rust-analyzer)
- [Install workshop runner `wr` to help to verify your solutions](https://mainmatter.github.io/rust-workshop-runner/)

I'm on MacOS, so I just use the following command to install Rust:

```sh
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

Rust is installed and managed by the `rustup` tool.

Use `rustup update` to update Rust installation.
Use `rustup self uninstall` to uninstall Rust.
Use `rustc --version` to check installed Rust version.

## Syntax

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

Rust is a **statically typed language**.
Every single value in Rust has a type and that type must be known to the compiler at compile-time.
