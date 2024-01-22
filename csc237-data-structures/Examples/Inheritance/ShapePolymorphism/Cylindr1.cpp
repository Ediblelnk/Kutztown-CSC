// Fig. 10.2: cylindr1.cpp
// Member and friend function definitions for class Cylinder
#include "Cylindr1.h"

Cylinder::Cylinder( double h, double r, int x, int y )
   : Circle( r, x, y )  // call base-class constructor
{ setHeight( h ); }

void Cylinder::setHeight( double h )
   { height = h > 0 ? h : 0; }

double Cylinder::getHeight() { return height; }

double Cylinder::area() const
{
   // surface area of Cylinder
   return 2 * Circle::area() +
          2 * 3.14159 * getRadius() * height;
}

double Cylinder::volume() const 
   { return Circle::area() * height; }

void Cylinder::print() const
{
   Circle::print();
   cout << "; Height = " << height;
}

ostream &operator<<(ostream &out,Cylinder C)
{C.print();
 return(out);
}
