Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2

  #include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Find node by value
struct Node* findNode(struct Node* root, int val) {
    if (root == NULL)
        return NULL;
    if (root->data == val)
        return root;

    struct Node* left = findNode(root->left, val);
    if (left != NULL)
        return left;

    return findNode(root->right, val);
}

// LCA function
struct Node* LCA(struct Node* root, struct Node* p, struct Node* q) {
    if (root == NULL)
        return NULL;

    if (root == p || root == q)
        return root;

    struct Node* left = LCA(root->left, p, q);
    struct Node* right = LCA(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    if (left != NULL)
        return left;
    else
        return right;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int v1, v2;
    scanf("%d %d", &v1, &v2);

    struct Node* root = buildTree(arr, n);

    struct Node* p = findNode(root, v1);
    struct Node* q = findNode(root, v2);

    struct Node* lca = LCA(root, p, q);

    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}
