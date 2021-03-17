/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
int solve(LLNode* node) {
    string s = "";
    while (node != NULL) {
        s += node->val + '0';
        node = node->next;
    }
    return stoi(s, NULL, 2);
}