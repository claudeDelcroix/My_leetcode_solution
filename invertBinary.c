// Fonction pour inverser un arbre binaire
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    
    // Échanger les sous-arbres gauche et droit
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Inverser récursivement les sous-arbres gauche et droit
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}

//mon idee de base , a echouer a cause du fait que il aurait pu avoir 
//des arbres de la formes [1,2] et une fois renverse donnerais la forme suivante [1,null,2]
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int height(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    else{
        const int leftHeight = height(root->left);
        const int rightHeight = height(root->right);
        if(leftHeight > rightHeight){
            return (leftHeight + 1);
        }else{
            return (rightHeight + 1);
        }
    }
}

struct TreeNode* createNode(const int data){
    struct TreeNode* noeud = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if(noeud == NULL){
        fprintf(stderr,"allocation failled\n");
        exit(1);
    }
    noeud->val = data;
    noeud->left = NULL;
    noeud->right = NULL;

    return noeud;
}

void level_order_to_array(struct TreeNode* root,const int level,int* arr,int* size){
    if(root == NULL){
        return;
    }
    if(level == 1){
        arr[*size] = root->val;
        (*size)++;
    }else if(level > 1){
        level_order_to_array(root->left,level - 1,arr,size);
        level_order_to_array(root->right,level - 1,arr,size);
    }
}

void levelOrderToArray(struct TreeNode* root,int* arr,int* size){
    const short h = height(root);
    for(short i = 1;i <= h;i++){
        level_order_to_array(root,i,arr,size);
    }
}

struct TreeNode* invertBinaryTreeFromArray(struct TreeNode* root,const int value) {
    if(root == NULL){
        struct TreeNode* node = createNode(value);
        return node;
    }else{
        struct TreeNode* cur = NULL;
        if(value >= root->val){
            cur = invertBinaryTreeFromArray(root->left,value);
            root->left = cur;
        }else{
            cur = invertBinaryTreeFromArray(root->right,value);
            root->right = cur;
        }
        return root;
    }
}

struct TreeNode* invertTree(struct TreeNode* root){
    if(root == NULL){
        return NULL;
    }
    int* arr = (int*)calloc(100,sizeof(int));
    if(arr == NULL){
        fprintf(stderr,"allocation failled\n");
        exit(1);
    }
    int size = 0;
    levelOrderToArray(root,arr,&size);
    struct TreeNode* newRoot = NULL;
    newRoot = createNode(arr[0]);

    for(short i = 1;i < size;i++){
        newRoot = invertBinaryTreeFromArray(newRoot,arr[i]);
    }

    return newRoot;
}
