int minValue(const int x,const int y){
    if(x < y){
        return x;
    }else{
        return y;
    }
}

int maximumStrongPairXor(int* nums, int numsSize) {
    int max = 0;
    for(int i = 0;i < numsSize;i++){
        for(int j = 0;j < numsSize;j++){
            if(abs(nums[i] - nums[j]) <= minValue(nums[i],nums[j])){
                if((nums[i] ^ nums[j]) >= max){
                    max = nums[i] ^ nums[j];
                }
            }
        }
    }
    return max;
}
