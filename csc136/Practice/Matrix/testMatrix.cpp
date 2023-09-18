#include <iostream>

#include "Matrix.h"

using namespace std;

int main() {
  int run = 1;
  Matrix A, B;
  int x, y, z;

  
  while(run) {
    cout << "Enter Dimensions for Matrix A:" << endl;
    cout << "_ , _: ";
    cin >> x;
    cout << x << " , _: ";
    cin >> y;
    cout << "Enter Dimensions for Matrix B:" << endl;
    cout << y << " , _: ";
    cin >> z;

    A = Matrix(x, y);
    B = Matrix(y, z);

    cin >> A;
    cin >> B;

    cout << "A:" << endl << A << endl;
    cout << "B:" << endl << B << endl;
    
    cout << "A x B" << endl << (A * B) << endl;

    cout << "continue? 0/1" << endl;
    cin >> run;
  }
}
