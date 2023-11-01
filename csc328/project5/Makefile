all: project5 target/debug/project5

project5: target/debug/project5
	cp target/debug/project5 project5

target/debug/project5: src/main.rs
	cargo build

.PHONY: clean
clean:
	cargo clean
	rm project5

.PHONY: submit
submit:
	~schwesin/bin/submit csc328 project5
