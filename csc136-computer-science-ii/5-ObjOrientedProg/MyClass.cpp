#include "MyClass.h"
#include <iostream>
using namespace std;

MyClass::MyClass() {
    cout << "constructing..." << endl;
    value=0;
}

void MyClass::setValue(int v) {
    value= v;
}

int MyClass::getValue() {
    return value;
}