// TODO: implement a multi-threaded version of the `sum` function
//  using `spawn` and `join`.
//  Given a vector of integers, split the vector into two halves and
//  sum each half in a separate thread.

// Caveat: We can't test *how* the function is implemented,
// we can only verify that it produces the correct result.
// You _could_ pass this test by just returning `v.iter().sum()`,
// but that would defeat the purpose of the exercise.
//
// Hint: you won't be able to get the spawned threads to _borrow_
// slices of the vector directly. You'll need to allocate new
// vectors for each half of the original vector. We'll see why
// this is necessary in the next exercise.
use std::thread;

pub fn sum(v: Vec<i32>) -> i32 {
    let mid = v.len() / 2;
    let (left, right) = v.split_at(mid); // find the middle of the vector and split it into two halves
    let left = left.to_vec(); // to_vec() creates a new vector that owns the data
    let right = right.to_vec(); // left, right type changed

    // create 2 threads to calculate sum separately
    let left_sum = thread::spawn(move || left.into_iter().sum::<i32>());
    // `move` is needed to move the ownership of left into the closure
    // || is a closure with no arguments
    // `into_iter()` converts the vector into an iterator that takes ownership of the data
    // `sum()` takes the iterator and returns the sum
    let right_sum = thread::spawn(move || right.into_iter().sum::<i32>());

    left_sum.join().unwrap() + right_sum.join().unwrap()
    // wait for the threads to finish and get the result
}

// The whole process
// start：
// v: Vec<i32> [1, 2, 3, 4, 5, 6]
//     │
//     ▼
// split_at(3)
//     │
//     ├─> left: &[i32] [1, 2, 3]  (borrow)
//     └─> right: &[i32] [4, 5, 6] (borrow)
//     │
//     ▼
// to_vec()
//     │
//     ├─> left: Vec<i32> [1, 2, 3]  (new copy with ownership)
//     └─> right: Vec<i32> [4, 5, 6] (new copy with ownership)
//     │
//     ▼
// move left, right into the closure
//     │
//     ├─> left thread owns [1, 2, 3]
//     └─> right thread owns [4, 5, 6]



#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn empty() {
        assert_eq!(sum(vec![]), 0);
    }

    #[test]
    fn one() {
        assert_eq!(sum(vec![1]), 1);
    }

    #[test]
    fn five() {
        assert_eq!(sum(vec![1, 2, 3, 4, 5]), 15);
    }

    #[test]
    fn nine() {
        assert_eq!(sum(vec![1, 2, 3, 4, 5, 6, 7, 8, 9]), 45);
    }

    #[test]
    fn ten() {
        assert_eq!(sum(vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10]), 55);
    }
}
