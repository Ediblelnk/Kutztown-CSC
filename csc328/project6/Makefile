all: server target/debug/server

server: target/debug/server
	cp target/debug/server server

target/debug/server: src/main.rs
	cargo build

.PHONY: clean
clean:
	cargo clean
	rm server

.PHONY: submit
submit:
	~schwesin/bin/submit csc328 project6