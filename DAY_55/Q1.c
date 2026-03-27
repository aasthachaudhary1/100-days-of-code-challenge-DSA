#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void solve(struct TreeNode* root, int level, int* result, int* returnSize) {
    if (root == NULL)
        return;

    if (level == *returnSize) {
        result[*returnSize] = root->val;
        (*returnSize)++;
    }

    solve(root->right, level + 1, result, returnSize);
    solve(root->left, level + 1, result, returnSize);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;

    solve(root, 0, result, returnSize);

    return result;
}
