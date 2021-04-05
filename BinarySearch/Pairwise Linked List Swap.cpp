/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* node) {
    LLNode* head = node;
    while (node != NULL && node->next != NULL) {
        LLNode* first = node;
        LLNode* second = node->next;

        int temp = first->val;
        first->val = second->val;
        second->val = temp;

        node = second->next;
    }
    return head;
}