#include <stdbool.h>
#include <stdlib.h>

// Définition de la structure ListNode
struct ListNode {
    int val;
    struct ListNode *next;
};

// Fonction pour inverser une liste chaînée
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Fonction pour vérifier si une liste chaînée est un palindrome
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // Trouver le milieu de la liste
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Inverser la deuxième moitié de la liste
    struct ListNode* secondHalf = reverseList(slow);
    struct ListNode* firstHalf = head;

    // Comparer les deux moitiés
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}
