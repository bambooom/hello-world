fn main() {
    let mut res = 42;
    let option = Some(12);
    // TODO: Fix the Clippy lint.
    if let Some(x) = option { // Use `if-let` instead of iteration.
        res += x;
    };

    println!("{res}");
}
