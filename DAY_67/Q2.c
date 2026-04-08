Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Graph
struct Node* adj[MAX];

// Stack
int stack[MAX];
int top = -1;

// Visited array
int visited[MAX];

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge u -> v
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS function
void DFS(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }

    push(v);
}

// Topological Sort
void topologicalSort(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    printf("Topological Order:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Main function
int main() {
    int n, e;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    topologicalSort(n);

    return 0;
}
