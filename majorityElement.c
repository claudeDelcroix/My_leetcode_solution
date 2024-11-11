/* le tri par selection a ete plus rapide que le tri a bulle
resolu 11.11.2024 
*/
void swap(int* xp,int* yp) {
    const int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int* arr,int n) {
    for(int i = 0; i < n-1;i++) {
        for(int j = 0; j < n-i-1;j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[],int n) {
    for(int i = 1;i < n;i++) {
        const int key = arr[i];
        int j = i -1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j -1;
        }
        arr[j + 1] = key;
    }
}

int majorityElement(int* nums,const int numsSize) {
    int maj = 0,el = 0,max = 0;
    insertionSort(nums,numsSize);
    int first = nums[0];
    for(int i = 0;i < numsSize;i++) {
        if(nums[i] == first) {
            el++;
        }else {
            first = nums[i];
            if(el > maj) {
                max = nums[i - 1];
                maj = el;
            }
            el = 1;
        }
    }
    if(el > maj){
        max = nums[numsSize - 1];
    }
   
    return max;
}
// le code suivant reussi a 0ms quel geni son createur 
int majorityElement(int* nums, int numsSize) {
    int i, sel, cnt = 0;
    for(i = 0; i < numsSize; i++) {
        if(cnt == 0) {
            sel = nums[i];
            cnt++;
        } else if(nums[i] == sel) {
            cnt++;
        } else {
            cnt--;
        }
    }
    return sel;
}

