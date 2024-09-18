#include <stdio.h>
#include <stdlib.h>

void afficherTrianglePascal(const int n) {
    int triangle[n][n];

    for (int ligne = 0; ligne < n; ligne++) {
        for (int i = 0; i <= ligne; i++) {
            if (i == 0 || i == ligne) {
                triangle[ligne][i] = 1;
            } else {
                triangle[ligne][i] = triangle[ligne-1][i-1] + triangle[ligne-1][i];
            }
            printf("%d ", triangle[ligne][i]);
        }
        printf("\n");
    }
}

int** generate(const int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    int** pascal = (int**)malloc(numRows*sizeof(int*));
    (*returnColumnSizes) = (int*)malloc(numRows*sizeof(int));

    for(int i = 0;i<numRows;i++){
        (*returnColumnSizes)[i] = i+1;
        pascal[i] = (int*)malloc((i+1)*sizeof(int));
    }
    if(numRows == 1){
        pascal[0][0] = 1;
        return pascal;
    }
    pascal[0][0] = 1;
    pascal [1][0] = 1;
    pascal[1][1] = 1;

    for(int i = 2;i<numRows;i++){
        pascal[i][0] = 1;
        pascal[i][i] = 1;
        for(int j = 1;j<i;j++){
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }

    return pascal;
}

//nouvelle fonction au nom de triangle de Pascal 2
//cette fonction permet de retourner un tableau a une dimension correspondant a la n-eme ligne du triangle avec cette entier n entrer par l'utilisateur 
int* getRow(int rowIndex, int* returnSize) {
    rowIndex+=1;
    *returnSize = rowIndex;
    int** pascal = (int**)malloc((rowIndex)*sizeof(int*));
   int* result = (int*)malloc((rowIndex )*sizeof(int));

      for(int i = 0;i<rowIndex;i++){
        pascal[i] = (int*)malloc((i+1)*sizeof(int));
      }
      if(rowIndex == 1){
        result[0] = 1;
        return result;
      }
      pascal[0][0] = 1;
      pascal [1][0] = 1;
      pascal[1][1] = 1;

      for(int i = 2;i<rowIndex ;i++){
        pascal[i][0] = 1;
        pascal[i][i] = 1;
        for(int j = 1;j<i;j++){
           pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
      }

       for(int i = 0;i<rowIndex;i++){
        result[i] = pascal[rowIndex-1][i];
       }
    for(int i = 0;i<rowIndex;i++){
          free(pascal[i]);
    }
    free(pascal);
        
      return result;
}

int main(void) {
    printf("Bienvenue!, ce programmer permet la construction du triangle de Pascal\n");
    printf("entrez le nombre de ligne :   ");

    int nbr_ligne = 0,returnSize = 0,*returnColumnSizes;
    scanf("%d",&nbr_ligne);
    printf("\n lancement de la construction du triangle de Pascal pour %d lignes\n",nbr_ligne);
    int** Pascal_triangle = generate(nbr_ligne,&returnSize,&returnColumnSizes);

    printf("Affichage du triangle de pascal...\n");
    for(int i = 0;i<nbr_ligne;i++) {
        for(int j = 0;j<returnColumnSizes[i];j++) {
            printf("%d ",Pascal_triangle[i][j]);
        }
        printf("\n");
    }

    for(int i = 0;i<nbr_ligne;i++) {
        free(Pascal_triangle[i]);
    }
    free(Pascal_triangle);
    free(returnColumnSizes);
    return 0;
}
