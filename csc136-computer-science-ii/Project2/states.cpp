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

#include "State.h"

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

  if(lines) {
    outputData(slist, lines);
    sortAscend(slist, lines);
    outputSorted(slist, lines, "Alphabetical");
    sortDescend(slist, lines);
    outputSorted(slist, lines, "Population Density");
  }
  
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
    if(ifs.fail()) {cout << "-File Failed-" << endl; return 0;}
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
