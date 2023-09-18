debug=-g

app: Application.o Cylindr1.o Circle1.o Point1.o
	g++ -o app Application.o Cylindr1.o Circle1.o Point1.o $(debug)

sApp: ShortApplication.o Cylindr1.o Circle1.o Point1.o
	g++ -o sApp ShortApplication.o Cylindr1.o Circle1.o Point1.o $(debug)

Application.o: Application.cpp Shape.h Point1.h Circle1.h Cylindr1.h
	g++ -c Application.cpp $(debug)

ShortApplication.o: ShortApplication.cpp Shape.h Point1.h Circle1.h Cylindr1.h
	g++ -c ShortApplication.cpp $(debug)

Cylindr1.o: Cylindr1.cpp Shape.h Point1.h Circle1.h Cylindr1.h
	g++ -c Cylindr1.cpp $(debug)

Circle1.o: Circle1.cpp Shape.h Point1.h Circle1.h 
	g++ -c Circle1.cpp $(debug)

Point1.o: Point1.cpp Shape.h Point1.h 
	g++ -c Point1.cpp $(debug)
	
clean:
	rm *.o sApp app
