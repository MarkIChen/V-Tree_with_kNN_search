#include "V-Tree.h"
#include <stdlib.h>

Vehicle::Vehicle(int desVertexIndex, int edgeVertexIndexFirst,
                 int edgeVertexIndexSecond)
    : vehicleIndex(vehicleCount++), desVertexIndex(desVertexIndex),
      edgeVertexIndexFirst(edgeVertexIndexFirst),
      edgeVertexIndexSecond(edgeVertexIndexSecond) {}

ActiveObject::ActiveObject(int objectIndex, float distance)
    : objectIndex(objectIndex), distance(distance) {}


// VTree buildVTree(){
//   //G1
//   int g1Size = 4;
//   float g1Value[] = {
//     0, 2, 5, 9, 2, 0, 3, 8, 5, 3, 0, 7, 9, 8, 7, 0
//   };
//
//   int g1IndexTable[] = {1, 2, 3, 4};
//
//   DistanceMatrix g1Node(g1Value, g1IndexTable, g1Size);
//
//   g1Node.showMatrix();
//
//   return g1Node;
// }
