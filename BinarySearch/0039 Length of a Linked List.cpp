/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
int solve(LLNode* node) {
    int count = 0;
    while(node != NULL) {
        count++;
        node = node->next;
    }
    return count;
}