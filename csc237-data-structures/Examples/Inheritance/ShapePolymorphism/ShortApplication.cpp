// Fig. 9.10: fig09_10.cpp
// Driver for class Cylinder
#include <iostream>
#include <iomanip>
#include "Point1.h"
#include "Circle1.h"
#include "Cylindr1.h"

using namespace std;

int main()
{  
   // create Circle object
   Circle cir( 2.3, 1.8, 12);
   // create Cylinder object
   Cylinder cyl( 5.7, 2.5, 12, 23 );

   // use get functions to display the Circle
   cout << "Circle:\nX coordinate is " << cir.getX()
        << "\nY coordinate is " << cir.getY()
        << "\nRadius is " << cir.getRadius();

   // use get functions to display the Cylinder
   cout << "\nCylinder:\nX coordinate is " << cyl.getX()
        << "\nY coordinate is " << cyl.getY()
        << "\nRadius is " << cyl.getRadius()
        << "\nHeight is " << cyl.getHeight() << "\n\n";

   // use set functions to change the Cylinder's attributes
   cyl.setHeight( 10 );
   cyl.setRadius( 4.25 );
   cyl.setPoint( 2, 2 );
   cout << "The new location, radius, and height of cyl are:\n"
        << cyl << '\n';

   // display the Circle as a Point
   Point *pRef = &cir;   // pRef "thinks" it is a Point
   cout << "\nCircle printed as a Point is: " 
        << *pRef << "\n\n"; // pRef->print() would have printed all the info
   
   // display the Cylinder as a Point
   pRef = &cyl;   // pRef "thinks" it is a Point if dereferenced
   cout << "\nCylinder printed as a Point is: " 
        << *pRef << "\n\n";
   
   // display the Cylinder as a Circle
   Circle *circleRef = &cyl;  // circleRef thinks it is a Circle
   cout << "Cylinder printed as a Circle is:\n" << *circleRef
        << "\nArea: " << circleRef->area() 
		/* Compile error << circleRef->volume() */<< endl;

   // display the Cylinder as a Circle
   Cylinder *cylRef = (Cylinder *)&cir;  // circleRef thinks it is a Circle
   cout << "Circle printed as a Cylinder is:\n" << *cylRef << "\nArea: " 
	        << cylRef->area() << "\nVolume:" << cylRef->volume() << endl;

   return 0;
}


