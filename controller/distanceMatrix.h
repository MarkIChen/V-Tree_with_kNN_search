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

  void showMatrix() const;
  const int *getIndexTable()const{return indexTable;}
  int getSize()const {return size;}
  int getIndex(int);
  float getValue(int, int);
};



#endif
