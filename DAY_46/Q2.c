#include <stdio.h>
#include <stdlib.h>

/* Queue */
struct Queue {
    int front, rear;
    int capacity;
    struct TreeNode **array;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
    q->array = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    return q;
}

int isEmpty(struct Queue* q) {
    return (q->front > q->rear);
}

/* FIX: prevent overflow */
void enqueue(struct Queue* q, struct TreeNode* node) {
    if (q->rear == q->capacity - 1) return;  // safety check
    q->array[++q->rear] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->array[q->front++];
}

/* MAIN FUNCTION */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
    *returnSize = 0;
    if (!root) return NULL;

    /* 🔥 FIX: large capacity */
    int cap = 100000;  

    struct Queue* q = createQueue(cap);

    int** result = (int**)malloc(cap * sizeof(int*));
    *returnColumnSizes = (int*)malloc(cap * sizeof(int));

    enqueue(q, root);

    while (!isEmpty(q)) {
        int size = q->rear - q->front + 1;

        result[*returnSize] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[*returnSize] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = dequeue(q);
            result[*returnSize][i] = curr->val;

            if (curr->left) enqueue(q, curr->left);
            if (curr->right) enqueue(q, curr->right);
        }

        (*returnSize)++;
    }

    return result;
}
