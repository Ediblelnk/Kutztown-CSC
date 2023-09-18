debug=-g

Competition: Competition.o AustralianShepherd.o Dog.o
	g++ -o Competition Competition.o AustralianShepherd.o Dog.o $(debug)

Competition.o: Competition.cpp AustralianShepherd.h
	g++ -c Competition.cpp $(debug)

AustralianShepherd.o: AustralianShepherd.cpp AustralianShepherd.h
	g++ -c AustralianShepherd.cpp $(debug)

Dog.o: Dog.cpp Dog.h
	g++ -c Dog.cpp $(debug)

clean:
	rm *.o Competition