cc=g++
debugFlag=-g

tree: BinarySearchTree.o Treetest.o 
	$(cc) -o tree Treetest.o BinarySearchTree.o $(debugFlag)

Treetest.o: Treetest.cpp  BinarySearchTree.h
	$(cc) -c Treetest.cpp $(debugFlag)

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h 
	$(cc) -c BinarySearchTree.cpp $(debugFlag)


clean: 
	\rm -f *.o tree    
