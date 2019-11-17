#include <iostream>
#include <ctime>
#include "controller/V-Tree.h"
#include "controller/Vehicle.h"
#include "controller/distanceMatrix.h"
#include "module/distanceMatrixValue.cpp"

using namespace std;
int treeNodeNumber = 7;
int boundaryVertexListSize = 8;

int Vehicle::vehicleCount = 0;

int main() {
  srand(time(0));
  DistanceMatrix gxDistanceMatrix[treeNodeNumber];
  for (int i = 0; i < treeNodeNumber; i++) {
    gxDistanceMatrix[i] =
        DistanceMatrix(gxValue[i], gxIndexTable[i], gxSize[i]);
    // gxDistanceMatrix[i].showMatrix();
  }

  VTree *VTreeArr[treeNodeNumber];
  for(int i =0; i<treeNodeNumber;i++){
    VTreeArr[i] = new VTree(gxDistanceMatrix[i]);
  }
  VTree root(*VTreeArr[0]);
  VTree g1(*VTreeArr[1]);
  VTree g2(*VTreeArr[2]);

  g1.setLeftNode(*VTreeArr[3]);
  g1.setRightNode(*VTreeArr[4]);

  g2.setLeftNode(*VTreeArr[5]);
  g2.setRightNode(*VTreeArr[6]);

  root.setLeftNode(g1);
  root.setRightNode(g2);

  root.showTree();
  root.rightNode->leftNode->showTree();

  cout <<"-----------------"<<endl;

  vector<Vehicle> vehicleList;
  vehicleList.push_back(Vehicle(4, 2, 4));
  vehicleList.push_back(Vehicle(5, 8, 5));
  vehicleList.push_back(Vehicle(8, 6, 8));
  vehicleList.push_back(Vehicle(2, 1, 2));

  for(int i =0;i<vehicleList.size();i++) root.insertObject(vehicleList[i]);
  root.setBoundaryVertexList(boundaryVertexIndex, boundaryVertexListSize);

  root.showTree();
  root.leftNode->leftNode->showTree();
  root.leftNode->rightNode->showTree();
  root.rightNode->leftNode->showTree();
  root.rightNode->rightNode->showTree();
  //
  // for(int i =0;i<treeNodeNumber;i++){
  //   delete VTreeArr[i];
  // }
  return 0;
}
