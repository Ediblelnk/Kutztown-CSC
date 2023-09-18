#include <iostream>
#include <iomanip>

#include "AustralianShepherd.h"

using namespace std;

int main() {
  AustralianShepherd* asP = new AustralianShepherd(13, "Aussie Pointing Aussie");
  AustralianShepherd as(13, "Aussie");

  asP->print();
  as.print();

  Dog* dP = new Dog(10, "Dog Pointing Dog", "Jack Russel");
  Dog d(10, "Dog", "Jack Russel");

  dP->print();
  d.print();

  Dog* dsP = new AustralianShepherd(15, "Dog Pointing Aussie");
  Pet* psP = new AustralianShepherd(3, "Pet Pointing Aussie");

  dsP->print();
  psP->print();
}