struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void flatten(struct TreeNode* root) {
    if (root == NULL)
        return;

    // Flatten left and right subtrees
    flatten(root->left);
    flatten(root->right);

    // Store right subtree
    struct TreeNode* temp = root->right;

    // Move left subtree to right
    root->right = root->left;
    root->left = NULL;

    // Go to end of new right subtree
    struct TreeNode* curr = root;
    while (curr->right != NULL) {
        curr = curr->right;
    }

    // Attach original right subtree
    curr->right = temp;
}
