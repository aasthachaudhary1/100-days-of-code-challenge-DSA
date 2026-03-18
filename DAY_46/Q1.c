Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
#include <stdio.h>
#include <stdlib.h>

/* Tree Node */
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

/* Create Node */
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

/* Queue for building tree */
struct Queue {
    struct TreeNode** arr;
    int front, rear;
};

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct TreeNode**)malloc(size * sizeof(struct TreeNode*));
    q->front = 0;
    q->rear = -1;
    return q;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[++q->rear] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

/* Build Tree from level order */
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;

    while (i < n) {
        struct TreeNode* curr = dequeue(q);

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

/* Level Order Traversal */
void levelOrder(struct TreeNode* root) {
    if (!root) return;

    struct Queue* q = createQueue(1000);
    enqueue(q, root);

    while (q->front <= q->rear) {
        int size = q->rear - q->front + 1;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = dequeue(q);
            printf("%d ", curr->val);

            if (curr->left) enqueue(q, curr->left);
            if (curr->right) enqueue(q, curr->right);
        }
        printf("\n");
    }
}

/* Main */
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}
