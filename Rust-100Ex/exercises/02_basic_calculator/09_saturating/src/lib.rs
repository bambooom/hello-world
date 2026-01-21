// overflow-checks is global setting, sometimes need different operations based on the context
//
// opt into wrapping arithmetic on a per-operation basis by using the `wrapping_` methods
//
// let x = 255u8;
// let y = 1u8;
// let sum = x.wrapping_add(y);
// assert_eq!(sum, 0);
//
// opt into saturating arithmetic by using the `saturating_` methods
// Instead of wrapping around, saturating arithmetic will return the maximum or minimum value for the integer type.
//
// let x = 255u8;
// let y = 1u8;
// let sum = x.saturating_add(y);
// assert_eq!(sum, 255);
//            ⬆️ 255 + 1 = 256, but 256 is bigger than the u8::MAX, the result is u8::MAX (255)


pub fn factorial(n: u32) -> u32 {
    let mut result: u32 = 1;
    for i in 1..=n {
        // Use saturating multiplication to stop at the maximum value of u32
        // rather than overflowing and wrapping around
        result = result.saturating_mul(i);
    }
    result
}

#[cfg(test)]
mod tests {
    use crate::factorial;

    #[test]
    fn twentieth() {
        assert_eq!(factorial(20), u32::MAX);
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
