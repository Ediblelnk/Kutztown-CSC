#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float f = 2.3345;
    float f2 = 5.75;
    float f3 = 3.0;
    float f4 = 0.0000004596;

    int i = 12;
    int i2 = 12000000;
    string s = "james bond";
    bool b = true;

    cout << left << setw(7) << "float:";
    cout << right << setw(7) << f << endl;
    cout << right << setw(14) << f2 << endl;

    cout << left << boolalpha << setw(12) << "boolalpha:";
    cout << right << setw(5) << b << endl;
    cout << left << noboolalpha << setw(12) << "noboolalpha:";
    cout << right << setw(5) << b << endl;

    cout << left << showpoint << setw(12) << "showpoint:";
    cout << right << setw(5) << f3 << endl;
    cout << left << noshowpoint << setw(12) << "noshowpoint:";
    cout << right << setw(5) << f3 << endl;

    cout << left << fixed << setw(12) << "fixed:";
    cout << setprecision(10) << f4 << endl;
    cout << scientific << setw(12) << "scientific:";
    cout << f4;

}