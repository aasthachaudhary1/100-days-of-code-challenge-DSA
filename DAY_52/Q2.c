struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL)
        return NULL;

    // If either p or q is the root
    if (root == p || root == q)
        return root;

    // Search in left and right subtree
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both sides returned non-NULL, this is LCA
    if (left != NULL && right != NULL)
        return root;

    // Otherwise return non-NULL child
    if (left != NULL)
        return left;
    else
        return right;
}
