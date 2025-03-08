//la solution du probleme de cet exercice 
//lien https://leetcode.com/problems/range-sum-query-immutable/?envType=problem-list-v2&envId=array&difficulty=EASY


typedef struct {
    int *p;
    int size;
} NumArray;

NumArray obj;

NumArray* numArrayCreate(int* nums, int numsSize) {
    int *ps = (int *)malloc(sizeof(int)*numsSize); //Prefix sum
    *(ps) = nums[0];
    for(int i=1;i<numsSize;i++)
    {
        *(ps+i) = *(ps+(i-1)) + nums[i]; //Calculate the Prefixsum and store it
    }
    obj.p = ps;
    obj.size = numsSize; //Populate the struct with pointer
    return &obj; //Return the struct

}

int numArraySumRange(NumArray* obj, int left, int right) {
    if(left == 0)
    {
        return *((obj->p)+right); //Carefully access the pointers you need to use *(obj->p) this will refer to the starting of dynamic array and then you use + to get whatever the index you want.
    }
    else
    {
        return (*((obj->p)+right) - (*((obj->p)+(left-1))));
    }
}

void numArrayFree(NumArray* obj) {
    free(obj->p);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/
