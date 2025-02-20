/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool preOrderTraversalAndSearch(const struct TreeNode* root,const int x){
    if(root == NULL){
        return false;
    }
    if(root->val == x){
        return true;
    }
    return preOrderTraversalAndSearch(root->left,x) || preOrderTraversalAndSearch(root->right,x);
}

void findLevelAndParent(const struct TreeNode* root,const int x,int*level,int* parent,const int depth){
    if(root == NULL){
        return ;
    }
    if(root->left && root->left->val == x){
        *level = depth;
        *parent = root->val;
        return;
    }
    if(root->right && root->right->val == x){
        *level = depth;
        *parent = root->val;
        return;
    }
    findLevelAndParent(root->left,x,level,parent,depth+1);
    findLevelAndParent(root->right,x,level,parent,depth+1);
}

bool isCousins(struct TreeNode* root, int x, int y) {
    if(root == NULL){
        return false;
    }
    if(x == root->val || y == root->val){
        return false;
    }
   if ((root->left && root->left->val == x && root->right && root->right->val == y) ||
        (root->left && root->left->val == y && root->right && root->right->val == x)) {
        return false;
    }
    int levelX = 0,parentX = -1;
    int levelY = 0, parentY = -1;

    findLevelAndParent(root,x,&levelX,&parentX,0);
    findLevelAndParent(root,y,&levelY,&parentY,0);

    return (levelX == levelY) && (parentX != parentY);
}
