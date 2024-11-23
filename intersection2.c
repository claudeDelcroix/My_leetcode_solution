#define TABLE_SIZE 1000

typedef struct node node;
struct node{
    int value;
    int nbrFois;
    node* next;
};

typedef struct hashTable hashTable;
struct hashTable{
    node* table[TABLE_SIZE];
};

int hash(const int key){
    return key % TABLE_SIZE;
}

hashTable* createTable() {
    hashTable* table = (hashTable*)malloc(sizeof(hashTable));
    if (table == NULL) {
        fprintf(stderr, "allocation failed\n");
        exit(EXIT_FAILURE);
    }
    memset(table->table, 0, sizeof(table->table));
    return table;
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

void insertIntersect(hashTable* table, const int value){
    const int hashIndex = hash(value);
    node* newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL){
        fprintf(stderr,"allocation failed\n");
        exit(1);
    }

    newNode->value = value;
    newNode->nbrFois = 1; // Initialisation correcte

    newNode->next = table->table[hashIndex];
    table->table[hashIndex] = newNode;
}

void insertWithHash(hashTable* table, const int value, int* array, int* sizeArr) {
    const int hashIndex = hash(value);
    node* current = table->table[hashIndex];
    while (current != NULL) {
        if (current->value == value && current->nbrFois > 0) {
            array[(*sizeArr)++] = value;
            current->nbrFois -= 1;
            return;
        }
        current = current->next;
    }
}


int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = 0; // Initialisation correcte de returnSize
    hashTable* table = createTable();
    const short sizeArray = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* array = (int*)malloc(sizeArray * sizeof(int));
    if(array == NULL){
        fprintf(stderr,"allocation failed\n");
        exit(1);
    }

    for(int i = 0; i < nums1Size; i++){
        insertIntersect(table, nums1[i]);
    }
    for(int i = 0; i < nums2Size; i++){
        insertWithHash(table, nums2[i], array, returnSize);
    }

    deleteHashTable(table);
    return array;
}
