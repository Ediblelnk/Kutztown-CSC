/**
 * @file Treetest.cpp
 * @author Peter Schaefer (pscha710@live.kutztown.edu) / Dr. Spiegel
 * @brief Test Driver for a Binary Tree implementation in which values are held,
 * with their corresponding counts of how many of that value are in the list.
 * Provides a menu in interactive mode, but can also use input text files to automate
 * the test process. Also provides a number of ways to print out the Binary Tree for
 * better understanding of what is happening "underneath the hood".
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

typedef BinaryTree<int> IntTree;

/**
 * @brief Gets the choice from the user. The choice must be a character in the input string.
 *
 * @param ok This string dictates the set of values that the choice from the user can be.
 * @return char
 */
char getChoice(string ok);

/**
 * @brief Insert Value to Search Tree, unless it already exists in the Search Tree,
 * in which case just increment the value of the element.
 *
 * @param TheTree
 */
void addToTree(IntTree &TheTree);

/**
 * @brief Remove Value from Search Tree. Period.
 *
 * @param TheTree
 */
void removeFromTree(IntTree &TheTree);

/**
 * @brief Decrements value from Search Tree.
 *
 * @param TheTree
 * @param entry value decremented
 * @param result count of value before decrementation
 */
void decrementFromTree(IntTree &TheTree, int entry, int *result);

int main()
{
  IntTree Tree;
  int entry, *result;
  char Choice;
  do
  {
    cout << "Select: A)dd    R)emove     P)rint     T)ree Print     Q)uit\n";
    Choice = getChoice("ARPTQ");
    switch (Choice)
    {
    case 'A':
      addToTree(Tree);
      break;
    case 'P':
      cout << "The Tree:" << endl;
      Tree.inorder();
      break;
    case 'R':
      removeFromTree(Tree);
      break;
    case 'T':
      cout << "The tree, as it appears (sort of)..\n";
      Tree.treePrint();
      break;
    case 'Q':
      break;
    default:
      cout << "Not a valid choice please try again" << endl;
    }
  } while (Choice != 'Q');
}

char getChoice(string ok)
{
  char ch = ' ';
  do
    ch = toupper(cin.get());
  while (ok.find(ch) == string::npos);
  cin.get(); // eat CR
  return (toupper(ch));
}

// Insert Value to Search Tree
void addToTree(IntTree &TheTree)
{
  int entry;
  cout << " Enter an Integer >";
  cin >> entry;
  TheTree.insertToTree(entry);
}

// Remove Value from Search Tree
void removeFromTree(IntTree &TheTree)
{
  int entry, *result;
  cout << "Value to Delete? >";
  cin >> entry;
  result = TheTree.treeSearch(entry);
  if (!result)
    cout << entry << " Not Found\n";
  else if (*result == 1)
    TheTree.deleteFromTree(entry);
  else
    decrementFromTree(TheTree, entry, result);
}

void decrementFromTree(IntTree &TheTree, int entry, int *result)
{
  cout << "Do you want to remove all " << *result << " copies or only one? (A or O)" << endl;
  char cEntry = getChoice("AO");

  switch (cEntry)
  {
  case 'A':
    TheTree.deleteFromTree(entry);
    break;
  case 'O':
    TheTree.decrementFromTree(entry);
    break;
  default:
    cout << "Not a valid choice please try again" << endl;
  }
}