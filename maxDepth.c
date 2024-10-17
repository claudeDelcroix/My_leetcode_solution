/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    else {
        const int leftHeight = maxDepth(root->left);
        const int rightHeight = maxDepth(root->right);
        if(leftHeight > rightHeight) {
            return (leftHeight + 1);
        }else {
            return (rightHeight + 1);
        }
    }
}
