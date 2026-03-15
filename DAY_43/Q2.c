void inorder(struct TreeNode* root, int* arr, int* index)
{
    if(root == NULL)
        return;

    inorder(root->left, arr, index);   // Left

    arr[*index] = root->val;           // Root
    (*index)++;

    inorder(root->right, arr, index);  // Right
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *result = (int*)malloc(100 * sizeof(int));
    int index = 0;

    inorder(root, result, &index);

    *returnSize = index;
    return result;
}
