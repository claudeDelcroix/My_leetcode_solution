//https://leetcode.com/problems/keyboard-row/submissions/1783724332/?envType=problem-list-v2&envId=array&difficulty=EASY
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define max_hash_table_f 27
typedef struct node_f node_f;
struct node_f{
    char letter;
    int index;
};


typedef struct hash_table_f hash_table_f;
struct hash_table_f {
    node_f* table[max_hash_table_f];
};

hash_table_f* createH() {
    hash_table_f* table = (hash_table_f*) malloc(sizeof(hash_table_f));
    if (table == NULL) {
        fprintf(stderr,"Error allocation\n");
        exit(EXIT_FAILURE);
    }
    memset(table->table,0,sizeof(table->table));
    return table;
}

int from_letter_to_number(char letter) {
    if (isupper((letter))) {
        letter = tolower((letter));
    }
    return (int)letter - 96;
}

void init_array_with_index(hash_table_f* table,const char string[],const int id) {
    for (int i = 0; string[i] != '\0'; i++) {
        const int index = from_letter_to_number(string[i]);
        node_f* element = (node_f*)malloc(sizeof(node_f));
        if (element == NULL) {
            fprintf(stderr,"Error allocation\n");
            exit(EXIT_FAILURE);
        }
        element->index = id;
        element->letter = string[i];
        table->table[index] = element;
    }
}

void init_hash_table_f(hash_table_f* table) {
    const char first[] = "qwertyuiop";
    const char second[] = "asdfghjkl";
    const char third[] = "zxcvbnm";

    //entrer de la premiere ligne de valeur
    init_array_with_index(table,first,1);
    init_array_with_index(table,second,2);
    init_array_with_index(table,third,3);
}

void print_hast_table(const hash_table_f* table) {
    printf("L'affichage se fait de la maniere suivante (letter,index)\n");

    for (int i = 1;i < max_hash_table_f;i++) {
        const node_f* current = table->table[i];
        printf("%d\t: (%c,%d)\n",i,current->letter,current->index);
    }
    printf("END\n");
}

void free_hash_table_f(hash_table_f* table) {
    for (int i = 0;i < max_hash_table_f;i++) {
        node_f* current = table->table[i];
        free(current);
        table->table[i] = NULL;
    }
    free(table);
}

bool check_is_string_is_ok(const char string[],const hash_table_f* table) {
    const int id = from_letter_to_number(string[0]);;
    const node_f* current = table->table[id];
    const int index = current->index;;
    for (int i = 0;i < strlen(string);i++) {
        const int id1 = from_letter_to_number(string[i]);
        const node_f* cur = table->table[id1];
        if (cur->index != index) {
            return false;
        }
    }
    return true;
}

char** findWords(char** words, int wordsSize, int* returnSize) {
    hash_table_f* table = createH();
    init_hash_table_f(table);
    char** result_String = (char**)malloc(20*sizeof(char*));
    for (int i = 0;i < 20;i++) {
        result_String[i] = (char*)malloc(100*sizeof(char));
    }
    *returnSize = 0;
    for (int i = 0;i < wordsSize;i++) {
        if (check_is_string_is_ok(words[i],table)) {
            strcpy(result_String[(*returnSize)],words[i]);
            *returnSize += 1;
        }
    }
    free_hash_table_f(table);
    return result_String;
}

//autre methode 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize) {
        int keyboardRows[26];
    
    // 填充哈希表
    char* row1 = "qwertyuiop";
    char* row2 = "asdfghjkl";
    char* row3 = "zxcvbnm";
    
    for (int i = 0; row1[i] != '\0'; i++) {
        keyboardRows[row1[i] - 'a'] = 1;
    }
    for (int i = 0; row2[i] != '\0'; i++) {
        keyboardRows[row2[i] - 'a'] = 2;
    }
    for (int i = 0; row3[i] != '\0'; i++) {
        keyboardRows[row3[i] - 'a'] = 3;
    }
    
    char** result = (char**)malloc(sizeof(char*) * wordsSize);
    *returnSize = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        char* word = words[i];
        if (word[0] == '\0') {
            continue; // 跳过空字符串
        }
        
        int rowId = keyboardRows[tolower(word[0]) - 'a'];
        int isSameRow = 1;
        
        // 检查单词的其余字母
        for (int j = 1; word[j] != '\0'; j++) {
            if (keyboardRows[tolower(word[j]) - 'a'] != rowId) {
                isSameRow = 0;
                break;
            }
        }
        
        if (isSameRow) {
            // 如果合格，将单词添加到结果中
            result[*returnSize] = (char*)malloc(strlen(word) + 1);
            strcpy(result[*returnSize], word);
            (*returnSize)++;
        }
    }
    
    // 调整结果数组大小
    result = (char**)realloc(result, sizeof(char*) * (*returnSize));
    return result;
}
