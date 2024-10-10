/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head->next == NULL){
        return NULL;
    }
    struct ListNode *cur = head,*prev = head;
    int count = 0;
    while(cur != NULL){
        count++;
        cur = cur->next;
    }
    int s = abs(count - n);
    if(s == 0){
        struct ListNode* delete = head;
        head = head->next;
        free(delete);
        return head;
    }
    cur = head;
    for(int i = 0; i < s;i++){
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    free(cur);
    return head;
}
