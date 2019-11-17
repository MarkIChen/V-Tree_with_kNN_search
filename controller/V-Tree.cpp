#include "V-Tree.h"
#include <stdlib.h>
using namespace std;
typedef std::numeric_limits<float> floatMax;

ActiveObject::ActiveObject(Vehicle vehicle, float distance)
    : vehicle(vehicle), distance(distance) {}

void LNAV::showActiveObjecList() const {
  for (int i = 0; i < activeObjectList.size(); i++) {
    cout << "   ObjectIndex = "
         << activeObjectList[i].getObjectVehicle().getVehicleIndex();
    cout << ", distance  = " << activeObjectList[i].getDistance() << endl;
  }
}

LNAV::LNAV()
    : distance(floatMax::max_digits10), activeVertex(-1),
      isBoundaryVertex(false) {}

bool LNAV::pushObject(ActiveObject &newObject) {
  activeObjectList.push_back(newObject);
  return true;
}

VTree::VTree(const DistanceMatrix &distanceMatrix)
    : distanceMatrix(distanceMatrix) {
  leftNode = nullptr;
  rightNode = nullptr;
  LNAVList = std::vector<LNAV>(distanceMatrix.getSize(), LNAV());
}

// copy constructor
VTree::VTree(const VTree &oldTree) {
  if (oldTree.leftNode != nullptr) {
    leftNode = new VTree(*oldTree.leftNode);
  } else {
    leftNode = nullptr;
  }
  if (oldTree.rightNode != nullptr) {
    rightNode = new VTree(*oldTree.rightNode);
  } else {
    rightNode = nullptr;
  }
  distanceMatrix = DistanceMatrix(oldTree.distanceMatrix);
  LNAVList = oldTree.LNAVList;
  boundaryVertexList = oldTree.boundaryVertexList;
}

VTree &VTree::operator=(const VTree &anotherTree) {
  if (anotherTree.leftNode != nullptr) {
    delete leftNode;
    leftNode = new VTree(*anotherTree.leftNode);
  } else {
    leftNode = nullptr;
  }
  if (anotherTree.rightNode != nullptr) {
    delete rightNode;
    rightNode = new VTree(*anotherTree.rightNode);
  } else {
    rightNode = nullptr;
  }
  distanceMatrix = anotherTree.distanceMatrix;
  LNAVList = anotherTree.LNAVList;
  boundaryVertexList = anotherTree.boundaryVertexList;
  return *this;
}

VTree::~VTree() {
  delete leftNode;
  delete rightNode;
}

bool VTree::setLeftNode(const VTree &newleftNode) {
  delete leftNode;
  leftNode = new VTree(newleftNode);

  return true;
}

bool VTree::setRightNode(const VTree &newRightNode) {
  delete rightNode;

  rightNode = new VTree(newRightNode);
  return true;
}

bool VTree::insertObject(const Vehicle &newVehicle) {
  int insertVertex = newVehicle.getDesVertexIndex();
  VTree &leaf = getLeaveOfIndex(*this, insertVertex);

  int arrIndex = leaf.distanceMatrix.getIndex(insertVertex);
  if (arrIndex == -1) {
    cout << "Insert Object Error." << endl;
    return false;
  }
  float randDis =
      rand() %
      int(leaf.distanceMatrix.getValue(newVehicle.getEdgeVertexIndexFirst(),
                                       newVehicle.getEdgeVertexIndexSecond()));

  ActiveObject object(newVehicle, randDis);
  leaf.LNAVList[arrIndex].pushObject(object);
  cout << "pass" << endl;
  return true;
}

void VTree::showTree() const {
  cout << "my distanceMatrix: " << endl;
  distanceMatrix.showMatrix();

  for (int i = 0; i < distanceMatrix.getSize(); i++) {
    cout << "layer: " << getLayer(*this);
    cout << ", vertex: " << distanceMatrix.getIndexTable()[i] << endl;
    LNAVList[i].showActiveObjecList();
  }
  cout << "Boundary : ";
  for (int i = 0; i < boundaryVertexList.size(); i++) {
    cout << boundaryVertexList[i] << " ";
  }
  cout << endl;
}

bool VTree::setBoundaryVertexList(int *vertexList, int listSize) {
  for (int i = 0; i < listSize; i++) {
    VTree &leaf = getLeaveOfIndex(*this, vertexList[i]);
    leaf.boundaryVertexList.push_back(vertexList[i]);
  }
  return true;
}

int VTree::getLayer(const VTree &root) {
  VTree *nextNode = root.leftNode;
  int layer = 0;
  while (nextNode != nullptr) {
    nextNode = nextNode->leftNode;
    layer++;
  }
  return layer;
}

VTree &VTree::getLeaveOfIndex(VTree &root, int searchIndex) {
  if (getLayer(root) == 0) {
    return root;
  }
  int index = searchIndex - 1;
  int cluster = index / (VTree::vertexNumPerLeaf * getLayer(root));

  return cluster % 2 ? getLeaveOfIndex(*root.rightNode, searchIndex)
                     : getLeaveOfIndex(*root.leftNode, searchIndex);
}
