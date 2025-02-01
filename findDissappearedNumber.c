/*
 * cette fonction findDissappearedNumber permet de creer a partir d'un tableau existant et de mettre dans le nouvea tableau
 * les elements absents du premier
 * exemple t[] = {1,2,3,5,5,7,5,9,11}
 * le nouveau tab qui sera renvoyer sera tab[] = {4,6,7,8,10}
 * sur leetcode la fonction passe les tests avec 4ms c'est plutot bon
 * il y a des codes avec 23ms 
 */
int* findDisappearedNumbers(int* nums,int numsSize,int* returnSize) {
    int* result = (int*)calloc(numsSize+1,sizeof(int));
    for(int i = 0;i < numsSize;i++) {
        result[nums[i]]++;
    }
    printArray(result,numsSize+1);
    int* solution = (int*)malloc(numsSize*sizeof(int));
    int c = 0;
    for(int i = 1;i < numsSize+1;i++) {
        if(result[i] == 0) {
            solution[c] = i;
            c++;
        }
    }
    *returnSize = c;
    free(result);
    return solution;
}

//solution avec 0 ms 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1; 
        if (nums[index] > 0) {
            nums[index] = -nums[index]; 
        }
    }
    int* result = malloc(numsSize * sizeof(int)); 
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            result[count++] = i + 1; 
        }
    }

    *returnSize = count; 
    return result;
}
