int countKDifference(int* nums, int numsSize, int k) {
    int count = 0;
    for(int i = 0;i < numsSize;i++) {
        for(int j = i + 1;j < numsSize;j++) {
            if(abs(nums[i] - nums[j]) == k) {
                count++;
            }
        }
    }
    return count;
}

//mon code a 3ms tandis que le code suivant a 0 ms avec une approche tout a fait difference et assez impressionnante 
int countKDifference(int* nums, int numsSize, int k) {
    int freq[101] = {0};
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
        if (nums[i] - k >= 1) {
            res += freq[nums[i] - k];
        }
        if (nums[i] + k <= 100) {
            res += freq[nums[i] + k];
        }
    }
    return res;
}

//solution avec une table de hachage 
#include <stdio.h>
#include <stdlib.h>
#define Rep(i, n) for (int i = 0; i < n; ++i)
#define Rep1(i, n) for (int i = 1; i <= n; i++)

typedef struct Map {
    int* arr;
} maps;

maps* intializeMap(int capacity) {
    maps* map = (maps*) malloc(sizeof(maps));
    map->arr = (int*) calloc(sizeof(int), capacity);
    
    return map;
}

bool containsKey(maps* map, int val) { 
    return map->arr[val];
}

int countKDifference(int* nums, int numsSize, int k) {
    maps* map = intializeMap(202);
    Rep (i, numsSize) 
        map->arr[nums[i]]++;

    int ans = 0;
    Rep (i, numsSize) {
        int comp = k + nums[i];
        if (containsKey(map, comp))
            ans += map->arr[comp];
    }
    free(map);
    return ans;
}
