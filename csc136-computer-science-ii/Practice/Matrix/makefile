testMatrix: testMatrix.o Matrix.o
	g++ -o testMatrix testMatrix.o Matrix.o

testMatrix.o: testMatrix.cpp Matrix.h
	g++ -c testMatrix.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ -c Matrix.cpp

clean:
	rm testMatrix *.o
