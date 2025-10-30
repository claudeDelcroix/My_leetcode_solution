#define MAX_WORDS 300
#define MAX_WORD_LEN 100

bool wordPattern(const char *pattern, const char *s) {
    const int len_p = strlen(pattern);
    char *words[MAX_WORDS];
    int count = 0;

    // --- Copier s pour pouvoir le découper ---
    char *copy = strdup(s);
    if (!copy) return false;

    // --- Découper en mots ---
    char *token = strtok(copy, " ");
    while (token) {
        if (count >= MAX_WORDS) { free(copy); return false; }
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    // --- Vérifier si le nombre de mots == taille du pattern ---
    if (count != len_p) {
        free(copy);
        return false;
    }

    // --- Mapping lettre → mot et mot → lettre ---
    char *letter_to_word[256] = {0};
    char *word_to_letter[MAX_WORDS] = {0};
    char *seen_words[MAX_WORDS];
    int seen_count = 0;

    for (int i = 0; i < len_p; i++) {
        unsigned char c = pattern[i];
        char *word = words[i];

        // Si la lettre n'a encore rien
        if (!letter_to_word[c]) {
            // Vérifie que le mot n'est pas déjà mappé à une autre lettre
            for (int k = 0; k < seen_count; k++) {
                if (strcmp(seen_words[k], word) == 0) {
                    free(copy);
                    return false; // mot déjà utilisé par une autre lettre
                }
            }
            // Nouveau mapping
            letter_to_word[c] = word;
            seen_words[seen_count++] = word;
        } else {
            // Si la lettre est déjà associée à un mot différent
            if (strcmp(letter_to_word[c], word) != 0) {
                free(copy);
                return false;
            }
        }
    }

    free(copy);
    return true;
}

//version de depart 
bool wordPattern(const char* pattern,const char *s) {
    int map_sum[255] = {0};
    const size_t len = strlen(pattern);
    const size_t len_s = strlen(s);
    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        int sum = 0;
        while (j < len_s && s[j] != ' ') {
            sum += (int)s[j];
            j++;
        }
        j++;
        if (map_sum[(int)pattern[i]] == 0) {
            map_sum[(int)pattern[i]] = sum * (int)pattern[i]*3;
            int k = (int)i;
            while (k >= 0) {
                if (map_sum[(int)pattern[k]] == sum && pattern[k] != pattern[i]) {
                    return false;
                }
                j--;
            }
        }else if (map_sum[(int)pattern[i]] != 0 && map_sum[(int)pattern[i]] != sum) {
            return false;
        }
    }
    return true;
}

