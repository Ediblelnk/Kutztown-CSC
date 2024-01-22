/*
 Author:          Peter Schaefer
 Creation Date:   9/29/22
 Due Date:        10/6/22
 Course:          CSC136CP 010
 Professor Name:  Dr. Carelli
 Assignment:      Project #2
 Filename:        State.cpp
 Purpose:         This file is a class definition for a State object.
                  It stores name, population, and area of a state.
                  Includes overloads of <, >, <<, and >> for use.
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "State.h"

//specific spacing for outputs
#define NAME_SPACE 15
#define POP_SPACE 15
#define AREA_SPACE 20
#define DENSITY_SPACE 25

/*
 Description:     creates a State object
 Parameters:      string n  -state name
                  float p   -state population
                  float a   -state area
 Return Value:    State
*/
State::State(string n, float p, float a) {
  name = n; population = p; area = a;
}

/*
 Method name:     setArea
 Description:     sets a new state area
 Parameters:      float a   -new state area
 Return Value:    N/A
*/
void State::setArea(float a) {
  area = a;
}

/*
 Method name:     setName
 Description:     sets a new state name
 Parameters:      string n   -new state name
 Return Value:    N/A
*/
void State::setName(string n) {
  name = n;
}

/*
 Method name:     setPopulation
 Description:     sets a new state population
 Parameters:      float p   -new state population
 Return Value:    N/A
*/
void State::setPopulation(float p) {
  population = p;
}

/*
 Method name:     getArea
 Description:     gets state area
 Parameters:      N/A
 Return Value:    float
*/
float State::getArea() const {
  return area;
}

/*
 Method name:     getName
 Description:     gets state name
 Parameters:      N/A
 Return Value:    string
*/
string State::getName() const {
  return name;
}

/*
 Method name:     getPopulation
 Description:     gets state population
 Parameters:      N/A
 Return Value:    float
*/
float State::getPopulation() const {
  return population;
}

/*
 Method name:     getPopulationDensity
 Description:     gets state population density
 Parameters:      N/A
 Return Value:    float
*/
float State::getPopulationDensity() const {
  return population / area * 1000;
}

/*
 Method name:     operator>
 Description:     compares two State objects using population density
 Parameters:      State &A  -the State compared
 Return Value:    bool
*/
bool State::operator>(const State &A) const {
  return getPopulationDensity() > A.getPopulationDensity();
}

/*
 Method name:     operator<
 Description:     compares two State objects using name
 Parameters:      State &A  -the State compared
 Return Value:    bool
*/
bool State::operator<(const State &A) const {
  return getName() < A.getName();
}

/*
 Function name:   operator>>
 Description:     loads a state from an in stream
 Parameters:      istream &input  -in stream variable
                  State &S        -the State loaded
 Return Value:    istream
*/
istream &operator>>(istream &input, State &S) {
  float p; string n; float a;
  input >> n >> p >> a;
  S.setName(n);
  S.setPopulation(p);
  S.setArea(a);

  return input;
}

/*
 Function name:   operator<<
 Description:     loads a state to an out stream
 Parameters:      ostream &ouput  -out stream variable
                  State &S        -the State loaded
 Return Value:    ostream
*/
ostream &operator<<(ostream &output, const State &S) {
  output << left << setw(NAME_SPACE) << S.getName()
     << right << setw(POP_SPACE) << S.getPopulation()
     << setw(AREA_SPACE) << S.getArea()
     << setw(DENSITY_SPACE) << S.getPopulationDensity() << endl;

  return output;
}
