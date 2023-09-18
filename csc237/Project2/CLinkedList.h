/**
 * @file CLinkedList.h
 * @author Peter Schaefer (pscha710@live.kutztown.edu)
 * @brief Class definition for a Circular Linked List, complete with iterator.
 * @version 0.1
 * @date 2023-03-11
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

#include <iostream>

using namespace std;

template <typename T>
class CLinkedList;
template <typename T>
class CListItr;

/* NODE DECLARATION / DEFINITION */

/**
 * @brief A Node of type T holds data of type T and a pointer to another Node
 *
 * @tparam T
 */
template <typename T>
class Node
{
private:
  /**
   * @brief MUTATOR: Construct a new Node object
   *
   * @param info IMPORT: data held by the Node
   * @param link IMPORT: pointer to the next Node
   */
  Node(T info, Node *link = NULL) : data(info), next(link){};

  /**
   * @brief Data held by a Node
   *
   */
  T data;

  /**
   * @brief Pointer to next Node
   *
   */
  Node *next;

  friend class CLinkedList<T>;
  friend class CListItr<T>;
};

/* CLINKEDLIST DECLARATION */

/**
 * @brief A Circular Linked List, a list where the last Node points back to the first Node
 *
 * @tparam T
 */
template <typename T>
class CLinkedList
{
public:
  /**
   * @brief MUTATOR: Construct a new CLinkedList<T>::CLinkedList object
   *
   * @tparam T
   */
  CLinkedList();

  /**
   * @brief MUTATOR: Copies a new CLinkedList<T>::CLinkedList object
   *
   * @tparam T
   * @param cl IMPORT: the list copied
   */
  CLinkedList(CLinkedList &cl);

  /**
   * @brief MUTATOR: Destroy the CLinkedList<T>::CLinkedList object
   *
   * @tparam T
   */
  ~CLinkedList();

  /**
   * @brief MUTATOR: Copies and assigns the right CLinkedList to this CLinkedList
   *
   * @tparam T
   * @param right IMPORT: the right-side CLinkedList
   * @return CLinkedList<T>&
   */
  CLinkedList &operator=(const CLinkedList &right);

  /**
   * @brief MUTATOR: Inserts data of type T into the Circular Linked List, based on its '<' value
   *
   * @tparam T
   * @param data IMPORT: value of type T inserted into the Circular Linked List
   */
  void insert(T data);

  /**
   * @brief MUTATOR: Removes an element from the Circular Linked List
   *
   * @tparam T
   * @param data IMPORT: element
   * @return true
   * @return false
   */
  bool remove(T data);

  /**
   * @brief FACILITATOR: Prints out the Circular Linked List in reverse order
   *
   * @tparam T
   * @param out IMPORT:EXPORT: ostream object loaded
   * @return ostream&
   */
  ostream &printReverse(ostream &out);

private:
  /**
   * @brief MUTATOR: Copies a Circular Linked List starting at Node n
   *
   * @tparam T
   * @param n IMPORT: the head Node
   * @return Node<T>*
   */
  Node<T> *copy(Node<T> *n);

  /**
   * @brief MUTATOR: Deletes the head Node and every Node following it
   *
   * @tparam T
   * @param n IMPORT:EXPORT: the head Node
   */
  void destroy(Node<T> *, Node<T> *&);

  /**
   * @brief FACILITATOR: Called by printReverse to recursively print the Circular Linked List in reverse order
   *
   * @tparam T
   * @param out IMPORT:EXPORT: ostream object loaded
   * @param n IMPORT:EXPORT: current Node printed, recursive value
   * @return ostream&
   */
  ostream &recursiveReverse(ostream &out, Node<T> *n);

  /**
   * @brief Pointer to the last Node in the Circular Linked List
   *
   */
  Node<T> *last;

  friend class CListItr<T>;
};

