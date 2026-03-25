#include <stdio.h>
#include <stdlib.h>

/* Tree Node */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* Queue */
struct Queue {
    int front, rear, size;
    struct TreeNode **array;
};

/* Create Tree Node */
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

/* Create Queue */
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = 0;
    q->rear = -1;
    q->size = size;
    q->array = (struct TreeNode**)malloc(size * sizeof(struct TreeNode*));
    return q;
}

/* Check Empty */
int isEmpty(struct Queue* q) {
    return q->rear < q->front;
}

/* Enqueue */
void enqueue(struct Queue* q, struct TreeNode* node) {
    q->array[++q->rear] = node;
}

/* Dequeue */
struct TreeNode* dequeue(struct Queue* q) {
    return q->array[q->front++];
}

/* Level Order Traversal */
void levelOrder(struct TreeNode* root) {
    if (root == NULL) return;

    struct Queue* q = createQueue(100);

    enqueue(q, root);

    while (!isEmpty(q)) {
        struct TreeNode* temp = dequeue(q);
        printf("%d ", temp->val);

        if (temp->left)
            enqueue(q, temp->left);

        if (temp->right)
            enqueue(q, temp->right);
    }
}

/* Main */
int main() {

    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Level Order Traversal:\n");
    levelOrder(root);

    return 0;
}
