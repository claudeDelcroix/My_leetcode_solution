//mon code roule sur 0ms sur 45 test
int findMaxConsecutiveOnes(const int* nums, int numsSize) {
    int max = -1, one = 0;
    for(int i = 0;i < numsSize;i++){
        if(nums[i] == 1){
            one++;
        }
        if(nums[i] == 0){
            if(max <= one){
                max = one;
            }
            one = 0;
        }
    }
    if(max <= one){
        max = one;
    }
    return max;
}

// autre code 
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int ans = 0;
    int consecutive = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            consecutive += 1;
        } else {
            ans = consecutive > ans ? consecutive : ans;
            consecutive = 0;
        }
    }
    ans = consecutive > ans ? consecutive : ans;
    return ans;
}
