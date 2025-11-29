bool canConstruct(char* ransomNote, char* magazine) {
    int freq_1[256] = {0};
    int freq_2[256] = {0};
    int size_1 = strlen(ransomNote), size_2 = strlen(magazine);
    for(int i = 0; i < size_1; i++){
        freq_1[ransomNote[i]]++;
    }
    for(int i = 0; i < size_2; i++){
        freq_2[magazine[i]]++;
    }

    for(int i = 0;i < size_1; i++){
        if(freq_2[ransomNote[i]] - freq_1[ransomNote[i]] < 0){
            return false;
        }
    }
    return true;
}

//other function with 0ms 
bool canConstruct(char* ransomNote, char* magazine) {
    int letters[26] = {0};

    for (char *p = magazine; *p; p++) {
        letters[*p - 'a']++;
    }

    for (char *p = ransomNote; *p; p++) {
        if (letters[*p - 'a'] == 0)
            return false;
        letters[*p - 'a']--;
    }

    return true;
}
