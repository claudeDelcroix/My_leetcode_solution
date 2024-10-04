//88ms 
struct HashNode
{
    int data;
    struct HashNode *next;
};

static inline int hash(int num, int size)
{
    int index = num % size;
    return (index > 0) ? (index) : (-index);
}

bool containsDuplicate(int* nums, int numsSize)
{
    if (numsSize < 2)
        return false;
    bool duplicated = false;

    int hash_size = numsSize / 2 + 1; /* proper size can be faster */
    struct HashNode **hash_table
        = (struct HashNode **)calloc(hash_size, sizeof(struct HashNode *));

    int i;
    for (i = 0; i < numsSize; i++)
    {
        int index = hash(nums[i], hash_size);
        struct HashNode **p = hash_table + index;

        while (*p)
        {
            if ((*p)->data == nums[i])
            {
                duplicated = true;
                goto OUT;
            }
            p = &((*p)->next);
        }

        struct HashNode *new_node
            = (struct HashNode *)malloc(sizeof(struct HashNode));
        new_node->data = nums[i];
        new_node->next = NULL;

        *p = new_node;
    }

OUT:
    for (i = 0; i < hash_size; i++)
    {
        struct HashNode *t = hash_table[i];
        struct HashNode *x = NULL;
        while (t)
        {
            x = t->next;
            free(t);
            t = x;
        }
    }
    free(hash_table);

    return duplicated;
}

//optimisation que 54ms
bool containsDuplicate(int* nums, int numsSize) {
long i,j;
int isNegative=0;
int *p;

if (numsSize <2) return false;
#define SMALLNUMSIZE 500

if (numsSize < SMALLNUMSIZE)
{
    for (i=0; i<numsSize; i++)
    {
        for (j=i+1; j<numsSize; j++)
        {
            if (*(nums+i) == *(nums+j) )
            {
                return true;
            }
        }
    }
    return false;
}

    p=malloc (10000000 *sizeof(int));
    //p=array;
    //for(i=0; i< 10000000; i++)
    //{
    //    *(p+i) = 0;
    //}
    for(i=0; i< numsSize; i++)
    {
        if (*(nums+i) >= 0 )
        {
            *(p + *(nums+i)) = 0;
        }
        else isNegative =1;        
    }

    for(i=0; i< numsSize; i++)
    {
        if (*(nums+i) >= 0 )
        {
            *(p + *(nums+i)) += 1;
            if (*(p + *(nums+i)) >1)
            {
                return true;
            }
        }
        
    }     
//    for(i=0; i< 10000000; i++)
//    {
//        if (*(p+i) >1)
//            return true;
//    }

    if(isNegative)
    {


        //check negative
        //for(i=0; i< 10000000; i++)
        //{
        //    *(p+i) = 0;
        //}     
        
        for(i=0; i< numsSize; i++)
        {
            if (*(nums+i) <0 )
            {
                *(p - *(nums+i)) =0;
            }
        }
        for(i=0; i< numsSize; i++)
        {
            if (*(nums+i) <0 )
            {
                *(p - *(nums+i)) += 1;
                if (*(p - *(nums+i)) >1)
                    return true;
            }
        }     
//        for(i=0; i< 10000000; i++)
//        {
//            if (*(p+i) >1)
//                return true;
//        }
    }
    //free(p);
    return false;
}

// avec quick sort 
#include <stdbool.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) {
    
    // Step 1: Sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Step 2: Check for adjacent duplicates in the sorted array
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            return true; // Duplicate found
        }
    }

    return false; // No duplicates found

    // Alternative approach commented out due to time limit exceed
    /*
    for(int i = 0; i < numsSize; i++) {
        for(int j = 0; j < numsSize; j++) {
            if(nums[i] > nums[j]) {
                nums[i] = nums[i] + nums[j];
                nums[j] = nums[i] - nums[j];
                nums[i] = nums[i] - nums[j];
            }
        }
    }

    for(int i = 0; i < numsSize - 1; i++) {
        if(nums[i] == nums[i + 1]) {
            return true; // Duplicate found
        }
    }
    
    return false; // No duplicates found
    */
}
