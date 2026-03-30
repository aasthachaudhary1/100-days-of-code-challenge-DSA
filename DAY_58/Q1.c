#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct TreeNode* build(
    int preorder[], int inorder[],
    int inStart, int inEnd,
    int *preIndex
) {
    if (inStart > inEnd)
        return NULL;

    struct TreeNode* node =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    node->val = preorder[*preIndex];
    node->left = node->right = NULL;
    (*preIndex)++;

    if (inStart == inEnd)
        return node;

    int inIndex = findIndex(inorder, inStart, inEnd, node->val);

    node->left = build(preorder, inorder, inStart, inIndex - 1, preIndex);
    node->right = build(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return node;
}

struct TreeNode* buildTree(
    int* preorder, int preorderSize,
    int* inorder, int inorderSize
) {
    int preIndex = 0;
    return build(preorder, inorder, 0, inorderSize - 1, &preIndex);
}
