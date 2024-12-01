//87 ms and 8.51 mb , my code with sorting and logical choice 
void swap(int* xp,int* yp){
    const int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int arr[],int low,int high){
    const int pivot = arr[high];
    int i = low - 1;

    for(int j = low;j < high;j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i + 1;
}

void quickSort(int arr[],int low,int high){
    if(low < high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi - 1);
        quickSort(arr,pi+1,high);
    }
}

int thirdMax(int* nums, int numsSize) {
    if(numsSize == 1){
        return nums[0];
    }else if(numsSize == 2){
        if(nums[0] > nums[1]){
            return nums[0];
        }else{
            return nums[1];
        }
    }

    quickSort(nums,0,numsSize -1);
    int max = nums[numsSize - 1],i = numsSize -1;
    while(max == nums[i] && i > 0){
        i--;
    }
    max = nums[i];
    while(max == nums[i] && i>0){
        i--;
    }
    if(max == nums[0]){
        i--;
    }
    if(i < 0){
        return nums[numsSize - 1];
    }

    return nums[i];
}

//0ms 


int thirdMax(int* nums, int numsSize) {
    int max_num;
    int second_max_num;
    int third_max_num;

    if(numsSize == 0){
        return 0;
    }

    

    int min = nums[0];
    for(int i = 0; i<numsSize; i++){
        if(nums[i] < min){
            min = nums[i];
        }
    }

    max_num = min;
    second_max_num = min;
    third_max_num = min;

    for(int i =0; i<numsSize;i++){
        if(nums[i] > max_num){
            third_max_num = second_max_num;
            second_max_num =max_num;
            max_num = nums[i];
        }
        else if(nums[i] > second_max_num && nums[i] != max_num){
            third_max_num = second_max_num;
            second_max_num = nums[i];
        }
        else if(nums[i] > third_max_num && nums[i] != second_max_num && nums[i] != max_num){
            third_max_num = nums[i];
        }
    }

    if(max_num != second_max_num && second_max_num != third_max_num){
        return third_max_num;
    }

    return max_num;
}

//1ms
int thirdMax(int* nums, int numsSize) {
    long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

    for (int i = 0; i < numsSize; i++) {
        // Skip duplicates
        if (nums[i] == first || nums[i] == second || nums[i] == third) {
            continue;
        }
        
        if (nums[i] > first) {
            third = second;
            second = first;
            first = nums[i];
        } else if (nums[i] > second) {
            third = second;
            second = nums[i];
        } else if (nums[i] > third) {
            third = nums[i];
        }
    }

    // If third maximum doesn't exist, return the maximum
    return (third == LONG_MIN) ? first : third;
}

//2ms
int thirdMax(int* nums, int numsSize) {
    long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num == first || num == second || num == third) {
            continue;
        }
        if (num > first) {
            third = second;
            second = first;
            first = num;
        } else if (num > second) {
            third = second;
            second = num;
        } else if (num > third) {
            third = num;
        }
    }
    return (third == LONG_MIN) ? first : third;
}
