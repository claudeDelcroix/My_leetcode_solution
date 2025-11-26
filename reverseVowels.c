#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Vérifie si un caractère est une voyelle
bool isVowel(char c) {
    return strchr("aeiouAEIOU", c) != NULL;
}

// Échange deux caractères
void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

// Fonction principale : inverse les voyelles
char* reverseVowels(char* s) {
    if (!s) return s;  // Vérifie si le pointeur est NULL

    size_t len = strlen(s);
    if (len < 2) return s;  // Rien à faire si longueur 0 ou 1

    char *head = s;
    char *tail = s + len - 1;

    while (head < tail) {
        // Avancer head jusqu'à une voyelle
        while (head < tail && !isVowel(*head)) head++;
        // Reculer tail jusqu'à une voyelle
        while (head < tail && !isVowel(*tail)) tail--;

        // Swap si on a deux voyelles
        if (head < tail) {
            swap(head, tail);
            head++;
            tail--;
        }
    }

    return s;
}


int main(){
    char *s = "IceCreAm";
    printf("String before s : %s \n",s);
    printf("string s : %s \n",reverseVowels(s));
    return 0;
}
