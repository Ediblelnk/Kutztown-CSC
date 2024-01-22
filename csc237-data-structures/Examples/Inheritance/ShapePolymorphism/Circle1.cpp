// Fig. 10.2: circle1.cpp
// Member function definitions for class Circle
#include "Circle1.h"

Circle::Circle( double r, int a, int b )
   : Point( a, b )  // call base-class constructor
{ setRadius( r ); }

void Circle::setRadius( double r ) { radius = r > 0 ? r : 0; }

double Circle::getRadius() const { return radius; }

double Circle::area() const 
   { return 3.14159 * radius * radius; }

void Circle::print() const
{
   Point::print();
   cout << "; Radius = " << radius;
}

ostream &operator<<(ostream &out,Circle C)
{C.print();
 return(out);
}
