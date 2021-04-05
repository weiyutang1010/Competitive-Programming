/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void dfs(Tree* node, int& num_inter, int& num_leaf) {
    if (!node) return;
    if (!node->left && !node->right) {
        num_leaf++;
        return;
    }

    num_inter++;
    if (node->left) {
        dfs(node->left, num_inter, num_leaf);
    }

    if (node->right) {
        dfs(node->right, num_inter, num_leaf);
    }
}

vector<int> solve(Tree* root) {
    int num_inter = 0, num_leaf = 0;
    dfs(root, num_inter, num_leaf);
    return vector<int> {num_leaf, num_inter};
}