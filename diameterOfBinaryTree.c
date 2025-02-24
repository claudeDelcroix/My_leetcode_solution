/*cette version du code a un resultat de 101/106
 * et failli a 5 test pourtant l'approche n'est pas mal calcul
 * les longueur max des sous arbres de gauche et de droit et
 * et renvoi la somme des deux
 */


int diameterOfBinaryTree(const Tree* root) {
    if(root == NULL) {
        return 0;
    }

    int maxLeft = 0,maxRight = 0;
    if(root->left != NULL) {
        maxLeft = height(root->left);
    }
    if(root->right != NULL) {
        maxRight = height(root->right);
    }
    return maxLeft + maxRight;
}

//version optimiser de diameter et passe tous les tests
//la logique est meilleure et les performances sont excellentes

//combiner la recherche de height et du diameter
int heightAndDiameter(const Tree* root,int* diameter) {
    if(root == NULL) {
        return 0;
    }

    const int leftHeight = heightAndDiameter(root->left,diameter);
    const int rightHeight = heightAndDiameter(root->right,diameter);

    const int currentDiameter = leftHeight + rightHeight;
    if(currentDiameter > *diameter) {
        *diameter = currentDiameter;
    }
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int diameterOfBinaryTreeBest(const Tree* root) {
    int diameter = 0;
    heightAndDiameter(root,&diameter);
    return diameter;
}
