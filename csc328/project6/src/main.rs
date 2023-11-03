use rand::random;
use std::{
    env,
    io::Write,
    iter::Iterator,
    net::{TcpListener, TcpStream},
    process,
};

const ERR: i32 = -1;

fn main() {
    let words: Vec<&str> = "the quick brown fox jumps over the lazy dog is an english language pangram a sentence that contains all the letter of the alphabet the phrase is commonly used for touch typing practice testing typewriters and computer keyboards displaying examples of fonts and other applications involving text where the use of all letter in the alphabet is used"
        .split(" ")
        .collect();

    ctrlc::set_handler(move || println!("Recieved Ctrl+C!")).expect("Error setting Ctrl+C handler");

    let args: Vec<String> = env::args().collect();

    if args.len() != 2 {
        eprintln!("USAGE: ./server <port>\n\t[where 10000 < port < 65535]");
        process::exit(ERR);
    }

    let port: i32 = args[1].trim().parse().unwrap_or_else(|why| {
        eprintln!("ERROR: {why}");
        process::exit(ERR);
    });

    let listener: TcpListener =
        TcpListener::bind(format!("localhost:{port}")).unwrap_or_else(|why| {
            eprintln!("ERROR: {why}");
            process::exit(ERR);
        });

    println!(
        "INFO: Server started on address {:?}",
        listener.local_addr().unwrap()
    );
    println!("INFO: Listening for connections...");

    for stream in listener.incoming() {
        match stream {
            Ok(mut s) => {
                println!("INFO: Got a connection from {:?}", s.peer_addr().unwrap());
                send_words(&mut s, &words);
            }
            Err(why) => {
                eprintln!("ERROR: {why}");
                process::exit(ERR);
            }
        }
    }
}

fn send_words(s: &mut TcpStream, word_bank: &Vec<&str>) {
    for _ in 0..(1 + random::<u8>() % 10) {
        let word = word_bank[random::<usize>() % word_bank.len()];
        s.write_all(&(word.len() as u16).to_be_bytes()).unwrap();
        s.write_all(word.as_bytes()).unwrap();
    }
}
