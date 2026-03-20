 Count Leaf Nodes

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
int countLeafNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Count in left and right subtree
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
