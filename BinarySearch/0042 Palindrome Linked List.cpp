/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
bool solve(LLNode* node) {
    vector<int> v;
    while(node != NULL) {
        v.push_back(node->val);
        node = node->next;
    }

    int n = v.size();
    for (int l = 0, r = n - 1; l < r; l++, r--) {
        if (v[l] != v[r]) return false;
    }
    return true;
}