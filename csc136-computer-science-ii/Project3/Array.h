/*
 Author:          Peter Schaefer
 Creation Date:   11/13/22
 Due Date:        11/15/22
 Course:          CSC136CP 010
 Professor Name:  Dr. Carelli
 Assignment:      Project #3
 Filename:        Array.h
 Purpose:         This file is a head/definition for an Array object.
                  It is special because it has num used and capacity,
		  which can be different to each other.
 */
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cassert>

using namespace std;

template <class dataType> 
class Array {
public:
  //constructors
  Array(int size= 3);
  Array(const Array&);
  Array(const dataType[], int, int);

  //deconstructor
  ~Array();

  //methods
  int getCapacity() const {return capacity;}
  int getNumUsed() const {return numUsed;}

  //operators
  const Array<dataType> &operator=(const Array &);
  Array<dataType> &operator+=(dataType);
  Array<dataType> &operator++(); // preincrement - add default to front
  Array<dataType> operator++(int); // postincrement - add default to front
  bool operator==(const Array &) const; // compare if equal
  bool operator>(const Array &) const; // just number used
  dataType &operator[](int); // l-value subscript operator
  const dataType &operator[](int) const; // r-value subscript operator
  dataType operator*() const; // dereference operator

private:
  //variables
  int capacity; // capacity of the array
  int numUsed; // number of elements in use
  dataType *ptr; // pointer to first element of array
};

/*
 Description:     creates an Array<dataType> object
 Parameters:      int size  -capacity of array
 Return Value:    Array<dataType>
*/ 
template <class dataType> 
Array<dataType>::Array(int size) {
  //give variables the proper values
  capacity = size;
  numUsed = 0;

  //give memory space for new array
  ptr = new dataType[capacity];
  assert( ptr != 0 ); //terminate if memory not allocated

  //initialize to default value
  for(int i = 0; i < capacity; ++i) ptr[i] = dataType();
}

/*
 Description:     creates an Array<dataType> object from an array
 Parameters:      dataType A[]  -array of dataTypes
                  int cap       -desired capacity of array
		  int num2copy  -number of elements to copy in array
 Return Value:    Array<dataType>
*/
template <class dataType>
Array<dataType>::Array(const dataType A[], int cap, int num2copy) {
  //make sure cap is larger than 0 and num2copy is smaller than cap
  assert(cap > 0 && num2copy <= cap);

  //set values for array
  numUsed = num2copy;
  capacity = cap;

  //give memory space for new array
  ptr = new dataType[capacity];
  assert(ptr);

  //copy over the values from A[] and initialize remaining to default
  for(int i = 0; i < numUsed; ++i) ptr[i] = A[i];
  for(int i = numUsed; i < capacity; i++) ptr[i] = dataType();
}

/*
 Description:     copy constructor for Array<dataType> object
 Parameters:      Array &A  -the array to be copied
 Return Value:    Array<dataType>
*/
template <class dataType> 
Array<dataType>::Array(const Array &A) {
  //set values for array
  numUsed = A.numUsed;
  capacity = A.capacity;

  //give memory space for new array
  ptr = new dataType[capacity];
  assert(ptr);

  //copy all values over to copy array
  for(int i = 0; i < capacity; i++) ptr[i] = A.ptr[i];
}

/*
 Description:     help to destroy an Array<dataType> object
 Return Value:    N/A
*/
template <class dataType> 
Array<dataType>::~Array() {
  delete [] ptr;
}

/*
 Operator:        =
 Description:     sets an Array<dataType> equal to another
 Parameters:      Array &right  -the array to be used to set the other
 Return Value:    Array<dataType>
*/
template <class dataType> 
const Array<dataType> &Array<dataType>::operator=( const Array &right ) {
  //check self-assignment
  if(this != &right) {
    //set values for array
    numUsed = right.numUsed;
    capacity = right.capacity;

    //delete previous pointer
    delete[] ptr;
    
    //give memory space for new array
    ptr = new dataType[capacity];
    assert(ptr);

    //copy all values over to new array
    for(int i = 0; i < capacity; i++) ptr[i] = right[i];
  }

  return *this;
}

/*
 Operator:        []
 Description:     gets an element from the Array<dataType>
                  Can be any valid location in array, and numUsed will update.
 Parameters:      int subscript  -the element requested to be returned
 Return Value:    dataType
*/
template <class dataType> 
dataType &Array<dataType>::operator[](int subscript) {
  //ensure a valid reference subscript
  assert(0 <= subscript && subscript < capacity);

  //everything up to the subscript is "used space" in array
  if(subscript >= numUsed) numUsed = subscript + 1;

  return ptr[subscript];
}

