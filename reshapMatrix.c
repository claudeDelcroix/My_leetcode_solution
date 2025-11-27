/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    if((c * r) != (matSize * (*matColSize))){
        *returnSize = matSize;

        *returnColumnSizes = malloc(matSize * sizeof(int));
        for (int i = 0; i < matSize; i++) {
            (*returnColumnSizes)[i] = *matColSize;
        }   

        return mat;
    }
    int* all_element = (int*)malloc((c*r)*sizeof(int));
    if(!all_element){
        fprintf(stderr,"Error allocation 'all_element'\n");
        exit(EXIT_FAILURE);
    }
    int count = 0;
    for(int i = 0;i < matSize;i++){
        for(int j = 0;j < (*matColSize);j++){
            all_element[count++] = mat[i][j];
        }
    }
    int** result = (int**)malloc(r * sizeof(int*));
    if(!result){
        fprintf(stderr,"Error allocation of result(array)\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0;i < r;i++){
        result[i] = (int*)malloc(c * sizeof(int));
    }
    count = 0;
    for(int i = 0;i < r;i++){
        for(int j = 0; j < c;j++){
            result[i][j] = all_element[count++];
        }
    }
    *returnSize = r;
    *returnColumnSizes = malloc(r * sizeof(int));
    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c;
    }
    free(all_element);
    return result;
}
