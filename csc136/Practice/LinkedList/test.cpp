#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"

int main()
{
  LinkedList<int>  l1;
  int x;
 
  // build a list
  for (x=1; x < 12; x+=2) {
    l1.insert(x);
  }
  cout << "New List:" << endl;
  cout << "  " << l1 << endl;
  cout << endl;

  // ------------------------------
  cout << "Insertions:" << endl;
  cout << " insert begin 0" << endl;
  l1.insert(0);
  cout << "  " << l1 << endl;
  cout << " insert end 13" << endl;
  l1.insert(13);
  cout << "  " << l1 << endl;
  cout << " insert middle 6" << endl;
  l1.insert(6);
  cout << "  " << l1 << endl;
  cout << endl;

  // ------------------------------
  cout << "Removals:" << endl;
  cout << " remove begin 0" << endl;
  l1.remove(0);
  cout << "  " << l1 << endl;
  cout << " remove end 13" << endl;
  l1.remove(13);
  cout << "  " << l1 << endl;
  cout << " remove middle 5" << endl;
  l1.remove(5);
  cout << "  " << l1 << endl;
  cout << endl;

  // ------------------------------
  cout << "copy constructor:" << endl;
  LinkedList<int>  l2(l1);
  cout << " copy l1" << endl;
  cout << "  " << l2 << endl;
  cout << endl;

  // ------------------------------
  cout << "assignment:" << endl;
  LinkedList<int>  l3=l2;
  cout << "  " << l3 << endl;
  cout << endl;

  // ------------------------------
  cout << "count nodes:" << endl;
  cout << "num: " << l3.countNodes() << endl;
  cout << endl;
  
  // ------------------------------
  cout << "count nodes (recursive):" << endl;
  cout << "num: " << l3.countNodesRecursive() << endl;
  cout << endl;
  
  // ------------------------------
  cout << "7 exists: " << l3.exists(7) << endl;
  cout << "8 exists: " << l3.exists(8) << endl;
}
