//
// Joaquim Madeira, AlgC, June 2020
// João Manuel Rodrigues, AlgC, June 2020
//
// GraphShortestPathsWithQueue - QUEUE algorithm for the Shortest Paths Tree
//

#include "GraphShortestPathsWithQueue.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "IntegersStack.h"
#include "IntegersQueue.h"
#include "PriorityQueue.h"

struct _GraphShortestPathsWithQueue {
  int* distance;
  int* predecessor;
  Graph* graph;
  unsigned int startVertex;
};

GraphShortestPathsWithQueue* GraphShortestPathsWithQueueExecute(Graph* g, unsigned int startVertex) {
  assert(g != NULL);
  assert(0 <= startVertex && startVertex < GraphGetNumVertices(g));

  GraphShortestPathsWithQueue* ShortestPathsWithQueue =
      (GraphShortestPathsWithQueue*)malloc(
          sizeof(struct _GraphShortestPathsWithQueue));
  assert(ShortestPathsWithQueue != NULL);

  unsigned int numVertices = GraphGetNumVertices(g);

  //
  // COMPLETAR !!
  //
  // CRIAR e INICIALIZAR os campos de ShortestPathsWithQueue
  // ShortestPathsWithQueue->distance
  // ShortestPathsWithQueue->predecessor
  //

  ShortestPathsWithQueue->distance = (int*)malloc(numVertices* sizeof(int));
  assert(ShortestPathsWithQueue->distance!=NULL);
  ShortestPathsWithQueue->predecessor = (int*)malloc (numVertices * sizeof(int));
  assert(ShortestPathsWithQueue->predecessor!=NULL);

  for(int i = 0; i < numVertices; i++){
    ShortestPathsWithQueue->distance[i] = INT_MAX/2;
    ShortestPathsWithQueue->predecessor[i] = -1;
  }
  ShortestPathsWithQueue->distance[startVertex]=0;
  ShortestPathsWithQueue->predecessor[startVertex]=0;
  ShortestPathsWithQueue->graph = g;
  ShortestPathsWithQueue->startVertex = startVertex;

  int belongs[numVertices];
  for(int i = 0;i<numVertices;i++){
    belongs[i]=0;
  }
  // EXECUTAR O ALGORITMO
  Queue* q = QueueCreate(numVertices);
  QueueEnqueue(q,startVertex);
  while (!QueueIsEmpty(q)){
    int u = QueueDequeue(q);
    belongs[u] = 0;
    int uDist = ShortestPathsWithQueue->distance[u];
    unsigned int* adj = GraphGetAdjacentsTo(ShortestPathsWithQueue->graph,u);
    int* dist =  GraphGetDistancesToAdjacents(ShortestPathsWithQueue->graph,u);
    for (int i = 1; i <= adj[0]; i++){
      int vDist= ShortestPathsWithQueue->distance[adj[i]];
      if (uDist + dist[i]< vDist){
        ShortestPathsWithQueue->distance[adj[i]] = uDist + dist[i];
        ShortestPathsWithQueue->predecessor[adj[i]] = u;
        if(!belongs[adj[i]]){
          QueueEnqueue(q,adj[i]);
        }
      }
    }
    free(adj);
    free(dist);
  }
  // COMPLETAR !!
  QueueDestroy(&q);
  return ShortestPathsWithQueue;
}

void GraphShortestPathsWithQueueDestroy(GraphShortestPathsWithQueue** p) {
  assert(*p != NULL);

  GraphShortestPathsWithQueue* aux = *p;

  free(aux->distance);
  free(aux->predecessor);

  free(*p);
  *p = NULL;
}

// Getting the result

unsigned int GraphShortestPathsWithQueueHasPathTo(
    const GraphShortestPathsWithQueue* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  return (p->distance[v] != INT_MAX);
}

int GraphShortestPathsWithQueueDistanceTo(const GraphShortestPathsWithQueue* p,
                                          unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  return p->distance[v];
}

Stack* GraphShortestPathsWithQueuePathTo(const GraphShortestPathsWithQueue* p,
                                         unsigned int v) {
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

void GraphShortestPathsWithQueueShowPath(const GraphShortestPathsWithQueue* p,
                                         unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  Stack* s = GraphShortestPathsWithQueuePathTo(p, v);

  while (StackIsEmpty(s) == 0) {
    printf("%d ", StackPop(s));
  }

  printf(" --- Distance = %d", p->distance[v]);

  StackDestroy(&s);
}

void GraphShortestPathsWithQueueDisplay(const GraphShortestPathsWithQueue* p) {
  // COMPLETAR !!
  int v;
  for(v = 0; v < GraphGetNumVertices(p); v++){
    Queue* q = GraphShortestPathsWithQueuePathTo(p, v);
    printf("\nvertex %d adjacent vertices\n",v);
    while(QueueIsEmpty(q) == 0){
      printf("%d -> ",p->startVertex);
      QueueDequeue(q);
    }
    printf("\n");
  }
}
