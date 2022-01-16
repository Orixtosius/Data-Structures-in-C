#include "graph.h"
int main(void)
{
    edge edges[] =
    {
        {0, 1, 6}, {0, 2, 2}, {1, 2, 3}, {2, 3, 5}
    };
 
    int n = sizeof(edges)/sizeof(edges[0]);
 
    graph *graph = createGraph(edges, n);

    
    int sum=0;
    printf("----------------------------------------------------------------------------------\n");
    printf("GRAPH STRUCTURE\n\n"); 
    printGraph(graph);
    printf("---------------------------------DIJKSTRA-----------------------------------------\n");
    int *res = Dijkstra(graph);
    printf("----------------------------------------------------------------------------------\n");
    for(int i=0;i<N;i++) {
        printf("Cost of %d operation is %d\n",i,res[i]);
        sum += res[i];
    }
    printf("----------------------------------------------------------------------------------\n");
    printf("Total cost of operations is %d",sum);
    printf("----------------------------------------------------------------------------------\n\n");

    printf("--------------------------------BELLMANFORD---------------------------------------\n");
    int *bf = BellmanFord(graph);
    int sumbs = 0;
    printf("----------------------------------------------------------------------------------\n");
    for(int i=0;i<N;i++) {
        printf("Cost of %d operation is %d\n",i,bf[i]);
        sumbs += bf[i];
    }
    printf("----------------------------------------------------------------------------------\n");
    printf("Total cost of operations is %d",sumbs);
    printf("----------------------------------------------------------------------------------\n\n");
    printf("---------------------------------FLOYDMARSHALL------------------------------------\n");
    FloydMarshall(graph);

    return 0;
}