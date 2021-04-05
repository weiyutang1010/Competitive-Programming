/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int dfs(Tree* node) {
    if (!node) return 0;

    int val = 0;
    if (node->left) val += dfs(node->left);
    if (node->right) {
        if (!node->right->right && !node->right->left) {
            val += node->right->val;
        } else {
            val += dfs(node->right);
        }
    }

    return val;
}

int solve(Tree* root) {
    return dfs(root);
}