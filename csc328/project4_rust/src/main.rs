use rand::prelude::*;
use rand::Rng;
use std::io::prelude::*;
use std::process::{Command, Stdio};
use std::{env, process};

fn main() {
    // depending on the amount of arguments, either be a child or a parent
    let args: Vec<String> = env::args().collect();
    match args.len() {
        1 => parent(),
        2 => child(),
        x => panic!("Incorrect number of arguments. Expected 1 or 2, got {}", x),
    }
}

fn parent() {
    let mut child = match Command::new(r".\project4.exe")
        .arg("a")
        .stdin(Stdio::piped())
        .stdout(Stdio::piped())
        .spawn()
    {
        Err(why) => panic!("couldn't fork process: {}", why),
        Ok(child) => child,
    };

    let number = SmallRng::seed_from_u64(process::id() as u64).gen_range(1..100);
    let cpid = child.id();
    let mut inhandle = child.stdin.take().unwrap();

    println!("Parent ID: {}", process::id());

    match inhandle.write(number.to_string().as_bytes()) {
        Err(why) => panic!("PARENT couldn't write to child: {}", why),
        Ok(_) => println!("Parent sending to pipe: {}", number),
    }
    inhandle.flush().unwrap();

    let mut s = String::new();
    match child.stdout.unwrap().read_to_string(&mut s) {
        Err(why) => panic!("PARENT couldn't read to string: {}", why),
        Ok(bytes) => println!("PARENT read {} bytes from buffer", bytes),
    }

    // match inhandle.write((number * cpid).to_string().as_bytes()) {
    //     Err(why) => panic!("PARENT couldn't write to child: {}", why),
    //     Ok(_) => println!("Parent sending to pipe: {}", number),
    // }

    println!("{:?}", s);
    // exit(0);
}

fn child() {
    let mut s = String::new();
    match std::io::stdin().read_line(&mut s) {
        Err(why) => panic!("CHILD couldn't read to string: {}", why),
        Ok(bytes) => println!("CHILD read {} bytes from buffer", bytes),
    };

    println!("CHILD RECEIVED: {}", s);

    match std::io::stdin().read_line(&mut s) {
        Err(why) => panic!("CHILD couldn't read to string: {}", why),
        Ok(bytes) => println!("CHILD read {} bytes from buffer", bytes),
    };
}
