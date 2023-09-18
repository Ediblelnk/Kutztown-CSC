/**
 * @file WordDataList.cpp
 * @author Peter Schaefer (pscha710@live.kutztown.edu) / Dr. Spiegel
 * @brief Class DEFINITION for array of WordData objects.
 * Contains special methods to parse in data from a file and update occurrences
 * of a given word.
 * @version 0.1
 * @date 2023-04-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <sstream>
#include <iostream>
#include "WordDataList.h"

using namespace std;

WordDataList::WordDataList(ifstream &inf)
{
  numWords = 0;
  parseIntoList(inf);
}

bool WordDataList::incMatch(string temp)
{
  for (int i = 0; i < numWords; i++)
  {
    if (temp == TheWords[i].getWord())
    {
      TheWords[i].incCount();
      return true;
    }
  }
  return false;
}

void WordDataList::parseIntoList(ifstream &inf)
{
  string temp;
  while (inf >> temp)
    if (!incMatch(temp) && numWords < 10)
    {
      TheWords[numWords].setWord(temp);
      TheWords[numWords++].setCount(1);
    }
}

// Print the data iteratively
void WordDataList::printIteratively()
{
  cout << "+-------------------------+" << endl
       << "| Object Array  Iterative |" << endl
       << "+-------------------------+" << endl
       << "| Word        Occurrences |" << endl
       << "+-------------------------+" << endl;
  for (int i = 0; i < numWords; i++)
    cout << TheWords[i] << endl;
  cout << "+-------------------------+" << endl;
}

// Print the data recursively
void WordDataList::printRecursivelyWorker(int numWords)
{
  if (numWords < 0)
    return;
  printRecursivelyWorker(numWords - 1);
  cout << TheWords[numWords] << endl;
}

// Call worker function to print the data recursively
void WordDataList::printRecursively()
{
  cout << "+-------------------------+" << endl
       << "| Object Array  Recursive |" << endl
       << "+-------------------------+" << endl
       << "| Word        Occurrences |" << endl
       << "+-------------------------+" << endl;
  printRecursivelyWorker(numWords - 1);
  cout << "+-------------------------+" << endl;
}

// Print the data recursively with a pointer
void WordDataList::printPtrWorker(int numWords)
{
  if (!numWords)
    return;
  printPtrWorker(numWords - 1);
  cout << *(TheWords + (numWords - 1)) << endl;
}

// Call worker function to print the data recursively
void WordDataList::printPtr()
{
  cout << "+-------------------------+" << endl
       << "|  Object Array  Pointer  |" << endl
       << "+-------------------------+" << endl
       << "| Word        Occurrences |" << endl
       << "+-------------------------+" << endl;
  printPtrWorker(numWords);
  cout << "+-------------------------+" << endl;
}
