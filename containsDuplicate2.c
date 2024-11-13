#define TABLE_SIZE 100000

typedef struct node node;
struct node {
    int index;
    int value;
    node* next;
};

typedef struct hashTable hashTable;
struct hashTable{
    node* table[TABLE_SIZE];
};

unsigned int hash(const int key){
    return abs((unsigned int)(key % TABLE_SIZE));
}

hashTable* createTable(){
    hashTable* table = (hashTable*)malloc(sizeof(hashTable));
    if( table == NULL){
        fprintf(stderr,"allocation failed\n");
        exit(1);
    }

    for(int i = 0;i < TABLE_SIZE;i++){
        table->table[i] = NULL;
    }
    return table;
}

void insert(hashTable* table,const int index,const int value,int* ok,int k){
    const int hashIndex = hash(value);
    node* newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL){
        fprintf(stderr,"allocation failed\n");
        exit(1);
    }
    newNode->index = index;
    newNode->value = value;
    if(table->table[hashIndex] != NULL){
        node* current = table->table[hashIndex];
        while(current != NULL){
            if((current->value == value) && abs(current->index - index) <= k){
                *ok = 1;
                free(newNode);
                return;
            }
            current = current->next;
        }
    }
    newNode->next = table->table[hashIndex];
    table->table[hashIndex] = newNode;
}

void deleteHashTable(hashTable* table){
    for(int i = 0;i < TABLE_SIZE;i++){
        node* temp = table->table[i];
        while(temp != NULL){
            node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(table);
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    hashTable* Table = createTable();
    int ok = -1;
    for(int i = 0;i < numsSize;i++){
        insert(Table,i,nums[i],&ok,k);
        if(ok > 0){
            deleteHashTable(Table);
            return true;
        }
    }
    deleteHashTable(Table);
    return false;
}

//le code suivant a 0ms
//****************************************************************************************************************************
/*bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int i, j;
    for(i = 0; i < numsSize-1; i++){
        for(j = i+1; j <= i + k && j < numsSize; j++){
            if(nums[i] == nums[j])
                return 1;
        }
    }

    return 0;
}*/

/*typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode** buckets;
    int size;
} HashMap;

HashMap* createHashMap(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->buckets = (HashNode**)malloc(size * sizeof(HashNode*));
    for (int i = 0; i < size; ++i) {
        map->buckets[i] = NULL;
    }
    map->size = size;
    return map;
}

int hashFunction(int key, int size) {
    return abs(key) % size;
}

void put(HashMap* map, int key, int value) {
    int hashIndex = hashFunction(key, map->size);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->buckets[hashIndex];
    map->buckets[hashIndex] = newNode;
}

bool get(HashMap* map, int key, int* value) {
    int hashIndex = hashFunction(key, map->size);
    HashNode* current = map->buckets[hashIndex];
    while (current != NULL) {
        if (current->key == key) {
            *value = current->value;
            return true;
        }
        current = current->next;
    }
    return false;
}

void freeHashMap(HashMap* map) {
    for (int i = 0; i < map->size; ++i) {
        HashNode* current = map->buckets[i];
        while (current != NULL) {
            HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    HashMap* map = createHashMap(numsSize);
    
    for (int i = 0; i < numsSize; ++i) {
        int index;
        if (get(map, nums[i], &index)) {
            if (i - index <= k) {
                freeHashMap(map);
                return true;
            }
        }
        put(map, nums[i], i);
    }
    freeHashMap(map);
    return 0;*/

    #define MAX 300000
    bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int record[MAX];

    memset(record, -1, sizeof(record));

    for(int i = 0, tmp; i < numsSize; i++){
        tmp = ((nums[i] % MAX) + MAX) % MAX;

        if(record[tmp] != -1 && i - record[tmp] <= k){
            return true;
        }

        record[tmp] = i;
    }
    return false;
}
//}
