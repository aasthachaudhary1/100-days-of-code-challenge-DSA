Height of Binary Tree

Implement the solution problem.

Input:
- Input specifications

Output:
- Output specifications

#include <stdio.h>
#include <stdlib.h>

/* Tree Node */
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/* Queue for level-order construction */
struct Queue {
    struct TreeNode** arr;
    int front, rear, size;
};

/* Create Queue */
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct TreeNode**)malloc(size * sizeof(struct TreeNode*));
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

/* Enqueue */
void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
}

/* Dequeue */
struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

/* Create new node */
struct TreeNode* newNode(int val) {
    if (val == -1) return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

/* Build tree from level-order */
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;
    while (i < n) {
        struct TreeNode* curr = dequeue(q);

        if (i < n && arr[i] != -1) {
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

/* Function to find height */
int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

/* Main */
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    printf("%d\n", height(root));

    return 0;
}
