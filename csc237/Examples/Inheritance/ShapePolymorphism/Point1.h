// Fig. 10.2: point1.h
// Definition of class Point
#ifndef POINT1_H
#define POINT1_H
#include "Shape.h"

class Point : public Shape {
public:
   Point( int = 0, int = 0 );  // default constructor
   void setPoint( int, int );
   int getX() const { return x; }
   int getY() const { return y; }
   virtual void printShapeName() const { cout << "Point: "; }
   virtual void print() const;
private:
   int x, y;   // x and y coordinates of Point

   friend ostream &operator<<(ostream &,Point);
};

#endif                                          

