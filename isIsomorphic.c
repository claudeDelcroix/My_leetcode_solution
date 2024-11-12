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
