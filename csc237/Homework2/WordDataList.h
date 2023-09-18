/**
 * @file WordDataList.h
 * @author Peter Schaefer (pscha710@live.kutztown.edu) / Dr. Spiegel
 * @brief Class DECLARATION for array of WordData objects.
 * Contains special methods to parse in data from a file and update occurrences
 * of a given word.
 * @version 0.1
 * @date 2023-04-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef WORDDATALIST_H
#define WORDDATALIST_H

#include <string>
#include "WordList.h"
#include "WordData.h"

using namespace std;

/**
 * @brief A WordDataList is a subclass of WordList and contains an array of WordData objects.
 * It can parse a file, print iteratively, print recursively, and print using a pointer.
 *
 */
class WordDataList : public WordList
{
public:
  /**
   * @brief MUTATOR: Construct a new WordDataList object AND parse the input file into the WordDataList.
   * Only the first 10 "words" will have their occurrences counted.
   *
   * @param inf IMPORT:EXPORT: file stream containing file that is parsed
   */
  WordDataList(ifstream &inf);

  /**
   * @brief MUTATOR: Parses the input file into the array of WordData objects. Items are NOT sorted.
   *
   * @param inf IMPORT:EXPORT: file stream containing file that is parsed
   */
  virtual void parseIntoList(ifstream &inf);

  /**
   * @brief FACILITATOR: Prints out the array through ITERATION. Prints each word and its occurrences
   *
   */
  virtual void printIteratively();

  /**
   * @brief FACILITATOR: Prints out the array through RECURSION.
   * Calls a worker function to conduct the actual recursion. Prints each word and its occurrences
   *
   */
  virtual void printRecursively();

  /**
   * @brief FACILITATOR: Prints out the array through POINTER ARITHMETIC RECURSION.
   * Calls a worker function to conduct the actual recursion. Prints each word and its occurrences
   *
   */
  virtual void printPtr();

private:
  /**
   * @brief Array of WordData objects which is used to hold the word and its occurrences. MAX size is 10.
   *
   */
  WordData TheWords[10];

  /**
   * @brief Integer which keeps track of how filled the array is of valid words and their occurrences.
   * Does not go above 10.
   *
   */
  int numWords;

  /**
   * @brief MUTATOR:FACILITATOR: Finds the inputted word, if it exists, in the lists and increments it
   *
   * @param temp IMPORT: the string of the word searched for in the array
   * @return true if the word was found and incremented
   * @return false if the word was not found OR if the array is empty
   */
  bool incMatch(string temp);

  /**
   * @brief FACILITATOR: Called by printRecursively in order to conduct recursion to print out array
   *
   * @param numWords IMPORT:EXPORT: integer used to print specific elements and advance to next element
   */
  void printRecursivelyWorker(int numWords);

  /**
   * @brief FACILITATOR: Called by printPtr in order to conduct recursion to print out array using a pointer
   *
   * @param numWords IMPORT:EXPORT: integer used to print specific elements and advance to next element
   */
  void printPtrWorker(int numWords);
};

#endif
