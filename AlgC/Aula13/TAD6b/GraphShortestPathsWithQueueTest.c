//
// Joaquim Madeira, AlgC, May 2020
// João Manuel Rodrigues, AlgC, May 2020
//
// Graph EXAMPLE
//

#include "Graph.h"
#include "GraphShortestPathsWithQueue.h"

int main(void) {
  Graph* g01 = GraphCreate(6, 0, 1);

  GraphAddWeightedEdge(g01, 0, 5, 3);
  GraphAddWeightedEdge(g01, 2, 4, 2);
  GraphAddWeightedEdge(g01, 2, 3, 7);
  GraphAddWeightedEdge(g01, 1, 2, 6);
  GraphAddWeightedEdge(g01, 0, 1, 5);
  GraphAddWeightedEdge(g01, 3, 4, 1);
  GraphAddWeightedEdge(g01, 3, 5, 9);
  GraphAddWeightedEdge(g01, 0, 2, 8);
  
  GraphDisplay(g01);

  GraphShortestPathsWithQueue* traversal = GraphShortestPathsWithQueueExecute(g01, 0);

  printf("Path from 0 to 5: ");
  GraphShortestPathsWithQueueShowPath(traversal, 5);
  printf("\n");

  GraphShortestPathsWithQueueDestroy(&traversal);

  GraphDestroy(&g01);

  return 0;
}
