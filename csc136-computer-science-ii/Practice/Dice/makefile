singleDie: singleDie.o Die.o
	g++ -o singleDie singleDie.o Die.o

singleDie.o: singleDie.cpp Die.h
	g++ -c singleDie.cpp

Die.o: Die.cpp Die.h
	g++ -c Die.cpp

clean:
	rm singleDie *.o
