/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

void dfs(vector<int>& v, Tree* node, int depth) {
    int n = v.size();
    if (depth == n) {
        v.push_back(node->val);
    }

    if (node->left) {
        dfs(v, node->left, depth + 1);
    }

    if (node->right) {
        dfs(v, node->right, depth + 1);
    }

    return;
}

vector<int> solve(Tree* root) {
    vector<int> ans;
    if (root) dfs(ans, root, 0);
    return ans;
}