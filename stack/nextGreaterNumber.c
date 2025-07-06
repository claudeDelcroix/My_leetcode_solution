int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(nums1Size*sizeof(int));
    if(result == NULL) {
        fprintf(stderr,"error allocation \n");
        exit(EXIT_FAILURE);
    }
    *returnSize = 0;
    int n = 0, m = 0;

    while(n < nums1Size) {
        const int verif = n;
        if(nums1[n] == nums2[m]) {
            while (m < nums2Size) {
                if(nums1[n] < nums2[m]) {
                    result[(*returnSize)++] = nums2[m];
                    m++;
                    n++;
                    break;
                }
                m++;
            }
            if(verif == n) {
                result[(*returnSize)++] = -1;
                n++;
            }
            m = 0;
        }else {
            if(m + 1 == nums2Size) {
                m = 0;
            }else {
                m++;
            }
        }
    }
    return  result;
}

// mon code avec les debugs 
int* result = (int*)malloc(nums1Size*sizeof(int));
    if(result == NULL) {
        fprintf(stderr,"error allocation \n");
        exit(EXIT_FAILURE);
    }
    *returnSize = 0;
    int n = 0, m = 0;

    while(n < nums1Size) {
        printf("n = %d\n",n);
        printf("m = %d\n",m);
        printf("La valeur de returnSize : %d \n",*returnSize);
        printf("result = %d\n",result[*returnSize - 1]);
        const int verif = n;
        if(nums1[n] == nums2[m]) {
            while (m < nums2Size) {
                printf("hors de if la valeur de nums2[m] = %d\n",nums2[m]);
                printf("hors de if la valeur de nums1[n] = %d\n",nums1[n]);
                if(nums1[n] < nums2[m]) {
                    printf("la valeur de nums2[m] = %d\n",nums2[m]);
                    result[(*returnSize)++] = nums2[m];
                    m++;
                    n++;
                    break;
                }
                m++;
            }
            if(verif == n) {
                result[(*returnSize)++] = -1;
                n++;
            }
            m = 0;
        }else {
            if(m + 1 == nums2Size) {
                m = 0;
            }else {
                m++;
            }
        }
    }
    return  result;
