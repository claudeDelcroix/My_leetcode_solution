int maximumCount(int* nums, int numsSize) {
    int minus = 0, plus = 0;
    for(int i = 0;i < numsSize;i++){
        if(nums[i] < 0){
            minus++;
        }
        if(nums[i] > 0){
            plus++;
        }
    }
    return plus >= minus ? plus : minus;
}
