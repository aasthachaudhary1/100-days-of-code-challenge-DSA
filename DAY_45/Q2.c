int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0; // Base case: empty tree
    }
    
    int leftDepth = maxDepth(root->left);   // Depth of left subtree
    int rightDepth = maxDepth(root->right); // Depth of right subtree
    
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}
