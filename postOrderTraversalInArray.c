void postOrderTraversalInArray(struct TreeNode* root,int* array,int* size){
    if(root != NULL){
        postOrderTraversalInArray(root->left,array,size);
        postOrderTraversalInArray(root->right,array,size);
        array[*size] = root->val;
        (*size)++;
    }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(100*sizeof(int));
    int i = 0;

    postOrderTraversalInArray(root,array,&i);
    *returnSize = i;

    return array;
}
