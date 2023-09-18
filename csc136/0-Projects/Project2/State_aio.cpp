/////////////////////////* State.h FILE */////////////////////////
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
/////////////////////////* State.h FILE */////////////////////////

/////////////////////////* State.cpp FILE *//////////////////////////
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

//#include "State.h" MAKE SURE TO UNCOMMENT THIS WHEN PLACED INTO PUTTY

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
/////////////////////////* State.cpp FILE */////////////////////////

/////////////////////////* states.cpp DRIVER FILE */////////////////////////
/*
 Author:          Peter Schaefer
 Creation Date:   9/29/22
 Due Date:        10/6/22
 Course:          CSC136CP 010
 Professor Name:  Dr. Carelli
 Assignment:      Project #2
 Filename:        states.cpp
 Purpose:         This is a driver file which takes a file input and
                  uses State objects to sort and manipulate raw data.
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//#include "State.h" MAKE SURE TO UNCOMMENT THIS WHEN PLACED INTO PUTTY

// DO NOT CHANGE THIS VALUE!
#define ARRAYSIZE 8

//specific spacing for outputs
#define NAME_SPACE 15
#define POP_SPACE 15
#define AREA_SPACE 20
#define DENSITY_SPACE 25

// read the data file, store in class
int readDatafile(State[], int);
// output the formatted "raw data"
void outputData(State[], int);
// output the sorted data, including population density
void outputSorted(State[], int, string);

// sorting routines - use a bubble sort
void sortAscend(State[], int);  // set this up to sort by name
void sortDescend(State[], int); // set this up to sort by population density
void swap(State&, State&);  // used by the bubble sort

// helper functions
void printTitles(bool);
void printUnits(bool);
void printLine(bool);

int main() {

  State slist[ARRAYSIZE];
  int lines = readDatafile(slist, ARRAYSIZE);

  outputData(slist, lines);
  sortAscend(slist, lines);
  outputSorted(slist, lines, "Alphabetical");
  sortDescend(slist, lines);
  outputSorted(slist, lines, "Population Density");

  return 0;
}

/*
 Function name:   readDatafile
 Description:     prompts the user for a file. Attempts to read
                  the contents; if it can it takes the data and
                  puts it into the array of States. If it can't
                  it ouputs an error message and quits.
 Parameters:      State s[] -array of State objects
                  int max   -maxiumum amount of states read
 Return Value:    int linse -the actual amount of lines read
*/
int readDatafile(State s[], int max) {
  string fname;
  ifstream ifs;
  int lines = 0;

  string name; float population; float area;

  cout << "Enter data file name: ";
  cin >> fname;
  ifs.open(fname);
  if(ifs.fail()) {cout << "-Error opening file-" << endl;}

  while(lines < max && ifs >> s[lines]) {
    if(ifs.fail()) {cout << "-File Failed" << endl; return 0;}
    lines++;
  }
  return lines;
}

/*
 Function name:   outputData
 Description:     ouputs the raw data from the file
 Parameters:      State s[] -array of State objects
                  int max   -maxiumum amount of states ouputted
 Return Value:    N/A
*/
void outputData(State s[], int max) {
  cout << "\n\n -Data- \n\n";

  printTitles(false);
  printUnits(false);
  printLine(false);

  for(int i = 0; i < max; i++) {
    cout << left << setw(NAME_SPACE) << s[i].getName();
    cout << right << setw(POP_SPACE) << s[i].getPopulation();
    cout << setw(AREA_SPACE) << s[i].getArea() << endl;
  }
}

/*
 Function name:   outputSorted
 Description:     ouputs sorted data from the file
 Parameters:      State s[]     -array of State objects
                  int max       -maxiumum amount of states ouputted
                  string style  -way the data is currently sorted
 Return Value:    N/A
*/
void outputSorted(State s[], int max, string style) {
  cout << "\n\n -" << style << " Sorted Data- \n\n";
  
  printTitles(true);
  printUnits(true); 
  printLine(true);

  for(int i = 0; i < max; i++) {
    cout << s[i];
  }
}

/*
 Function name:   swap
 Description:     swaps the instance of two State objects
 Parameters:      State &a  -first State object
                  State &b  -second State object
 Return Value:    N/A
*/
void swap(State &a, State &b) {
  State temp = a; a = b; b = temp;
}

/*
 Function name:   sortAscend
 Description:     sorts the State array using their names
 Parameters:      State s[] -array of State objects
                  int max   -maxiumum amount of states
 Return Value:    N/A
*/
void sortAscend(State s[], int max) {
  bool flag = true;
  while(flag) {
    flag = false;
    for(int i = 0; i < max-1; i++) {
      if(s[i+1] < s[i]) {swap(s[i], s[i+1]); flag = true;}
    }
  }
}

/*
 Function name:   sortDescend
 Description:     sorts the State array using their population densities
 Parameters:      State s[] -array of State objects
                  int max   -maxiumum amount of states
 Return Value:    N/A
*/
void sortDescend(State s[], int max) {
  bool flag = true;
  while(flag) {
    flag = false;
    for(int i = 0; i < max-1; i++) {
      if(s[i+1] > s[i]) {swap(s[i], s[i+1]); flag = true;}
    }
  }
}

/*
 Function name:   printTitles
 Description:     prints the title for ouput data
 Parameters:      bool density  -determines whether density title
                                 should be printed
 Return Value:    N/A
*/
void printTitles(bool density = false) {
  cout << setprecision(1)
   << fixed << left << setw(NAME_SPACE) << "Name"
   << right << setw(POP_SPACE) << "Population"
   << setw(AREA_SPACE) << "Area";

   if(density) {cout << setw(DENSITY_SPACE) << "Density" << endl;}
   else {cout << endl;}
}

/*
 Function name:   printUnits
 Description:     prints the units for ouput data
 Parameters:      bool density  -determines whether density units
                                 should be printed
 Return Value:    N/A
*/
void printUnits(bool density = false) {
  cout << fixed << left << setw(NAME_SPACE) << " "
   << right << setw(POP_SPACE) << "(millions)"
   << setw(AREA_SPACE) << "(thou. sq. mi.)";
   if(density) {cout << setw(DENSITY_SPACE) << "(peop. per sq. mi.)" << endl;}
   else {cout << endl;}
}

/*
 Function name:   printLine
 Description:     prints the line for seperating titles and ouput data
 Parameters:      bool density  -determines whether density space
                                 should be printed
 Return Value:    N/A
*/
void printLine(bool density = false) {
  if(density) {
    for(int i = 0; i < NAME_SPACE + POP_SPACE + AREA_SPACE + DENSITY_SPACE; i++) {cout << "-";}
    cout << endl;
  } else {
    for(int i = 0; i < NAME_SPACE + POP_SPACE + AREA_SPACE; i++) {cout << "-";}
    cout << endl;
  }
}
/////////////////////////* states.cpp DRIVER FILE */////////////////////////