int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int sum = 0;

    // Check left child
    if (root->left != NULL) {
        // If left child is a leaf
        if (root->left->left == NULL && root->left->right == NULL) {
            sum += root->left->val;
        } else {
            sum += sumOfLeftLeaves(root->left);
        }
    }

    // Recur for right subtree
    sum += sumOfLeftLeaves(root->right);

    return sum;
}
