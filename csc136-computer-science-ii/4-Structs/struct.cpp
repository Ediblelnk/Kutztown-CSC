//struct is a USER DEFINED DATA TYPE

/*
3 parts to defining and using a structure
    declaraction of structure
    use of structure to define a new variable
    access of members of the structured variable
*/
#include <iostream>
using namespace std;

struct student {
    string firstName;
    string lastName;
    int age;
    float GPA;
    char major;
    int cls;
};

//using '&' to pass by reference
void printStudent(student &s) {
    cout << s.lastName << ", " << s.firstName << ":\n";
    cout << s.age << "y/o\n";
    cout << "GPA: " << s.GPA << " Major: " << s.major << endl;
}

int main() {
    student S1;

    S1.firstName = "John";
    S1.lastName = "Doe";
    S1.age = 20;
    S1.GPA = 3.8;
    S1.major = 'C';

    student S2 = S1; //copy S1 to S2
    //structs are stored sequentially in memory

    printStudent(S1);
}