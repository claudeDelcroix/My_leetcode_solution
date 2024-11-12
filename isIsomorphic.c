typedef struct node node;
struct node {
    char a;
    char b;
    node* next;
};

typedef struct element element;
struct element {
    node* first;
}

//isIsomorphic avec l'utilisation des listes chainees
element* initialisation() {
    element* liste = (element*)malloc(sizeof(element));
    if(liste == NULL) {
        fprintf(stderr,"l'alocation au niveau de initialisation a echouee\n");
        exit(EXIT_FAILURE);
    }

    liste->first = NULL;
    return liste;
}

void insertNode(element* liste,const char one,const char two,int* ok) {
    node* noeud = (node*)malloc(sizeof(node));
    if(noeud == NULL) {
        fprintf(stderr,"l'allocation a echouee au niveau de noeud\n");
        exit(EXIT_FAILURE);
    }

    noeud->a = one;
    noeud->b = two;
    if(liste->first == NULL) {
        noeud->next = liste->first;
        liste->first = noeud;
        return;
    }

    noeud->next = NULL;
    node* current = liste->first;

    while(current != NULL) {
        char x = current->a,y = current->b;
        if((x == one && y != two) || (x != one && y == two)) {
            *ok = 1;
            free(noeud);
            return;
        }
        if(current->next == NULL) {
            break;
        }
        current = current->next;
    }

    current->next = noeud;
}

void deleteListLinked(element* liste) {
    node* current = liste->first;
    node* suivant = NULL;

    while(current != NULL) {
        suivant = current->next;
        free(current);
        current = suivant;
    }
    free(liste);
    liste = NULL;
}

void printList(const element* liste) {
    node* current = liste->first;
    while(current->next != NULL) {
        printf("(%c,%c)->",current->a,current->b);
        current = current->next;
    }
    printf("NULL\n");
}
//cette approche sur les liste a poser des problemes de mappages
// la solution a ce probleme ce trouve dans la fonction suivante
//utilisant des map, de plus cette approche n'est pas si mal
bool isIsomorphic(const char* s,const char* t) {
    element* chaineString = initialisation();
    int ok = 0;

    for(int i = 0;i <= strlen(s);i++) {
        insertNode(chaineString,s[i],t[i],&ok);
        printf("La valeur de ok : %d\n",ok);
        if(ok > 0) {
            deleteListLinked(chaineString);
            return false;
        }
    }
    printList(chaineString);
    deleteListLinked(chaineString);
    return true;
}

//coorection grace aux map
bool isIsomorphic1(const char* s,const char* t) {
    int map_s[256] = {0};
    int map_t[256] = {0};

    for(int i = 0;i < strlen(s);i++){
        if(map_s[(unsigned char)s[i]] != map_t[(unsigned char)t[i]]){
            return false;
        }
        map_s[(unsigned char)s[i]] = i + 1;
        map_t[(unsigned char)t[i]] = i + 1;
    }
    return true;
}

// utilisation des map avec un runtime de 0ms
bool isIsomorphic(char* s, char* t)
{
    char s_map[256] = {0} ;
    char t_map[256] = {0} ;

    for(int i=0;s[i] != '\0';i++)
    {
      char  s_char = s[i] ;
      char  t_char = t[i] ;

        if((s_map[s_char] != '\0') && (s_map[s_char] != t_char))
        {
            return false ;
        }
        if((t_map[t_char] != '\0') && (t_map[t_char] != s_char))
        {
            return false ;
        }
        s_map[s_char] = t_char ;
        t_map[t_char] = s_char ;
        
    } 
    return true ;
    
}

//solution utilisant les tables de hachages 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "uthash.h"

// Structure pour les entrées de la table de hachage
typedef struct {
    char key;
    char value;
    UT_hash_handle hh;
} HashEntry;

// Fonction pour vérifier l'isomorphisme des chaînes
bool isIsomorphic(char* s, char* t) {
    HashEntry *mapST = NULL, *mapTS = NULL, *entry;
    for (int i = 0; i < strlen(s); i++) {
        // Vérifier la mappage de s vers t
        HASH_FIND(hh, mapST, &s[i], sizeof(char), entry);
        if (entry == NULL) {
            // Ajouter une nouvelle entrée
            entry = (HashEntry*)malloc(sizeof(HashEntry));
            entry->key = s[i];
            entry->value = t[i];
            HASH_ADD(hh, mapST, key, sizeof(char), entry);
        } else if (entry->value != t[i]) {
            // Mappage incohérent
            HASH_CLEAR(hh, mapST);
            HASH_CLEAR(hh, mapTS);
            return false;
        }
        
        // Vérifier la mappage de t vers s
        HASH_FIND(hh, mapTS, &t[i], sizeof(char), entry);
        if (entry == NULL) {
            // Ajouter une nouvelle entrée
            entry = (HashEntry*)malloc(sizeof(HashEntry));
            entry->key = t[i];
            entry->value = s[i];
            HASH_ADD(hh, mapTS, key, sizeof(char), entry);
        } else if (entry->value != s[i]) {
            // Mappage incohérent
            HASH_CLEAR(hh, mapST);
            HASH_CLEAR(hh, mapTS);
            return false;
        }
    }
    
    // Libérer la mémoire allouée
    HashEntry *current, *tmp;
    HASH_ITER(hh, mapST, current, tmp) {
        HASH_DEL(mapST, current);
        free(current);
    }
    HASH_ITER(hh, mapTS, current, tmp) {
        HASH_DEL(mapTS, current);
        free(current);
    }
    
    return true;
}

int main() {
    char s[] = "foo";
    char t[] = "bar";

    if (isIsomorphic(s, t)) {
        printf("Les chaînes sont isomorphes.\n");
    } else {
        printf("Les chaînes ne sont pas isomorphes.\n");
    }

    return 0;
}

