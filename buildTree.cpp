#include "controller/V-Tree.h"
#include "controller/Vehicle.h"
#include "controller/distanceMatrix.h"
#include "module/distanceMatrixValue.cpp"
#include <ctime>
#include <iostream>
// #define floatMax std::numeric_limits<float>::max()

using namespace std;
int treeNodeNumber = 7;
int boundaryVertexListSize = 8;

int Vehicle::vehicleCount = 0;

int main() {
  cout << " floatMax" << floatMax << endl;

  srand(time(0));
  DistanceMatrix gxDistanceMatrix[treeNodeNumber];
  for (int i = 0; i < treeNodeNumber; i++) {
    gxDistanceMatrix[i] =
        DistanceMatrix(gxValue[i], gxIndexTable[i], gxSize[i]);
    // gxDistanceMatrix[i].showMatrix();
  }

  VTree *VTreeArr[treeNodeNumber];
  for (int i = 0; i < treeNodeNumber; i++) {
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
  root.setBoundaryVertexList(boundaryVertexIndex, boundaryVertexListSize);

  root.showTree();
  root.leftNode->showTree();

  cout << "-----------------" << endl;

  vector<Vehicle> vehicleList;
  vehicleList.push_back(Vehicle(2, 4));
  vehicleList.push_back(Vehicle(2, 4));
  vehicleList.push_back(Vehicle(2, 4));
  vehicleList.push_back(Vehicle(2, 4));
  vehicleList.push_back(Vehicle(8, 5));
  vehicleList.push_back(Vehicle(6, 8));
  vehicleList.push_back(Vehicle(9, 11));
  vehicleList.push_back(Vehicle(16, 15));

  for (int i = 0; i < vehicleList.size(); i++)
    root.insertObject(vehicleList[i]);

  // root.deleteObject(vehicleList[0]);
  // root.deleteObject(vehicleList[2]);

  root.showTree();
  root.leftNode->showTree();
  root.rightNode->showTree();
  root.leftNode->leftNode->showTree();
  root.leftNode->rightNode->showTree();
  root.rightNode->leftNode->showTree();
  root.rightNode->rightNode->showTree();

  cout << "-------------------" << endl;
  // SPDist
  // for(int i=1;i<17;i++){
  //   for(int j=1;j<17;j++){
  //     cout <<i <<" to "<<j<<" is = "<< root.SPDist(i, j) <<endl;
  //   }
  // }
  cout << "-------------------" << endl;
  GNAVData gnavVertex = root.gnav(2);
  cout << "gnav: " << gnavVertex.vertexIndex
       << ", dis = " << gnavVertex.shortestDistance << endl;

  gnavVertex = root.nnav(2, gnavVertex);
  cout << "gnav: " << gnavVertex.vertexIndex
       << ", dis = " << gnavVertex.shortestDistance << endl;

  gnavVertex = root.nnav(2, gnavVertex);
  cout << "gnav: " << gnavVertex.vertexIndex
       << ", dis = " << gnavVertex.shortestDistance << endl;

       gnavVertex = root.nnav(2, gnavVertex);
       cout << "gnav: " << gnavVertex.vertexIndex
            << ", dis = " << gnavVertex.shortestDistance << endl;

  cout << "-------------------" << endl;
  vector<GNAVData> knnList = root.knn(5, 3);
  for(int i=0;i<knnList.size();i++){
    cout <<"vertex: "<<knnList[i].vertexIndex<<", dis = "<<knnList[i].shortestDistance<<endl;
  }


  //
  // for(int i =0;i<treeNodeNumber;i++){
  //   delete VTreeArr[i];
  // }
  return 0;
}
