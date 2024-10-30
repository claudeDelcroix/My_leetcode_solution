/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
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
