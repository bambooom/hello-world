// TODO: Fix the compiler error without taking the macro definition out of this
// module.
#[macro_use] // need to add this attribute to the module to make the macro available in the current scope
mod macros {
    macro_rules! my_macro {
        () => {
            println!("Check out my macro!");
        };
    }
}

fn main() {
    // use the macro from the module
    // use macros::my_macro;

    my_macro!();
}
