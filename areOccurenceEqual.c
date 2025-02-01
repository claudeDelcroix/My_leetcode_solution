bool areOccurrencesEqual(char* s) {
    int* array = (int*)calloc(257,sizeof(int));
    const int taille = strlen(s);

    for(int i = 0;i < taille;i++){
        array[s[i]]++;
    }
    const int oneElement = array[s[0]];

    for(int i = 0;i < 257;i++){
        if(array[i] != 0 && array[i] != oneElement){
            free(array);
            return false;
        }
    }
    free(array);
    return true;    
}
