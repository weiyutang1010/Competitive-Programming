/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void dfs(Tree* node, int& ans, string value) {
    value += to_string(node->val);

    if (!node->left && !node->right) {
        ans += stoi(value);
    }

    if (node->left) dfs(node->left, ans, value);
    if (node->right) dfs(node->right, ans, value);
    return;
}

int solve(Tree* root) {
    int ans = 0;
    if (root) dfs(root, ans, "");
    return ans;
}