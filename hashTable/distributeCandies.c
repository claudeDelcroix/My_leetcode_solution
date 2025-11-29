typedef struct Node Node;
struct Node{
    int value;
    Node* next;
};

typedef struct HashTable HashTable;
struct HashTable{
    int size;
    int type;
    Node** buckets;
};

int hash(int value,int size){
    return (value % size + size) % size;
}

HashTable* crete_table(int size){
    HashTable* table = malloc(sizeof(HashTable));
    if(!table){
        fprintf(stderr,"Error allocation of table\n");
        exit(EXIT_FAILURE);
    }
    table->size = size;
    table->type = 0;
    table->buckets = calloc(size,sizeof(Node*));
    return table;
}

void insert(HashTable* table,int value){
    int index = hash(value, table->size);
    Node* current = table->buckets[index];
    while(current){
        if(current->value == value){
            return;
        }
        current = current->next;
    }
    Node* new_node = malloc(sizeof(Node));
    table->type += 1;
    new_node->value = value;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

void free_table(HashTable* table){
    for(int i = 0;i < table->size;i++){
        Node* current = table->buckets[i];
        while(current){
            Node* tmp = current;
            current = current->next;
            free(tmp);
        }
    }
    free(table->buckets);
    free(table);
}

int distributeCandies(int* candyType, int candyTypeSize) {
    HashTable* table = crete_table(1000);
    for(int i = 0; i < candyTypeSize; i++){
        insert(table,candyType[i]);
        if(table->type == (candyTypeSize / 2)){
            int result = table->type;
            free_table(table);
            return result;
        }
    }
    int result = table->type;
    free(table);
    return result;
}

// solution avec 0ms
//c'etait mon idee de base mais pas avec cette belle logique 
int distributeCandies(int* candyType, int candyTypeSize) {
    int map[200001] = {0};
    int count = 0;

    for(int i = 0; i < candyTypeSize; i++){
        if(map[candyType[i]+100000] == 0){
            map[candyType[i]+100000]++;
            count++;
        }
        if(count == candyTypeSize / 2) return count;
    }
    return count;
}
