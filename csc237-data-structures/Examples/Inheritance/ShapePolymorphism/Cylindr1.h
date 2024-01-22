// Fig. 10.2: cylindr1.h
// Definition of class Cylinder
#ifndef CYLINDR1_H
#define CYLINDR1_H
#include "Circle1.h"

class Cylinder : public Circle {
public:
   // default constructor
   Cylinder( double h = 0.0, double r = 0.0,
             int x = 0, int y = 0 );

   void setHeight( double );
   double getHeight();
   virtual double area() const;
   virtual double volume() const;
   virtual void printShapeName() const {cout << "Cylinder: ";}
   virtual void print() const;
private:
   double height;   // height of Cylinder

   friend ostream &operator<<(ostream &,Cylinder);
};

#endif

