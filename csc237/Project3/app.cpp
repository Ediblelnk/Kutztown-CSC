/**
 * @file app.cpp
 * @author Peter Schaefer (pscha710@live.kutztown.edu) / Dr. Spiegel
 * @brief This Example inputs a string and demonstrates how to store it using a subclass
 * of an abstract base class that incorporates virtual functions to enable polymorphism.
 * If a file name is input through the command line all of the options will be done
 * automatically for the first line of the file.
 * @version 0.1
 * @date 2023-04-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <chrono>
#include "WordList.h"
#include "WordDataList.h"
#include "WordCList.h"
#include "WordSTLSeq.h"

using namespace std;

/* FUNCTION PROTOTYPES */

/**
 * @brief Displays the menu on the screen.
 *
 */
void displayMenu();

/**
 * @brief Takes in a sentence and sends it through every parsing and printing function
 *
 * @param fname IMPORT: name of the file parsed
 * @param inf IMPORT:EXPORT: file stream used to parse
 * @param TheList EXPORT: pointer to WordList subclass(es)
 */
void printEverything(const string &fname, ifstream &inf, WordList *TheList);

/**
 * @brief Takes in a title, start time, and end time; calculates the time between and prints it out in a box
 *
 * @param title IMPORT: title for the time calculated and printed
 * @param start IMPORT: start time used to calculate delta
 * @param end IMPORT: end time used to calculate delta
 */
void printDelta(const string &title, chrono::_V2::system_clock::time_point start, chrono::_V2::system_clock::time_point end);

int main(int argc, char *argv[])
{
  ifstream inf;
  WordList *TheList;
  if (argc > 1) // if there was an input on the command line
  {
    inf.open(argv[1]); // try and open the file
    if (inf.fail())    // if the file does not open
    {                  // terminate
      cout << "Sorry, the file failed to open." << endl;
      return 0;
    }
    printEverything(argv[1], inf, TheList);
    return 0;
  }

  char selection;
  string fileName;
  cout << "Please enter a file name:" << endl;
  getline(cin, fileName);

  while (true)
  {
    inf.open(fileName.c_str());
    if (inf.fail()) // if the file does not open
    {               // terminate
      cout << "Sorry, the file failed to open." << endl;
      return 0;
    }
    displayMenu();
    cout << "  ";
    cin >> selection;

    auto parse_begin = chrono::high_resolution_clock::now();
    switch (selection)
    {
    case '1':
    case '2':
    case '3':
      TheList = new WordDataList(inf); // instantiation also parses file
      break;
    case '4':
    case '5':
      TheList = new WordCList(inf);
      break;
    case '6':
    case '7':
      TheList = new WordSTLSeq(inf);
      break;
    case '8':
      cout << "  Goodbye" << endl;
      return 0;
    default:
      cout << "  I cannot understand " << selection << ".  Try again." << endl;
      break;
    }
    auto parse_end = chrono::high_resolution_clock::now();

    auto print_begin = chrono::high_resolution_clock::now();
    switch (selection)
    {
    case '1': // Object Array Iterative
    case '4': // Circular List Iterator
    case '6': // STL list Iterative
      TheList->printIteratively();
      delete TheList;
      break;
    case '2': // Object Array Recursively
    case '5': // Circular List Iterator Recursive
    case '7': // STL list Recursive
      TheList->printRecursively();
      delete TheList;
      break;
    case '3': // Object Array Pointer Only
      TheList->printPtr();
      delete TheList;
      break;
    }
    auto print_end = chrono::high_resolution_clock::now();
    inf.close();

    switch (selection)
    {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
      printDelta("Time to Parse", parse_begin, parse_end);
      printDelta("Time to Print", print_begin, print_end);
    }
  }

  return 0;
}

void displayMenu()
{
  cout << endl
       << "+--------------------------------------------------+" << endl
       << "| How do you want to print your sentence elements? |" << endl
       << "+--------------------------------------------------+" << endl
       << "| 1. Object Array Iterative                        |" << endl
       << "| 2. Object Array Recursive                        |" << endl
       << "| 3. Object Array Pointer Recursive                |" << endl
       << "| 4. Circular List Iterator                        |" << endl
       << "| 5. Circular List Iterator Recursive              |" << endl
       << "| 6. STL List Iterative                            |" << endl
       << "| 7. STL List Recursive                            |" << endl
       << "| 8. Quit                                          |" << endl
       << "+--------------------------------------------------+" << endl;
}

void printEverything(const string &fname, ifstream &inf, WordList *TheList)
{
  chrono::_V2::system_clock::time_point start, end;

  /* PRINT AND TIME ALL OF THE WORDDATALIST */
  start = chrono::high_resolution_clock::now();
  TheList = new WordDataList(inf);
  end = chrono::high_resolution_clock::now();
  printDelta("Time to parse Object Array:", start, end);

  start = chrono::high_resolution_clock::now();
  TheList->printIteratively();
  end = chrono::high_resolution_clock::now();
  printDelta("Time to print Object Array Iterative:", start, end);
  start = chrono::high_resolution_clock::now();
  TheList->printRecursively();
  end = chrono::high_resolution_clock::now();
  printDelta("Time to print Object Array Recursive:", start, end);
  start = chrono::high_resolution_clock::now();
  TheList->printPtr();
  end = chrono::high_resolution_clock::now();
  printDelta("Time to print Object Array Pointer Recursive:", start, end);
  inf.close();
  delete TheList;

  inf.open(fname);
  /* PRINT AND TIME ALL OF THE WORDCLIST */
  start = chrono::high_resolution_clock::now();
  TheList = new WordCList(inf);
  end = chrono::high_resolution_clock::now();
  printDelta("Time to parse Circular List:", start, end);

  start = chrono::high_resolution_clock::now();
  TheList->printIteratively();
  end = chrono::high_resolution_clock::now();
  printDelta("Time to print Circular List Iterative:", start, end);
  start = chrono::high_resolution_clock::now();
  TheList->printRecursively();
  end = chrono::high_resolution_clock::now();
  printDelta("Time to print Circular List Recursive:", start, end);
  inf.close();
  delete TheList;

  inf.open(fname);
  /* PRINT AND TIME ALL OF THE WORDSTLSEQ */
  start = chrono::high_resolution_clock::now();
  TheList = new WordSTLSeq(inf);
  end = chrono::high_resolution_clock::now();
  printDelta("Time to parse STL List:", start, end);

  start = chrono::high_resolution_clock::now();
  TheList->printIteratively();
  end = chrono::high_resolution_clock::now();
  printDelta("Time to print STL List Iterative:", start, end);
  start = chrono::high_resolution_clock::now();
  TheList->printRecursively();
  end = chrono::high_resolution_clock::now();
  printDelta("Time to print STL List Recursive:", start, end);
  inf.close();
}

void printDelta(const string &title, chrono::_V2::system_clock::time_point start, chrono::_V2::system_clock::time_point end)
{
  auto delta = chrono::duration_cast<chrono::microseconds>(end - start);
  cout << "+---------------------------------------------------------------------+" << endl
       << "| " << left << setw(47) << title << right << setw(7) << delta.count() << " microseconds |" << endl
       << "+---------------------------------------------------------------------+" << endl;
}