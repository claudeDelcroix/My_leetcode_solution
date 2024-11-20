//la meilleure solution etait de creer une nouvelle liste factrice et de sauter les doublons 
#include <stdio.h>
#include <stdlib.h>

// Définition de la structure ListNode
struct ListNode {
    int val;
    struct ListNode *next;
};

// Fonction pour supprimer les doublons d'une liste chaînée
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;

    struct ListNode* prev = dummy;
    struct ListNode* current = head;

    while (current != NULL) {
        while (current->next != NULL && current->val == current->next->val) {
            current = current->next;
        }

        if (prev->next == current) {
            prev = prev->next;
        } else {
            prev->next = current->next;
        }

        current = current->next;
    }

    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}


Liste* deleteDuplicatesBest(Liste* head) {
    if(head->first == NULL || head->first->next == NULL) {
        return head;
    }
    node* dummy = (node*)malloc(sizeof(node));
    dummy->value = 0;
    dummy->next = head->first;
    node* prev = dummy;
    node* current = head->first;

    while(current != NULL) {
        while(current->next != NULL && current->value == current->next->value) {
            current = current->next;
        }

        if(prev->next == current) {
            prev = prev->next;
        }
        else {
            prev->next = current->next;
        }
        current = current->next;
    }
    Liste* newHead = initialisation();
    newHead->first = dummy->next;
    free(dummy);
    return newHead;
}
