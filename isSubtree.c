/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(const struct TreeNode* root,const struct TreeNode* root1){
    if(root == NULL && root1 == NULL){
        return true;
    }
    if(root == NULL || root1 == NULL){
        return false;
    }
    if(root->val != root1->val ){
        return false;
    }
    return isSameTree(root->left,root1->left) && isSameTree(root->right,root1->right);
}


bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if(root == NULL){
        return false;
    }
    if(subRoot == NULL){
        return true;
    }
    if(isSameTree(root,subRoot)){
        return true;
    }
    return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
}

//solution with 0ms 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSame(struct TreeNode* s, struct TreeNode* t) {
    if (!s && !t) 
        return true;
    if (!s || !t) 
        return false;
    if (s->val != t->val) 
        return false;
    return isSame(s->left, t->left) && isSame(s->right, t->right);
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    if (!s) return false;
    if (isSame(s, t)) return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSame(struct TreeNode* s, struct TreeNode* t) {
    if (!s && !t) 
        return true;
    if (!s || !t) 
        return false;
    if (s->val != t->val) 
        return false;
    return isSame(s->left, t->left) && isSame(s->right, t->right);
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    if (!s) return false;
    if (isSame(s, t)) return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}
