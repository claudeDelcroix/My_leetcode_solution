
void swap(char* a,char *b) {
    const char temp = *a;
    *a = *b;
    *b = temp;

}

void reverseString(char* s, int sSize) {
        if (sSize == 1) {
        return;
    }
    char* head = s;
    char * tail = s + sSize -1;
    while (head < tail) {
        swap(head,tail);
        head++;
        tail--;
    }
}
