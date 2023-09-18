#ifndef LLISTITER
#define  LLISTITER
#include <iostream>

using namespace std;

// Need to prototype template classes 
// since they are referenced as friends below
template <typename T> class Node;
template <typename T> class LinkedList;

// Define an iterator object for the LinkedList
template <typename T>
class LListIter {
  public:
    // Construct a List Iterator
    LListIter(const LinkedList<T> &list);

    // Reset current to point at the first node of llist
    void reset();
    // Are we at the end?
    bool end();
    // Go to current->next (true if not NULL)
    bool next();
    // dereference operator
    T getData();
    // dereference operator
    T operator*();

  private:
    const LinkedList<T> &LL;
    Node<T> *current;
};

// LListIter constructor
template <typename T> 
LListIter<T>::LListIter(const LinkedList<T> &list) : 
  LL(list), current(LL.first) {}

// Set current to point at llist's head
template <typename T> 
void LListIter<T>::reset() {
  current = LL.getFirst();
}

// Is current at the end of the list?
template <typename T> 
bool LListIter<T>::end() {
  return current == NULL;
}

// Move current to next Node
template <typename T> 
bool LListIter<T>::next() {
  current = current->next;
  return (current != NULL);
}

// dereference operator
template <typename T> 
T LListIter<T>::operator*() {
  return getData();
}

// get data from current LL node
template <typename T> 
T LListIter<T>::getData() {
  // return default value for T if current is NULL
  if(current == NULL) { return T(); }
  return current->getData();
}

#endif
