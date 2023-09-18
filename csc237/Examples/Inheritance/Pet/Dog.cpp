#include "Dog.h"

Dog::Dog(int age, string name, string breed) {
  setAge(age);
  setName(name);
  setBreed(breed);
}

void Dog::print() const {
  cout << "==INFORMATION==" << endl
       << "Name: " << this->name << endl
       << "Age: " << this->age << endl
       << "Breed: " << this->breed << endl;
}

void Dog::setAge(int age) {
  this->age = age;
}

int Dog::getAge() const {
  return this->age;
}

void Dog::setName(string name) {
  this->name = name;
}

string Dog::getName() const {
  return this->name;
}

void Dog::setBreed(string breed) {
  this->breed = breed;
}

string Dog::getBreed() const {
  return this->breed;
}