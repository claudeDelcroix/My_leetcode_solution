void swap(int* xp,int* yp){
    const int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int* arr,const int n){
    for(int i = 0;i < n-1;i++){
        for(int j = 0;j < n-i-1;j++){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
// o(n2)
int missingNumber(int* nums,const int numsSize){
    bubbleSort(nums,numsSize);

    if(nums[numsSize - 1] != numsSize){
        return numsSize;
    }
    for(int i = 0;i < numsSize;i++){
        if(i != nums[i]){
            return i;
        }
    }
    return 0 ;
}

//meilleure solution 
int missingNumber(int* nums, int numsSize) {
   
   int tot=(numsSize*(numsSize+1))/2;
   int sum=0;
   for(int i=0;i<numsSize;i++)
   sum+=nums[i];
int res=tot-sum;
return res;

}

//avec les bits 
int missingNumber(int* nums, int numsSize) {
  int m = numsSize;
  for(int i=0; i <numsSize ;i++){
    m ^= i ^ nums[i];
  }
  return m;
}

//resolution sur la base de la formule mathematique de la somme 
int missingNumber(int nums[], int n) {
int sum=0;
for(int i=0;i<n;i++) 
sum=sum+nums[i];
return (n*(n+1))/2-sum;  
}
