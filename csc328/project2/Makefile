all: project2.o
	gcc -o project2 project2.o

project2.o: project2.c
	gcc -c project2.c

.PHONY: clean
clean:
	rm project2 project2.o

.PHONY: submit
submit:
	~schwesin/bin/submit csc328 project2
