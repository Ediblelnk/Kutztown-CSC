/**
 * @file WordCList.cpp
 * @author Peter Schaefer (pscha710@live.kutztown.edu)
 * @brief Class DEFINITION for a Circular Linked List of WordData objects.
 * Contains special methods to parse in data from a file and update occurrences
 * of a given word.
 * @version 0.1
 * @date 2023-04-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <string>
#include "WordCList.h"

using namespace std;

WordCList::WordCList(ifstream &inf)
{
  parseIntoList(inf);
}

bool WordCList::incMatch(string temp)
{
  CListItr<WordData> itr(TheWords);
  if (itr.isEmpty())
    return false;
  itr.begin();
  do
  {
    if (temp == (*itr).getWord())
    {
      (*itr).incCount();
      return true;
    }
    ++itr;
  } while (!itr.isFirstNode());
  return false;
}

void WordCList::parseIntoList(ifstream &inf)
{
  string temp;
  while (inf >> temp)
    if (!incMatch(temp))
      TheWords.insert(WordData(temp));
}

void WordCList::printIteratively()
{
  cout << "+-------------------------+" << endl
       << "| Circular List  Iterator |" << endl
       << "+-------------------------+" << endl
       << "| Word        Occurrences |" << endl
       << "+-------------------------+" << endl;
  cout << TheWords;
  cout << "+-------------------------+" << endl;
}

void WordCList::printRecursively()
{
  cout << "+-------------------------+" << endl
       << "| Circular List Recursive |" << endl
       << "+-------------------------+" << endl
       << "| Word        Occurrences |" << endl
       << "+-------------------------+" << endl;
  CListItr<WordData> itr(TheWords);
  if (!itr.isEmpty())
  {
    itr.begin();
    printRecursivelyWorker(itr);
  }
  cout << "+-------------------------+" << endl;
}

void WordCList::printRecursivelyWorker(CListItr<WordData> &itr)
{
  cout << *itr << endl;
  if (!itr.isLastNode())
    printRecursivelyWorker(++itr);
}