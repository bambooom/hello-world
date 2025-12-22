// TODO: this is an example of an orphan rule violation.
//  We're implementing a foreign trait (`PartialEq`, from `std`) on
//  a foreign type (`u32`, from `std`).
//  Look at the compiler error to get familiar with what it looks like.
//  Then delete the code below and move on to the next exercise.

// impl PartialEq for u32 {
//     fn eq(&self, _other: &Self) -> bool {
//         todo!()
//     }
// }

/*
error[E0117]: only traits defined in the current crate can be implemented for primitive types
            --> exercises/04_traits/02_orphan_rule/src/lib.rs:7:1
            |
          7 | impl PartialEq for u32 {
            | ^^^^^---------^^^^^---
            |      |             |
            |      |             `u32` is not defined in the current crate
            |      `u32` is not defined in the current crate
            |
        = note: impl doesn't have any local type before any uncovered type parameters
        = note: for more information see https://doc.rust-lang.org/reference/items/implementations.html#orphan-rules
        = note: define and implement a trait or new type instead
*/
