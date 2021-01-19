//
// Joaquim Madeira, AlgC, May 2020
// João Manuel Rodrigues, AlgC, May 2020
//
// Graph EXAMPLE
//

#include "Graph.h"
#include "GraphDFSWithStack.h"
#include "GraphBFSWithQueue.h"
#include "GraphDFSRec.h"

int main(void) {
  // What kind of graph is g01?
  Graph* g01 = GraphCreate(6, 0, 0);
  GraphAddEdge(g01, 1, 2);
  GraphAddEdge(g01, 1, 4);
  GraphAddEdge(g01, 3, 4);
  GraphDisplay(g01);

  //test graph DFS with stack
  /*GraphDFSWithStack* g02 = GraphDFSWithStackExecute(g01,0);
  GraphDFSWithStackDisplay(g02);*/

  for (int i = 0; i < 6; i++) {
    GraphListAdjacents(g01, i);
  }
  Graph* dig01 = GraphCreate(6, 1, 0);
  GraphAddEdge(dig01, 1, 2);
  GraphAddEdge(dig01, 1, 4);
  GraphAddEdge(dig01, 3, 4);
  GraphDisplay(dig01);
  Graph* g03 = GraphCreate(6, 0, 1);
  GraphAddWeightedEdge(g03, 1, 2, 3);
  GraphAddWeightedEdge(g03, 1, 4, 5);
  GraphAddWeightedEdge(g03, 3, 4, 10);
  GraphDisplay(g03);

  GraphDestroy(&g01);
  GraphDestroy(&dig01);
  GraphDestroy(&g03);

  return 0;
}
