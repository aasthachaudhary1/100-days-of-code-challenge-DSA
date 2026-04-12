#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int absVal(int x) {
    return (x < 0) ? -x : x;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    (void)pointsColSize;  // 🔥 prevents unused parameter error

    bool* visited = (bool*)malloc(pointsSize * sizeof(bool));
    int* minDist = (int*)malloc(pointsSize * sizeof(int));

    for (int i = 0; i < pointsSize; i++) {
        visited[i] = false;
        minDist[i] = INT_MAX;
    }

    minDist[0] = 0;
    int totalCost = 0;

    for (int i = 0; i < pointsSize; i++) {
        int u = -1;

        for (int j = 0; j < pointsSize; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = true;
        totalCost += minDist[u];

        for (int v = 0; v < pointsSize; v++) {
            if (!visited[v]) {
                int dist = absVal(points[u][0] - points[v][0]) +
                           absVal(points[u][1] - points[v][1]);

                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    free(visited);
    free(minDist);

    return totalCost;
}
