// When the result of an arithmetic operation is bigger than the maximum value for a given integer type, we are talking about an integer overflow.
// you can reject the operation via `panic!`
// or you can wrap around, e.g.:
//  - If you do a wrapping addition between 1 and 255 (=u8::MAX), the result is 0 (=u8::MIN).
//  - If you're working with signed integers, the same principle applies. E.g. adding 1 to 127 (=i8::MAX) with wrapping will give you -128 (=i8::MIN).
//
// can choose to configure the profile setting:
// If `overflow-checks` is set to true, Rust will panic at runtime when an integer operation overflows.
// If `overflow-checks` is set to false, Rust will wrap around when an integer operation overflows.

// Cargo provides 4 built-in profiles: dev, release, test, and bench
// The dev profile is used every time you run cargo build, cargo run or cargo test. It's aimed at local development
// The release profile, instead, is optimized for runtime performance but incurs longer compilation times.
//
// By default, overflow-checks is set to:
// true for the dev profile
// false for the release profile

// Customize the `dev` profile to wrap around on overflow.
// Check Cargo's documentation to find out the right syntax:
// https://doc.rust-lang.org/cargo/reference/profiles.html
//
// For reasons that we'll explain later, the customization needs to be done in the `Cargo.toml`
// at the root of the repository, not in the `Cargo.toml` of the exercise.

pub fn factorial(n: u32) -> u32 {
    let mut result = 1;
    for i in 1..=n {
        result *= i;
    }
    result
}

#[cfg(test)]
mod tests {
    use crate::factorial;

    #[test]
    fn twentieth() {
        // 20! is 2432902008176640000, which is too large to fit in a u32
        // With the default dev profile, this will panic when you run `cargo test`
        // We want it to wrap around instead
        assert_eq!(factorial(20), 2_192_834_560);
        //                           ☝️
        // A large number literal using underscores to improve readability!
    }

    #[test]
    fn first() {
        assert_eq!(factorial(0), 1);
    }

    #[test]
    fn second() {
        assert_eq!(factorial(1), 1);
    }

    #[test]
    fn third() {
        assert_eq!(factorial(2), 2);
    }

    #[test]
    fn fifth() {
        assert_eq!(factorial(5), 120);
    }
}
