#ifndef AUSTRALIAN_SHEPHERD_H
#define AUSTRALIAN_SHEPHERD_H

#include "Dog.h"

using namespace std;

class AustralianShepherd : public Dog {
  public:
    AustralianShepherd(int age = 0, string name = "", string marking = "White Markings");

    virtual void print() const;

    virtual void setMarking(string marking);
    virtual string getMarking() const;

  protected:
    string marking;
};

#endif