//29.09.2024 
//code optiimiser par copilot 
struct ListNode* removeElements(struct ListNode* head, int val) {
   if(head == NULL){
    return NULL;
   }
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *current = &dummy;

    while (current->next != NULL) {
        if (current->next->val == val) {
            struct ListNode *temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return dummy.next;
}

// algorithm et code de base 
//code pas assez performant surtout lorsqu'on supprime l'element situe a la premier place on
//le manque de clarte dans le code 
void suppression( Liste *liste,int nombre) {
    if(liste == NULL) {
        exit(EXIT_FAILURE);
    }
    node *current = liste->first, *suivant = NULL,*precedent = NULL;

    if(current->val == nombre) {
        suivant = current->next;
        free(current);
        liste->first = suivant;
    }
    current = liste->first;
    suivant = NULL;

    while(current != NULL) {
        if(current->val == nombre) {
            if(precedent == NULL) {
                liste->first = current->next;
            }
            else {
                precedent->next = current->next;
            }
            free(current);
            current = precedent;
        }
        precedent = current;
        current = current->next;
    }
}
