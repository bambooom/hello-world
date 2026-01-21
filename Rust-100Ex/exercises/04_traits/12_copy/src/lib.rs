// TODO: implement the necessary traits to make the test compile and pass.
//  You *can't* modify the test.

#[derive(Copy, Clone, Debug, PartialEq)]
pub struct WrappingU32 {
    value: u32,
}

impl WrappingU32 {
    pub fn new(value: u32) -> Self {
        Self { value }
    }
}

// Error: implementation of `Add` might be missing for `WrappingU32`

// need to implement std::ops::Add, which is the `+`

impl std::ops::Add for WrappingU32 {
    type Output = Self;

    fn add(self, rhs: Self) -> Self::Output {
        // return a new instance of WrappingU32
        // self.value which is u32 instance
        // and using the wrapping_add method to add two u32 values
        Self::new(self.value.wrapping_add(rhs.value))
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_ops() {
        let x = WrappingU32::new(42);
        let y = WrappingU32::new(31);
        let z = WrappingU32::new(u32::MAX);
        assert_eq!(x + y + y + z, WrappingU32::new(103));
    }
}
