/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* a, LLNode* b) {
    // Given two sorted linked list
    // Goal: Find union of the two lists

    // Algorithm: 
    // Always add the smaller element. When the element a and b are pointing to the same number
    // We add insert only one of them and move both pointer forward

    // Case when either ll is empty
    if (!a) return b;
    if (!b) return a;

    LLNode* head;

    // Choose smaller number head as the new head
    if (a->val == b->val) {
        head = a;
        a = a->next;
        b = b->next;
    } else if (a->val < b->val) {
        head = a;
        a = a->next;
    } else {
        head = b;
        b = b->next;
    }
    LLNode* curr = head;

    while (a || b) {
        // Case when either list is empty
        if (!a) {
            curr->next = b;
            b = b->next;
            curr = curr->next;
            continue;
        } else if (!b) {
            curr->next = a;
            a = a->next;
            curr = curr->next;
            continue;
        }

        // Pick the smaller element to add
        // If both element are the same, add one of them only
        if (a->val == b->val) {
            curr->next = a;
            a = a->next;
            b = b->next;
        } else if (a->val < b->val) {
            curr->next = a;
            a = a->next;
        } else {
            curr->next = b;
            b = b->next;
        }
        curr = curr->next;
    }

    return head;
}