#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int findIndex(int* inorder, int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

struct TreeNode* build(int* inorder, int* postorder, int inStart, int inEnd, int* postIndex) {
    if(inStart > inEnd)
        return NULL;

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = postorder[*postIndex];
    node->left = node->right = NULL;

    (*postIndex)--;

    if(inStart == inEnd)
        return node;

    int inIndex = findIndex(inorder, inStart, inEnd, node->val);

    // Build right subtree first
    node->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = build(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIndex = postorderSize - 1;
    return build(inorder, postorder, 0, inorderSize - 1, &postIndex);
}
