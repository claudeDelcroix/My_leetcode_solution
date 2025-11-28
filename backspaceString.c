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
