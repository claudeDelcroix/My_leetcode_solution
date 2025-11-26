//solution avec 0ms 
/*
int arrayPairSum(int* nums, int numsSize) {
    
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arrayPairSum(int* nums, int numsSize) {
    int bucket[20001] = {0};   // for values from -10000 to 10000
    int offset = 10000;

    // Count occurrences (build frequency bucket)
    for (int i = 0; i < numsSize; i++) {
        bucket[nums[i] + offset]++;
    }

    int res = 0;
    bool flag = true;  // used to take every other element

    // Iterate through sorted order implicitly using the bucket
    for (int i = 0; i < 20001; i++) {
        while (bucket[i] > 0) {
            if (flag)
                res += i - offset;   // add the smaller element in each pair
            flag = !flag;            // alternate between taking / skipping
            bucket[i]--;
        }
    }

    return res;
}
//perso tres obscure comme solution 

//ma solution avec 23ms et 10mb  sur 83/83 test 
int cmp_int(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y; 
}

int min(int* a,int* b){
    return *a < *b ? *a : *b;
}

int arrayPairSum(int* nums,int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp_int);
    int max = 0;
    for(int i = 1; i < numsSize;i+=2){
        max += min(&nums[i-1],&nums[i]);
    }
    return max;
}
