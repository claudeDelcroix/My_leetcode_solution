void moveZeroes(int* nums, int numsSize) {
    int noZero = 0;
    for(int i = 0; i < numsSize;i++){
        if(nums[i] != 0){
            nums[noZero++] = nums[i]; 
        }
    }
    for(int i = noZero;i < numsSize; i++){
        nums[i] = 0;
    }
}
