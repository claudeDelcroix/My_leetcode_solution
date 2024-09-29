/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//premiere version du code a beaucoup de faille mais remplie certains tests 
bool isPalindrome(struct ListNode* head) {
    int *stack = (int*)malloc(200*sizeof(int)),i = 1;
    struct ListNode* current = head;
    if(current->next == NULL){
        return true;
    }

    while(current != NULL){
        if(stack[i-1] == current->val){
            i--;
        }
        else{
            stack[i] = current->val;
            i++;
        }
        current = current->next;
    }
    i--;

    free(stack);
    if(i == 0){
        return true;
    }
    else{
        return false;
    }
}


//voici la fonction complete mais qui ne remplie pas mes attentes elle ne s'excecute pas a O(n) elle a 123ms et occupe beaucoup d'espace 
bool isPalindrome(struct ListNode* head) {
    int *stack = (int*)malloc(100001*sizeof(int)),i = 0;
    struct ListNode* current = head;

    while(current != NULL){
       stack[i] = current->val;
       i++;
       current = current->next;
    }

    for(int j = i-1,k = 0;k<i;j--,k++){
        if(stack[j] != stack[k]){
            return false;
        }
    }
    free(stack);
    return true;
}
