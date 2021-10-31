/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool dfs(Tree* node) {
    if (!node->left && !node->right) return true;

    if (node->left && !dfs(node->left)) return false;
    if (node->right && !dfs(node->right)) return false;

    int sum = 0;
    if (node->left) sum += node->left->val;
    if (node->right) sum += node->right->val;

    return sum == node->val;
}

bool solve(Tree* root) {
    if (!root) return true;
    return dfs(root);
}
