/**
 * @file WordSTLSeq.h
 * @author Peter Schaefer (pscha710@live.kutztown.edu)
 * @brief Class DECLARATION for STL list of WordData objects.
 * Contains special methods to parse in data from a file and update occurrences
 * of a given word.
 * @version 0.1
 * @date 2023-04-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef WORDSTLSEQ_H
#define WORDSTLSEQ_H

#include <string>
#include "WordList.h"
#include "WordData.h"
#include <list>

using namespace std;

/**
 * @brief A WordSTLSeq is a subclass of WordList and contains a list<WordData>.
 * It can parse a file, print iteratively, and print recursively.
 *
 */
class WordSTLSeq : public WordList
{
public:
  /**
   * @brief MUTATOR: Construct a new WordSTLSeq object AND parse the input file into the list
   *
   * @param inf IMPORT:EXPORT: file stream containing file that is parsed
   */
  WordSTLSeq(ifstream &inf);

  /**
   * @brief MUTATOR: Parses the input file into the Circular list.
   * After fully parsed, Items are sorted alphabetically in n log n time.
   *
   * @param inf IMPORT:EXPORT: file stream containing file that is parsed
   */
  virtual void parseIntoList(ifstream &inf);

  /**
   * @brief FACILITATOR: Prints out the STL list<WordData> through ITERATION. Prints each word and its occurrences
   *
   */
  virtual void printIteratively();

  /**
   * @brief FACILITATOR: Prints out the STL list<WordData> through RECURSION.
   * Calls a worker function to conduct the actual recursion. Prints each word and its occurrences
   *
   */
  virtual void printRecursively();

private:
  /**
   * @brief STL list of WordData objects which is used to hold the word and its occurrences
   *
   */
  list<WordData> TheWords;

  /**
   * @brief MUTATOR:FACILITATOR: Finds the inputted word, if it exists, in the list and increments it
   *
   * @param temp IMPORT: the string of the word searched for in the STL list
   * @return true if the word was found and incremented
   * @return false if the word was not found OR if the STL List is empty
   */
  bool incMatch(string temp);

  /**
   * @brief FACILITATOR: Called by printRecursively in order to conduct recursion to print out STL list
   *
   * @param itr IMPORT:EXPORT: STL list iterator used to print specific elements and advance to next element
   */
  void printRecursivelyWorker(list<WordData>::iterator &itr);
};

#endif