/*
 Operator:        const []
 Description:     gets an element from the Array<dataType>
                  Can be any valid location in array WITHIN numUsed.
 Parameters:      int subscript  -the element requested to be returned
 Return Value:    const dataType
*/
template <class dataType> 
const dataType &Array<dataType>::operator[](int subscript) const {
  //ensure a vlid reference subscript
  assert(0 <= subscript && subscript < numUsed);

  return ptr[subscript];
}

/*
 Operator:        *
 Description:     gets the first element from the Array<dataType>
 Return Value:    dataType
*/
template <class dataType> 
dataType Array<dataType>::operator*() const {
  return ptr[0];
}

/*
 Operator:        +=
 Description:     appends an element to the end of the Array<dataType>
 Parameters:      dataType elt  -the value appended
 Return Value:    Array<dataType>
*/
template <class dataType> 
Array<dataType> &Array<dataType>::operator+=(dataType elt) {
    //need to allocate more memory to fit data
  if(numUsed == capacity) {
    //create new array of dataType
    dataType* temp = new dataType[capacity+1];

    //copy values over to temp
    for(int i = 0; i < capacity; i++) temp[i] = ptr[i];
    temp[capacity++] = elt;
    numUsed++;
    
    //return to heap and adopt new array
    delete[] ptr;
    ptr = temp;
  }
  if(numUsed < capacity) {
    //enough space for another element
    ptr[numUsed++] = elt;
  }

  return *this;
}

/*
 Operator:        ++pre
 Description:     inserts a default element to the front of the Array<dataType>
                  ALWAYS increases both capacity and numUsed by 1
 Return Value:    Array<dataType>
*/
template <class dataType> 
Array<dataType> &Array<dataType>::operator++() {

  //increase the size of array
  dataType* temp = new dataType[capacity+1];

  //go through each element and shift it over to the right
  for(int i = 0; i < capacity; i++) temp[i+1] = ptr[i];
  temp[0] = dataType();

  //everything is one larger
  numUsed++;
  capacity++;

  //pointer switch
  delete[] ptr;
  ptr = temp;
  
  return *this;
}

/*
 Operator:        post++
 Description:     inserts a default element to the front of the Array<dataType>
                  ALWAYS increases both capacity and numUsed by 1
 Return Value:    Array<dataType>
*/
template <class dataType> 
Array<dataType> Array<dataType>::operator++(int) {
  Array<dataType> temp = *this;

  //preincrement
  ++(*this);

  return temp;
}

/*
 Operator:        ==
 Description:     tests if the numUsed is the same for two Array<dataType>s
 Parameters:      const Array &right  -right array
 Return Value:    bool
*/
template <class dataType>
bool Array<dataType>::operator==(const Array &right) const {
  //two arrays are equal if they have same number of elements used
  return this->numUsed == right.getNumUsed();
}

/*
 Operator:        >
 Description:     tests if the numUsed of left is greater than right
 Parameters:      const Array &right  -right array
 Return Value:    bool
*/
template <class dataType>
bool Array<dataType>::operator>(const Array &right) const  {
  //an array is larger if it has a larger number of elements used
  return this->numUsed > right.getNumUsed();
}

/*
 Operator:        <<
 Description:     inserts an Array into an outstream object
 Parameters:      ostream &output           -outstream object being loaded
                  const Array<dataType> &A  -Array loaded into stream
 Return Value:    ostream
*/
template <class dataType> 
ostream &operator<<(ostream &output, const Array<dataType> &A) {
  int i;
  output << "[ ";
  for ( i = 0; i < A.getNumUsed(); i++ ) {
     if (i != 0) { output << ", "; }
     output << A[i]; 
  }
  output << " ]" << endl;;

  return output;   // enables cout << x << y;
}

/*
 Operator:        >>
 Description:     extracts from an instream object and puts into Array
 Parameters:      istream &input            -instream object being extracted
                  Array<dataType> &A  -Array being loaded
 Return Value:    istream
*/
template <class dataType> 
istream &operator>>(istream &input, Array<dataType> &A) {

  dataType n;
  while(A.getNumUsed() < A.getCapacity()) {
    input >> n; A += n;
  }
  
  return input;
}

#endif
