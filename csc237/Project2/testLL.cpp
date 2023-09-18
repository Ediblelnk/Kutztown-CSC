/**
 * @file testLL.cpp
 * @author Peter Schaefer (pscha710@live.kutztown.edu)
 * @brief Interactive demo for the implementation of a circular linked list
 * @version 0.1
 * @date 2023-03-11
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>

#include "CLinkedList.h"

using namespace std;

/**
 * @brief FACILITATOR: Prints the menu for the user to choose from
 *
 */
void print_menu();

/**
 * @brief MUTATOR: Prompts the user and inserts the inputted integer into the circular linked list
 *
 * @param clist EXPORT: circular linked list integer is inserted to
 */
void insert_integer(CLinkedList<int> &clist);

/**
 * @brief MUTATOR: Prompts the user and attempts to remove the requested integer from the circular linked list
 *
 * @param clist EXPORT: circular linked list integer is removed from
 */
void remove_integer(CLinkedList<int> &clist);

/**
 * @brief FACILITATOR: Prints the circular linked list in the "forward" direction
 *
 * @param clist IMPORT: circular linked list printed
 */
void forward_print(CLinkedList<int> &clist);

/**
 * @brief FACILITATOR: Prints the circular linked list in the "backward" direction
 *
 * @param clist IMPORT: circular linked list printed
 */
void backward_print(CLinkedList<int> &clist);

/**
 * @brief Interactive demo for the implementation of a circular linked list.
 * @details Prints a menu, which provides the options of 'insert integer',
 * 'remove integer', 'forward print', and 'backward print'.
 *
 * @return int
 */
int main()
{
  // variables
  CLinkedList<int> clist;
  char menuInput;
  bool loop_flag = true;

  // program loop
  while (loop_flag)
  {
    // preamble
    print_menu();
    cin >> menuInput;

    // do action
    switch (menuInput)
    {
    case 'I':
    case 'i':
      insert_integer(clist);
      break;
    case 'R':
    case 'r':
      remove_integer(clist);
      break;
    case 'F':
    case 'f':
      forward_print(clist);
      break;
    case 'B':
    case 'b':
      backward_print(clist);
      break;
    case 'E':
    case 'e':
      loop_flag = false;
      break;
    default:
      cout << endl
           << "UNKNOWN INPUT: PLEASE TRY AGAIN" << endl
           << endl;
    }
  }
}

void print_menu()
{
  cout << ".--------------------." << endl
       << "|        Menu        |" << endl
       << "|--------------------|" << endl
       << "| I - Insert Integer |" << endl
       << "| R - Remove Integer |" << endl
       << "| F - Forward Print  |" << endl
       << "| B - Backward Print |" << endl
       << "| E - Exit           |" << endl
       << "*--------------------*" << endl
       << endl
       << "      Your Choice: ";
}

void insert_integer(CLinkedList<int> &clist)
{
  int value;

  // get value to insert
  cout << endl
       << "   Integer to add: ";
  cin >> value;
  cout << endl;

  // insert value
  clist.insert(value);
}

void remove_integer(CLinkedList<int> &clist)
{
  int value;

  // get value to remove
  cout << endl
       << "Integer to remove: ";
  cin >> value;

  // attempt to remove value
  if (clist.remove(value))
    // able to remove
    cout << endl
         << "Integer removed successfully" << endl;
  else
    // unable to remove
    cout << endl
         << "ERROR: Integer not found in Circular Linked List" << endl
         << endl;
}

void forward_print(CLinkedList<int> &clist)
{
  cout << endl
       << "Current List Forwards:" << endl
       << clist << endl
       << endl;
}

void backward_print(CLinkedList<int> &clist)
{
  cout << endl
       << "Current List Backwards:" << endl;
  clist.printReverse(cout);
  cout << endl
       << endl;
}