/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* head, int pos, int val) {
    // Convert value to a new node
    LLNode* node = new LLNode;
    node->val = val;

    // insert node at the beginning (need to set new head)
    if (pos == 0) {
        node->next = head;
        return node;
    }

    // Traverse until the node before the position
    LLNode* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
    }
    // Update pointer
    node->next = temp->next;
    temp->next = node;

    return head;
}