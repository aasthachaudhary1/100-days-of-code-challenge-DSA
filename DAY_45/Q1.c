Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3
  #include <stdio.h>
#include <stdlib.h>

// Define the binary tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    if (data == -1) return NULL;  // -1 represents NULL
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the height of the binary tree
int height(struct Node* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to build tree from level-order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;
    
    struct Node* root = newNode(arr[0]);
    queue[rear++] = root;
    
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];
        if (curr == NULL) continue;
        
        // Left child
        curr->left = newNode(arr[i++]);
        if (curr->left) queue[rear++] = curr->left;
        
        if (i >= n) break;
        
        // Right child
        curr->right = newNode(arr[i++]);
        if (curr->right) queue[rear++] = curr->right;
    }
    
    free(queue);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct Node* root = buildTree(arr, n);
    printf("%d\n", height(root));
    
    return 0;
}
