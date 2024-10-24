void preOrderInArray(struct TreeNode* root,int* array,int* size){
    if(root != NULL){
        array[(*size)] = root->val;
        (*size)++;
        preOrderInArray(root->left,array,size);
        preOrderInArray(root->right,array,size);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* array = (int*)malloc(100*sizeof(int));
    int i = 0;
    preOrderInArray(root,array,&i);
    *returnSize = i;

    return array;
}
