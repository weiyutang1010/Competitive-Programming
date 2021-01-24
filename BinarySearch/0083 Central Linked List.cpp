/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
int solve(LLNode* node) {
    LLNode* head = node;
    int count = 0;
    while (node) {
        node = node->next;
        count++;
    }

    node = head;
    for (int i = 0; i < count/2; i++) {
        node = node->next;
    }
    return node->val;
}