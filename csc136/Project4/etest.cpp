#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Employee.h"

using namespace std;

int main()
{
   Employee E1("chris");
   Employee E2("sam");

   E1+= 4.5;
   E1+= 5.5;
   E1+= 6.5;

   cout << "E1:" << endl;
   cout << E1;
   cout << "total: " << E1.getTotal() << endl;

   E2+= 8.5;
   E2+= 9.5;

   cout << endl;
   cout << "E2:" << endl;
   cout << E2;
   cout << "total: " << E2.getTotal() << endl;

   cout << boolalpha << endl;
   cout << "E1 == E2 ? " << (E1 == E2) << endl;
   cout << "E1 <= E2 ? " << (E1 <= E2) << endl;
   cout << "E1 >= E2 ? " << (E1 >= E2) << endl;
}

