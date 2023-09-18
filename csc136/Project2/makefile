debugFlag=-g

states: State.o states.o 
	g++ -o states states.o State.o $(debugFlag)

states.o: states.cpp  State.h
	g++ -c states.cpp $(debugFlag)

State.o: State.cpp State.h 
	g++ -c State.cpp $(debugFlag)

clean: 
	/bin/rm -f *.o states

