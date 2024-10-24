/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if(numsSize <= 0){
        return NULL;
    }
    int left = 0;
    int right = (numsSize - 1);
    int mid = (left + right)/2;

    struct TreeNode* leftNode = sortedArrayToBST(nums,mid);
    struct TreeNode* rightNode = sortedArrayToBST(nums + mid + 1,right - mid);

    struct TreeNode* pRoot = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    pRoot->val = nums[mid];
    pRoot->left = leftNode;
    pRoot->right = rightNode;

    return pRoot;
    
    
}
