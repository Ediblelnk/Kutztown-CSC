
p1: p1.o WordData.o
	g++ -o p1 p1.o WordData.o

p1.o: p1.cpp WordData.h
	g++ -c p1.cpp

WordData.o: WordData.cpp WordData.h
	g++ -c WordData.cpp

sweep:
	rm *.o

clean:
	rm *.o p1
