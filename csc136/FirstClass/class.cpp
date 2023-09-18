#include <iostream>
using namespace std;

#include "MyClass.h" // <--- Include the header file so the compiler
//knows the blueprint for each definition

//prototype
void printMyClass(MyClass);

int main() {
  MyClass c1 = MyClass(33);

  cout << "Value is: " << c1.getValue() << endl;

  c1.setValue(20);
  cout << "Value is: " << c1.getValue() << endl;
}

void printMyClass(MyClass c) {
  cout << "[printMyClass function]" << endl;
  cout << c.getValue() << endl;
}
