#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    const int SIZE = 10;
    int iarr[SIZE];
    float flarr[SIZE];
    double darr[SIZE];
    char charr[SIZE];
    string starr[SIZE];
    string s = "star";

    for(int i = 0; i < SIZE; i++) {
        iarr[i] = 2*i;
        flarr[i] = M_PI*i;
        darr[i] = pow(2, i);
        charr[i] = 'a' + i; // a, b, c, d....
        starr[i] = s + to_string(i);
    }

    for(int i = 0; i < SIZE; i++) {
        cout << left << setw(5) << iarr[i] << setprecision(5) << flarr[i];
        cout << "\t" << darr[i] << endl;
        cout << setw(3) << charr[i] << starr[i] << "\n\n";
    }

    char ticTacToe[3][3]; //2d array

    //array[row][column]
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            if((row+col)%2 == 0) ticTacToe[row][col] = 'x';
            else ticTacToe[row][col] = 'o'; 
            cout << ticTacToe[row][col];
        }
        cout << endl;
    }

    cout << starr[0][0]; //should print the first char of the first string
}

//important thing to know about arrays,
//they are always passed by reference (pointer)
//elements of an array can be changed by a function (just like in java)
