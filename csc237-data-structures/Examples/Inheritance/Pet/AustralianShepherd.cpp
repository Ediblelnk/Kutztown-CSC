#include "AustralianShepherd.h"

AustralianShepherd::AustralianShepherd(int age, string name, string marking) : Dog(age, name, "Australian Shepherd") {
  setMarking(marking);
}

void AustralianShepherd::print() const {
  Dog::print();
  cout << "Marking: " << this->marking << endl;
}

void AustralianShepherd::setMarking(string marking) {
  this->marking = marking;
}

string AustralianShepherd::getMarking() const {
  return this->marking;
}