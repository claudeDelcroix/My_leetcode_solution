/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void inOrderInArray(struct TreeNode* root,int* array,int*index){
    if(root != NULL){
        inOrderInArray(root->left,array,index);
        array[*index] = root->val;
        (*index)++;
        inOrderInArray(root->right,array,index);
    }
 }
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(100*sizeof(int));
    int i = 0;

    inOrderInArray(root,array,&i);
    *returnSize = i;

    return array;
}
