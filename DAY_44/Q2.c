int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    struct TreeNode* stack[100];
    int top = -1, index = 0;

    if(root == NULL){
        *returnSize = 0;
        return result;
    }

    stack[++top] = root;

    while(top >= 0){
        struct TreeNode* node = stack[top--];
        result[index++] = node->val;

        if(node->right)
            stack[++top] = node->right;

        if(node->left)
            stack[++top] = node->left;
    }

    *returnSize = index;
    return result;
}
