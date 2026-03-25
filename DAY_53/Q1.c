Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.

  #include <stdio.h>
#include <stdlib.h>

/* Tree Node */
struct Node {
    int data;
    struct Node *left, *right;
};

/* Queue Node for BFS with Horizontal Distance */
struct QNode {
    struct Node* node;
    int hd;
};

/* Create new tree node */
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

/* Build tree from level order */
struct Node* buildTree(int arr[], int n) {
    if (arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[100];
    int front = 0, rear = 0;

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

/* Vertical Order Traversal */
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct QNode queue[100];
    int front = 0, rear = 0;

    int hdMap[200][100];  // store nodes
    int count[200] = {0};

    int minHD = 0, maxHD = 0;

    queue[rear++] = (struct QNode){root, 0};

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* node = temp.node;
        int hd = temp.hd + 100;

        hdMap[hd][count[hd]++] = node->data;

        if (temp.hd < minHD) minHD = temp.hd;
        if (temp.hd > maxHD) maxHD = temp.hd;

        if (node->left)
            queue[rear++] = (struct QNode){node->left, temp.hd - 1};

        if (node->right)
            queue[rear++] = (struct QNode){node->right, temp.hd + 1};
    }

    for (int i = minHD; i <= maxHD; i++) {
        int index = i + 100;
        for (int j = 0; j < count[index]; j++) {
            printf("%d ", hdMap[index][j]);
        }
        printf("\n");
    }
}

/* Main */
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
