// Fig. 10.2: point1.cpp
// Member function definitions for class Point
#include "Point1.h"

Point::Point( int a, int b ) { setPoint( a, b ); }

void Point::setPoint( int a, int b )
{
   x = a;
   y = b;
}

void Point::print() const 
   { cout << '[' << x << ", " << y << ']'; }

ostream &operator<<(ostream &out,Point P)
{P.print();
 return(out);
}

