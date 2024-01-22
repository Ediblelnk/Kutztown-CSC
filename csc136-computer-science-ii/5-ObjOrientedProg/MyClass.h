#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
   public: 
      MyClass();  // default constructor!
      void setValue(int v) ;
      int getValue();

   private:
      int value;
};

#endif