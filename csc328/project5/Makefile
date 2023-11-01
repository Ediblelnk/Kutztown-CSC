all: client target/debug/client

client: target/debug/client
	cp target/debug/client client

target/debug/client: src/main.rs
	cargo build

.PHONY: clean
clean:
	cargo clean
	rm client

.PHONY: submit
submit:
	~schwesin/bin/submit csc328 project5
