/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool dfs(Tree* node, int val) {
    if (!node) return true;
    if (node->val != val) return false;

    return dfs(node->left, val) && dfs(node->right, val);
}

bool solve(Tree* root) {
    if (root) {
        int val = root->val;
        return dfs(root, val);
    }
    return true;
}