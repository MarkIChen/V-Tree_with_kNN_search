#ifndef V_TREE_H
#define  V_TREE_H
# define VERTEX_PER_NODE 4

#include <iostream>
#include "vertex.h"
#include "Vehicle.h"
#include <vector>
#include "distanceMatrix.h"
#include <stdlib.h>
using namespace std;


class ActiveObject {
private:
  // const int objectIndex; // objectIndex = vehicleIndex
  Vehicle vehicle;
  float distance;
  ActiveObject();
public:
  ActiveObject(Vehicle ,float);
  const Vehicle getObjectVehicle() const {return vehicle;};
  float getDistance() const {return distance;};
  void setDistance(float newDis){distance = newDis;}
};

class LNAV {
private:
  float distance;
  int activeVertex;
  bool isBoundaryVertex;
  vector<ActiveObject> activeObjectList;
public:
  LNAV();

  void setDistance(int newDistance){distance = newDistance;}
  void setActiveVertex(int vertex){activeVertex = vertex;}

  float getDistance(){return distance;}
  int getActiveVertex(){return activeVertex;}

  bool pushObject(ActiveObject &);
  const vector<ActiveObject> getActiveObjectList(){return activeObjectList;}
  void showActiveObjecList() const;
  void setBoundaryVertex() {isBoundaryVertex = true;};
};

class VTree {
private:
  DistanceMatrix distanceMatrix;
  vector<LNAV> LNAVList;
  vector<int> boundaryVertexList;
  VTree(){};

  static int getLayer(const VTree&);
  static VTree& getLeaveOfIndex(VTree&, int);
public:
  const static int vertexNumPerLeaf = 4;
  VTree *leftNode;
  VTree *rightNode;

  VTree(const DistanceMatrix&);
  VTree(const VTree&);
  ~VTree();
  VTree& operator=(const VTree &anotherTree);

  bool findVertex(int);

  bool setLeftNode(const VTree&);
  bool setRightNode(const VTree&);

  bool insertObject(const Vehicle&);
  bool removeObject(const Vehicle&);

  bool setBoundaryVertexList(int *, int);

  void showTree() const;
  const DistanceMatrix& getDistanceMatrix()const{return distanceMatrix;};



};



#endif
