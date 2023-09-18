#include "MyClass.h"
#include <iostream>
using namespace std;

MyClass::MyClass() {
  cout << "[Constructor Called]" << endl;
  value = 0;
}

MyClass::MyClass(int v) {
  cout << "[Constructor 2 Called]" << endl;
  value = v;
}

void MyClass::setValue(int v) {
  cout << "[setValue Called]" << endl;
  value = v;
}

int MyClass::getValue() {
  cout << "[getValue Called]" << endl;
  return value;
}
