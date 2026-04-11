#include <limits.h>

#define SIZE 105

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int K) {
    
    int adj[SIZE][SIZE];
    int i, j;

    // Initialize
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            adj[i][j] = -1;

    // Build graph
    for(i = 0; i < flightsSize; i++) {
        int u = flights[i][0];
        int v = flights[i][1];
        int w = flights[i][2];
        adj[u][v] = w;
    }

    // Queue
    int nodeQ[10000], costQ[10000], stopQ[10000];
    int front = 0, rear = 0;

    nodeQ[rear] = src;
    costQ[rear] = 0;
    stopQ[rear] = 0;
    rear++;

    int minCost = INT_MAX;

    while(front < rear) {
        int node = nodeQ[front];
        int cost = costQ[front];
        int stops = stopQ[front];
        front++;

        if(node == dst && cost < minCost)
            minCost = cost;

        if(stops > K) continue;

        for(i = 0; i < n; i++) {
            if(adj[node][i] != -1) {
                int newCost = cost + adj[node][i];

                if(newCost < minCost) {
                    nodeQ[rear] = i;
                    costQ[rear] = newCost;
                    stopQ[rear] = stops + 1;
                    rear++;
                }
            }
        }
    }

    return (minCost == INT_MAX) ? -1 : minCost;
}
