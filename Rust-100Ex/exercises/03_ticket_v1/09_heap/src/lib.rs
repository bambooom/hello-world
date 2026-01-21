// usize type: an unsigned integer that's as big as the number of bytes needed to address memory on your machine.
// On a 32-bit machine, usize is equivalent to u32. On a 64-bit machine, it matches u64.

// std::mem::size_of returns the amount of space a type would take on the stack, which is also known as the size of the type.
// Unfortunately there is no equivalent of std::mem::size_of to measure the amount of heap memory that a certain value is allocating at runtime. Some types might provide methods to inspect their heap usage (e.g. String's capacity method),
// but there is no general-purpose "API" to retrieve runtime heap usage in Rust.

pub struct Ticket {
    title: String,
    description: String,
    status: String,
}

// TODO: based on what you learned in this section, replace `todo!()` with
//  the correct **stack size** for the respective type.
#[cfg(test)]
mod tests {
    use super::Ticket;
    use std::mem::size_of;

    #[test]
    fn string_size() {
        // contains a pointer to the heap, a length, and a capacity
        // usally pointer size is *mut u8, which is 8 bytes
        // length and capacity are both usize, which is 8 bytes under 64-bit machine, u64 is 8 bytes
        assert_eq!(size_of::<String>(), 24);
    }

    #[test]
    fn ticket_size() {
        // This is a tricky question!
        // The "intuitive" answer happens to be the correct answer this time,
        // but, in general, the memory layout of structs is a more complex topic.
        // If you're curious, check out the "Type layout" section of The Rust Reference
        // https://doc.rust-lang.org/reference/type-layout.html for more information.
        assert_eq!(size_of::<Ticket>(), 72);
    }
}
