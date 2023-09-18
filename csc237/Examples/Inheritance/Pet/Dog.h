#ifndef DOG_H
#define DOG_H

#include "Pet.h"

using namespace std;

class Dog : public Pet {
  public:
    Dog(int age = 0, string name = "", string breed = "");

    virtual void print() const;

    virtual void setAge(int age);
    virtual int getAge() const;

    virtual void setName(string name);
    virtual string getName() const;

    virtual void setBreed(string breed);
    virtual string getBreed() const;

  protected:
    string breed;
};

#endif