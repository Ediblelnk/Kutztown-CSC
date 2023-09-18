#ifndef PET_H
#define PET_H

#include <iostream>

using namespace std;

class Pet {
  public:
    virtual void print() const = 0;

    virtual void setAge(int age) = 0;
    virtual int getAge() const = 0;

    virtual void setName(string name) = 0;
    virtual string getName() const = 0;

  protected:
    string name;
    int age;
};

#endif