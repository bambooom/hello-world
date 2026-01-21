// TODO: Define a function named `squared` that raises all `i32`s within a slice to the power of 2.
//  The slice should be modified in place.

// &mut keyword indicates that the function can modify the contents of the slice.
pub fn squared(slice: &mut [i32]) {
    // iter_mut() method returns an iterator that yields mutable references to each element in the slice.
    for i in slice.iter_mut() { // i is a mutable reference to an i32
        //  *i syntax is used to dereference the mutable reference and access the actual value of the element.
        *i *= *i; // dereference the mutable reference to get the value, and then modify the value
    }
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn empty() {
        let mut s = vec![];
        squared(&mut s);
        assert_eq!(s, vec![]);
    }

    #[test]
    fn one() {
        let mut s = [2];
        squared(&mut s);
        assert_eq!(s, [4]);
    }

    #[test]
    fn multiple() {
        let mut s = vec![2, 4];
        squared(&mut s);
        assert_eq!(s, vec![4, 16]);
    }
}
