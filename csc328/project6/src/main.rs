use nix::sys::socket::*;
use std::env;
use std::os::fd::{AsRawFd, OwnedFd};

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() != 2 {
        panic!("USAGE:\n\t./server <port>\n[where 10000 < port < 65535]");
    }
}
