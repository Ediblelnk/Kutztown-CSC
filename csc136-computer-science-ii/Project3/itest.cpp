/*
 Author:          Peter Schaefer
 Creation Date:   11/13/22
 Due Date:        11/15/22
 Course:          CSC136CP 010
 Professor Name:  Dr. Carelli
 Assignment:      Project #3
 Filename:        itest.cpp
 Purpose:         This file tests the operator definitions for
                  the Array<dataType> class.
 */
#include <iostream>
#include <iomanip>
#include <string>
#include "Array.h"

using namespace std;

template <typename dataType> 
void printArray(const Array<dataType> &);

int main()
{ 
  int array[]= { 1, 2, 3, 4 };
  cout << boolalpha; // for boolean testing

  // test default constructor : create iList1
  Array<int> iList1;
  cout << "Default Constructor" << endl; 
  printArray(iList1);

  // test constructor from array : uses array[] 
  cout << "Constructor from array:" << endl;
  Array<int> iList2(array, 6, 4);
  printArray(iList2);

  // test copy constructor : create iList3 as a copy of iList2
  cout << "Copy Constructor:" << endl;
  Array<int> iList3(iList2);
  printArray(iList3);

  // test += : object that is not at capacity
  cout << "Add an item (+= under capacity)" << endl;
  iList1 += 2;
  printArray(iList1);

  // test += : object that is "at" capacity [it really isn't]
  cout << "Add an item (+= at capacity)" << endl;
  iList2 += 20;
  printArray(iList2);

  // test [] : change the first value in iList1 to 6
  cout << "Test non-const [] operator (< numUsed)" << endl;
  iList1[0]= 6;
  // Output the Array.
  printArray(iList1);

  // test [] : change the third value in iList1 to 7
  cout << "Test non-const [] operator (> numUsed)" << endl;
  iList1[2]= 7;
  printArray(iList1);

  // test ++ : add empty item to iList1
  cout << "Add empty item using preincrement" << endl;
  printArray(++iList2);
  printArray(iList2);

  // test ++ : add empty item to iList1
  cout << "Add empty item using postincrement" << endl;
  printArray(iList2++);
  printArray(iList2);

  // test = : assign iList4 to iList1
  cout << "Assignment:" << endl;
  Array<int> iList4 = iList1;
  printArray(iList4);

  // test > : compare iList2 to iList1
  cout << "Test > operator:" << endl;
  cout << "  iList1 > iList1: " << (iList2 > iList1) << endl;
  cout << endl << endl;
  
  // test * : dereference iList1
  cout << "Test dereference operator" << endl;
  cout << "  *iList1: " << *iList1 << endl;
  cout << endl;

  return(0);
}

/*
 Function name:   printArray
 Description:     prints out information about an Array<dataType> object
 Parameters:      Array<dataType> &MyArray  -Array to be printed
*/
template <typename dataType> 
void printArray(const Array<dataType> &MyArray) { 
  cout << "  Capacity: " << MyArray.getCapacity() 
       << ", Elements in Use: " << MyArray.getNumUsed() << endl;
  cout << "  Contents: " << MyArray << endl;
  cout << endl;
}

