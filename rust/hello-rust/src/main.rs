use std::io;

fn main() {
    let mut name = String::new();
    let _ = io::stdin().read_line ( &mut name );
    println! ( "Hello, {}!", name );
    println! ("idk")
}
