#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
using namespace std;

// A class for storing student information
class Employee {
public:
  
  // constructors/destructor
  Employee(string N= "") :
      name(N), numSales(0), sales(NULL) {}; 
  Employee(const Employee &);
  ~Employee();

  // get info
  string getName() const { return name; }
  float getNumSales() const { return numSales; }
  const float operator[](int) const;
  float getTotal() const;

  // set info
  void clear(); // remove existing info
  void setName(string s) { name= s; }
  Employee &operator=(const Employee &);
  Employee &operator+=(float);

  // compare two Employees 
  bool operator==(const Employee &);
  // compare two Employees by total sales 
  bool operator>=(const Employee &);
  // compare two Employees by gmepa 
  bool operator<=(const Employee &);

private:
  string name;  
  int numSales;
  float *sales;
};

// print out an employee
ostream& operator<<(ostream &, const Employee &);
// input an employee from a file
ifstream& operator>>(ifstream &, Employee &);

#endif
