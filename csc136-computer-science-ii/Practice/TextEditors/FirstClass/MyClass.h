#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
   public: 
    MyClass();  // default constructor!

    MyClass(const MyClass &); //copy constructor!
  
    MyClass(int v); //constructor 2
    void setValue(int v) ;
    int getValue();

  private:
    int value;
};

#endif
