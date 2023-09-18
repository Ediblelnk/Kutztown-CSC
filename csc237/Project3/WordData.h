/**
 * @file WordData.h
 * @author Peter Schaefer (pscha710@live.kutztown.edu) / Dr. Spiegel
 * @brief Class DECLARATION for a WordData object. A WordData object contains a word
 * and its corresponding number of occurrences. There are also methods to print, getWord / getCount
 * incCount, and setWord / setCount.
 * @version 0.1
 * @date 2023-04-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef WORDDATA_H
#define WORDDATA_H
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief A WordData object contains a word
 * and its corresponding number of occurrences. There are also methods to print, getWord / getCount
 * incCount, and setWord / setCount.
 *
 */
class WordData
{

public:
  /**
   * @brief MUTATOR: Construct a new WordData object. Defaults word to the empty string and the count to 1.
   *
   * @param wrd
   * @param cnt
   */
  WordData(string wrd = "", int cnt = 1);

  /**
   * @brief MUTATOR: Set the word of the WordData object
   *
   * @param wrd IMPORT: string of the new word
   */
  void setWord(string wrd);

  /**
   * @brief MUTATOR: Set the count of the WordData object
   *
   * @param cnt IMPORT: integer of the new count
   */
  void setCount(int cnt);

  /**
   * @brief Set the Word Data object: both the word and count
   *
   * @param wrd IMPORT: string of the new word
   * @param cnt IMPORT: integer of the new count
   */
  void setWordData(string wrd, int cnt);

  /**
   * @brief INSPECTOR: Get the word of the WordData object
   *
   * @return string
   */
  string getWord() const;

  /**
   * @brief INSPECTOR: Get the count of the WordData object
   *
   * @return int
   */
  int getCount() const;

  /**
   * @brief MUTATOR: Increments the count of the WordData object by the given amount (default is 1)
   *
   * @param inc IMPORT: integer amount to increment the count by
   */
  void incCount(int inc = 1);

  /**
   * @brief INSPECTOR: Compares the alphabetic order of the two WordData objects
   *
   * @param right IMPORT: WordData object on the right side of the comparison
   * @return true if the word on the right comes second alphabetically
   * @return false if the word on the right comes first alphabetically
   */
  bool operator<(const WordData &right) const;

private:
  /**
   * @brief String of the word
   *
   */
  string word;

  /**
   * @brief Integer of the count of the word
   *
   */
  int count;
};

/**
 * @brief FACILITATOR: Inserts a formatted form of the WordData object into the desired ostream object
 *
 * @param output IMPORT:EXPORT: ostream object inserted into
 * @param words IMPORT: WordData object that is inserted
 * @return ostream&
 */
ostream &operator<<(ostream &output, const WordData &words);

#endif