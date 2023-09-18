#ifndef STATE_H
#define STATE_H

#include <string>
using namespace std;

// DO NOT CHANGE THIS FILE!!!

// struct definition for a State object
class State {
public:

  // constructor
  State(string n="", float p=0, float a=0);

  // modifiers
  void setName(string n);
  void setPopulation(float v);
  void setArea(float v);
  
  // inspectors
  string getName() const;
  float getPopulation() const;
  float getArea() const;
  
  float getPopulationDensity() const;

  // overloads
  // greater than - compares population densities
  bool operator>(const State &) const; // greater than
  // less than - compares state names
  bool operator<(const State &) const; // less than

private:
  string name;      // state name
  float population;   // state test score
  float area;         // state progam score
};                  

// overload of external stream operators
ostream &operator<<(ostream &, const State &);
istream &operator>>(istream &, State &);

#endif
