#include <stdio.h>
#include <stdlib.h>

// Queue structure
typedef struct {
    int *data;
    int front, rear;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int) * size);
    q->front = q->rear = 0;
    return q;
}

void enqueue(Queue* q, int val) {
    q->data[q->rear++] = val;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Main function
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize,
               int* prerequisitesColSize, int* returnSize) {

    // Allocate graph
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    int* count = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int));
    }

    // Build graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];

        adj[prereq][count[prereq]++] = course;
        indegree[course]++;
    }

    // Queue for BFS
    Queue* q = createQueue(numCourses);

    // Push nodes with indegree 0
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            enqueue(q, i);
        }
    }

    int* result = (int*)malloc(numCourses * sizeof(int));
    int idx = 0;

    // BFS
    while (!isEmpty(q)) {
        int node = dequeue(q);
        result[idx++] = node;

        for (int i = 0; i < count[node]; i++) {
            int next = adj[node][i];
            indegree[next]--;

            if (indegree[next] == 0) {
                enqueue(q, next);
            }
        }
    }

    // Check if valid
    if (idx != numCourses) {
        *returnSize = 0;
        return (int*)malloc(0);  // empty array
    }

    *returnSize = numCourses;
    return result;
}
