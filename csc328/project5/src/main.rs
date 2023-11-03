/**
 * Filename:	main.rs
 * Author:	    Schaefer, Peter
 * Assignment: 	Fall 2023, Project 5: Sockets (Client)
 * Course: 	    CSC 328 Network and Secure Programming
 * Professor:	Schwesinger
 */
use nix::sys::socket::*;
use std::env;
use std::os::fd::{AsRawFd, OwnedFd};

/**
 * Description: reads from the socket until the buffer is filled.
 * Parameters:  fd: &OwnedFd            :   the socket owned file descriptor read from.
 *              mut buffer: &mut [u8]   :   array of bytes used as a buffer
 * Returns:     returns the amount of bytes read
 */
fn read_packet(fd: &OwnedFd, mut buffer: &mut [u8]) -> usize {
    match recv(fd.as_raw_fd(), &mut buffer, MsgFlags::empty()) {
        Ok(bytes) => bytes,
        Err(why) => panic!("{}", why),
    }
}

/**
 * Description: in a loop: reads the socket for the size of the next packet.
 *              if the read returns zero, then the loop breaks.
 *              if the next packed exists, it is read and printed to stdout.
 * Parameters:  fd: &OwnedFd    :   the owned file descriptor of the socket
 */
fn socket_loop(fd: &OwnedFd) {
    println!("RECEIVED FROM SOCKET:\n");
    loop {
        let mut buffer = [0; u16::MAX as usize];

        // reads the buffer for the size of the next packet
        match read_packet(&fd, &mut buffer[0..2]) {
            0 => break, // connection was closed
            2 => {
                // there is data to be read, decode how many bytes the packet is
                let n = u16::from_be_bytes([buffer[0], buffer[1]]) as usize;
                // read the packet (containing a word)
                read_packet(&fd, &mut buffer[0..n]);
                //print out the data
                println!("{}", String::from_utf8_lossy(&buffer));
            }
            _ => panic!("Read an unexpected packet size!"), // edge case, possible if socket broke while sending
        }
    }
}

/**
 * Description: takes the raw string input for the host, and converts it into a vector that represents and IPv4 address.
 * Parameters:  host: &str  :   the raw host string
 */
fn parse_host(host: &str) -> Vec<u8> {
    host.split(".")
        .map(|x| match x.parse::<u8>() {
            Ok(x) => x,
            Err(_) => panic!("ERROR: received invalid IPv4 format:\n\tUse format u8.u8.u8.u8"),
        })
        .collect()
}

/**
 * Description: takes the raw string input for the port, and converts it into a u16
 * Parameters:  port: &str  :   the raw port string
 */
fn parse_port(port: &str) -> u16 {
    let port = match port.parse::<u16>() {
        Ok(x) => x,
        Err(_) => panic!("ERROR: received invalid port format:\n\tUse a valid u16 range"),
    };

    if port < 10000 {
        panic!("ERROR: received invalid port number:\n\tUse a port number between 10000 and 65535")
    }

    port
}

/**
 * Description: main program. takes exactly 2 command line arguments.
 *              demonstrates connecting to a socket and reading from a socket.
 *              uses the provided host and port and connects to the socked via a server
 * Arguments:   <host>  :   an IPv4 address
 *              <port>  :   a port number between 10000 and 65535
 */
fn main() {
    // collect arguments
    let args: Vec<String> = env::args().collect();

    // ensure the proper number of arguments to program.
    // if not, then error and prompt usage
    if args.len() != 3 {
        panic!("USAGE:\n\t./client <host: IPv4 address> <port>");
    }

    // get host and port based on arguments
    let host: Vec<u8> = parse_host(&args[1]);
    let port: u16 = parse_port(&args[2]);
    let address: SockaddrIn = SockaddrIn::new(host[0], host[1], host[2], host[3], port);

    // create socket file descriptor
    let fd: OwnedFd = match socket(
        AddressFamily::Inet,
        SockType::Stream,
        SockFlag::empty(),
        None,
    ) {
        Ok(fd) => fd,
        Err(why) => panic!("{}", why),
    };

    // connect to socket in IPv4 and port number
    match connect(fd.as_raw_fd(), &address) {
        Ok(()) => println!("INFO: Socket is connected to {}\n", address),
        Err(why) => panic!("{}", why),
    }

    // parse and decode until end of connection
    socket_loop(&fd);

    // graceful shutdown
    match shutdown(fd.as_raw_fd(), Shutdown::Both) {
        Ok(()) => println!("\nINFO: Socket has shutdown."),
        Err(why) => panic!("{}", why),
    };
}
