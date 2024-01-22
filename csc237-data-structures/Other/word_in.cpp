#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream ins;
    string word;

    ins.open("words.txt");

    while(!ins.eof()) {
        ins >> word;
        if(ins.fail()) {
            ins.clear();
            ins.ignore(1, '\n');
        } else {
          cout << word + " | ";
        }
    }
}

/*
FROM https://faculty.kutztown.edu/spiegel/CSc136/C_Plus_Plus/WordsInFile.cpp
*/
// void getWords(ifstream &source,string words[],int &count)
// { string Token;
//   count=0;
//   while (!source.eof() && count<MAXWORDS) {
// 	 source >> Token;
//  	 words[count++]=Token;
//   }
//   source.close();
// }