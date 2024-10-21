/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void swap(struct ListNode* slow,struct ListNode* speed){
    slow->next = speed->next;
    speed->next = slow;
}

struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    
    struct ListNode* slowNode = head;
    struct ListNode* speedNode = head->next;
    head = speedNode;

    while(true){
        struct ListNode* nextPair = speedNode->next;
        swap(slowNode,speedNode);

        if(nextPair == NULL || nextPair->next == NULL){
            break;
        }

        slowNode->next = nextPair->next;
        slowNode = nextPair;
        speedNode = nextPair->next;
    }
    return head;
}
