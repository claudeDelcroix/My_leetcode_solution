/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// my version of 8ms
#define TRUE 1
#define FALSE 0


 void tri_a_bulle(int* t,const int n){
    int en_desordre = 1;

    while(en_desordre){
        en_desordre = FALSE;
        for(int j = 0;j < n - 1;j++){
            if(t[j] > t[j+1]){
                int tmp = t[j];
                t[j] = t[j+1];
                t[j+1] = tmp;
                en_desordre = TRUE;
            }
        }
    }
 }

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    tri_a_bulle(nums1,nums1Size);
    tri_a_bulle(nums2,nums2Size);

    int count = 0,notSame = -1;
    const short size = nums1Size > nums2Size ? nums2Size : nums1Size;
    int* array = (int*)malloc(size*sizeof(int));

    for(int i = 0;i < nums1Size;i++){
        for(int j = 0;j < nums2Size;j++){
            if(nums1[i] == nums2[j] && nums1[i] != notSame){
                array[count++] = nums1[i];
                notSame = nums1[i];
                break;
            }
            if(nums2[j] > nums1[i]){
                break;
            }
        }
    }
    *returnSize = count;
    return array;
}

//version of this for 0 ms
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // 用陣列模擬 HashSet
    bool set1[1001] = {false};  // 記錄 nums1 中出現的數字
    bool set2[1001] = {false};  // 記錄 nums2 中出現的數字
    
    // 把 nums1 的數字加入 set1
    for(int i = 0; i < nums1Size; i++) {
        set1[nums1[i]] = true;
    }
    
    // 找交集並加入 set2
    int count = 0;
    for(int i = 0; i < nums2Size; i++) {
        if(set1[nums2[i]] && !set2[nums2[i]]) {
            set2[nums2[i]] = true;
            count++;
        }
    }
    
    // 建立結果數組
    int* result = (int*)malloc(count * sizeof(int));
    int idx = 0;
    for(int i = 0; i < 1001; i++) {
        if(set2[i]) {
            result[idx++] = i;
        }
    }
    
    *returnSize = count;
    return result;
}
