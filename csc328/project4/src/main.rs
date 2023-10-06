use core::panic;
use rand::prelude::*;
use rand::Rng;
use std::io::prelude::*;
use std::process::{exit, Command, Stdio};
use std::{env, process};

fn main() {
    let args: Vec<String> = env::args().collect();
    match args.len() {
        1 => parent(),
        2 => child(),
        x => panic!("Incorrect number of arguments. Expected 1 or 2, got {x}"),
    }
}

fn parent() {
    let mut child = match Command::new(r".\project4.exe")
        .arg("child")
        .stdin(Stdio::piped())
        .stdout(Stdio::piped())
        .spawn()
    {
        Err(why) => panic!("couldn't fork process: {}", why),
        Ok(child) => child,
    };

    let number = SmallRng::seed_from_u64(process::id() as u64).gen_range(1..100);
    let cpid = child.id();
    let mut stdin = child.stdin.take().unwrap();

    match stdin.write(&[number as u8]) {
        Err(why) => panic!("couldn't write to child: {}", why),
        Ok(_) => println!("Parent sent to pipe: {}", number),
    }

    println!("Parent ID: {}", process::id());

    exit(0);
}

fn child() {
    println!("Child process: {}", process::id())
}
