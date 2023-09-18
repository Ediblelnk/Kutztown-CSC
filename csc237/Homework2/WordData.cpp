/**
 * @file WordData.cpp
 * @author Peter Schaefer (pscha710@live.kutztown.edu) / Dr. Spiegel
 * @brief Class DEFINITION for a WordData object. A WordData object contains a word
 * and its corresponding number of occurrences. There are also methods to print, getWord / getCount
 * incCount, and setWord / setCount.
 * @version 0.1
 * @date 2023-04-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "WordData.h"

using namespace std;

WordData::WordData(string wrd, int cnt)
{
  setWordData(wrd, cnt);
}

void WordData::setWord(string wrd)
{
  word = wrd;
}

void WordData::setCount(int cnt)
{
  count = cnt;
}

void WordData::setWordData(string wrd, int cnt)
{
  setWord(wrd);
  setCount(cnt);
}
string WordData::getWord() const
{
  return (word);
}

int WordData::getCount() const
{
  return (count);
}

void WordData::incCount(int inc)
{
  count += inc;
}

bool WordData::operator<(const WordData &right) const
{
  return (this->getWord() < right.getWord());
}

ostream &operator<<(ostream &output, const WordData &words)
{
  output << "| " << left << setw(18) << words.getWord() << setw(5) << right << words.getCount() << " |";
  return output;
}
