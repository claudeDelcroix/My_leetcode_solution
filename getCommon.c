int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int binarySearch(int arr[],const int size,const int x) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    qsort(nums1,nums1Size,sizeof(int),compare);
    qsort(nums2,nums2Size,sizeof(int),compare);

    int smallestCommon = -1;

    // Utiliser la recherche binaire pour trouver la plus petite valeur commune
    for (int i = 0; i < nums1Size; i++) {
        if (binarySearch(nums2, nums2Size, nums1[i]) != -1) {
            smallestCommon = nums1[i];
            break;
        }
    }

    return smallestCommon;
}

//l'approche suivant est plus qu'ideal je ne pensais pas qu'une telle solution pouvait exister 
//0 ms contre 21 ms pour la recherche binaire 
int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i=0,j=0;
    while((i<nums1Size)&&(j<nums2Size))
    {
        if(nums1[i]<nums2[j])
        i++;
        else if(nums1[i]>nums2[j])
        j++;
        else
        return nums1[i];
    }
    return -1;
}
