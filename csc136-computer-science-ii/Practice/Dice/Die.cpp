#include "Die.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Die::Die(int s, bool p) {
  if(p) {cout << "[Die.die]" << endl;}
  int rand();
  srand(time(NULL));
  sides = s;
  print = p;
}

void Die::rollDie() {
  if(print) {cout << "[Die.rollDie]" << endl;}
  roll = rand()%sides + 1;
}

void Die::changeSides(int num) {
  if(print) {cout << "[Die.changeSides]" << endl;}
  sides = num;
}

int Die::viewRoll() {
  if(print) {cout << "[Die.viewRoll]" << endl;}
  return roll;
}

bool Die::operator>(Die &d) {
  if(print) {cout << "[Die.operator>]" << endl;}
  return roll > d.viewRoll();
}
