[resource](https://en.wikipedia.org/wiki/Transmission_Control_Protocol)

![[csc328/notes/assets/img1.png]]

**Source port**: 16 bits, identifies the sending port
**Destination port**: 16 bits, identifies the receiving port

>	Use bit shifting to decode and encode endian-ness

1. Make a socket, connect it to a host and a port
2. Use a 5 digit port number
3. Kill server before exiting terminal, do not create servers running forever

[beej's guide to network programming](https://beej.us/guide/bgnet/)

[sockets by example](https://www.cs.brandeis.edu/~cs146a/rust/rustbyexample-02-21-2015/sockets.html)

