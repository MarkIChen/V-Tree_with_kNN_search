/**************************************
 * Copyright(c) 2019 ICheng Chen 陳易成 E14046583
 * All rights reserved.
 ***************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "V-Tree.h"

using namespace std;

int main(){

  Vertex vertexList[100];

  string line;
  int vertexListSize = 0;
  ifstream inputFile("vertex.txt");

  if(inputFile.is_open()){
    while(inputFile >> vertexList[vertexListSize]){
      vertexListSize++;
    }
  } else {
    cout << "Failed to open file." <<endl;
  }

  for(int i =0;i<vertexListSize;i++){
    cout << vertexList[i];
  }
  inputFile.close();

  // init closest distance matrix
  float closestDistanceMatrix[vertexListSize][vertexListSize];
  for(int i =0;i<vertexListSize;i++){
    for(int j =0;j<vertexListSize;j++){
      closestDistanceMatrix[i][j] = -1;
      if(i == j) closestDistanceMatrix[i][j] = 0;
    }
  }
  ifstream routeFile("route.txt");
  if(routeFile.is_open()){
    int index = 0;
    int v1, v2;
    float distance;
    while(routeFile >>  v1){
      if(routeFile >> v2){
        if(routeFile >> distance){
          cout << distance <<endl;
          closestDistanceMatrix[v1][v2] = distance;
          closestDistanceMatrix[v2][v1] = distance;
        }
      }
      index ++;
    }
  } else {
    cout << "Failed to open file." <<endl;
  }
  for(int i =0;i<vertexListSize;i++){
    for(int j =0;j<vertexListSize;j++){
      cout << "i = " << i <<", j = " <<j;
      cout << ", value = "<<closestDistanceMatrix[i][j] <<endl;
    }
  }
  inputFile.close();

  //

  return 0;
}
