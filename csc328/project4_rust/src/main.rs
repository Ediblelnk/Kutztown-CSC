use rand::prelude::*;
use rand::Error;
use rand::Rng;
use std::io::prelude::*;
use std::process::exit;
use std::process::{Command, Stdio};
use std::process::{ExitCode, ExitStatus};
use std::{env, process};

fn main() {
    // depending on the amount of arguments, either be a child or a parent
    let args: Vec<String> = env::args().collect();
    let result = match args.len() {
        1 => parent(),
        2 => child(),
        x => panic!("Incorrect number of arguments. Expected 1 or 2, got {}", x),
    };

    println!("{:?}", result);
}

fn parent() -> Result<ExitStatus, Error> {
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
    let mut outhandle = child.stdout.take().unwrap();

    println!("Parent ID: {}", process::id());

    match inhandle.write(number.to_string().as_bytes()) {
        Err(why) => panic!("PARENT couldn't write to child: {}", why),
        Ok(_) => println!("Parent sending to pipe: {}", number),
    }
    inhandle.flush().unwrap();
    println!("Parent sent");

    let mut s = Vec::new();
    match outhandle.read(&mut s) {
        Err(why) => panic!("PARENT couldn't read to string: {}", why),
        Ok(bytes) => println!("PARENT read {} bytes from buffer", bytes),
    }

    println!("Parent read");
    let result = child.wait();
    println!("Result of waiting {:?}", result);

    println!("{:?}", s);

    exit(0);
}

fn child() -> Result<ExitStatus, Error> {
    let mut s = String::new();
    match std::io::stdin().read_line(&mut s) {
        Err(why) => panic!("CHILD couldn't read to string: {}", why),
        Ok(bytes) => println!("CHILD read {} bytes from buffer", bytes),
    };

    println!("CHILD RECEIVED: {}", s);
    std::io::stdout().flush().unwrap();

    match std::io::stdin().read_line(&mut s) {
        Err(why) => panic!("CHILD couldn't read to string: {}", why),
        Ok(bytes) => println!("CHILD read {} bytes from buffer", bytes),
    };

    exit(0)
}
