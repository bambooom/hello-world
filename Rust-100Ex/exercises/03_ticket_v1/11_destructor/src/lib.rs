// When the owner of a value goes out of scope, Rust invokes its destructor.
// The destructor tries to clean up the resources used by that value—in particular, whatever memory it allocated.
// You can manually invoke the destructor of a value by passing it to `std::mem::drop`.
// That's why you'll often hear Rust developers saying "that value has been dropped" as a way to state that a value has gone out of scope and its destructor has been invoked.

// fn main() {
//    let y = "Hello".to_string();
//    let x = "World".to_string();
//    let h = "!".to_string();
//    // Variables are dropped in reverse order of declaration
//    drop(h);
//    drop(x);
//    drop(y);
// }

// When you transfer ownership of a value to a function, you're also transferring the responsibility of cleaning it up.
// This ensures that the destructor for a value is called at most1 once, preventing double free bugs by design.s

// You can have multiple references to the same value—if we called the destructor for the value they point at when one of them goes out of scope, what would happen to the others?
// They would refer to a memory location that's no longer valid: a so-called dangling pointer, a close relative of use-after-free bugs. Rust's ownership system rules out these kinds of bugs by design.

// We need some more machinery to write a proper exercise for destructors.
// We'll pick the concept up again in a later chapter after covering traits and
// interior mutability.
fn outro() -> &'static str {
    "I have a basic understanding of destructors!"
}

#[cfg(test)]
mod tests {
    use crate::outro;

    #[test]
    fn test_outro() {
        assert_eq!(outro(), "I have a basic understanding of destructors!");
    }
}
