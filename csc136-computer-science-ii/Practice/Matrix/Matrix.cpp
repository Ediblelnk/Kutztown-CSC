#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <assert.h>

#include "Matrix.h"

using namespace std;

Matrix::Matrix(int r, int c) {
  //no negative dimensions
  this->rows = (r > 0 ? r : 1);
  this->columns = (c > 0 ? c : 1);

  //ensure proper memory allocation
  this->ptr = new float[this->rows * this->columns];
  assert(this->ptr != 0);

  //init all values to 0
  for(int i = 0; i < this->rows * this->columns; i++) {
    this->ptr[i] = 0;
  }
}

Matrix::Matrix(const Matrix &M): rows(M.rows), columns(M.columns) {
  //ensure proper memory allocation
  this->ptr = new float[this->rows * this->columns];
  assert(this->ptr != 0);

  //copy each value into matrix
  for(int i = 0; i < this->rows * this->columns; i++) {
    this->ptr[i] = M.ptr[i];
  }
}

Matrix::~Matrix() {
  delete[] this->ptr;
}

int Matrix::getRows() const {
  return this->rows;
}

int Matrix::getColumns() const {
  return this->columns;
}

float Matrix::getMax() const {
  float max = (*this)(1, 1);

  for(int r = 1; r <= this->getRows(); r++)
    for(int c = 1; c <= this->getColumns(); c++)
      if(max < (*this)(r, c)) max = (*this)(r, c);

  return max;
}

float *Matrix::getRow(int r) const {
  assert( 0 < r && r <= this->rows);

  float *row = new float[this->columns];

  for(int i = 1; i <= this->columns; i++) {
    row[i-1] = (*this)(r, i);
  }

  return row;
}

float *Matrix::getColumn(int c) const {
  assert( 0 < c && c <= this->columns);

  float *column = new float[this->rows];

  for(int i = 1; i <= this->rows; i++) {
    column[i-1] = (*this)(i, c);
  }

  return column;
}


const Matrix &Matrix::operator=(const Matrix &M) {
  //check self assignment
  if(&M == this) {
    return *this;
  }

  //handle size difference
  if(M.rows != this->rows || M.columns != this->columns) {
    delete[] this->ptr;
    this->rows = M.rows;
    this->columns = M.columns;
    this->ptr = new float[this->rows * this->columns];
    assert(this->ptr != 0);
  }

  //copy values into this
  for(int i = 0; i < this->rows * this->columns; i++)
    this->ptr[i] = M.ptr[i];

  //enable cascading
  return *this;
}

Matrix Matrix::operator+(const Matrix &M) {
  assert(this->rows == M.rows && this->columns == M.columns);

  Matrix R = Matrix(this->rows, this->columns);

  for(int r = 1; r <= R.rows; r++) {
    for(int c = 1; c <= R.columns; c++) {
      R(r, c) = (*this)(r, c) + M(r, c);
    }
  }

  return R;
}

Matrix Matrix::operator*(const Matrix &M) {
  //ensure multiplication is defined
  assert(this->columns == M.rows);

  Matrix R = Matrix(this->rows, M.columns);

  for(int r = 1; r <= R.rows; r++) {
    for(int c = 1; c <= R.columns; c++) {
      float *row = this->getRow(r);
      float *column = M.getColumn(c);

      float *rolumn = this->elementMult(row, column, this->columns);

      float sum = this->elementSum(rolumn, this->columns);

      R(r, c) = sum;

      delete[] row, column, rolumn;
    }
  }
  
  return R;
}

float *Matrix::elementMult(float *a, float *b, int len) {
  float *r = new float[len];

  for(int i = 0; i < len; i++) {
    r[i] = a[i] * b[i];
  }

  return r;
}

float Matrix::elementSum(float *a, int len) {
  float r = 0;

  for(int i = 0; i < len; i++) {
    r = r + a[i];
  }

  return r;
}

bool Matrix::operator==(const Matrix &M) const {
  //must have same dimensions
  if(this->rows != M.rows || this->columns != M.columns) {
    return false;
  }

  //loop through values and ensure the same
  for(int i = 0; i < this->rows * this->columns; i++) {
    if(this->ptr[i] != M.ptr[i]) {return false;}
  }

  //all of the values are the same
  return true;
}

bool Matrix::operator!=(const Matrix &M) const {
  return !(*this == M);
}

float &Matrix::operator()(int r, int c) {
  //make sure rows are in range
  assert(0 < r && r <= this->rows);

  //make sure columns are in range
  assert(0 < c && c <= this->columns);

  //decrement both row and column
  r--;
  c--;

  return this->ptr[r*this->columns + c];
}

const float &Matrix::operator()(int r, int c) const {
  //make sure rows are in range
  assert(0 < r && r <= this->rows);

  //make sure columns are in range
  assert(0 < c && c <= this->columns);

  //decrement both row and column
  r--;
  c--;

  return this->ptr[r*this->columns + c];
}

ostream &operator<<(ostream &output, const Matrix &M) {
  for(int r = 1; r <= M.getRows(); r++) {
    output << "[";
    for(int c = 1; c <= M.getColumns(); c++) {
      if(c != M.getColumns()) {output << M(r, c) << ", ";}
      else {output << M(r, c) << "]" << endl;}
    }
  }
  return output;
}

istream &operator>>(istream &input, Matrix &M) {
  cout << "Matrix: " << M.getRows() << ", " << M.getColumns() << endl;

  for(int r = 1; r <= M.getRows(); r++) {
    cout << "Row " << r << ":" << endl; 
    for(int c = 1; c <= M.getColumns(); c++) {
      input >> M(r, c);
    }
  }

  return input;
}
