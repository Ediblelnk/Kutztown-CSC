/*
 Author:          Peter Schaefer
 Creation Date:   9/11/22
 Due Date:        9/15/22
 Course:          CSC136CP 010
 Professor Name:  Dr. Carelli
 Assignment:      #1
 Filename:        array.cpp
 Purpose:         This program takes states' name, population,
                  and area from a file and calculates the 
                  population density. It outputs a formatted data.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// do NOT change this!
#define ARRAYSIZE 8

//specific spacing for outputs
#define NAME_SPACE 15
#define POP_SPACE 15
#define AREA_SPACE 20
#define DENSITY_SPACE 25

// prototypes
int readDatafile(string[], float[], float[], int);
void calcPopDensity(float[], float[], float[], int);
void outputRawData(string[], float[], float[], int);
void outputAllData(string[], float[], float[], float[], int, string);
void filterData(string[], float[], float[], float[], int);

int main() {
  string names[ARRAYSIZE];        // state names
  float population[ARRAYSIZE];    // state population
  float area[ARRAYSIZE];          // state area (square miles)

  float popDensity[ARRAYSIZE];    // state population density

  int lines;                      // number of lines filled with data

  //read the data and return amount of lines filled with data
  lines = readDatafile(names, population, area, ARRAYSIZE);
  //lines will always be equal to or less than ARRAYSIZE

  //no lines were taken from the file
  if(!lines) {cout << "-Data Format Unusable-" << endl; return 1;}

  calcPopDensity(population, area, popDensity, lines);

  //output the raw and all data
  outputRawData(names, population, area, lines);
  outputAllData(names, population, area, popDensity, lines, "All Data");

  filterData(names, population, area, popDensity, lines);

  outputAllData(names, population, area, popDensity, lines, "Filtered Data");

  return 0;
}


/*
 Function name:   readDatafile
 Description:     prompts the user for a filename and
                  attempts to read the contents. If possible,
                  it fits the data to state names, population,
                  and area.
 Parameters:      string n[]  -array of names
                  float p[]   -array of populations
                  float a[]   -array of areas
                  int max     -maxiumum element accessed
 Return Value:    int line    -the amount of lines read
*/
int readDatafile(string n[], float p[], float a[], int max) {
  string fname;
  ifstream ifs;
  int num=0;

  //get data file and check validity
  cout << "Enter data file name: ";
  cin >> fname;
  ifs.open(fname);
  if(ifs.fail()) {cout << "-Error opening file-" << endl;}

  //data file exists, now extract the data from it
  int line=0;
  while(line < max && ifs >> n[line]) {
    ifs >> p[line];
    ifs >> a[line];

    //data did not have the required format for data extraction
    if(ifs.fail()) {cout << "-File Failed-" << endl; return 0;}

    line++;
  }
    return line;
}

/*
 Function name:   outputRawData
 Description:     prints out the states' information in a readable way
 Parameters:      string n[]  -array of names
                  float p[]   -array of populations
                  float a[]   -array of areas
                  int max     -maxiumum element accessed
 Return Value:    N/A
*/
void outputRawData(string n[], float p[], float a[], int max) {
  cout << "\n\n  -Raw Data-  \n\n";
  cout << fixed << setprecision(1) << left << setw(NAME_SPACE) << "Name" << right << setw(POP_SPACE)
       << "Population" << setw(AREA_SPACE) << "Area\n"; //title line

  cout << setw(NAME_SPACE) << " " << setw(POP_SPACE) << "(millions)" << setw(AREA_SPACE) << "(thou. sq. mi.)" << endl; //unit line
  
  for(int i = 0; i < NAME_SPACE + POP_SPACE + AREA_SPACE; i++) {cout << "-";}
  cout << endl;

  for(int i = 0; i < max; i++) {
    cout << left << setw(NAME_SPACE) << n[i] << right << setw(POP_SPACE) << p[i] << setw(AREA_SPACE) << a[i] << endl;
  }
}

/*
 Function name:   outputAllData
 Description:     prints out the states' information in a readable way
 Parameters:      string n[]  -array of names
                  float p[]   -array of populations
                  float a[]   -array of areas
                  float d[]   -array of population densities
                  int max     -maxiumum element accessed
                  string s    -the title of the data
 Return Value:    N/A
*/
void outputAllData(string n[], float p[], float a[], float d[], int max, string s) {
  cout << "\n\n  -" << s << "-  \n\n";
  cout << left << setw(NAME_SPACE) << "Name" << right << setw(DENSITY_SPACE) << "Pop. Density"
       << setw(POP_SPACE) << "Population" << setw(AREA_SPACE) << "Area" << endl; //title line

  cout << setw(NAME_SPACE) << " " << setw(DENSITY_SPACE) << "(peop. per sq. mi.)"
       << setw(POP_SPACE) << "(millions)" << setw(AREA_SPACE) << "(thou. sq. mi.)" << endl; //unit line

  for(int i = 0; i < NAME_SPACE + POP_SPACE + AREA_SPACE + DENSITY_SPACE; i++) {cout << "-";}
  cout << endl;

  for(int i = 0; i < max; i++) {
    cout << left << setw(NAME_SPACE) << n[i] << right << setw(DENSITY_SPACE) << d[i] << setw(POP_SPACE) << p[i] 
         << setw(AREA_SPACE) << a[i] << endl;
  }
}

/*
 Function name:   calcPopDensity
 Description:     calculates the population density for each state
 Parameters:      float p[]   -array of populations
                  float a[]   -array of areas
                  float d[]   -array of population densities
                  int max     -maxiumum element accessed
 Return Value:    N/A
*/
void calcPopDensity(float p[], float a[], float d[], int max) {
  for(int i = 0; i < max; i++) {d[i] = p[i]/a[i] * 1000;}
}

/*
 Function name:   filterData
 Description:     filters states' using population density via bubblesort
 Parameters:      string n[]  -array of names
                  float p[]   -array of populations
                  float a[]   -array of areas
                  float d[]   -array of population densities
                  int max     -maxiumum element accessed
 Return Value:    N/A
*/
void filterData(string n[], float p[], float a[], float d[], int max) {
  bool flag = true;
  string stemp;
  float ftemp;

  //classic bubble sort
  while(flag) {
    flag = false;
    for(int i = 0; i < max - 1; i++) {
      if(d[i] < d[i+1]) {

        //switch the names
        stemp = n[i];
        n[i] = n[i+1];
        n[i+1] = stemp;

        //switch the populations
        ftemp = p[i];
        p[i] = p[i+1];
        p[i+1] = ftemp;

        //switch the areas
        ftemp = a[i];
        a[i] = a[i+1];
        a[i+1] = ftemp;

        //switch the pop densitys
        ftemp = d[i];
        d[i] = d[i+1];
        d[i+1] = ftemp;

        //set the flag to know that a switch happened this pass
        flag = true;
      }
    }
  }
}