// version avec 0 ms
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if(root1 == NULL) return root2;    
    if(root2 == NULL) return root1;

    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);    
    root1->right = mergeTrees(root1->right, root2->right);    

    return root1;
}

// ma version avec l'aide de copilot 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if(root1 == NULL)return root2;
    if(root2 == NULL)return root1;

    struct TreeNode* tree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if(tree == NULL){
        fprintf(stderr,"Erreur d'allocation memoire \n");
        exit(1);
    }
    tree->val = (root1?root1->val : 0) + (root2? root2->val : 0);
    
    tree->left = mergeTrees(root1? root1->left:NULL,root2?root2->left:NULL);
    tree->right = mergeTrees(root1?root1->right : NULL,root2?root2->right : NULL);
    return tree;
}
