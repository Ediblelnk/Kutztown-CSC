/**
 * @file WordList.h
 * @author Peter Schaefer (pscha710@live.kutztown.edu) / Dr. Spiegel
 * @brief Abstract base class for containers of word data. Subclasses MUST
 * have parseIntoList(), printIteratively(), and printRecursively implemented,
 * as they are pure virtual functions.
 * KNOWN SUBCLASSES: WordDataList, WordSTLSeq, and WordCList
 * @version 0.1
 * @date 2023-04-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef WORDLIST_H
#define WORDLIST_H

#include <fstream>
#include <string>

using namespace std;

/**
 * @brief A WordList is a data structure that contains the ability to parse a file,
 * printIteratively, and printRecursively. MAY be able to print using a pointer.
 *
 */
class WordList
{
public:
  /**
   * @brief MUTATOR: Parses the input file.
   *
   * @param inf IMPORT:EXPORT: file stream containing file that is parsed
   */
  virtual void parseIntoList(ifstream &inf) = 0;

  /**
   * @brief FACILITATOR: Prints through ITERATION. Prints each word and its occurrences
   *
   */
  virtual void printIteratively() = 0;

  /**
   * @brief FACILITATOR: Prints through RECURSION. Prints each word and its occurrences
   *
   */
  virtual void printRecursively() = 0;

  /**
   * @brief FACILITATOR: Prints out the array through POINTER ARITHMETIC RECURSION. Prints each word and its occurrences
   *
   */
  virtual void printPtr() {}
};

#endif