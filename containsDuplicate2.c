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
