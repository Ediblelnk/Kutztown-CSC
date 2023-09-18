/**
 * @file WordSTLSeq.cpp
 * @author Peter Schaefer (pscha710@live.kutztown.edu)
 * @brief Class DEFINITION for STL list of WordData objects.
 * Contains special methods to parse in data from a file and update occurrences
 * of a given word.
 * @version 0.1
 * @date 2023-04-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "WordSTLSeq.h"

using namespace std;

WordSTLSeq::WordSTLSeq(ifstream &inf)
{
  parseIntoList(inf);
}

bool WordSTLSeq::incMatch(string temp)
{
  if (TheWords.empty())
    return false;
  for (list<WordData>::iterator itr = TheWords.begin(); itr != TheWords.end(); ++itr)
  {
    if (temp == (*itr).getWord())
    {
      (*itr).incCount();
      return true;
    }
  }
  return false;
}

void WordSTLSeq::parseIntoList(ifstream &inf)
{
  // code
  string temp;
  while (inf >> temp)
    if (!incMatch(temp))
      TheWords.push_back(WordData(temp));
  TheWords.sort();
}

void WordSTLSeq::printIteratively()
{
  cout << "+-------------------------+" << endl
       << "|    STL List Iterator    |" << endl
       << "+-------------------------+" << endl
       << "| Word        Occurrences |" << endl
       << "+-------------------------+" << endl;

  if (!TheWords.empty())
  {
    list<WordData>::iterator itr = TheWords.begin();
    do
    {
      cout << *itr << endl;
      ++itr;
    } while (itr != TheWords.end());
  }
  cout << "+-------------------------+" << endl;
}

void WordSTLSeq::printRecursively()
{
  cout << "+-------------------------+" << endl
       << "|   STL List  Recursive   |" << endl
       << "+-------------------------+" << endl
       << "| Word        Occurrences |" << endl
       << "+-------------------------+" << endl;
  if (!TheWords.empty())
  {
    list<WordData>::iterator itr = TheWords.begin();
    printRecursivelyWorker(itr);
  }
  cout << "+-------------------------+" << endl;
}

void WordSTLSeq::printRecursivelyWorker(list<WordData>::iterator &itr)
{
  if (itr != TheWords.end())
  {
    cout << *itr << endl;
    printRecursivelyWorker(++itr);
  }
}