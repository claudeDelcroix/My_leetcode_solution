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

//moyen de resoudre le probleme avec Qsort fonction pour trier de facon generique
//et rearangement de la menoire a la fin
int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(sizeof(int)*1001);

    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    int length = 0, i, j;

    for(i = 0, j = 0; i < nums1Size && j < nums2Size; i++, j++){
        if(nums1[i] == nums2[j])
            result[length++] = nums1[i];
        else if(nums1[i] < nums2[j])
            j--;
        else
            i--;
    }

    *returnSize = length;
    result = realloc(result, sizeof(int)*length);
    return result;
}

//avec le moins de memoire sur l'exercice
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int* t = (int*)malloc(sizeof(int) * (nums1Size > nums2Size ? nums1Size : nums2Size));
    int i = 0, j = 0, k = 0;
    *returnSize = 0;


    for(i = 0; i < nums2Size; i++) {

        for(j = 0; j < nums1Size; j++) {

            if(nums2[i] == nums1[j]) {

                t[k] = nums2[i];
                (*returnSize)++;
                k++;
                nums1[j] = -1;
                break;
            }
        }
    }

    return t;
}
