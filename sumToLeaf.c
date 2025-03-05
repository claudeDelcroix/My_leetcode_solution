/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <math.h>

int binaryToNumber(const int* array,const int* size){
    if(array == NULL){
        return 0;
    }
    int sum = 0;
    for(int i = 0,j = *size -1;i < *size;i++,j--){
        sum += array[i]*pow(2,j);
    }
    return sum;
}

void storeBranchValues(const struct TreeNode* root,int* branch,int* size,int* maxSize,int* sum){
    if(root == NULL){
        return;
    }
    if(*size >= *maxSize){
        *maxSize *= 2;
        branch = (int*)realloc(branch,(*maxSize)*sizeof(int));
    }
    branch[(*size)++] = root->val;

    if(root->left == NULL && root->right == NULL){
        *sum += binaryToNumber(branch,size);
    }
    storeBranchValues(root->left,branch,size,maxSize,sum);
    storeBranchValues(root->right,branch,size,maxSize,sum);

    (*size)--;
}

 
int sumRootToLeaf(struct TreeNode* root) {
    int* arr_binary = (int*)malloc(50*sizeof(int));
    int sum = 0,size = 0,maxSize = 50;
    storeBranchValues(root,arr_binary,&size,&maxSize,&sum);
    free(arr_binary);
    return sum;
}
