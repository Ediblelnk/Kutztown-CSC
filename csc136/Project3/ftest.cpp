/*
 Author:          Peter Schaefer
 Creation Date:   11/13/22
 Due Date:        11/15/22
 Course:          CSC136CP 010
 Professor Name:  Dr. Carelli
 Assignment:      Project #3
 Filename:        ftest.cpp
 Purpose:         This file tests the insertion operator and ensures
                  Array<dataType> works for floats
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

  // 1: create an empty Array object using a default constructor
  cout << "Default Constructor" << endl;
  Array<float> arr = Array<float>(3);

  // 2: output the empty object
  printArray(arr);
  
  // 3: test >> : add 3 items
  cout << "Add 3 items using input stream: " << endl;
  cin >> arr;

  // 4: output final object
  printArray(arr);

  return(0);
}

/*
 Function name:   printArray
 Description:     prints out information about an Array<dataType> object
 Parameters:      Array<dataType> &MyArray  -Array to be printed
*/
template <typename dataType> 
void printArray(const Array<dataType> &MyArray) { 
  cout << endl;
  cout << "Array Info:" << endl;
  cout << "  Capacity: " << MyArray.getCapacity() 
       << ", Elements in Use: " << MyArray.getNumUsed() << endl;
  cout << "  Contents: " << MyArray << endl;
  cout << endl;
}
