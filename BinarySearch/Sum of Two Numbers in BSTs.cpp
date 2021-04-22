/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void dfs(Tree* node, unordered_map<int, int>& mp, bool find, bool& ans, int target) {
    if (!node) return;
    if (ans) return;

    if (find) {
        mp[node->val] = 1;
    } else {
        ans = mp.find(target - node->val) != mp.end();
    }

    if (node->left) {
        dfs(node->left, mp, find, ans, target);
    }

    if (node->right) {
        dfs(node->right, mp, find, ans, target);
    }

    return;
}

bool solve(Tree* a, Tree* b, int target) {
    unordered_map<int, int> mp;

    bool ans = false;
    dfs(a, mp, true, ans, target);
    dfs(b, mp, false, ans, target);

    return ans;   
}