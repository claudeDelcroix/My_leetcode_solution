/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// calcul la valeur minimun entre les noeuds
//les noeuds sont d'abord placer dans un tableau et ensuite la difference est a calculer
//entre chaque noeud les uns apres avec les autres
// Given the root of a Binary Search Tree (BST), return the minimum
// difference between the values of any two different nodes in the tree.
// Given the root of a Binary Search Tree (BST), return the minimum absolute
// difference between the values of any two different nodes in the tree.



 #include <math.h>
void inOrderTraversal(const struct TreeNode* root,int *array,int* index){
    if(root != NULL){
        inOrderTraversal(root->left,array,index);
        array[*index] = root->val;
        (*index)++;
        inOrderTraversal(root->right,array,index);
    }
}

int* inOrderInArray(const struct TreeNode* root,int* returnSize){
    int *array = (int*)malloc(10001*sizeof(int));
    if(array == NULL){
        fprintf(stderr,"allocation failled\n");
        exit(1);
    }
    
    inOrderTraversal(root,array,returnSize);
    return array;
}

int minDifference(const int *arr,const int sizeArr){
    int min = INT_MAX;
    for(int i = 1;i < sizeArr;i++){
        if(abs(arr[i] - arr[i-1]) <= min){
            min = abs(arr[i] - arr[i-1]);
        }
    }
    return min;
}

int getMinimumDifference(struct TreeNode* root) {
    int sizeArray = 0;
    int* array = inOrderInArray(root,&sizeArray);
    const int min = minDifference(array,sizeArray);
    free(array);
    return min;
}
