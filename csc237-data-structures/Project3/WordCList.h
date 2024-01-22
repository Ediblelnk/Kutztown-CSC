/**
 * @file WordCList.h
 * @author Peter Schaefer (pscha710@live.kutztown.edu)
 * @brief Class DECLARATION for a Circular Linked List of WordData objects.
 * Contains special methods to parse in data from a file and update occurrences
 * of a given word.
 * @version 0.1
 * @date 2023-04-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef WORDCLIST_H
#define WORDCLIST_H

#include <string>
#include "WordList.h"
#include "WordData.h"
#include "CLinkedList.h"

using namespace std;

/**
 * @brief A WordCList is a subclass of WordList and contains a CLinkedList<WordData>.
 * It can parse a file, print iteratively, and print recursively.
 *
 */
class WordCList : public WordList
{
public:
  /**
   * @brief MUTATOR: Construct a new WordCList object AND parse the input file into the WordCList
   *
   * @param inf IMPORT:EXPORT: file stream containing file that is parsed
   */
  WordCList(ifstream &inf);

  /**
   * @brief MUTATOR: Parses the input file into the Circular list. Items are sorted alphabetically
   *
   * @param inf IMPORT:EXPORT: file stream containing file that is parsed
   */
  virtual void parseIntoList(ifstream &inf);

  /**
   * @brief FACILITATOR: Prints out the CLinkedList<WordData> through ITERATION. Prints each word and its occurrences
   *
   */
  virtual void printIteratively();

  /**
   * @brief FACILITATOR: Prints out the CLinkedList<WordData> through RECURSION.
   * Calls a worker function to conduct the actual recursion. Prints each word and its occurrences
   *
   */
  virtual void printRecursively();

private:
  /**
   * @brief CLinkedList of WordData objects which is used to hold the word and its occurrences
   *
   */
  CLinkedList<WordData> TheWords;

  /**
   * @brief MUTATOR:FACILITATOR: Finds the inputted word, if it exists, in the list and increments it
   *
   * @param temp IMPORT: the string of the word searched for in the Circular list
   * @return true if the word was found and incremented
   * @return false if the word was not found OR if the Circular List is empty
   */
  bool incMatch(string temp);

  /**
   * @brief FACILITATOR: Called by printRecursively in order to conduct recursion to print out Circular list
   *
   * @param itr IMPORT:EXPORT: Circular list iterator used to print specific elements and advance to next element
   */
  void printRecursivelyWorker(CListItr<WordData> &itr);
};

#endif