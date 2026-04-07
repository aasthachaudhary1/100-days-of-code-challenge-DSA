Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
bool dfs(int node, int* visited, int* recStack, int** adj, int* adjSize) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int nei = adj[node][i];

        if (!visited[nei]) {
            if (dfs(nei, visited, recStack, adj, adjSize))
                return true;
        }
        else if (recStack[nei]) {
            return true; // cycle found
        }
    }

    recStack[node] = 0; // remove from recursion stack
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // adjacency list
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int)); // max edges
    }

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v; // directed edge
    }

    int* visited = (int*)calloc(n, sizeof(int));
    int* recStack = (int*)calloc(n, sizeof(int));

    // check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, adj, adjSize)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
