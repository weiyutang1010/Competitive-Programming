/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* node) {
    vector<int> v;

    LLNode* temp = node;
    while (temp) {
        v.push_back(temp->val);
        temp = temp->next;
    }

    int n = v.size();
    for (int i = 0; i < n / 2; i++) {
        node = node->next;
    }

    int idx = n / 2 - 1;
    temp = node;
    if (n & 1) temp = temp->next;
    while (temp) {
        temp->val += v[idx];
        idx--;
        temp = temp->next;
    }

    return node;
}
