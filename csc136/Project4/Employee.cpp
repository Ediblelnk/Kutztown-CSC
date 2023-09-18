/*
 Author:          Peter Schaefer
 Creation Date:   12/4/22
 Due Date:        12/8/22
 Course:          CSC136CP 010
 Professor Name:  Dr. Carelli
 Assignment:      Project #4
 Filename:        Employee.cpp
 Purpose:         This file is a head/definition for an Employee object.
                  An employee has a name and a array of sales
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <assert.h>
#include "Employee.h"

using namespace std;

//copy constructor
Employee::Employee(const Employee& E) { 

  //copy vars
  this->name = E.name;
  this->numSales = E.numSales;
  this->sales = NULL;
  
  //copy over all sales
  if(E.sales) {
    this->sales = new float[numSales];
    for(int i = 0; i < numSales; i++) {sales[i]= E.sales[i];}
  }
}

//destructor
Employee::~Employee() { 
  delete[] sales;
}

//delete existing information
void Employee::clear() { 
  this->name = ""; this->numSales = 0; 
  if(this->sales) delete[] this->sales;
  this->sales = NULL; 
}

//Overloaded subscript operator
const float Employee::operator[](int subscript) const {
  //check for subscript out of range error
  assert(subscript >= 0 && subscript < numSales);

  return sales[subscript]; //const reference return
}

// Overloaded assignment operator
Employee &Employee::operator=( const Employee &right ) {
  //check for self-assignment
  if ( &right != this ) {

    //copy the name
    this->name = right.name;

    //arrays are different sizes
    if (this->numSales != right.numSales) {
      delete [] this->sales;               //reclaim space
      this->numSales = right.numSales;     //renumSales this object
      this->sales = new float[numSales];   //create space for array copy
      assert(this->sales != 0);            //terminate if not allocated
    }

    for ( int i = 0; i < this->numSales; i++ )
      this->sales[i] = right.sales[i];     //copy array into object
  }

 return *this;   //enables x = y = z;
}

// Append element to end of array
Employee &Employee::operator+=(float value) {

  //create new array for sales
  float *temp = new float[numSales+1];

  //fill array with current sales
  for(int i = 0; i < numSales; i++) {temp[i] = sales[i];}

  //last index to new value and increase numSales
  temp[numSales++] = value;

  //reallocate memory
  delete[] sales;
  
  //put info back to sale
  sales = temp;
  
  return(*this);
}

//Output an Employee
ostream& operator<<(ostream &output, const Employee &E) {
  output << left << setw(12) << E.getName();
  output << fixed << setprecision(2);
  output << right << " " << setw(5) << E.getTotal() << " : ";

  for(int i=0; i<E.getNumSales(); i++) {
    output << "  " << right << setw(5) << E[i];
  }
  output << endl;
  return output;
}

//input an Employee
ifstream& operator>>(ifstream &input, Employee &E) {
  string line;

  if(getline(input,line)) {
    E.clear(); // remove existing information

    stringstream ss(line);
    string name; float value;
    ss >> name;
    E.setName(name); 

    while(ss >> value) {
      E += value;
    }
  }
  return input;
}

//////////////////////////////////////////
// Complete the following
//////////////////////////////////////////


/*
 Description:     sums an employees total sales
 Return Value:    float
*/
float Employee::getTotal() const {
  float total = float();

  //sum each sale value
  for(int i = 0; i < numSales; i++) {total += sales[i];}

  return total;
}

/*
 Description:     compares if employee names are the same
 Parameters:      const Employee &E  -the right side employee
 Return Value:    bool
*/
bool Employee::operator==(const Employee &E) {
  return this->name == E.name;
}

/*
 Description:     compares if left employee sales are less than or equal to right side employee
 Parameters:      const Employee &E  -the right side employee
 Return Value:    bool
*/
bool Employee::operator<=(const Employee &E) {
  return this->getTotal() <= E.getTotal();
}

/*
 Description:     compares if left employee name are greater than or equal to right side employee
 Parameters:      const Employee &E  -the right side employee
 Return Value:    bool
*/
bool Employee::operator>=(const Employee &E) {
  return this->name >= E.name;
}

