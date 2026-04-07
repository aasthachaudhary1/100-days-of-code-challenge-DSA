#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function to detect cycle
bool dfs(int node, int* state, int** adj, int* adjSize) {
    if (state[node] == 1) return true;   // cycle found
    if (state[node] == 2) return false;  // already processed

    state[node] = 1; // mark as visiting

    for (int i = 0; i < adjSize[node]; i++) {
        int nei = adj[node][i];
        if (dfs(nei, state, adj, adjSize)) {
            return true;
        }
    }

    state[node] = 2; // mark as visited
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    // Step 1: Create adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int)); // max possible
    }

    // Fill adjacency list
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a;
    }

    // Step 2: State array
    int* state = (int*)calloc(numCourses, sizeof(int));

    // Step 3: Check each node
    for (int i = 0; i < numCourses; i++) {
        if (dfs(i, state, adj, adjSize)) {
            return false; // cycle exists
        }
    }

    return true;
}
