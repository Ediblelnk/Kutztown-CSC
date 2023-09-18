// Fig. 10.2: shape.h
// Definition of abstract base class Shape
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

using namespace std;

class Shape {
public:
   virtual double area() const { return 0.0; }
   virtual double volume() const { return 0.0; }

   // pure virtual functions overridden in derived classes
   virtual void printShapeName() const = 0;
   virtual void print() const = 0;
};

#endif

