#ifndef V_TREE_H
#define  V_TREE_H

# define VERTEX_PER_NODE 4

#include <iostream>
#include "vertex.h"
#include "distanceMatrix.h"
using namespace std;

// class VTree {
// private:
//   DistanceMatrix distanceMatrix;
//   VTree *leftNode;
//   VTree *rightNode;
//   LNAV *LNAVList;
//
//
// public:
//   implement four function
//
// };

// class LNAV {
// private:
//   float distance;
//   int activeVertexIndex;
// };

class Vehicle {
private:

  const int vehicleIndex;
  int desVertexIndex;
  int edgeVertexIndexFirst;
  int edgeVertexIndexSecond;
  Vehicle();

public:
  static int vehicleCount;
  Vehicle(int, int, int);

  int getintVehicleIndex(){return vehicleIndex;}
  int getDesVertexIndex(){return desVertexIndex;}
  int getEdgeVertexIndexFirst(){return edgeVertexIndexFirst;}
  int getEdgeVertexIndexSecond(){return edgeVertexIndexSecond;}

  void setDesVertexIndex(int newValue){ desVertexIndex = newValue;}
  void setEdgeVertexIndexFirst(int newValue){ edgeVertexIndexFirst = newValue;}
  void setEdgeVertexIndexSecond(int newValue){ edgeVertexIndexSecond = newValue;}
};

class ActiveObject {
private:
  const int objectIndex;
  float distance;
  ActiveObject();
public:
  ActiveObject(int ,float);
  float getDistance(){return distance;};
  void setDistance(float newDis){distance = newDis;}

};


#endif
