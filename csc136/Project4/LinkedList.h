/*
 Author:          Peter Schaefer
 Creation Date:   12/4/22
 Due Date:        12/8/22
 Course:          CSC136CP 010
 Professor Name:  Dr. Carelli
 Assignment:      Project #4
 Filename:        LinkedList.h
 Purpose:         This file is a header/definition for a linked list with some special methods.
 */
#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>
using namespace std;

#include "LListIter.h"

// Need to prototype template classes 
// since they are referenced as friends below
template <typename T> class LListIter;

/////////////////////////////////////////////////////
// define a class to contain one linked list Node
template <typename T> 
class Node {  
  private:
    Node(T value=T(), Node* ptr=NULL) {
      data= value; next= ptr;
    }

    T getData() { return data; }
    void setData(const T& d) { data= d; }
    Node *getNext() { return next; }

    T data;
    Node *next;

    // must make LinkedList and LListIter friends to Node
    // otherwise, Node pointers will need to be passed around
    // allowing visiblity into LL elements
    friend class LinkedList<T>;
    friend class LListIter<T>;
};

/////////////////////////////////////////////////////
// the linked list class
template <typename T> 
class LinkedList {
  public:
    // Default constructor
    LinkedList();
    // destructor
    ~LinkedList();

    // add an item to the end
    void add(T); 
    // remove item with specified value
    bool remove(T);
    // delete everything
    void deleteAll();
    // replace an existing entry with given item
    bool replace(T);

    // Is the LinkedList empty?
    bool isEmpty();
    // find the max value in the list
    T findMax();
    // sort the list in ascending order
    void sortAscend();
    // find the min value in the list
    T findMin();
    // sort the list in descending order
    void sortDescend();
    // reverse the order of items in the list 
    void reverse();

    // get a copy of an entry
    T getEntry(T);

  private:
    // look for an item in the list
    Node<T>* findItem(T);
  
    // linked list pointer
    Node<T>* first;

    // extract item with specified value
    // return the extracted node
    Node<T>* extract(T);

    // make iterator a friend
    friend class LListIter<T>;
};
 
// Output a linked list, using a list iterator
template <typename T> 
ostream& operator<<(ostream &os,const LinkedList<T> &llist) {  
  LListIter<T>  iter(llist);
  if(!iter.end()) { 
    do {
      os << " " << *iter;
    } while(iter.next());
  }
  return os;
}

/////////////////////////////////////////////////////
// Linked List Implementations
/////////////////////////////////////////////////////

// Construct empty LinkedList
template <typename T> 
LinkedList<T>::LinkedList() {
  first= NULL;
}

// Free all Nodes
template <typename T> 
LinkedList<T>::~LinkedList() {
  deleteAll();
}

// is list empty?
// Note: inline !!!!!!!!!!!!
template <typename T> inline 
bool LinkedList<T>::isEmpty() {
  return (first == NULL);
}

// remove an item from the llist 
// return true if successful (false if not found)
template <typename T> 
bool LinkedList<T>::remove(T val) {  
  Node<T> *current= first;
  if(!isEmpty()) {
    // val is first item, remove it
    if(val == current->data) {
      first= current->next; delete current;
      return true;
    }
    // not the first, check the rest
    while(current->next != NULL) {
      if(val == current->next->data) {
        Node<T> *temp= current->next->next;
        delete current->next; current->next= temp;
        return true;
      }
      // not found, go on to the next one
      current= current->next;
    }
  }
  return false;
}

// Delete all Nodes in the linked list
template <typename T> 
void LinkedList<T>::deleteAll() {  
  Node<T> *ptr= first;
  while (ptr != NULL) {  
    Node<T> *doomed = ptr;
    ptr = ptr->next;
    delete doomed;
  }
}

// locate and return a copy of an item
template <typename T> 
T LinkedList<T>::getEntry(T val) {  
  Node<T> *ptr = first;
  while(ptr != NULL) {
    if(ptr->data == val) { 
       return ptr->getData(); 
    }
    ptr = ptr->next; 
  }
  return T();
}

