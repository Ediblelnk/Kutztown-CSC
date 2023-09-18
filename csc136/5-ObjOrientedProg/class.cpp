#include <iostream>
using namespace std;

#include "MyClass.h"

int main() {
  MyClass c1;

  c1.setValue(10);
  cout << "Value is: " << c1.getValue() << endl;

  c1.setValue(20);
  cout << "Value is: " << c1.getValue() << endl;
}