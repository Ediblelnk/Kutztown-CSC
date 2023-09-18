#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class Matrix {
 public:
  //constructors
  Matrix(int=1, int=1);
  Matrix(const Matrix &);
  
  //deconstructors
  ~Matrix();

  //methods
  int getRows() const;
  int getColumns() const;
  float getMax() const;
  float *getRow(int) const;
  float *getColumn(int) const;
  
  //overloads
  const Matrix &operator=(const Matrix &);
  Matrix operator+(const Matrix &);
  Matrix operator*(const Matrix &);
  bool operator==(const Matrix &) const;
  bool operator!=(const Matrix &) const;
  float &operator()(int, int);
  const float &operator()(int, int) const;

 private:
  int rows;
  int columns;
  float *ptr;

  //private methods
  float *elementMult(float*, float*, int);
  float elementSum(float*, int);
};

ostream &operator<<(ostream &, const Matrix &);
istream &operator>>(istream &, Matrix &);

#endif
