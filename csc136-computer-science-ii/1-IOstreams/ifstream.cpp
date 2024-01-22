#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream ins;
    ofstream outs;

    outs.open("ftext.txt");
    outs << "Writing to a file now. \nHope it works and doesn't break.";
    outs.close();

    ins.open("ftext.txt");
    char c;
    ins.get(c);
    cout << c << " << first character \n";
    string s;
    getline(ins, s);
    cout << s << endl;
    getline(ins, s, 't');
    cout << s << " << read up until 't' and no more" << endl;
    getline(ins, s);
    cout << s << " << notice how the 't' is gone"<< endl;
    cout << "fails? " << ins.fail() << endl;
    cout << "end of file? " << ins.eof() << endl;
    getline(ins, s);
    cout << s << " << tries to grab next line" << endl;
    cout << "fails? " << ins.fail() << endl;
    ins.clear();
    cout << " << clears the error flag" << endl;
    cout << "fails? " << ins.fail() << endl;
    ins.close();
}