/**
 * @brief FACILITATOR: Inserts the values of the Circular Linked List into a out stream object, with cascading
 *
 * @tparam T
 * @param out IMPORT:EXPORT: ostream being extracted to
 * @param right IMPORT: Circular Linked List being extracted
 * @return ostream&
 */
template <typename T>
ostream &operator<<(ostream &out, const CLinkedList<T> &right);

/* CLISTITR DECLARATION */

/**
 * @brief A Circular Linked List Iterator, provides ability to iterator through the Circular Linked List
 *
 * @tparam T
 */
template <typename T>
class CListItr
{
public:
  /**
   * @brief MUTATOR: Construct a new CListItr<T>::CListItr object
   *
   * @tparam T
   * @param clist IMPORT: Circular Linked List iterator is attached to
   */
  CListItr(const CLinkedList<T> &clist);

  /**
   * @brief MUTATOR: Sets the iterator to the first Node of the linked list, or NULL if the list is empty
   *
   * @tparam T
   */
  void begin();

  /**
   * @brief INSPECTOR: Returns whether or not the Circular Linked List is empty
   *
   * @tparam T
   * @return true
   * @return false
   */
  bool isEmpty();

  /**
   * @brief INSPECTOR: Returns whether the present Node is the first Node of the Circular Linked List
   *
   * @tparam T
   * @return true
   * @return false
   */
  bool isFirstNode();

  /**
   * @brief INSPECTOR: Returns whether the present Node is the last Node of the circular liked list
   *
   * @tparam T
   * @return true
   * @return false
   */
  bool isLastNode();

  /**
   * @brief INSPECTOR:MUTATOR: Returns the data of the Node currently pointed at
   *
   * @tparam T
   * @return T&
   */
  T &operator*();

  /**
   * @brief INSPECTOR: Returns the !const! data of the Node currently pointed at
   *
   * @tparam T
   * @return const T&
   */
  const T &operator*() const;

  /**
   * @brief INSPECTOR:MUTATOR: Pre-increment, advances the pointer to the next Node, if there is one
   *
   * @return CListItr<T>&
   */
  CListItr<T> &operator++();

  /**
   * @brief INSPECTOR:MUTATOR: Post-increment, advances the pointer to the next Node, if there is one
   *
   * @return CListItr<T>
   */
  CListItr<T> operator++(int);

private:
  /**
   * @brief Constant reference to Circular Linked List that the Iterator is attached to
   *
   */
  const CLinkedList<T> &clist;

  /**
   * @brief Pointer to the iterator's current Node
   *
   */
  Node<T> *current;
};

/* CLINKEDLIST DEFINITIONS */

template <typename T>
CLinkedList<T>::CLinkedList() : last(NULL) {}

template <typename T>
CLinkedList<T>::CLinkedList(CLinkedList<T> &cl)
{
  last = copy(cl.last);
}

template <typename T>
CLinkedList<T>::~CLinkedList()
{
  destroy(last, last);
}

template <typename T>
CLinkedList<T> &CLinkedList<T>::operator=(const CLinkedList<T> &right)
{
  // if refers to the same CLinkedList, just return the reference
  if (this == &right)
    return *this;
  // they are different delete the left, and copy right into lest
  destroy(last, last);
  last = copy(right.last);
  return *this;
}

template <typename T>
void CLinkedList<T>::insert(T data)
{
  if (!last) // first Node, insert data and point to itself
  {
    last = new Node<T>(data);
    last->next = last;
  }
  else if (data < last->next->data) // data is a minimum value, insert at head
  {
    last->next = new Node<T>(data, last->next);
  }
  else if (last->data < data) // data is a maximum value, insert at last
  {
    last->next = new Node<T>(data, last->next);
    last = last->next;
  }
  else // data is a middle value
  {
    Node<T> *trailP = last->next;
    Node<T> *p = last->next->next;
    for (; p != last && p->data < data; trailP = p, p = p->next)
      ;
    trailP->next = new Node<T>(data, p);
  }
}

