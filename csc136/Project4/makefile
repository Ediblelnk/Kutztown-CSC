DEBUG=-g

all: etest lltest

lltest: LLtest.o Employee.o 
	g++ -o lltest LLtest.o Employee.o $(DEBUG)

LLtest.o: LLtest.cpp Employee.h LinkedList.h LListIter.h
	g++ -c LLtest.cpp $(DEBUG)

Employee.o: Employee.cpp Employee.h
	g++ -c Employee.cpp $(DEBUG)

# stand alone Employee test
etest: etest.o Employee.o 
	g++ -o etest etest.o Employee.o $(DEBUG)

etest.o: etest.cpp Employee.h
	g++ -c etest.cpp $(DEBUG)

# cleanup
clean:
	rm -f lltest etest *.o
