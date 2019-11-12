#include <iostream>

#include "module/distanceMatrixValue.cpp"
#include "controller/distanceMatrix.h"
#include "controller/V-Tree.h"

using namespace std;

int main(){

  DistanceMatrix gxDistanceMatrix[6];
  for (int i = 0;i<6 ;i++){
    gxDistanceMatrix[i] = DistanceMatrix(gxValue[i], gxIndexTable[i], gxSize[i]);
    gxDistanceMatrix[i].showMatrix();
  }


  return 0;
}
