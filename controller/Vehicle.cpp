#include "Vehicle.h"


Vehicle::Vehicle(int desVertexIndex, int edgeVertexIndexFirst,
                 int edgeVertexIndexSecond)
    : vehicleIndex(vehicleCount++), desVertexIndex(desVertexIndex),
      edgeVertexIndexFirst(edgeVertexIndexFirst),
      edgeVertexIndexSecond(edgeVertexIndexSecond) {}
