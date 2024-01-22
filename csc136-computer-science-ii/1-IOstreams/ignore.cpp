#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream ins;
    ofstream outs;

    string line;

    ins.open("ignore.txt");

    cout << "-----\n";

    while(!ins.eof()) {
        getline(ins, line);
        if(ins.fail()) {
            ins.clear();
            ins.ignore(1, '\n');
            cout << "Had a failure" << endl;
        } else {
            cout << line << endl;
        }
    }
}