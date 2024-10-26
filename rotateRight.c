struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || k == 0) {
        return head;
    }

    struct ListNode* current = head;
    int length = 1;
    while (current->next) {
        current = current->next;
        length++;
    }
    current->next = head;


    k = k % length;
    int stepsToNewHead = length - k;
    
    current = head;
    for (int i = 0; i < stepsToNewHead - 1; i++) {
        current = current->next;
    }

    struct ListNode* newHead = current->next;
    current->next = NULL;

    return newHead;
}
