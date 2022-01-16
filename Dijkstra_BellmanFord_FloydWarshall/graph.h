#ifndef GRAPH_H_
#define GRAPH_H_
#include <stdio.h>
#include <stdlib.h>
#define N 4
#define INF 9999

typedef struct node {
  int destination, weight;
  struct node* next;
}node;

typedef struct edge{
  int source, destination;
  int weight;
}edge;

typedef struct graph {
  node* nodeLists[N];
}graph;

graph* createGraph(edge AdjacencyList[], int n);
void printGraph(graph* graph);
int* Dijkstra(graph* graph);
int* BellmanFord(graph* graph);
void FloydMarshall(graph *graph);

#endif
