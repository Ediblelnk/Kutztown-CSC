all: target/debug/project4.exe

target/debug/project4.exe: src/main.rs
	cargo build
	cp target/debug/project4.exe project4.exe

.PHONY: clean
clean:
	cargo clean
	rm project4.exe

.PHONY: submit
submit:
	~schwesin/bin/submit csc328 project4
