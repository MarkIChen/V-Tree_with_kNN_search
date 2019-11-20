#include "Vehicle.h"


Vehicle::Vehicle(int edgeVertexIndexFirst,
                 int edgeVertexIndexSecond)
    : vehicleIndex(vehicleCount++), desVertexIndex(edgeVertexIndexSecond),
      edgeVertexIndexFirst(edgeVertexIndexFirst),
      edgeVertexIndexSecond(edgeVertexIndexSecond) {}
