#include <stdlib.h>

#define N 100005

struct Node {
    int v;
    struct Node* next;
};

struct Node* adj[N];
int disc[N], low[N], visited[N], parent[N];
int timeCounter;

int** result;
int* colSizes;
int idx;

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

void dfs(int u) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    struct Node* temp = adj[u];

    while (temp != NULL) {
        int v = temp->v;

        if (!visited[v]) {
            parent[v] = u;
            dfs(v);

            if (low[v] < low[u])
                low[u] = low[v];

            if (low[v] > disc[u]) {
                result[idx] = (int*)malloc(2 * sizeof(int));
                result[idx][0] = u;
                result[idx][1] = v;
                colSizes[idx] = 2;
                idx++;
            }
        }
        else if (v != parent[u]) {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }

        temp = temp->next;
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize, int* returnSize, int** returnColumnSizes) {
    
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
        parent[i] = -1;
    }

    for (int i = 0; i < connectionsSize; i++) {
        addEdge(connections[i][0], connections[i][1]);
    }

    result = (int**)malloc(connectionsSize * sizeof(int*));
    colSizes = (int*)malloc(connectionsSize * sizeof(int));

    idx = 0;
    timeCounter = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    *returnSize = idx;
    *returnColumnSizes = colSizes;

    return result;
}
