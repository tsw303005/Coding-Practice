#include "function.h"
#include <vector>

Matrix::Matrix(int s) {
  this->size = s;
  this->matrix = new int*[this->size];
  for (int i = 0; i < this->size; i++) {
    this->matrix[i] = new int[this->size];
  }
}

Matrix::Matrix(const Matrix &a) {
  this->size = a.size;
  this->matrix = new int*[this->size];
  for (int i = 0; i < this->size; i++) {
    this->matrix[i] = new int[this->size];
  }

  for (int i = 0; i < this->size; i++) {
    for (int j = 0; j < this->size; j++) {
      this->matrix[i][j] = a.matrix[i][j];
    }
  }
}

std::ostream &operator<<(std::ostream &a, const Matrix &b) {
  for (int i = 0; i < b.size; i++) {
    for (int j = 0; j < b.size; j++) {
      a << b.matrix[i][j];
      if (j == b.size-1) a << '\n';
      else a << ' ';
    }
  }
  return a;
}

std::istream &operator>>(std::istream &a, Matrix &b) {
  for (int i = 0; i < b.size; i++) {
    for (int j = 0; j < b.size; j++) {
      a >> b.matrix[i][j];
    }
  }
  return a;
}

Matrix& Matrix::operator=(const Matrix &a) {
  for (int i = 0; i < this->size; i++) delete[] this->matrix[i];
  delete[] this->matrix;
  this->size = a.size;
  this->matrix = new int*[this->size];
  for (int i = 0; i < this->size; i++) this->matrix[i] = new int[this->size];

  for (int i = 0; i < this->size; i++) {
    for (int j = 0; j < this->size; j++) {
      this->matrix[i][j] = a.matrix[i][j];
    }
  }
  return *this;
}

Matrix& Matrix::clockwise90() {

  int** tmp = new int*[this->size];
  for (int i = 0; i < this->size; i++) tmp[i] = new int[this->size];

  for (int i = 0; i < this->size; i++) {
    for (int j = 0; j < this->size; j++) {
      tmp[i][j] = this->matrix[i][j];
    }
  }

  for (int i = 0; i < this->size; i++) {
    for (int j = 0; j < this->size; j++) {
      this->matrix[i][j] = tmp[this->size-1-j][i];
    }
  }

  for (int i = 0; i < this->size; i++) delete[] tmp[i];
  delete[] tmp;
  
  return *this;
}

Matrix::~Matrix() {
  for (int i = 0; i < this->size; i++) delete[] this->matrix[i];
  delete[] matrix;
}