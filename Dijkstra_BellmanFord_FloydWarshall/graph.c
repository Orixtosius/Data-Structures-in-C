#include "graph.h"

graph* createGraph(edge AdjacencyList[], int n) {
  graph* newGraph = (graph*)malloc(sizeof(graph));

  for(int i=0;i<N;i++) {
    newGraph->nodeLists[i] = NULL;
  }

  for (int i = 0; i < n; ++i) {

    int source = AdjacencyList[i].source;
    int destination = AdjacencyList[i].destination;
    int weight = AdjacencyList[i].weight;

    node* newNode = (node*)malloc(sizeof(node));
    newNode->destination = destination;
    newNode->weight = weight;
    newNode->next = newGraph->nodeLists[source];
    newGraph->nodeLists[source] = newNode;
  }
  return newGraph;
}

void printGraph(graph* graph) {
  for (int i = 0; i < N; i++) {

        node* vertex = graph->nodeLists[i];
        while (vertex != NULL)
        {
            printf("%d ---> %d (%d)\t", i, vertex->destination, vertex->weight);
            vertex = vertex->next;
        }
 
        printf("\n");
    }
}

int* BellmanFord(graph* graph) {
  static int costs[N];
  costs[0] = 0;
  //Assigning infinite costs except first element
  for(int i=1;i<=N;i++) {
    costs[i] = INF;
  }

  node *vertex;

  for(int i=0;i<N;i++) {
    vertex = graph->nodeLists[i];
    while(vertex != NULL) {
      if(costs[vertex->destination] > vertex->weight + costs[i])
        costs[vertex->destination] = vertex->weight + costs[i];
      vertex = vertex->next;
    }
  }

  return costs;
}

int* Dijkstra(graph* graph) {
    int min = INF;
    int dest = INF;
    node *vertex;
    int weightpre = 0;
    static int costs[N];
    int visited[0];
    costs[0] = 0;
    visited[0] = 1;
    for(int i=1;i<=N;i++) {
      costs[i] = INF;
      visited[i] = 0;
    }

    for(int i=0;i<N;i++)
      {
        if(visited[i]==1) 
        {
          vertex = graph->nodeLists[i];

          while (vertex != NULL) {
            if(vertex->weight + costs[i] <min)
            {
              min = vertex->weight + costs[i];
              dest = vertex->destination;
            }
            vertex = vertex->next;         
            }
            costs[dest] = min;
            visited[dest] = 1;
            printf("Chosen path is from %d to %d and its weight is %d\n",i,dest, costs[dest]);
            printf("%d ---> %d (%d)\n", i, dest, costs[dest]);        
        }
      }

    for(int i=0;i<=N;i++) {
      if(visited[i]==0) {
        min = costs[i];
        for(int j=0;j<=N && i!=j;j++) {
          vertex = graph->nodeLists[j];
          while (vertex!=NULL) {
            if(vertex->destination == i && min> vertex->weight + costs[j]) {
              min = vertex->weight + costs[j];
              dest = j;
            }
            vertex = vertex->next;
          } 
        }
      costs[i] = min;
      visited[i]=1;
      printf("Chosen path is from %d to %d and its weight is %d\n",i,dest, costs[i]);
      printf("%d ---> %d (%d)\n", i, dest, i);   
      }
    }

      return costs;
}


void FloydMarshall(graph *graph) {
    int CostVertex[N+1][N+1];
    node *vertex;
    int dest;
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++)
        {
            if(i==j)
                CostVertex[i][j] = 0;
            else
                CostVertex[i][j] = INF;            
        }
    }
    for(int i=0;i<=N;i++)
    {
        vertex = graph->nodeLists[i];
            while(vertex != NULL) {
                CostVertex[i][vertex->destination] = vertex->weight;
                vertex=vertex->next;
            }
    }
    
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++) {
            for(int k=0;k<=N;k++) {
                if (CostVertex[i][k] + CostVertex[k][j] < CostVertex[i][j])
                    CostVertex[i][j] = CostVertex[i][k] + CostVertex[k][j];
            }
        
        }       
    }
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++) {
          printf("[Line:%d Column:%d] = %d \t",i,j,CostVertex[i][j]);          
        }
        printf("\n");

    }   
}