// sort the linked list in ascending order
template <class T>
void LinkedList<T>::sortAscend() {
  Node<T> *nptr= NULL;
  Node<T> *lptr= nptr;

  while(!isEmpty()) {
    T data= findMax();
    lptr= nptr; nptr= extract(data); nptr->next= lptr;
  }
  first= nptr;
}

/////////////////////////////////////////////////////
//
// COMPLETE THE FOLLOWING METHODS !!!
//
/////////////////////////////////////////////////////

/*
 Description:     add an item to the end of the linked list.
 Parameters:      T val  -value to be added
*/
template <typename T> 
void LinkedList<T>::add(T val) {
  Node<T>* current = first;

  //case for no first node
  if(!current) {
    first = new Node<T>(val);
  } else {
    //loop through nodes until at last node
    while(current->next) {
      current = current->next;
    }

    //point at new node instead of null
    current->next = new Node<T>(val);
  }
}

/*
 Description:     replaces an existing item that matches the supplied item with the supplied item.
                  returns true if successful, false otherwise
 Parameters:      T nitem  -item to be replaced
 Return Value:    bool
*/
template <typename T> 
bool LinkedList<T>::replace(T nitem) {
  Node<T> *current= first;
  if(!isEmpty()) {
    // val is first item, replace it
    if(nitem == current->data) {
      Node<T> *next = new Node<T>(nitem, current->next);
      delete current;
      first = next;
      return true;
    }
    // not the first, check the rest
    while(current->next != NULL) {
      if(nitem == current->next->data) {
        Node<T> *next= new Node<T>(nitem, current->next->next);
        delete current->next;
	current->next= next;
        return true;
      }
      // not found, go on to the next one
      current= current->next;
    }
  }
  return false;
}

/*
 Description:     extracts the item with the given value from the list.
                  returns pointer to given value if successful, NULL otherwise.
 Parameters:      T val  -value extracted
 Return Value:    Node<T>
*/
template <typename T> 
Node<T> *LinkedList<T>::extract(T val) {  
  Node<T> *current= first;
  if(!isEmpty()) {
    // val is first item, remove it
    if(val == current->data) {
      first= current->next;
      return current;
    }
    // not the first, check the rest
    while(current->next != NULL) {
      if(val == current->next->data) {
	//keep plucked node
        Node<T> *ret = current->next;
	current->next = current->next->next;
	//return plucked node
        return ret;
      }
      // not found, go on to the next one
      current= current->next;
    }
  }
  return NULL;
}

/*
 Description:     find and return a copy of the maximum value in the list. If the list is empty,
                  return the default value for class T
 Return Value:    T
*/
template <typename T>
T LinkedList<T>::findMax() {
  if(!first) return T();

  T max = first->data;
  Node<T>* current = first;

  while(current) {
    if(current->data >= max){max = current->data;}
    current = current->next;
  }

  return max;
}

/*
 Description:     reverses the order of the linked list
*/
template <class T>
void LinkedList<T>::reverse() {
  Node<T> *nptr= NULL;
  Node<T> *lptr= nptr;

  while(!isEmpty()) {
    Node<T>* seeker = first;

    //get front of linked list
    T data= seeker->data;
    lptr= nptr; nptr= extract(data); nptr->next= lptr;
  }
  first= nptr;
}

/*
 Description:     find and return a copy of the minimum value in the list. If the list is empty,
                  return the default value for class T
 Return Value:    T
*/
template <typename T>
T LinkedList<T>::findMin() {
  if(!first) return T();

  T min = first->data;
  Node<T>* current = first;

  while(current) {
    if(current->data <= min){min = current->data;}
    current = current->next;
  }

  return min;
}

/*
 Description:     sorts the linked list in descending order
*/
template <class T>
void LinkedList<T>::sortDescend() {
  Node<T> *nptr= NULL;
  Node<T> *lptr= nptr;

  while(!isEmpty()) {
    T data= findMin();
    lptr= nptr; nptr= extract(data); nptr->next= lptr;
  }
  first= nptr;
}

#endif
