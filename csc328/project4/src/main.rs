use std::io::prelude::*;
use std::process::Command;
use rand::Rng;

fn main() {
    let mut rng = rand::thread_rng();
    println!("Random Integer: {}", rng.gen_range(1..100));
}
