#include <iostream>
using namespace std;

int main() {
  float x = 0.5;
  float y[] = {2, 4, 5};
  float *p = &x; //creates pointer p and assigns it the memory address of x
  float *q = &y[0];
  cout << "x = *p; *p: " << *p << endl; // *p is the value at the stored memory address
  cout << "         p: " << p << endl;  // p  is the value of the stored memory address
  cout << "    *(p+1): " << *(p+1) << endl;
  cout << "    *(q+1): " << *(q+1) << endl;
  cout << "      q[0]: " << q[0] << endl;

  /* MEMORY ALLOCATION: new and delete */
  float *fp = new float; //one floating point number
  int *it = new int[10]; //an array of 10 integers

  *fp = 10;
  cout << "*fp: " << *fp << endl;
  cout << " fp: " << fp << endl;

  delete fp;
  delete[] it; //important to use '[]' for an array of memory allocated 

  /* POINTER ARITHMETIC EXAMPLES */
  int iarr[] = {1, 1, 2, 3, 5, 8};
  int *ip;
  ip = iarr;

  cout << "*ip:     " << *ip << endl; // is equivalent to ip[0] and iarr[0];
  cout << "*(ip+2): " << *(ip+2) << endl;
  cout << "*(ip+5): " << *(ip+5) << " this is the end of the array" << endl;
  *ip++;
  cout << "*(ip++): " << *(ip+5) << " this is the next memory place, it is not part of the program" << endl;

  /* REFERENCES */
  /*
  A reference variable is an "alias" to another variable.
    NOT a copy
    can be used interchangeably for the variable to which it refers
    **changing the value of one will also change the value for the other

  Created using the & operator
    MUST be assigned upon creation (if not, compiler error)
    CANNOT be changed or reassigned after creation (also a compiler error)
  */

 int w;
 int &v = w; //v is now a reference to w
             //useful for passing objects to/from functions and methods
             //no need to construct a new object, just pass its "alias"

  /*

  POINTERS VS REFERENCES
    
  Similarities
    Both "refer" to other variables
    Use of & operator with both

  Differences
    Reference is fixed
      serves as an alias to one variable
      value of reference is the actual value of referenced variable
    Pointer is changeable
      value is a memory address
      needs to be dereferenced to retrieve useable data

  Operators:

    "*"
      creates a new pointer when used in variable creation
      dereferences a pointer variable when used in an expression

    "&"
      creates a new reference variable when used in variable creation
      retrieves the memory address of a variable when used in an expression

  */

}