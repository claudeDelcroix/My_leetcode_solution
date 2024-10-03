/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL){
        return false;
    }

    struct ListNode *current = head, *temp = head->next;
    for(int i = 0;i<10000;i++){
        for(int j = 0;j<10000;j++){
            if(temp == NULL){
                break;
            }
            if(current->next == temp->next){
                return true;
            }
            temp = temp->next;
        }
        if(current->next == NULL){
            break;
        }
        current = current->next;
        temp = current->next;
    }
    
    return false;
}
