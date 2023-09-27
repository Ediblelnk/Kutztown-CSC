all: project3

project3: project3.c
	gcc project3.c -o project3 -lpthread

.PHONY: clean
clean:
	rm project3

.PHONY: submit
submit:
	~schwesin/bin/submit csc328 project3
