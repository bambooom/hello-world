// TODO: Fix the compiler error by moving the whole definition of this macro.
// macro definition needs to be before its call
macro_rules! my_macro {
    () => {
        println!("Check out my macro!");
    };
}
fn main() {
    my_macro!();
}
