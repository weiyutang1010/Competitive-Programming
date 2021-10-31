/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void dfs(Tree* node, int idx, vector<int>& ans) {
    if (!node) return;

    if (idx >= ans.size()) {
        ans.push_back(node->val);
    } else {
        ans[idx] += node->val;
    }

    if (node->left) {
        dfs(node->left, idx + 1, ans);
    }

    if (node->right) {
        dfs(node->right, idx, ans);
    }
}

vector<int> solve(Tree* root) {
    vector<int> ans;
    if (root) dfs(root, 0, ans);
    return ans;
}
