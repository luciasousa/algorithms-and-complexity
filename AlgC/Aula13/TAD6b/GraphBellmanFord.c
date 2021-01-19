//
// Joaquim Madeira, AlgC, June 2020
// João Manuel Rodrigues, AlgC, June 2020
//
// GraphBellmanFord - Bellman-Ford Alg. for the Shortest Paths Tree
//

#include "GraphBellmanFord.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "IntegersStack.h"

struct _GraphBellmanFord {
  int* distance;
  int* predecessor;
  Graph* graph;
  unsigned int startVertex;
};

GraphBellmanFord* GraphBellmanFordExecute(Graph* g, unsigned int startVertex) {
  assert(g != NULL);
  assert(0 <= startVertex && startVertex < GraphGetNumVertices(g));

  GraphBellmanFord* bellmanFord =
      (GraphBellmanFord*)malloc(sizeof(struct _GraphBellmanFord));
  assert(bellmanFord != NULL);

  unsigned int numVertices = GraphGetNumVertices(g);
  unsigned int numEdges = GraphGetNumEdges(g);

  //
  // COMPLETAR !!
  //
  // CRIAR e INICIALIZAR os campos de bellmanFord
  // bellmanFord->distance
  // bellmanFord->predecessor
  //

  bellmanFord->distance = (int*) malloc(numVertices* sizeof(int));
  assert(bellmanFord->distance != NULL);

  bellmanFord->predecessor = (int*) malloc(numVertices* sizeof(int));
  assert(bellmanFord->predecessor != NULL);

  for (int i = 0; i < numVertices; i++) {
    bellmanFord->distance[i] = INT_MAX/2;
    bellmanFord->predecessor[i] = -1;
  }
  bellmanFord->distance[startVertex] = 0;

  bellmanFord->graph = g;
  bellmanFord->startVertex = startVertex;

/*
  int belongs[numVertices];
  for(int i = 0;i<numVertices;i++){
    belongs[i]=0;
  }
*/

  // EXECUTAR O ALGORITMO
  //belongs[startVertex] = 1;
  //belongs[u] = 0;
  int b;
  for (int i = 1; i < (numVertices-1); i++){
    for(int u = 0; u < numVertices; u++){
      b = 0;
      int* adj = GraphGetAdjacentsTo(bellmanFord->graph,u);
      int* dist = GraphGetDistancesToAdjacents(bellmanFord->graph,u);
      for(int v = 1; v <= adj[0]; v++){
        int uDist = bellmanFord->distance[u];
        int vDist = bellmanFord->distance[v];
        if((uDist + dist[v]) < vDist){
          bellmanFord->distance[adj[v]] = uDist + dist[v];
          bellmanFord->predecessor[adj[v]] = u;
          b = 1;
        }
      }
      free(adj);
      free(dist);
    }
    if(!b) break;
  }
  for(int i = 1; i < numVertices; i++){
    int* dist = GraphGetDistancesToAdjacents(bellmanFord->graph,i);
    if(dist[i] < 0){
      printf("Negative weight cycle.\n");
      return;
    }
  }
  // COMPLETAR !!
  return bellmanFord;
}

void GraphBellmanFordDestroy(GraphBellmanFord** p) {
  assert(*p != NULL);

  GraphBellmanFord* aux = *p;

  free(aux->distance);
  free(aux->predecessor);

  free(*p);
  *p = NULL;
}

// Getting the result

unsigned int GraphBellmanFordHasPathTo(const GraphBellmanFord* p,
                                       unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  return (p->distance[v] != INT_MAX);
}

int GraphBellmanFordDistanceTo(const GraphBellmanFord* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  return p->distance[v];
}

Stack* GraphBellmanFordPathTo(const GraphBellmanFord* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  Stack* s = StackCreate(GraphGetNumVertices(p->graph));

  if (p->distance[v] == INT_MAX) {
    return s;
  }

  // Store the path
  for (unsigned int current = v; current != p->startVertex;
       current = p->predecessor[current]) {
    StackPush(s, current);
  }

  StackPush(s, p->startVertex);

  return s;
}

// DISPLAYING on the console

void GraphBellmanFordShowPath(const GraphBellmanFord* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  Stack* s = GraphBellmanFordPathTo(p, v);

  while (StackIsEmpty(s) == 0) {
    printf("%d ", StackPop(s));
  }

  printf(" --- Distance = %d", p->distance[v]);

  StackDestroy(&s);
}

void GraphBellmanFordDisplay(const GraphBellmanFord* p) {
  // COMPLETAR !!
  int v;
  for(v = 0; v < GraphGetNumVertices(p); v++){
    Stack* s = GraphBellmanFordPathTo(p,v);
    printf("\nvertex %d\n",v);
    while(StackIsEmpty(s) == 0){
      printf("%d -> ",p->startVertex);
      StackPop(s);
    }
    printf("\n");
  }
}

