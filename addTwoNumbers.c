/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//ne passe que 1565 sur 1569 a cause de la taille limite que peuvent les long
//avec des unsigned long 1566 sur 1569
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!newNode) {
        printf("Erreur d'allocation mémoiren");
        exit(1);
    }
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}


void insertEnd(struct ListNode** head, int data) {
    struct ListNode* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode; 
        return;
    }

    struct ListNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

 int* listToArray(struct ListNode* l1,int* returnSize){
    int* arr = (int*)malloc(100*sizeof(int));
    struct ListNode* current = l1;
    int i = 0;

    while(current != NULL){
        arr[i] = current->val;
        i++;
        current = current->next;
    }
    free(current);
    *returnSize = i;
    return arr;
 }

 int* listToArrayToGoodArray(int* arr,int arrSize){
    int* tab = (int*)malloc(arrSize*sizeof(int));
    int k = arrSize - 1;
    for(int i = 0;i < arrSize; i++){
        tab[i] = arr[k];
        k--;
    }
    return tab;
 }

 long arrayToLong(int* arr,int size){
    long result = 0, multiplier = 1;

    for(int i = size - 1; i >= 0;i--){
        result += arr[i]*multiplier;
        multiplier *= 10;
    }
    return result;
 }

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL && l2 == NULL){
        return NULL;
    }
    if(l1 == NULL){
        return l2;
    }
    if(l2 == NULL){
        return l1;
    }

    int i = 0,j = 0;
    int* arr1 = listToArray(l1,&i);
    int* arr2 = listToArray(l2,&j);
    if(i == 1 && j == 1){
        struct ListNode* l = NULL;
        int s = (arr1[0]+arr2[0]);
        if(s < 10){
            l = createNode(s);
        }else{
            int t = 2;
            while(s>0){
                int n = s%10;
                insertEnd(&l,n);
                s /= 10;
            }
        }
        free(arr1);
        free(arr2);
        return l;
    }
    int* t1 = listToArrayToGoodArray(arr1,i);
    int* t2 = listToArrayToGoodArray(arr2,j);
    long isArr1 = arrayToLong(t1,i);
    long isArr2 = arrayToLong(t2,j);
    long sum = isArr1 + isArr2;
    
    struct ListNode* newListe = NULL;

    while(sum > 0){
        int n = sum%10;
        insertEnd(&newListe,n);
        sum /= 10;
    }
    free(arr1);
    free(arr2);
    free(t1);
    free(t2);
    return newListe;
}

//la solution optimale 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode_t;

void InsertNodeTail (ListNode_t **tail, int val) {
    ListNode_t *newNode = NULL;

    newNode = (ListNode_t *)malloc(sizeof(ListNode_t));

    if (newNode != NULL) {
        newNode->val = val;
        newNode->next = NULL;

        if (*tail != NULL) {
            (*tail)->next = newNode;
        } 
        *tail = newNode;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    ListNode_t *head = NULL;
    ListNode_t *tail = NULL;
    
    int sum = 0;
    int carry = 0;

    while ((l1 != NULL) || (l2 != NULL)) {
        sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        if (sum >= 10) {
            carry = sum/10;
            sum %= 10;
        } else {
            carry = 0;
        }

        if (tail == NULL) {
            InsertNodeTail(&tail, sum);
            head = tail;
        } else {
            InsertNodeTail(&tail, sum);
        }
    }

    if (carry > 0) {
        InsertNodeTail(&tail, carry);
    }

    return head;
}
