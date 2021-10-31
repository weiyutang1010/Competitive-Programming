/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void dfs(Tree* node, int k, int& ans) {
    if (node->left) dfs(node->left, k, ans);
    if (node->right) dfs(node->right, k, ans);

    if (node->left && node->left->val == k) ans = node->right->val;
    if (node->right && node->right->val == k) ans = node->left->val;
    return;
}

int solve(Tree* root, int k) {
    int ans = 0;
    dfs(root, k, ans);
    return ans;
}
