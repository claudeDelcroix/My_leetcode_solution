/*
le lien github de tous les fichiers d'entete 
https://github.com/troydhanson/uthash
*/
struct hash_entry {
    int id;            /* we'll use this field as the key */
    int value;
    UT_hash_handle hh; /* makes this structure hashable */
};

struct hash_entry *temp = NULL;

struct hash_entry *find_num(int id) {
    struct hash_entry *s;
    HASH_FIND_INT(temp, &id, s);
    return s;
}

void delete_all() {
    struct hash_entry *current_user, *tmp;
    HASH_ITER(hh, temp, current_user, tmp) {
        HASH_DEL(temp,current_user);  /* delete it (users advances to next) */
        free(current_user);            /* free it */
    }
}

int majorityElement(int* nums, int numsSize){
    int majority_element = nums[0], count = 1;
    for(int i = 0; i < numsSize; i++){
        int key = nums[i];
        struct hash_entry *s = find_num(key);
        if(s == NULL){
            s = (struct hash_entry *)malloc(sizeof(struct hash_entry));
            s->id = key;
            s->value = 1;
            HASH_ADD_INT(temp, id, s);
        }
        else{
            s->value += 1;
            if(count < s->value){
                count = s->value;
                majority_element = s->id;
            }
        }
    }
    delete_all();
    return majority_element;
}

//solution with a bitwise operation 
int majorityElement(int* nums, int numsSize) {

    /* try a bit wise operation */
int num_bits = (sizeof(int)*8);
    int i,j,data, cnt;
     int majElement = 0;
    for(i=0; i<num_bits; i++)
    {
        cnt = 0;
        for(j=0; j<numsSize; j++)
        {

            if(nums[j] &(1ULL<<i))
                cnt++;
        }
        if(cnt>numsSize/2)
            {
                majElement = (majElement | (1ULL<<i) );
            }
    }
    return majElement;
    
}
