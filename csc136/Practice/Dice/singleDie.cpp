#include "Die.h"
#include <iostream>
using namespace std;

int main() {
  Die d = Die(100);
  Die d2 = Die(100);
  d.rollDie();
  d2.rollDie();
  cout << "Roll of die:  " << d.viewRoll() << endl;
  cout << "Roll of die2: " << d2.viewRoll() << endl;
  cout << "Larger value: " << ((d > d2) ? d.viewRoll() : d2.viewRoll()) << endl;
}
