class: class.o MyClass.o
	g++ -o class class.o MyClass.o

class.o: class.cpp MyClass.h
	g++ -c class.cpp

MyClass.o: MyClass.cpp MyClass.h
	g++ -c MyClass.cpp

clean:
	rm class *.o