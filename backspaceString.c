typedef struct stack stack;
struct stack{
    int top;
    int max;
    int min;
    char* data;
};

void init_stack(stack* s, const int size){
    s->data = (char*)malloc(size * sizeof(char));
    if(!s->data){
        fprintf(stderr,"Error of allocation\n");
        exit(EXIT_FAILURE);
    }
    s->max = size;
    s->min = size;
    s->top = -1;
}

void push(stack* s,char value){
    if(s->top < s->max -1){
        s->top++;
        s->data[s->top] = value;
    }else{
        s->max = s->max * 2;
        s->data = (char*)realloc(s->data,s->max * sizeof(char));
        push(s,value);
    }
}

void pop(stack* s){
    if(s->top >= 0){
        s->top--;
        if(s->top < (s->max / 2) && s->max > s->min){
            s->max = s->max / 2;
            s->data = (char*)realloc(s->data,s->max * sizeof(char));
        }
    }
}

bool compare_string(const char* s1, const char* s2,const int size1,const int size2){
    if(size1 != size2){
        return false;
    }
    for(int i = 0;i <= size1;i++){
        if(s1[i] != s2[i]){
            return false;
        }
    }
    return true;
}


bool backspaceCompare(char* s, char* t) {
    stack ss;
    stack st;
    init_stack(&ss,50);
    init_stack(&st,50);
    for(int i = 0;i < strlen(s);i++){
        if(s[i] == '#'){
            pop(&ss);
        }else{
            push(&ss,s[i]);
        }
    }

    for(int i = 0;i < strlen(t);i++){
        if(t[i] == '#'){
            pop(&st);
        }else{
            push(&st,t[i]);
        }
    }

    bool result = compare_string(ss.data,st.data,ss.top,st.top);
    free(ss.data);
    free(st.data);
    return result;
}


//methode des deux pointeurs 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool backspaceCompare(const char* s, const char* t) {
    int i = strlen(s) - 1;  // pointeur pour s
    int j = strlen(t) - 1;  // pointeur pour t

    int skipS = 0;  // nombre de caractères à sauter dans s
    int skipT = 0;  // nombre de caractères à sauter dans t

    // parcourir tant qu'il reste un caractère dans au moins une chaîne
    while (i >= 0 || j >= 0) {

        // --- Avancer dans s ---
        while (i >= 0) {
            if (s[i] == '#') {      // un backspace ?
                skipS++;
                i--;
            }
            else if (skipS > 0) {   // caractère à effacer
                skipS--;
                i--;
            }
            else {
                break;              // caractère réel trouvé
            }
        }

        // --- Avancer dans t ---
        while (j >= 0) {
            if (t[j] == '#') {
                skipT++;
                j--;
            }
            else if (skipT > 0) {
                skipT--;
                j--;
            }
            else {
                break;
            }
        }

        // Maintenant : soit on compare les caractères, soit les deux sont en dehors de la chaîne

        // Si les deux pointeurs sont valides
        if (i >= 0 && j >= 0) {
            // caractères différents ?
            if (s[i] != t[j]) {
                return false;
            }
        }
        else {
            // Un seul est valide : longueurs finales différentes
            if (i >= 0 || j >= 0) {
                return false;
            }
        }

        i--;
        j--;
    }

    return true;
}

