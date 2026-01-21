// module is a way to group related code together, under a common namespace
//
// inline modules:
// #[cfg(test)]
// mod tests {
//     // [...]
// }
//
// crate, root module
//
// mod dog;
// -> If your module is declared in the root of your crate (e.g. src/lib.rs or src/main.rs), cargo expects the file to be named either:
//      src/<module_name>.rs
//      src/<module_name>/mod.rs
//
// importing like:
// use crate::module_1::module_2::MyStruct;

// // Now you can refer to `MyStruct` directly
// fn a_function(s: MyStruct) {
//      // [...]
// }
//
// star import: discouraged generally
// use crate::module_1::module_2::*;




// use crate::Ticket; <- wrong

mod helpers {
    // TODO: Make this code compile, either by adding a `use` statement or by using
    //  the appropriate path to refer to the `Ticket` struct.

    // use crate::Ticket;
    use super::Ticket; // only need to super to parent module, no need crate

    fn create_todo_ticket(title: String, description: String) -> Ticket {
        Ticket::new(title, description, "To-Do".into())
    }
}

struct Ticket {
    title: String,
    description: String,
    status: String,
}

impl Ticket {
    fn new(title: String, description: String, status: String) -> Ticket {
        if title.is_empty() {
            panic!("Title cannot be empty");
        }
        if title.len() > 50 {
            panic!("Title cannot be longer than 50 bytes");
        }
        if description.is_empty() {
            panic!("Description cannot be empty");
        }
        if description.len() > 500 {
            panic!("Description cannot be longer than 500 bytes");
        }
        if status != "To-Do" && status != "In Progress" && status != "Done" {
            panic!("Only `To-Do`, `In Progress`, and `Done` statuses are allowed");
        }

        Ticket {
            title,
            description,
            status,
        }
    }
}