template <typename T>
bool CLinkedList<T>::remove(T data)
{
  if (!last) // empty list, return false
    return false;
  if (last->data == data && last == last->next) // removal at last and just 1 element
  {
    delete last;
    last = NULL;
    return true;
  }
  if (last->data == data) // removal at last
  {
    Node<T> *trailLast = last;
    for (; trailLast->next != last; trailLast = trailLast->next)
      ;
    trailLast->next = last->next;
    delete last;
    last = trailLast;
    return true;
  }
  else // removal at anywhere else in the list
  {
    Node<T> *trailP = last;
    Node<T> *p = last->next;
    for (; p != last && p->data != data; trailP = p, p = p->next)
      ;
    if (p == last) // data was not found in the list, return false
      return false;
    // data was found in the list, remove and return true
    trailP->next = p->next;
    delete p;
    return true;
  }
}

template <typename T>
ostream &operator<<(ostream &out, const CLinkedList<T> &right)
{
  CListItr<T> iter(right);
  // iterator needs to refer to a linked list WITH elements
  if (!iter.isEmpty())
  {
    // extract elements until final node
    for (iter.begin(); !iter.isLastNode(); iter++)
      out << *iter << " ";
    // extract final node
    out << *iter;
  }
  return out;
}

template <typename T>
ostream &CLinkedList<T>::printReverse(ostream &out)
{
  // call helper function
  // needs to refer to a linked list WITH elements
  if (last)
    recursiveReverse(out, last->next);
  return out;
}

template <typename T>
ostream &CLinkedList<T>::recursiveReverse(ostream &out, Node<T> *n)
{
  // print previous element before this element, unless last element
  if (n != last)
    recursiveReverse(out, n->next);
  // all previous elements have been printed, print this element
  out << n->data << " ";
  return out;
}

template <typename T>
Node<T> *CLinkedList<T>::copy(Node<T> *n)
{
  // if the Node is NULL, just return NULL
  if (!n)
    return NULL;

  // declare pointers to keep track of beginning for both source and destination
  Node<T> *start = n;
  // declare and copy first Node
  Node<T> *first = last = new Node<T>(n->data);
  // copy all of the remainder nodes but stop once reach the beginning again
  for (n = n->next; n != start; n = n->next, last = last->next)
    last->next = new Node<T>(n->data);
  // reassign the end of the list to the beginning Node
  last->next = first;
  return first;
}

template <class T>
void CLinkedList<T>::destroy(Node<T> *n, Node<T> *&start)
{
  if (n)
  {
    // delete the passed Node and follow to the next Node
    Node<T> *doomed = n;
    n = n->next;
    delete doomed;
    // if not back at the beginning of the list, delete the next Node
    if (n != start)
      destroy(n, start);
  }
}

/* CLISTITR DEFINITIONS */

template <typename T>
CListItr<T>::CListItr(const CLinkedList<T> &clist) : clist(clist),
                                                     current(clist.last) {}

template <typename T>
void CListItr<T>::begin()
{
  // list has at least one element
  if (clist.last)
    current = clist.last->next;
  // list has NO elements
  else
    current = NULL;
}

template <typename T>
bool CListItr<T>::isEmpty()
{
  return clist.last == NULL;
}

template <typename T>
bool CListItr<T>::isFirstNode()
{
  return current == clist.last->next;
}

template <typename T>
bool CListItr<T>::isLastNode()
{
  return current == clist.last;
}

template <typename T>
T &CListItr<T>::operator*()
{
  return current->data;
}

template <typename T>
const T &CListItr<T>::operator*() const
{
  return current->data;
}

template <typename T>
CListItr<T> &CListItr<T>::operator++()
{
  if (current)
    current = current->next;
  return *this;
}

template <typename T>
CListItr<T> CListItr<T>::operator++(int)
{
  CListItr prior = *this;
  ++(*this);
  return prior;
}

#endif
