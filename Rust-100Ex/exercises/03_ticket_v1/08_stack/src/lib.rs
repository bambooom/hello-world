// You can verify how much space a type would take on the stack using the std::mem::size_of function.
//
// assert_eq!(std::mem::size_of::<u8>(), 1);
//  a u8 is 8 bits long, or 1 byte

// TODO: based on what you learned in this section, replace `todo!()` with
//  the correct **stack size** for the respective type.
#[cfg(test)]
mod tests {
    use std::mem::size_of;

    #[test]
    fn u16_size() {
        assert_eq!(size_of::<u16>(), 2);
    }

    #[test]
    fn i32_size() {
        assert_eq!(size_of::<i32>(), 4);
    }

    #[test]
    fn bool_size() {
        assert_eq!(size_of::<bool>(), 1); // use single byte to store bool
    }
}
