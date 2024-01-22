#include <iostream>
using namespace std;

void func(int[], int);

int main() {
    int array[3] = {2, 4, 6}, s=3;
    func(array, s);
    cout << array[2] << endl;
}

void func(int A[], int size) {
    if(size >= 3) A[2] = 10;
}

void c_func(const int A[], int size) {
    //cannot change array A inside this func bc of 'const'
}