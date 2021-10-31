/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool dfs(Tree* node, int depth, int& level) {
    if (!node) return true;
    if (!node->left && !node->right) {
        if (level == -1) level = depth;
        else return level == depth;
    }

    if (node->left && !dfs(node->left, depth+1, level)) return false;
    if (node->right && !dfs(node->right, depth+1, level)) return false;

    return true;
}

bool solve(Tree* root) {
    int level = -1;
    return dfs(root, 0, level);
}
