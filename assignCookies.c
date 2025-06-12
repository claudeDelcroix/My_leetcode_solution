static int cmp_int(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

int findContentChildren(int *g, int gSize, int *s, int sSize) {
    // on trie en O(n log n)
    qsort(g, gSize, sizeof *g, cmp_int);
    qsort(s, sSize, sizeof *s, cmp_int);

    int count = 0, i = 0, j = 0;
 
    while (i < gSize && j < sSize) {
        if (s[j] >= g[i]) {
            // on trouve une friandise pour l'enfant i
            ++count;
            ++i;
            ++j;
        } else {
            // la friandise s[j] est trop petite, on regarde la suivante
            ++j;
        }
    }
    return count;
}
