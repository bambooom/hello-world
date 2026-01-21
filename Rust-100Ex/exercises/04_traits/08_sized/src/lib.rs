pub fn example() {
    // Trying to get the size of a str (or any other DST)
    // via `std::mem::size_of` will result in a compile-time error.
    //
    // TODO: Comment out the following line and move on to the next exercise.
    // std::mem::size_of::<str>();
}

// str is a dynamically sized type (DST).
// A DST is a type whose size is not known at compile time.
// Whenever you have a reference to a DST, like &str, it has to include additional information about the data it points to. It is a fat pointer.
//
// str, as we just saw, is not Sized.
// &str is Sized though! We know its size at compile time: two usizes, one for the pointer and one for the length.

// so use std::mem::size_of::<str>() will give compile error

        // error[E0277]: the size for values of type `str` cannot be known at compilation time
        //    --> exercises/04_traits/08_sized/src/lib.rs:6:25
        //     |
        //   6 |     std::mem::size_of::<str>();
        //     |                         ^^^ doesn't have a size known at compile-time
        //     |
        //     = help: the trait `Sized` is not implemented for `str`
        // note: required by an implicit `Sized` bound in `std::mem::size_of`
        //    --> /Users/mn/.rustup/toolchains/stable-aarch64-apple-darwin/lib/rustlib/src/rust/library/core/src/mem/mod.rs:334:22
        //     |
        // 334 | pub const fn size_of<T>() -> usize {
        //     |                      ^ required by the implicit `Sized` requirement on this type parameter in `size_of`

        // For more information about this error, try `rustc --explain E0277`.
        // error: could not compile `sized` (lib) due to 1 previous error
        // error: could not compile `sized` (lib test) due to 1 previous error
