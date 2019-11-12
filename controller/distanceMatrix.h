#ifndef DISTANCE_MATRIX_H
#define DISTANCE_MATRIX_H
#include <iostream>

using namespace std;

class DistanceMatrix {
private:
  float *value;
  int *indexTable;
  int size;

public:
  DistanceMatrix();
  DistanceMatrix(float *, int *, int);
  DistanceMatrix(const DistanceMatrix &);
  ~DistanceMatrix();

  DistanceMatrix& operator=(const DistanceMatrix&);

  void showMatrix();
};



#endif
