/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
int solve(LLNode* node, int k) {
    LLNode* temp = node;
    for (int i = 0; i < k; i++) {
        node = node->next;
    }

    while (node->next != NULL) {
        node = node->next;
        temp = temp->next;
    }

    return temp->val;
}