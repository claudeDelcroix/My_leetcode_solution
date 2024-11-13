//mon code de base , il contient une faille 46/51 test passer mais reste pour autant tres utiles
#define TABLE_SIZE 300

typedef struct nodeChar nodeChar;
struct nodeChar{
    char letter;
    nodeChar* next;
};

typedef struct hashTable hashTable;
struct hashTable{
    nodeChar* table[TABLE_SIZE];
};

unsigned int hash(const char a){
    return (unsigned int)a;
}

hashTable* createTable(){
    hashTable* table = (hashTable*)malloc(sizeof(hashTable));
    if(table == NULL){
        fprintf(stderr,"l'allocation de table a echouee\n");
        exit(1);
    }

    for(int i = 0; i < TABLE_SIZE;i++){
        table->table[i] = NULL;
    }
    return table;
}

void insertFirstString(hashTable* table,const char a){
    const unsigned int index = hash(a);
    nodeChar* newNode = (nodeChar*)malloc(sizeof(nodeChar));
    if(newNode == NULL){
        fprintf(stderr,"allocation failed\n");
        exit(1);
    }

    newNode->letter = a;
    newNode->next = table->table[index];
    table->table[index] = newNode;
}

void insertSecondString(hashTable* table,const char b,int* ok){
    const unsigned int index = hash(b);
    nodeChar* newNode = (nodeChar*)malloc(sizeof(nodeChar));
    if(newNode == NULL){
        fprintf(stderr,"allocation failed\n");
        exit(1);
    }

    newNode->letter = b;
    if(table->table[index] == NULL){
        *ok = 1;
        free(newNode);
        return;
    }else{
        newNode->next = table->table[index];
        table->table[index] = newNode;
    }
}

void freeTable(hashTable* table){
    for(int i = 0;i < TABLE_SIZE;i++){
        nodeChar* temp = table->table[i];
        while(temp != NULL){
            nodeChar* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(table);
}

bool isAnagram(char* s, char* t) {
    if(strlen(s) != strlen(t)){
        return false;
    }
    
    hashTable* table = createTable();

    for(int i = 0; i < strlen(s);i++){
        insertFirstString(table,s[i]);
    }

    int ok = -1;
    for(int i = 0; i < strlen(t);i++){
        insertSecondString(table,t[i],&ok);
        if(ok > 0){
            return false;
        }
    }
    freeTable(table);
    return true;
}

//mon code rearanger par copilot pour verifier le nombre de repetion de chaque caracteres 
//juste un peu lent 138 ms mais excellent en espaces 8.04 73.39%
#define TABLE_SIZE 256

typedef struct hashTable {
    int table[TABLE_SIZE];
} hashTable;

hashTable* createTable() {
    hashTable* table = (hashTable*)malloc(sizeof(hashTable));
    if (table == NULL) {
        fprintf(stderr, "l'allocation de table a echouee\n");
        exit(1);
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        table->table[i] = 0;
    }
    return table;
}

void insertString(hashTable* table, const char* str) {
    for (int i = 0; i < strlen(str); i++) {
        table->table[(unsigned char)str[i]]++;
    }
}

bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }

    hashTable* table1 = createTable();
    hashTable* table2 = createTable();

    insertString(table1, s);
    insertString(table2, t);

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table1->table[i] != table2->table[i]) {
            free(table1);
            free(table2);
            return false;
        }
    }

    free(table1);
    free(table2);
    return true;
}

//meilleure solution avec 0ms 
bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }

    // Create an array to store character counts (for 26 lowercase letters)
    int charCount[26] = {0};

    // Increment count for each character in `s`
    for (int i = 0; s[i] != '\0'; i++) {
        charCount[s[i] - 'a']++;
    }

    // Decrement count for each character in `t`
    for (int i = 0; t[i] != '\0'; i++) {
        charCount[t[i] - 'a']--;
    }

    // If any count is not zero, they are not anagrams
    for (int i = 0; i < 26; i++) {
        if (charCount[i] != 0) {
            return false;
        }
    }

    return true;
}
