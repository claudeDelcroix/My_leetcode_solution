/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int count_node(const struct ListNode* head,const int k,struct ListNode** x){
    struct ListNode* current = head;
    int count = 0;
    while (current != NULL){
        if(count == k-1){
            *x = current;
        }
        current = current->next;
        count++;        
    }
    return count;
}

struct ListNode* swapNodes(struct ListNode* head, int k) {
   struct ListNode* x = NULL;
    int count = count_node(head,k,&x);
    if(count == 1)return head;
    //to get the y
    struct ListNode* y = head;
    //printf("count : %d\n count - k = %d\n",count,count-k);
    for(int i = 0;i < count - k;i++){
       //printf("i = %i and y->val = %d\n",i,y->val);
        y = y->next;
    }
    //printf("x->val = %d\ny->val = %d\n",x->val,y->val);
    int temp = y->val;
    y->val = x->val;
    x->val = temp;
    return head;
}
