 Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

   #include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10005

// Min Heap Node
typedef struct {
    int node;
    int dist;
} HeapNode;

// Min Heap
typedef struct {
    HeapNode arr[MAX];
    int size;
} MinHeap;

// Swap
void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(MinHeap *heap, int i) {
    while (i > 0 && heap->arr[(i - 1) / 2].dist > heap->arr[i].dist) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify Down
void heapifyDown(MinHeap *heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left].dist < heap->arr[smallest].dist)
        smallest = left;

    if (right < heap->size && heap->arr[right].dist < heap->arr[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Push into heap
void push(MinHeap *heap, int node, int dist) {
    heap->arr[heap->size].node = node;
    heap->arr[heap->size].dist = dist;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

// Pop min
HeapNode pop(MinHeap *heap) {
    HeapNode root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapifyDown(heap, 0);
    return root;
}

// Adjacency List Node
typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

// Add edge
void addEdge(Node* adj[], int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra using Min Heap
void dijkstra(int n, Node* adj[], int src) {
    int dist[MAX];

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    push(&heap, src, 0);

    while (heap.size > 0) {
        HeapNode top = pop(&heap);
        int u = top.node;
        int d = top.dist;

        if (d > dist[u]) continue;

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->v;
            int weight = temp->w;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("Node %d: INF\n", i);
        else
            printf("Node %d: %d\n", i, dist[i]);
    }
}
