#include "distanceMatrix.h"

DistanceMatrix::DistanceMatrix():value(nullptr), indexTable(nullptr){};
DistanceMatrix::DistanceMatrix(float *value, int *indexTable, int size)
    : size(size) {
  this->indexTable = new int[size];
  this->value = new float[size * size];

  for (int i = 0; i < size * size; i++) {
    this->value[i] = value[i];
  }
  for (int i = 0; i < size; i++) {
    this->indexTable[i] = indexTable[i];
  }
}

void DistanceMatrix::showMatrix() {
  for (int i = 0; i < size * size; i++) {
    cout << value[i] << " ";
    if (i % size == size - 1)
      cout << endl;
  }
  cout << endl;
}
DistanceMatrix::DistanceMatrix(const DistanceMatrix &node) : size(node.size) {
  indexTable = new int[node.size];
  value = new float[size * size];

  for (int i = 0; i < node.size * node.size; i++) {
    value[i] = node.value[i];
  }
  for (int i = 0; i < node.size; i++) {
    indexTable[i] = node.indexTable[i];
  }
}
DistanceMatrix& DistanceMatrix::operator=(const DistanceMatrix& node){
  size = node.size;
  delete value;
  delete indexTable;
  indexTable = new int[node.size];
  value = new float[size * size];
  for (int i = 0; i < node.size * node.size; i++) {
    value[i] = node.value[i];
  }
  for (int i = 0; i < node.size; i++) {
    indexTable[i] = node.indexTable[i];
  }
  return *this;
}
DistanceMatrix::~DistanceMatrix() {
  delete value;
  delete indexTable;
}
