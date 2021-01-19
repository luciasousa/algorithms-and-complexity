//
// Joaquim Madeira, AlgC, June 2020
// João Manuel Rodrigues, AlgC, June 2020
//
// GraphDijkstra - Dijkstra Alg for the Shortest Paths Tree
//

#include "GraphDijkstra.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "IntegersStack.h"
#include "PriorityQueue.h"

struct _GraphDijkstra {
  int* distance;
  int* predecessor;
  Graph* graph;
  unsigned int startVertex;
};

// FOR THE PRIORITY QUEUE /////////////////////////////////////////////

// The items in the priority queue will be ID:PRIORITY pairs (type ITEM)

typedef struct {
  int id;   // item id (assigned automatically = index in ITEM array)
  int pri;  // item priority (assigned by the user)
} ITEM;

// The priority comparator for items.
int comparator(const void* p1, const void* p2) {
  return ((ITEM*)p1)->pri - ((ITEM*)p2)->pri;
}

// The printer for items.
void printer(void* p) {
  ITEM* pitem = (ITEM*)p;
  printf("%d:%d", pitem->id, pitem->pri);
}

///////////////////////////////////////////////////////////////////////

GraphDijkstra* GraphDijkstraExecute(Graph* g, unsigned int startVertex) {
  assert(g != NULL);
  assert(0 <= startVertex && startVertex < GraphGetNumVertices(g));

  GraphDijkstra* result = (GraphDijkstra*)malloc(sizeof(struct _GraphDijkstra));
  assert(result != NULL);

  unsigned int numVertices = GraphGetNumVertices(g);

  //
  // COMPLETAR !!
  //
  // CRIAR e INICIALIZAR os campos de result
  // result->distance
  // result->predecessor
  //

  result->distance = (int*) malloc(numVertices*sizeof(int));
  assert(result->distance != NULL);
  result->predecessor = (int*) malloc(numVertices*sizeof(int));
  assert(result->predecessor != NULL);

  for (int i = 1; i < numVertices; i++) {
    result->distance[i] = INT_MAX/2;
    result->predecessor[i] = -1;
  }
  result->distance[startVertex]=0;
  result ->predecessor[startVertex]=0;
  result->graph = g;
  result->startVertex = startVertex; 

  // EXECUTAR O ALGORITMO
  PriorityQueue* pq = PriorityQueueCreate(numVertices,comparator,printer);
  ITEM items[numVertices];
  for(int i=0;i<numVertices;i++){
    items[i].id = i;
    items[i].pri = INT_MAX/2;
    PriorityQueueInsert(pq,&(items[i]));
  }
  items[startVertex].pri=0;
  PriorityQueueDecreasePriority(pq,&(items[startVertex]));
  
  while (!PriorityQueueIsEmpty(pq)){
    int u = ((ITEM*) (PriorityQueueGetMin(pq)))->id;
    PriorityQueueRemoveMin(pq);
    int uDist = result->distance[u];
    unsigned int* adj = GraphGetAdjacentsTo(g,u);
    int* dist = GraphGetDistancesToAdjacents(g,u);
    for (int i = 0; i <= adj[0]; i++){
      int vDist = result->distance[adj[i]];
      if(uDist + dist[i]< vDist){
        result->distance[adj[i]] = uDist + dist[i];
        result->predecessor[adj[i]] = u;
        items[adj[i]].pri= result->distance[adj[i]];
        PriorityQueueDecreasePriority(pq,&items[adj[i]]);
      }
    }
  }
  // COMPLETAR !!
  PriorityQueueDestroy(&pq);
  return result;
}

void GraphDijkstraDestroy(GraphDijkstra** p) {
  assert(*p != NULL);

  GraphDijkstra* aux = *p;

  free(aux->distance);
  free(aux->predecessor);

  free(*p);
  *p = NULL;
}

// Getting the result

unsigned int GraphDijkstraHasPathTo(const GraphDijkstra* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  return (p->distance[v] != INT_MAX);
}

int GraphDijkstraDistanceTo(const GraphDijkstra* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  return p->distance[v];
}

Stack* GraphDijkstraPathTo(const GraphDijkstra* p, unsigned int v) {
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

void GraphDijkstraShowPath(const GraphDijkstra* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  Stack* s = GraphDijkstraPathTo(p, v);

  while (StackIsEmpty(s) == 0) {
    printf("%d ", StackPop(s));
  }

  printf(" --- Distance = %d", p->distance[v]);

  StackDestroy(&s);
}

void GraphDijkstraDisplay(const GraphDijkstra* p) {
  // COMPLETAR !!
  int v;
  for(v = 0; v < GraphGetNumVertices(p); v++){
    PriorityQueue* pq = GraphDijkstraPathTo(p, v);
    printf("\nVertice: %d\n",v);
    while(!PriorityQueueIsEmpty(pq)){
      printf("%d -> ",p->startVertex);
      PriorityQueueRemoveMin(pq);
    }
    printf("\n");
  }
}
