/*
Given the root of a binary tree, return the sum of every tree node's tilt.

The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if the node does not have a right child.
*/ 
int calculateTilt(const Tree* root,int* totalTilt) {
    if(root == NULL) {
        return 0;
    }
    const int leftSum = calculateTilt(root->left,totalTilt);
    const int rightSum = calculateTilt(root->right,totalTilt);
    const int tilt = abs(leftSum - rightSum);
    *totalTilt += tilt;
    return root->data + leftSum + rightSum;
}

int findTilt(const Tree* root) {
    int totalTilt = 0;
    calculateTilt(root,&totalTilt);
    return totalTilt;
}

//autre methode 

int leftSum(struct TreeNode* root, int sum){
    if(root == NULL) return sum;
    sum += root->val;
    sum = leftSum(root->left, sum);
    sum = leftSum(root->right, sum);
    return sum;
}

int rightSum(struct TreeNode* root, int sum){
    if(root == NULL) return sum;
    sum += root->val;
    sum = rightSum(root->left, sum);
    sum = rightSum(root->right, sum);
    return sum;
}

int findTilt(struct TreeNode* root) {
    if(root == NULL) return 0;

    int sumL = 0, sumR = 0;
    int leftVal = leftSum(root->left, sumL);
    int rightVal = rightSum(root->right, sumR);
    int tilt = abs(leftVal - rightVal);
    return tilt + findTilt(root->left) + findTilt(root->right);
}
